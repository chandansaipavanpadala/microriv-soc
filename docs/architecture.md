# microriv-soc Architecture & Design Log (Phase 2)

This document captures the architectural decisions, memory mappings, and interface definitions for Phase 2 of the **microriv-soc** project.

---

## 1. System Block Diagram & Bus Topology

Phase 2 replaces the direct-memory-mapped simulation console hack with a standard **AMBA APB3** peripheral bus hierarchy. All modules run on the same clock and reset domain (`clk` and `resetn`).

```
                +----------------------------+
                |         PicoRV32           |
                |        (RV32I Core)        |
                +-------------+--------------+
                              | CPU Native Memory Bus
                              v
                +----------------------------+
                |    picorv32_apb_bridge     |
                |        (APB3 Master)       |
                +-------------+--------------+
                              | APB Master Bus
                              | (PADDR, PWDATA, PWRITE, PSEL, PENABLE)
                              v
             +----------------+----------------+
             | Decode & Multiplexer            |
             +-------+--------+--------+-------+
                     |        |        |
            UART PSEL|    GPIO|    Timer
                     |    PSEL|    PSEL
                     v        v        v
                 +-------+ +-------+ +-------+
                 |  APB  | |  APB  | |  APB  |
                 | UART  | | GPIO  | | Timer |
                 +-------+ +-------+ +-------+
```

---

## 2. Memory Map & Address Decoding

The address space of the SoC is divided as follows:

| Address Range | Target Module | Access Type | Description |
| :--- | :--- | :---: | :--- |
| `0x0000_0000` - `0x0000_3FFF` | `soc_ram.v` (16KB) | R/W | Main internal SRAM (Code + Data + Stack) |
| `0x1000_0000` - `0x1000_000F` | `apb_uart_bridge.v` | R/W | APB UART peripheral (loopback stub) |
| `0x1001_0000` - `0x1001_000F` | `apb_gpio.v` | R/W | APB GPIO register interface |
| `0x1002_0000` - `0x1002_000F` | `apb_timer.v` | R/W | APB countdown Timer register interface |
| `0x8000_0004` | Sim Exit Control | Write Only | Writes `1` for SUCCESS, other values for FAILURE |

### Peripheral Registers & Offsets

#### 1. APB UART (`0x1000_0000`)
- **`0x00`** (Write-only): `tx_data` - Write byte to transmit.
- **`0x04`** (Read-only): `rx_data` - Read received loopback byte.
- **`0x08`** (Read-only): `status` - Status flags:
  - Bit 0: `rx_ready` (high if data is available to read)
  - Bit 1: `tx_busy` (high if transmitter is busy)

#### 2. APB GPIO (`0x1001_0000`)
- **`0x00`** (R/W): `gpio_out` - 32-bit output pins register.
- **`0x04`** (Read-only): `gpio_in` - 32-bit input pins monitor.

#### 3. APB Timer (`0x1002_0000`)
- **`0x00`** (R/W): `load_val` - 32-bit initial countdown reload value.
- **`0x04`** (R/W): `running` - Bit 0 starts (`1`) or stops (`0`) the countdown.
- **`0x08`** (Read-only): `timer_done` - Bit 0 goes high when count reaches `0`.
- **`0x0C`** (Read-only): `count` - Exposes the current active countdown value for firmware inspection.

---

## 3. Peripheral IP Modifications & Integration Notes

To integrate your reference IPs from the bootcamp, the following modifications and custom logic were added:

1. **Timer IP (`apb_timer.v`)**:
   - **`PREADY` Addition**: Added `output wire PREADY = 1'b1;` so it interfaces cleanly with the APB3 Master Bridge (which supports slave handshaking).
   - **Counter Read-back**: Added a register read path at offset `0x0c` to expose the internal active decrementing `count` register, satisfying the verification requirement to monitor the counter loop.
2. **UART IP (`uart.v`)**:
   - **Terminal Printing Redirect**: Removed the direct memory hack at `0x8000_0000`. Instead, a standard `$write("%c", tx_data); $fflush();` is placed inside `uart.v` triggered whenever `tx_write` goes high. This means writing characters to the standard UART registers naturally echoes text to the simulation stdout.
3. **GPIO IP (`apb_gpio.v`)**:
   - Implemented from scratch as a generic 0-wait-state APB slave register to bridge physical pin inputs/outputs.
4. **Verilog Testbench Loopback (`tb_soc.v`)**:
   - Simulates external board wiring by looping output pins back to inputs (`assign gpio_in = gpio_out;`). This lets the CPU write a test pattern to `gpio_out` and immediately read it back on `gpio_in` to verify correct register operation.
