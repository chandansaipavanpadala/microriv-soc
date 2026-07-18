# MicroRiv SoC (Phase 5: Verification, Assertions & Project Wrap-up)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes.

This repository contains the final deliverables for **Phase 5**, enclosing full SystemVerilog Assertions (SVA) for clock domain crossing (CDC) and APB protocol verification, regression tools, and a complete design wrap-up.

---

## 1. Project Directory Structure

```
microriv-soc/
├── rtl/                   # System RTL Verilog/SystemVerilog files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core (PD_CPU / clk_cpu)
│   ├── picorv32_apb_bridge.v # APB3 Master Bridge (PD_CPU / clk_cpu)
│   ├── sync2_stage.v      # 2-stage D-FF synchronizer to resolve metastability
│   ├── clk_divider.v      # Clock divider generating raw peripheral clock
│   ├── icg.v              # Glitch-free latch-based clock gating cell (with assertions)
│   ├── apb_cdc_bridge.v   # Level-Handshake APB3 CDC Bridge (with SVA assertions)
│   ├── apb_uart_bridge.v  # APB UART register decoder (PD_PERIPH / gated_clk_periph)
│   ├── uart.v             # UART transceiver stub (PD_PERIPH / gated_clk_periph)
│   ├── apb_gpio.v         # 32-bit APB GPIO controller (PD_PERIPH / gated_clk_periph)
│   ├── apb_timer.v        # 32-bit APB countdown Timer (PD_PERIPH / gated_clk_periph)
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (PD_CPU / clk_cpu)
│   └── soc_top.v          # Top-level SoC wrapper instantiating all components
├── tb/                    # Testbench files
│   └── tb_soc.v           # Verilog-only testbench (counts clock edges and reports savings)
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (UART, GPIO, and Timer tests)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   └── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
├── docs/                  # Architectural documentation
│   ├── architecture.md    # [UPDATED] Detailed clock gating, UPF domain maps, and assertions checklist
│   └── summary.md         # [NEW] End-to-end project overview, bug logs, and synthesis next steps
├── power.upf              # Unified Power Format specification mapping power domains
└── run.sh                 # [UPDATED] Compile script supporting assertions and bug injection
```

---

## 2. Power & Verification Domain Definitions (UPF)

The power domains are formally defined in `power.upf` as follows:

| Power Domain | Included Modules | Primary Supply | Isolation Policy | Description |
| :--- | :--- | :---: | :---: | :--- |
| **`PD_CPU`** | Core, SRAM, CDC bridge (CPU side) | `VDD_CPU` | N/A (Always-on) | Always-on high-speed execution block |
| **`PD_PERIPH`** | Peripherals (UART, GPIO, Timer, CDC bridge periph side) | `VDD_PERIPH` | Clamp outputs to `0` | Sleep domain gated by the dynamic power controller |

---

## 3. How to Run the Simulation

### A. Normal Functional Run
To compile and run the baseline simulation (without assertions or bugs):
```bash
./run.sh
```

### B. Assertion-Enabled Verification Run
To run the simulation with SystemVerilog Assertions (SVA) and checkers compiled in:
```bash
./run.sh --assertions
```
This enables SVA checks ensuring CDC data stability, handshake sequencing, clock gating pulse protection, and APB compliance.

### C. Deliberate CDC Bug-Injection Run
To prove that our verification checkers successfully catch domain-crossing bugs, execute:
```bash
./run.sh --assertions --inject-cdc-bug
```
* **What this does**: Bypasses the request synchronizer stage in `apb_cdc_bridge.v`, passing the request combinational and unsynchronized across clocks.
* **Expected outcome**: The simulation halts immediately with the following checker assertion error:
  `%Error: [SVA CDC ERROR] Synchronizer output req_periph_sync changed asynchronously while clk_periph is low!`

---

## 4. Verification Checklists & Wrap-up

Detailed documentation on implementation details, latency charts, CDC stability, and physical ASIC deployment can be found in:
* **[SoC Architectural Specifications](file:///p:/OneDrive%20-%20Amrita%20vishwa%20vidyapeetham/ASEB/NIELET%20Bootcamp/microriv-soc/docs/architecture.md)**
* **[Project Final Summary & Bug Log](file:///p:/OneDrive%20-%20Amrita%20vishwa%20vidyapeetham/ASEB/NIELET%20Bootcamp/microriv-soc/docs/summary.md)**
