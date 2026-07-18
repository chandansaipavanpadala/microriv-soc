# MicroRiv SoC - RTL Synthesis Report

This document details the RTL synthesis flow, standard cell library mapping, and schematic generation for the **MicroRiv SoC** project.

---

## 1. Synthesis Flow Overview

The synthesis flow targets standard cell mapping using the open-source **Yosys RTL Synthesis Suite** paired with the **ABC logic optimization tool**.

```
    RTL Sources (*.v)  ------->  [ Yosys Parser ]
                                        |
    OSU gscl45nm.lib   ------->  [ FF/Gate Mapper ]
                                        |
    netlist.v & stats  <-------  [ Optimization ]
```

### Flow Execution:
1. **RTL Compilation**: Imports core hardware modules as SystemVerilog (excluding testbench wrappers, SVA assertions, and initialization files).
2. **Generic Pass (`synth -top soc_top`)**: Elaborates the hierarchy, performs FSM extraction, optimization, and constant folding.
3. **FF Mapping (`dfflibmap`)**: Maps flip-flops in the design to D-type flip-flop cells defined in the liberty file.
4. **Logic Mapping (`abc`)**: Maps combinational logic expressions to logical standard gates (AND, OR, NOT, multiplexers, etc.).
5. **Report Generation (`stat`)**: Analyzes cell usage metrics and computes generic transistor count and gate statistics.

---

## 2. Synthesis Target Library

* **Standard Cell Library**: **OSU gscl45nm** (Oklahoma State University 45nm Standard Cell Library).
* **Liberty File**: [synth/gscl45nm.lib](file:///p:/OneDrive%20-%20Amrita%20vishwa%20vidyapeetham/ASEB/NIELET%20Bootcamp/microriv-soc/synth/gscl45nm.lib).
* **Technology Nodes**: 45nm CMOS process modeling basic standard gates, multiplexers, D flip-flops, and level-sensitive latches.

---

## 3. Latch and Memory Mapping Analysis

During synthesis, two critical hardware blocks require careful review:

### A. Intentional Latch in Clock Gating (`icg.v`)
* **Construct**:
  ```verilog
  always_latch begin
      if (!clk_in) begin
          en_latch = en;
      end
  end
  ```
* **Yosys Synthesis Behavior**: Yosys correctly parses the `always_latch` block and infers an active-low level-sensitive transparent latch (`DLATCH` cell).
* **Safety Verification**: This is **intentional hardware design** to enable glitch-free clock gating. It is not an accidental logic loop (which would be flagged as a design error).

### B. Generic SRAM Block (`soc_ram.v`)
* **Simulation Exclusions**: The `$readmemh("firmware.hex", mem)` startup file load is simulation-only. It is bypassed in synthesis using a preprocessor guard:
  ```verilog
  `ifndef SYNTHESIS
      initial begin
          $readmemh("firmware.hex", mem);
      end
  `endif
  ```
* **Memory Inference**: Yosys treats the `mem` array as an abstract inferred memory block. In a production ASIC flow, this is replaced by SRAM macros compiled with memory compilers. In an FPGA flow, it maps to block RAM resources.

---

## 4. Excluded Elements

To ensure synthesis targets only physical hardware gates, the following files and code blocks are bypassed:
1. **Verification Code (SVA)**: SystemVerilog Assertions (`assert property`) are ignored by compiling without the `ASSERTIONS_ON` macro.
2. **Simulation Testbench (`tb_soc.v`)**: Testbench constructs, clocks, wait states, and exit trackers are simulation wrappers and excluded from the Yosys file lists.

---

## 5. Physical Flow Next Steps (ASIC vs FPGA)

This synthesis pass compiles code to generic logic gates. To prepare this SoC for actual silicon or FPGA tape-out:

1. **ASIC Backend Physical Design**:
   * **PDK Selection**: Select a physical foundry PDK (e.g. SkyWater 130nm, TSMC 65nm).
   * **Technology Mapping**: Swap the generic `gscl45nm.lib` with foundry standard cell library liberty formats.
   * **Timing Constraints (SDC)**: Define a Synopsys Design Constraints (SDC) file defining clock periods, domain clock skew, CDC boundaries, and false paths.
   * **Place and Route (P&R)**: Import the synthesized netlist into a layout compiler (e.g. Cadence Innovus, OpenLane) to generate floorplanning, power grids, clock tree synthesis (CTS), routing, and clean GDSII layouts.
2. **FPGA Synthesis**:
   * **Tooling**: Compile the design in AMD Vivado, Intel Quartus, or Yosys-NextPNR.
   * **Mapping**: Let the compiler map flip-flops to FPGA register slices and logic gates to Look-Up Tables (LUTs) and block memory slices.
