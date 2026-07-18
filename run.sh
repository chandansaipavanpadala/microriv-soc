#!/bin/bash
#
#  microriv-soc -- A simulation-first RISC-V mini SoC
#
#  Copyright (C) 2026
#
#  Description: Unified compile-and-run bash script for MicroRiv SoC.
#               Compiles the test assembly firmware, runs Verilator
#               to build the simulation executable from Verilog-only
#               sources, and executes the simulation.
#

# Exit immediately on error
set -e

# Resolve directory structure relative to the script's directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
RTL_DIR="$SCRIPT_DIR/rtl"
TB_DIR="$SCRIPT_DIR/tb"
FIRMWARE_DIR="$SCRIPT_DIR/firmware"
SIM_DIR="$SCRIPT_DIR/sim"

# Create the simulation workspace directory
mkdir -p "$SIM_DIR"

echo "=================================================================="
echo " 1. Compiling test firmware (start.S)"
echo "=================================================================="

# Detect RISC-V compiler prefix
if command -v riscv32-unknown-elf-gcc &> /dev/null; then
    PREFIX="riscv32-unknown-elf-"
elif command -v riscv64-unknown-elf-gcc &> /dev/null; then
    PREFIX="riscv64-unknown-elf-"
elif command -v riscv-none-elf-gcc &> /dev/null; then
    PREFIX="riscv-none-elf-"
elif command -v riscv-none-embed-gcc &> /dev/null; then
    PREFIX="riscv-none-embed-"
else
    echo "ERROR: No RISC-V GCC cross-compiler found (e.g. riscv32-unknown-elf-gcc)!"
    exit 1
fi

CC="${PREFIX}gcc"
LD="${PREFIX}ld"

# Detect Objcopy (with fallbacks if prefix version is missing)
if command -v ${PREFIX}objcopy &> /dev/null; then
    OBJCOPY="${PREFIX}objcopy"
elif command -v riscv64-unknown-elf-objcopy &> /dev/null; then
    OBJCOPY="riscv64-unknown-elf-objcopy"
elif command -v riscv32-unknown-elf-objcopy &> /dev/null; then
    OBJCOPY="riscv32-unknown-elf-objcopy"
elif command -v riscv-none-elf-objcopy &> /dev/null; then
    OBJCOPY="riscv-none-elf-objcopy"
else
    OBJCOPY="objcopy"
fi

# Detect Python interpreter (prefer python3)
if command -v python3 &> /dev/null; then
    PYTHON="python3"
elif command -v python &> /dev/null; then
    PYTHON="python"
else
    echo "ERROR: Python is required to run makehex.py!"
    exit 1
fi

echo "  Compiler: $CC"
echo "  Linker:   $LD"
echo "  Objcopy:  $OBJCOPY"
echo "  Python:   $PYTHON"

# Run toolchain compilation steps
$CC -march=rv32i -mabi=ilp32 -c "$FIRMWARE_DIR/start.S" -o "$FIRMWARE_DIR/start.o"
$LD -T "$FIRMWARE_DIR/sections.lds" -m elf32lriscv "$FIRMWARE_DIR/start.o" -o "$FIRMWARE_DIR/firmware.elf"
$OBJCOPY -O binary "$FIRMWARE_DIR/firmware.elf" "$FIRMWARE_DIR/firmware.bin"

# Generate hex configuration file for SRAM initialization
$PYTHON "$FIRMWARE_DIR/makehex.py" "$FIRMWARE_DIR/firmware.bin" "$SIM_DIR/firmware.hex" 16384

echo "Firmware compilation complete. Hex output saved to: sim/firmware.hex"
echo ""

echo "=================================================================="
echo " 2. Compiling RTL and Verilog Testbench with Verilator"
echo "=================================================================="

# Clean old simulation files to ensure a fresh compile
rm -rf "$SIM_DIR/obj_dir"

# Invoke Verilator
# --binary: creates the simulation executable directly
# -j 0: runs multi-threaded host compilation
# --timing: enables delay models (# delay) inside the testbench
# --trace: enables waveform VCD dumping
verilator --binary -j 0 -Wall \
    "$RTL_DIR/picorv32.v" \
    "$RTL_DIR/soc_ram.v" \
    "$RTL_DIR/soc_top.v" \
    "$TB_DIR/tb_soc.v" \
    --top-module tb_soc \
    --timing \
    --trace \
    -Mdir "$SIM_DIR/obj_dir" \
    -o "sim_soc"

echo "Verilator compilation complete."
echo ""

echo "=================================================================="
echo " 3. Running Simulation"
echo "=================================================================="

# Execute simulation binary from within the sim directory (so firmware.hex is loaded correctly)
cd "$SIM_DIR"
./sim_soc

echo "=================================================================="
echo " Simulation Finished"
echo "=================================================================="
