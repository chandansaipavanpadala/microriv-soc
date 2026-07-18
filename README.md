# MicroRiv SoC (Phase 3: Clock Domain Crossing Integration)

**MicroRiv SoC** is a simulation-first RISC-V mini System-on-Chip (SoC) designed for educational and prototyping purposes.

This repository contains the deliverables for **Phase 3** of the multi-phase project.

The objective of Phase 3 is to split the system into two distinct clock domains running at different frequencies:
* **CPU Clock Domain (`clk_cpu`)**: Runs at 50 MHz, clocking the PicoRV32 RISC-V core and the main system SRAM.
* **Peripheral Clock Domain (`clk_periph`)**: Runs at 12.5 MHz (divided-by-4), clocking the UART, GPIO, and Timer peripherals.

The boundary crossing is synchronized via a Level-Handshake Clock Domain Crossing (CDC) Bridge (`apb_cdc_bridge.v`).

---

## 1. Project Directory Structure

```
microriv-soc/
├── rtl/                   # System RTL Verilog files
│   ├── picorv32.v         # Open-source PicoRV32 RISC-V core (CPU Domain)
│   ├── picorv32_apb_bridge.v # APB3 Master Bridge (CPU Domain)
│   ├── sync2_stage.v      # [NEW] 2-stage D-FF synchronizer to resolve metastability
│   ├── clk_divider.v      # [NEW] Clock divider dividing clk_cpu by 4 to generate clk_periph
│   ├── apb_cdc_bridge.v   # [NEW] Level-Handshake APB3 CDC Bridge crossing domains
│   ├── apb_uart_bridge.v  # APB UART register decoder (Peripheral Domain)
│   ├── uart.v             # UART transceiver stub (Peripheral Domain)
│   ├── apb_gpio.v         # 32-bit APB GPIO controller (Peripheral Domain)
│   ├── apb_timer.v        # 32-bit APB countdown Timer (Peripheral Domain)
│   ├── soc_ram.v          # 16KB Byte-enabled SRAM block (CPU Domain)
│   └── soc_top.v          # [UPDATED] Top-level SoC wrapper instantiating clock divider & CDC bridge
├── tb/                    # Testbench files
│   └── tb_soc.v           # [UPDATED] Verilog-only testbench generating CPU clock
├── firmware/              # Bare-metal test firmware source
│   ├── start.S            # Startup assembly (UART, GPIO, and Timer tests)
│   ├── sections.lds       # Linker script mapping code to memory start (0x0000_0000)
│   └── makehex.py         # Python utility to convert binary ELF to $readmemh hex format
├── docs/                  # Architectural documentation
│   └── architecture.md    # [UPDATED] Detail clock topologies, CDC bridge tradeoffs, and latency
└── run.sh                 # Unified bash script compiling firmware, Verilator, and running simulation
```

---

## 2. APB Memory Map

| Device / Slave | Base Address | Size | Clock Domain | Description / Registers |
| :--- | :---: | :---: | :---: | :--- |
| **System SRAM** | `0x0000_0000` | 16KB | `clk_cpu` | Main internal RAM for code and data |
| **APB UART** | `0x1000_0000` | 16B | `clk_periph` | Register stub: `tx_data` (0x00), `rx_data` (0x04), `status` (0x08) |
| **APB GPIO** | `0x1001_0000` | 16B | `clk_periph` | `gpio_out` (0x00) and `gpio_in` (0x04) |
| **APB Timer** | `0x1002_0000` | 16B | `clk_periph` | `load_val` (0x00), `running` (0x04), `timer_done` (0x08), `count` (0x0c) |
| **Sim Exit Register**| `0x8000_0004` | 4B | `clk_cpu` | Write `1` for SUCCESS, other values for FAILURE |

---

## 3. How to Run the Project

1. Navigate to the `microriv-soc` root directory:
   ```bash
   cd microriv-soc
   ```
2. Execute the unified simulation script:
   ```bash
   ./run.sh
   ```

### Expected Output
The script compiles the assembly, linkers, generates `firmware.hex`, compiles with Verilator, and executes the simulation:
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

---

## 4. GTKWave Verification of CDC Crossings

To verify the Level-Handshake Clock Domain Crossing in GTKWave:
1. Open the generated VCD file in GTKWave:
   ```bash
   gtkwave sim/waveform.vcd
   ```
2. In the signal tree, navigate to: `tb_soc` -> `dut` -> `apb_cdc`.
3. Add the following signals to your viewer:
   * **`clk_cpu`**: The high-speed CPU clock (50 MHz).
   * **`clk_periph`**: The divided-by-4 peripheral clock (12.5 MHz).
   * **`req_cpu`**: Request signal initiated in the CPU domain.
   * **`req_periph_sync`**: Synchronized request signal in the peripheral domain (should transition high 2 `clk_periph` cycles after `req_cpu`).
   * **`PSEL_periph`** and **`PENABLE_periph`**: APB peripheral control bus toggling.
   * **`ack_periph`**: Acknowledge signal raised in the peripheral domain upon transaction completion.
   * **`ack_cpu_sync`**: Synchronized acknowledge signal in the CPU domain (should transition high 2 `clk_cpu` cycles after `ack_periph`).
4. Trace the request-acknowledge handshake cycle and verify that data buses are static and stable during the active handshake window.
