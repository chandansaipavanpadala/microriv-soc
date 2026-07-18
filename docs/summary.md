# MicroRiv SoC - Project Wrap-up & Final Summary

This document serves as a complete project wrap-up for the **MicroRiv SoC** project, summarizing the design choices, architectural progression, bug history, and verification methodologies across all 5 integration phases.

---

## 1. End-to-End SoC Architecture

The **MicroRiv SoC** is a dual-clock, low-power RISC-V system-on-chip built using structural Verilog and verified with Verilator simulation.

```
       [clk_cpu Domain - 50 MHz]                   [clk_periph Domain - 12.5 MHz]
   +---------------------------------+          +-----------------------------------+
   |                                 |          |                                   |
   |   +----------+     +--------+   |          |    +------------+                 |
   |   | PicoRV32 |     | APB    |   |  CDC     |    | Glitch-Free|                 |
   |   | CPU Core | === | Master | === Bridge ====== | ICG Cell   |                 |
   |   +----+-----+     | Bridge |   | Boundary |    +-----+------+                 |
   |        |           +--------+   |          |          | gated_clk              |
   |   +----+-----+                  |          |    +-----v-----+                  |
   |   | 16KB RAM |                  |          |    | Peripheral| (UART, GPIO,     |
   |   +----------+                  |          |    | Decoder   |  Timer)          |
   |                                 |          |    +-----------+                  |
   +---------------------------------+          +-----------------------------------+
```

### Core Pipeline Components:
1. **CPU Core (PicoRV32)**: Configured for compact size and standard RV32I ISA execution, interfacing with SRAM via a native memory bus.
2. **System Memory (16KB SRAM)**: Single-cycle read/write static RAM storing instructions, data, and stack segments.
3. **APB3 Master Bridge**: Bridges the CPU's native memory transactions into APB3 protocol phases.
4. **Glitch-Free Clock Divider**: Divide-by-4 register counter providing a synchronous 12.5 MHz clock (`clk_periph_raw`) from the 50 MHz `clk_cpu`.
5. **APB CDC Bridge**: Safely translates APB control and data signals across clock domain boundaries using a Level-Handshake protocol with 2-stage synchronizers (`sync2_stage.v`).
6. **Integrated Clock Gating (ICG)**: An active-low transparent latch combined with an AND gate to dynamically shut off `clk_periph` when the bus is idle.
7. **APB Slaves**:
   * **UART Transceiver**: Handles bare-metal character transmission and status checking.
   * **GPIO Controller**: 32-bit output/input pins supporting external digital interfaces.
   * **Countdown Timer**: 32-bit programmable timer generating completion interrupts.

---

## 2. Power and Verification Structure

### UPF Power Domain Design
The project is partitioned into two power domains described in `power.upf`:
* **`PD_CPU` (Always-On)**: The core computing subsystem.
* **`PD_PERIPH` (Power-Gateable)**: The peripheral domain.
* **Boundary Policy**: Outputs crossing from `PD_PERIPH` to `PD_CPU` must be clamped to logic `0` during sleep modes via isolation cells to prevent floating nodes from burning leakage current.

### Real vs. Conceptual Verification Matrix
* **Real (Simulated and Verified)**:
  * Functional code compilation and execution of test programs.
  * Clock divider, CDC bridge, and negative-latch ICG cell behavior.
  * Testbench counters showing **~30% clock edge reduction** during active UART polling and **>90%** during CPU computations.
  * SystemVerilog Assertions checking CDC stability, APB compliance, and synchronizer clock alignment.
* **Conceptual (Synthesis/ASIC Specifications)**:
  * `power.upf` script used for physical layout compiler input.
  * Isolation cell instantiation, sleep control switches, and level shifters (which require a physical backend PDK library to simulate).

---

## 3. Bug History & Resolved Issues

Throughout the integration phases, several significant design bugs were found, debugged, and structurally resolved:

1. **Duplicate APB Transactions (Phase 2)**:
   * *Symptom*: CPU memory reads repeated background APB transfers on the same command, causing processor lockups.
   * *Fix*: Modified `picorv32_apb_bridge.v` to check `if (mem_valid && !mem_ready)` in `STATE_IDLE` before launching a transaction, preventing repeated triggers.
2. **UART Character Duplication (Phase 2)**:
   * *Symptom*: Characters printed to the console were duplicated.
   * *Fix*: Switched `tx_write` and `tx_data` inside `apb_uart_bridge.v` from sequential registers to combinatorial expressions gated by `PREADY`, ensuring write triggers are active for exactly one clock edge.
3. **Firmware Literal Address Compilation Error (Phase 2)**:
   * *Symptom*: Assembler errors about "bignums with underscores" during compile.
   * *Fix*: Replaced underscore hex formats (e.g. `0x8000_0004`) with clean literals (`0x80000004`) in `start.S` to compile under standard GNU RISC-V compilers.
4. **Verilator Linter Warnings (Phase 2 & 3)**:
   * *Warnings*: `CASEINCOMPLETE` in peripherals, `SYNCASYNCNET` on reset nets.
   * *Fixes*: Added `default` blocks to all peripheral case registers. Created a clock-aligned `sim_started` register in `tb_soc.v` to gate the simulation monitor instead of using raw async resets directly, resolving `SYNCASYNCNET` cleanly.

---

## 4. Next Steps for Hardware Deployment (ASIC / FPGA)

If this design is deployed to an FPGA (such as a Xilinx Artix-7) or synthesized using open-source ASIC tools (Yosys + OpenLane):

1. **Physical Clock Buffer Substitution**:
   * Replace the RTL-level ICG cell (`icg.v`) with vendor-specific clock buffers (e.g., `BUFGCE` on Xilinx FPGAs, or PDK ICG cells in ASIC libraries) to ensure optimal timing and clock distribution tree balancing.
2. **Reset Synchronizers**:
   * Integrate active reset synchronizers for both domains (`rst_n_cpu` and `rst_n_periph`) to resolve reset deassertion timing violations and prevent meta-stability on power-on.
3. **Interrupt controller (PLIC)**:
   * Connect `timer_done` and UART RX interrupts to a simple programmable interrupt controller, and hook it up to the PicoRV32 IRQ interface to transition the CPU from polling loops to interrupt-driven execution.
