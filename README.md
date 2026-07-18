# MicroRiv SoC (Phase 2: APB Bus Fabric & Peripheral Integration)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes.

This repository contains the deliverables for **Phase 2** of the multi-phase project. 

The objective of Phase 2 is to replace the direct-memory-mapped simulation console hack with a proper **AMBA APB3 bus fabric** and integrate three peripherals: **UART**, **GPIO**, and a **Timer**. All simulation steps compile and execute via a single entry script `run.sh` inside a Verilog-only environment.

---

## 1. Project Directory Structure

```
microriv-soc/
├── rtl/                   # System RTL Verilog files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core
│   ├── picorv32_apb_bridge.v # [NEW] APB3 Master Bridge
│   ├── apb_uart_bridge.v  # [NEW] APB UART register decoder (from boot camp references)
│   ├── uart.v             # [NEW] UART transceiver stub (prints outputs to simulation terminal)
│   ├── apb_gpio.v         # [NEW] 32-bit APB GPIO controller
│   ├── apb_timer.v        # [NEW] 32-bit APB countdown Timer (modified references with PREADY)
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (1-wait-state)
│   └── soc_top.v          # Top-level SoC wrapper (interconnect & peripheral routing)
├── tb/                    # Testbench files
│   └── tb_soc.v           # Verilog-only testbench (clock/reset, GPIO loopback, VCD trace)
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (register computation, UART print, GPIO & Timer checks)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   └── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
├── docs/                  # Architectural documentation
│   └── architecture.md    # [UPDATED] Detail memory maps, block topology, and IP adaptations
└── run.sh                 # Unified bash script to compile firmware, compile Verilator, and run
```

---

## 2. APB Memory Map

| Device / Slave | Base Address | Size | Description / Target Registers |
| :--- | :---: | :---: | :--- |
| **System SRAM** | `0x0000_0000` | 16KB | Main internal RAM for code and data |
| **APB UART** | `0x1000_0000` | 16B | register-level stub: `tx_data` (0x00), `rx_data` (0x04), `status` (0x08) |
| **APB GPIO** | `0x1001_0000` | 16B | `gpio_out` (0x00) and `gpio_in` (0x04) |
| **APB Timer** | `0x1002_0000` | 16B | `load_val` (0x00), `running` (0x04), `timer_done` (0x08), `count` (0x0c) |
| **Sim Exit Register**| `0x8000_0004` | 4B | Write `1` for SUCCESS, other values for FAILURE |

---

## 3. How to Run the Project

To run the simulation end-to-end on your target system:

1. Navigate to the `microriv-soc` root directory:
   ```bash
   cd microriv-soc
   ```
2. Execute the unified simulation script:
   ```bash
   ./run.sh
   ```

### Execution Status Output
Upon running, the script compiles the assembly, links it, generates `firmware.hex`, compiles the Verilog-only sources with Verilator timing-checks, and runs:
```text
==================================================================
 1. Compiling test firmware (start.S)
==================================================================
...
Firmware compilation complete. Hex output saved to: sim/firmware.hex

==================================================================
 2. Compiling RTL and Verilog Testbench with Verilator
==================================================================
Verilator compilation complete.

==================================================================
 3. Running Simulation
==================================================================
[TB] Starting Phase 2 simulation...
[TB] Reset released. Core executing...
Hello APB UART!
[TB] Simulation exit requested by firmware.
[TB] Exit code:          1
[TB] SUCCESS: Test program completed successfully!
==================================================================
 Simulation Finished
==================================================================
```

### Trace Verification
The testbench generates `sim/waveform.vcd`. Open it in GTKWave to inspect peripheral handshakes:
```bash
gtkwave sim/waveform.vcd
```
- **UART**: Check `psel_uart` and `PENABLE` toggling when `"Hello APB UART!\n"` is written.
- **GPIO**: Trace `gpio_out` and `gpio_in` signals. Confirm they match `0x5555_AAAA`.
- **Timer**: Trace `timer_peripheral.count` to observe it decrementing from `100`.
- **APB Master**: Trace `PWRITE`, `PADDR`, `PWDATA`, and `PREADY` to confirm compliant APB Master transaction timing.
