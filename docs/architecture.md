# microriv-soc Architecture & Design Log

This document captures the architectural decisions and interface definitions for Phase 1 of the **microriv-soc** project. It serves as a guide for carrying the context forward to other development environments and subsequent phases.

---

## 1. Core Selection: PicoRV32 vs SERV

For Phase 1 standalone bring-up in Verilator, **PicoRV32** was chosen over SERV for several reasons:

1. **Memory Interface Simplicity**:
   - PicoRV32 uses a standard 32-bit parallel bus interface with simple request/acknowledge signals (`mem_valid`, `mem_ready`, `mem_addr`, `mem_wdata`, `mem_wstrb`, `mem_rdata`).
   - SERV is a bit-serial core. It operates on a bit-serial memory bus, which requires additional complex serial-parallel/parallel-serial transceivers to connect to standard parallel memory systems.
2. **Integration Complexity**:
   - PicoRV32 is distributed as a single Verilog file (`picorv32.v`) which simplifies the simulation compile process in Verilator.
   - SERV consists of multiple files and is more difficult to configure standalone.
3. **Execution Model**:
   - PicoRV32's native interface supports 0-wait-state and 1-wait-state standard RAM structures natively.

---

## 2. Memory Map & Address Decoding

To keep core integration clean and allow direct drops of APB bridges and peripheral IPs in Phase 2, the memory bus is decoded at the top-level SoC (`soc_top.v`):

| Address Range | Target Module | Access Type | Description |
| :--- | :--- | :---: | :--- |
| `0x0000_0000` - `0x0000_3FFF` | `soc_ram.v` (16KB) | R/W | Main internal SRAM (Code + Data + Stack) |
| `0x8000_0000` | Sim Console Out | Write Only | Prints low 8 bits of write data to stdout |
| `0x8000_0004` | Sim Exit Control | Write Only | Terminates simulation and passes exit code |

### Future-Proofing for Phase 2:
- The address mapping structure leaves the ranges `0x4000_0000` to `0x7FFF_FFFF` open for APB-based peripherals (e.g. UART, GPIO, Timer) via a custom APB bridge.
- The top-level `soc_top.v` separates the bus multiplexing logic, allowing easy integration of an APB bus bridge in place of direct mapping.

---

## 3. Simulator Integration Hooks

To allow automated simulation testing without complex C++ memory access code:
1. **Console Character Output (`0x8000_0000`)**:
   - Any write to `0x8000_0000` is decoded in Verilog. If a write strobe is active, the simulator uses standard Verilog `$write` to output the character directly to the console.
2. **Simulation Termination (`0x8000_0004`)**:
   - Any write to `0x8000_0004` triggers the `sim_exit_req` output to go high. The write data is latched into `sim_exit_code`.
   - The C++ testbench (`tb_soc.cpp`) monitors `sim_exit_req` at every clock cycle. When asserted, it terminates the C++ simulation loop, reporting the exit code (`1` for SUCCESS, others for FAILURE).

---

## 4. Clock and Reset Design

- **Clock (`clk`)**: Toggled by the C++ testbench in steps. Each clock cycle consists of a falling edge and a rising edge.
- **Reset (`resetn`)**: The CPU is active-low reset.
  - The C++ testbench holds `resetn` low for 10 full clock cycles (20 ticks) at the start of simulation to ensure all core registers and RAM structures clear cleanly.
  - After 10 cycles, `resetn` is asserted high to start code execution.

---

## 5. Waveform Dump & Tracing

- Waveform dumping is fully integrated via Verilator's VCD tracing capabilities.
- To prevent slowing down the simulation or filling up disk space when not needed, waveform generation is gated behind the compile-time flag `VM_TRACE` and the Makefile configuration `TRACE=1`.
- If enabled, a standard `waveform.vcd` file is generated in the simulation directory. It contains full internal traces of the CPU, memory, and top-level registers.
