# microriv-soc Architecture & Design Log (Phase 4)

This document captures the architectural decisions, memory mappings, clock domain crossing (CDC) bridge designs, and power management structures (Clock Gating and UPF) for Phase 4 of the **microriv-soc** project.

---

## 1. System Block Diagram & Power Domain Topology

Phase 4 splits the SoC into separate clock domains and layers a Unified Power Format (UPF) power domain strategy on top:
1. **Always-On Domain (`PD_CPU`)**: Runs on `clk_cpu` (50 MHz) and includes the PicoRV32 core, system SRAM, and the CPU domain side of `apb_cdc_bridge`.
2. **Clock-Gated / Power-Gateable Domain (`PD_PERIPH`)**: Runs on `clk_periph` (12.5 MHz, divided by 4) and includes the APB decoder/multiplexer, UART, GPIO, and countdown Timer peripherals. Its clock is dynamically gated using an Integrated Clock Gate (ICG) cell when the APB bus is idle.

```
+-------------------------------------------------------------------------------+
|                       Always-On Power Domain (PD_CPU)                         |
|                                                                               |
|  +--------------+                      +-------------------------+            |
|  |   PicoRV32   |    Native Memory Bus |   picorv32_apb_bridge   |            |
|  |     Core     | -------------------> |      (APB3 Master)      |            |
|  +-------+------+                      +------------+------------+            |
|          | (SRAM Bus)                               |                         |
|          v                                          v                         |
|     +----+----+                             +-------+-------+                 |
|     | SRAM RAM|                             |  cdc_bridge   |                 |
|     +---------+                             | (CPU Domain)  |                 |
|                                             +-------+-------+                 |
|                                                     |                         |
+-----------------------------------------------------|-------------------------+
                                                      |
                                                      | CDC / Power Boundary
                                                      | (with UPF Isolation Net Clamps)
                                                      v
+-------------------------------------------------------------------------------+
|             Gated Clock / Power-Gateable Power Domain (PD_PERIPH)             |
|                                                     |                         |
|                                             +-------+-------+                 |
|                                             |  cdc_bridge   |                 |
|                                             | (Periph Domain)                 |
|                                             +-------+-------+                 |
|                                                     |                         |
|  +-------------+  clk_periph_raw            +-------v-------+                 |
|  | clk_divider | -------------------------> |   icg cell    |                 |
|  +-------------+                            | (gated clock) |                 |
|                                             +-------+-------+                 |
|                                                     | gated_clk_periph        |
|                                                     v APB Bus                 |
|                                            +--------+--------+                |
|                                            | Decode / Mux    |                |
|                                            +---+----+----+---+                |
|                                                |    |    |                    |
|                                                v    v    v                    |
|                                              UART  GPIO Timer                 |
|                                                                               |
+-------------------------------------------------------------------------------+
```

---

## 2. Memory Map & Address Decoding

The memory map remains identical to previous phases:

| Address Range | Target Module | Power Domain | Clock Domain | Description |
| :--- | :--- | :---: | :---: | :--- |
| `0x0000_0000` - `0x0000_3FFF` | `soc_ram.v` (16KB) | `PD_CPU` | `clk_cpu` | Main internal SRAM (Code + Data + Stack) |
| `0x1000_0000` - `0x1000_000F` | `apb_uart_bridge.v` | `PD_PERIPH` | `gated_clk_periph` | APB UART loopback stub |
| `0x1001_0000` - `0x1001_000F` | `apb_gpio.v` | `PD_PERIPH` | `gated_clk_periph` | APB GPIO register interface |
| `0x1002_0000` - `0x1002_000F` | `apb_timer.v` | `PD_PERIPH` | `gated_clk_periph` | APB countdown Timer register interface |
| `0x8000_0004` | Sim Exit Control | `PD_CPU` | `clk_cpu` | Writes `1` for SUCCESS, other values for FAILURE |

---

## 3. Dynamic Clock Gating Scheme (Glitch-Free ICG)

To reduce dynamic power consumption during periods of bus idle, `clk_periph` is gated off at the root of `PD_PERIPH` using a glitch-free Integrated Clock Gating (ICG) cell (`icg.v`).

### Glitch Prevention Rationale:
* Directly ANDing a raw clock with a combinational enable signal is prone to clock glitches (pulses that are truncated or generated accidentally when the enable switches).
* The ICG cell resolves this by feeding the enable signal (`en`) into a **negative-edge transparent latch** (active-low transparent, i.e., transparent only when the clock is low) before combining it with the clock via an AND gate.
* Any changes in the enable signal are captured only while `clk_in` is low. When `clk_in` rises, the latch closes and locks the enable value, guaranteeing that `clk_out` experiences only clean, full-width pulses.

### Wakeup and Handshake Logic:
1. **Wakeup**: The CPU initiates an APB request in the high-speed domain, raising `req_cpu`. This immediately asserts `clk_periph_en` (which is driven combinatorially by the CDC bridge as `req_cpu || ack_periph`). The ICG cell transparently registers this enable during the low phase of the clock, starting `clk_periph` toggling on the next edge.
2. **Synchronization**: Once the gated clock starts, the synchronizer `sync_req` propagates `req_cpu` to the peripheral domain as `req_periph_sync` (taking 2 cycles of the now-running `clk_periph`).
3. **Execution**: The APB transaction executes and completes, raising `ack_periph`.
4. **Clean-up**: The CPU deasserts `req_cpu`. To prevent the clock from shutting down before the CDC bridge completes its cleanup, the enable is held by `ack_periph`. Once the peripheral FSM deasserts `ack_periph`, the clock turns off cleanly on the next clock-low phase.

---

## 4. UPF Power Specifications (Real vs. Conceptual)

The `power.upf` script provides a formal specification of the SoC's power intent.

### Verification Categories:

1. **verified in Simulation (Real)**:
   * **Dynamic Clock Gating**: The clock divider, ICG latch, and enable logic are fully simulated in Verilog. The testbench counts the toggling edges of both the raw and gated clock lines.
   * **Simulation edge saving check**: The edge comparison prints performance statistics confirming the active saving of clock edges (expected >85% saving due to long idle periods in firmware execution).
2. **Conceptual (UPF & Physical Flow Documentation)**:
   * **Verilator UPF support**: Verilator compiles pure structural Verilog and does not execute power state formats (UPF/CPF) directly. Therefore, `power.upf` is a conceptual/documentation-only artifact for downstream synthesis.
   * **ASIC Physical Flow**: In a real silicon flow, a synthesis tool (like Synopsys Design Compiler) reads the UPF file to:
     * Insert **power switches** (sleep transistors) to disconnect the VDD supply mesh from `PD_PERIPH`.
     * Insert **isolation cells** at the boundary (PD_PERIPH -> PD_CPU) to clamp outputs to logic `0` (so always-on gates in `PD_CPU` do not float and burn leakage power when `PD_PERIPH` is off).
     * Insert **level shifters** if the two domains run at different supply voltages.

---

## 5. CDC and Clock Gating Failure Mode Analysis (Interview Diagnostics)

* **What happens if CDC control synchronizers are removed?**
  * Control lines (such as `PSEL`, `PENABLE`) will violate setup/hold times at the peripheral domain inputs if clock edges align closely, resulting in metastabilities that corrupt state machines and lock the bus.
* **What happens if data/address buses are not held stable during handshakes?**
  * Multi-bit bus skew would cause different bits to cross the domain boundary at slightly different physical delays, leading to transient corrupted values being captured at the target slave.
* **What happens if clock gating is performed using a raw AND gate?**
  * If the enable signal goes high or low while the raw clock is high, it will truncate the active clock pulse or insert a tiny "glitch" pulse. These narrow pulses violate the setup times of downstream registers, causing registers to lock up or latch corrupt data.
