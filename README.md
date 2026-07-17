# MicroRiv SoC (Phase 1: RISC-V Standalone Core Simulation)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes. 

This repository contains the deliverables for **Phase 1** of the multi-phase project. The objective of Phase 1 is to establish a robust simulation environment to compile a custom RISC-V software binary, execute it on an open-source RISC-V CPU core in a Verilator-based simulation, trace variables, print terminal strings, and handle simulation termination cleanly.

---

## 1. Project Directory Structure

The repository is organized to keep RTL, testbenches, simulation scripts, and firmware isolated, leaving dedicated locations for custom APB-based peripherals (UART, GPIO, Timer, APB Bridge, CDC FIFO) to be dropped in during Phase 2:

```
microriv-soc/
├── rtl/                   # System RTL source files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (1-wait-state)
│   └── soc_top.v          # Top-level SoC wrapper (address decoding, memory bus mux)
├── tb/                    # Testbench files
│   └── tb_soc.cpp         # Verilator C++ testbench (clock/reset, trap & exit monitors)
├── sim/                   # Simulation build and run workspace
│   └── Makefile           # Cross-platform simulation Makefile (Linux & Windows)
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (register computation loop & exit ports)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   ├── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
│   └── Makefile           # Firmware compilation Makefile
└── docs/                  # Architectural documentation
    └── architecture.md    # Summary of Phase 1 design decisions
```

---

## 2. Key Design Decisions

- **Core Selection**: We utilize **PicoRV32** rather than SERV. PicoRV32's native parallel memory interface is substantially simpler to interface with a standard byte-enabled SRAM block than SERV's bit-serial interface, which speeds up bring-up and simplifies custom APB bridge integration in Phase 2.
- **Top-Level Address Decoding**: The top-level wrapper (`rtl/soc_top.v`) implements address decoding for the bus:
  - `0x0000_0000` to `0x0000_3FFF` (16KB) maps to local SRAM.
  - `0x8000_0000` maps to the simulation console printer (writing a byte here prints it to the console).
  - `0x8000_0004` maps to simulation termination controls.
- **Verification Loop**: The test firmware runs a register-based computation loop (adding `5` in each iteration to register `x4` up to `10` times), outputs `"PASS\n"` characters sequentially to the console printer address `0x8000_0000`, and terminates the simulation successfully (returning status code `1`) by writing to address `0x8000_0004`.

---

## 3. How to Compile the Firmware

You need a RISC-V cross-compiler toolchain installed on your system (e.g. `riscv64-unknown-elf-gcc` or `riscv32-unknown-elf-gcc`).

1. Navigate to the `firmware/` directory:
   ```bash
   cd firmware
   ```
2. Compile the startup assembly and generate the memory initialization hex file:
   ```bash
   make
   ```
   *Note: The Makefile automatically detects which compiler toolchain prefix is installed on your system. If you want to force a specific toolchain, run:*
   ```bash
   make TOOLCHAIN_PREFIX=riscv64-unknown-elf-
   ```
3. This creates:
   - `firmware.elf`: Linker-mapped executable.
   - `firmware.bin`: Raw binary payload.
   - `firmware.hex`: Hexadecimal format parsed by `$readmemh` (padded to 16KB).
   - `firmware.dump`: Assembly disassembly for instruction debugging.

---

## 4. How to Run the Simulation

You need **Verilator** and **make** installed on your system.

1. Navigate to the `sim/` directory:
   ```bash
   cd sim
   ```
2. Build the simulation binary:
   ```bash
   make sim
   ```
3. Run the compiled SoC simulator:
   ```bash
   make run
   ```
4. To clean previous compilation artifacts:
   ```bash
   make clean
   ```

### Enabling Waveform Generation (VCD)
To dump internal CPU execution waveforms to `waveform.vcd` for hardware verification, compile and run with `TRACE=1`:
```bash
make run TRACE=1
```
This produces `waveform.vcd` in the `sim/` folder. You can load this file into **GTKWave** or any VCD viewer to verify signals such as memory accesses, register states, and instruction fetches.

---

## 5. Verification of Correct Execution

Upon executing `make run`, you should see the following output in your terminal:
```text
[TB] Starting reset sequence...
[TB] Reset released. Simulation running...
PASS
[TB] Simulation exit requested by firmware at cycle 176.
[TB] Exit code returned: 1
[TB] SUCCESS: Test firmware executed correctly!
[TB] Simulation finished at cycle 176.
```

If the console outputs `PASS` and finishes with `SUCCESS`, the PicoRV32 core successfully fetched, decoded, and executed instructions, managed loop branching, printed strings, and exited cleanly.
