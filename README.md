# MicroRiv SoC (Phase 1: RISC-V Standalone Core Simulation)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes.

In this revision of Phase 1, the simulation framework has been converted to a **Verilog-only** code architecture (`.v` files for RTL and Testbench) managed by a unified, cross-platform compilation and execution script (`run.sh`), matching the workflow pattern found in the references.

---

## 1. Project Directory Structure

All components are written in Verilog (or python/assembly) and located in the `microriv-soc` folder, leaving placeholders for Phase 2 peripherals:

```
microriv-soc/
├── rtl/                   # System RTL Verilog files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (1-wait-state)
│   └── soc_top.v          # Top-level SoC wrapper (address decoding, memory bus mux)
├── tb/                    # Testbench files
│   └── tb_soc.v           # [NEW] Verilog-only testbench (clock/reset, VCD trace, watchdog, exit check)
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (register computation loop & exit ports)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   └── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
├── docs/                  # Architectural documentation
│   └── architecture.md    # Summary of Phase 1 design decisions
└── run.sh                 # [NEW] Unified bash script to compile firmware, Verilator, and run simulation
```

---

## 2. Rationale & Key Architecture Decisions

- **Verilog-Only Design (`tb_soc.v`)**: By utilizing Verilator's native timing engine support (`--timing`), the testbench is written entirely in Verilog rather than C++. This aligns the workflow with standard RTL simulation and removes C++ testbench compilation steps.
- **Unified Simulation Script (`run.sh`)**: All Makefile configurations have been replaced with a unified bash script `run.sh` located in the root of the project. It handles:
  1. Locating the RISC-V toolchain prefix (e.g. `riscv32-unknown-elf-`, `riscv64-unknown-elf-`).
  2. Compiling the assembly test code.
  3. Extracting the raw binary using `objcopy` (with automatic failover handling).
  4. Converting the binary to a little-endian Verilog HEX file using Python (detecting `python3` or `python`).
  5. Invoking Verilator with `--binary`, `--timing`, and `--trace` parameters.
  6. Executing the resulting simulation binary.

---

## 3. How to Run the Project

To run the simulation end-to-end on a Linux target with Verilator and a RISC-V cross-compiler installed:

1. Navigate to the `microriv-soc` root directory:
   ```bash
   cd microriv-soc
   ```
2. Set execute permissions for the runner script (if needed):
   ```bash
   chmod +x run.sh
   ```
3. Run the unified simulation script:
   ```bash
   ./run.sh
   ```

### Output and Verification
Upon running the script, you should see the compilation status followed by the testbench execution:
```text
==================================================================
 1. Compiling test firmware (start.S)
==================================================================
  Compiler: riscv32-unknown-elf-gcc
  Linker:   riscv32-unknown-elf-ld
  Objcopy:  riscv64-unknown-elf-objcopy
  Python:    python3
Firmware compilation complete. Hex output saved to: sim/firmware.hex

==================================================================
 2. Compiling RTL and Verilog Testbench with Verilator
==================================================================
Verilator compilation complete.

==================================================================
 3. Running Simulation
==================================================================
[TB] Starting simulation...
[TB] Reset released. Core executing...
PASS
[TB] Simulation exit requested by firmware.
[TB] Exit code:          1
[TB] SUCCESS: Test program completed successfully!
==================================================================
 Simulation Finished
==================================================================
```

### Visualizing Waveforms
The simulation generates a `waveform.vcd` trace inside the `sim/` folder. Load this file in GTKWave to view active execution, register state progressions, and SRAM bus reads/writes:
```bash
gtkwave sim/waveform.vcd
```
