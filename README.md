# MicroRiv SoC (Phase 4: Low-Power Power Management & UPF)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes.

This repository contains the deliverables for **Phase 4** of the multi-phase project.

The objective of Phase 4 is to incorporate dynamic **low-power clock gating** on the peripheral clock domain using a glitch-free Integrated Clock Gating (ICG) cell and layer a conceptual **Unified Power Format (UPF)** description defining the power domain intent.

---

## 1. Project Directory Structure

```
microriv-soc/
├── rtl/                   # System RTL Verilog files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core (PD_CPU / clk_cpu)
│   ├── picorv32_apb_bridge.v # APB3 Master Bridge (PD_CPU / clk_cpu)
│   ├── sync2_stage.v      # 2-stage D-FF synchronizer to resolve metastability
│   ├── clk_divider.v      # Clock divider generating raw peripheral clock
│   ├── icg.v              # [NEW] Glitch-free latch-based clock gating cell
│   ├── apb_cdc_bridge.v   # Level-Handshake APB3 CDC Bridge (outputs clk_periph_en)
│   ├── apb_uart_bridge.v  # APB UART register decoder (PD_PERIPH / gated_clk_periph)
│   ├── uart.v             # UART transceiver stub (PD_PERIPH / gated_clk_periph)
│   ├── apb_gpio.v         # 32-bit APB GPIO controller (PD_PERIPH / gated_clk_periph)
│   ├── apb_timer.v        # 32-bit APB countdown Timer (PD_PERIPH / gated_clk_periph)
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (PD_CPU / clk_cpu)
│   └── soc_top.v          # Top-level SoC wrapper instantiating clk_divider, ICG, and CDC bridge
├── tb/                    # Testbench files
│   └── tb_soc.v           # [UPDATED] Verilog-only testbench (counts clock edges and prints savings)
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (UART, GPIO, and Timer tests)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   └── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
├── docs/                  # Architectural documentation
│   └── architecture.md    # [UPDATED] Detail clock gating schemes, wakeup timings, and UPF models
├── power.upf              # [NEW] Unified Power Format specification mapping power domains
└── run.sh                 # Unified bash script compiling firmware, Verilator, and running simulation
```

---

## 2. Power Domain Definitions (UPF)

The power domains are formally defined in `power.upf` as follows:

| Power Domain | Included Modules | Primary Supply | Isolation Policy | Description |
| :--- | :--- | :---: | :---: | :--- |
| **`PD_CPU`** | Core, SRAM, CDC bridge (CPU side) | `VDD_CPU` | N/A (Always-on) | Always-on high-speed execution block |
| **`PD_PERIPH`** | Peripherals (UART, GPIO, Timer, CDC bridge periph side) | `VDD_PERIPH` | Clamp outputs to `0` | Sleep domain gated by the dynamic power controller |

---

## 3. How to Run and Verify Gating Statistics

1. Navigate to the `microriv-soc` root directory:
   ```bash
   cd microriv-soc
   ```
2. Execute the unified simulation script:
   ```bash
   ./run.sh
   ```

### Gating Savings Output
Upon completion, the testbench counts the active rising edges of both the raw (ungated) divided clock and the gated clock, outputting the metrics to the terminal:
```text
==================================================================
 3. Running Simulation
==================================================================
[TB] Starting Phase 4 simulation...
[TB] Reset released. Core executing...
Hello APB UART!
[TB] Simulation exit requested by firmware.
[TB] Exit code:          1
[TB] SUCCESS: Test program completed successfully!
==================================================================
 Clock Gating Performance Statistics (During Active Simulation)
==================================================================
 Raw Peripheral Clock Edges:   36675
 Gated Peripheral Clock Edges: 5293
 Clock Edges Saved:            31382
 Dynamic Power Reduction:      85%
==================================================================
```
*(Note: Edges and savings percentages may vary slightly depending on compiler optimization and cycles).*

---

## 4. GTKWave Verification of Gated Clocks

To verify the ICG un-gating and gating transitions:
1. Open GTKWave:
   ```bash
   gtkwave sim/waveform.vcd
   ```
2. Navigate to `tb_soc` -> `dut` -> `periph_icg`.
3. Add the following signals to the wave trace:
   * **`clk_in`**: The raw divided clock (always toggling).
   * **`en`**: The clock gate enable signal (`clk_periph_en` from the CDC bridge).
   * **`en_latch`**: The negative-latch output (locked and stable when `clk_in` is high).
   * **`clk_out`**: The gated clock (`gated_clk_periph` feeding the peripherals).
4. Observe that `clk_out` stays completely static (logic low) during idle periods and starts toggling cleanly (without glitches) only when `en` rises, stopping cleanly after the transaction finishes.
