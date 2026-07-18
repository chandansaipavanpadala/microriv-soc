#!/bin/bash
#
#  microriv-soc -- A simulation-first RISC-V mini SoC
#
#  Copyright (C) 2026
#
#  Description: Compile script for Yosys RTL Synthesis.
#               Generates gate-level netlist, Liberty cell mapping reports,
#               and renders structural design schematics.
#

# Exit immediately on error
set -e

# Resolve directory structure relative to the script's directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "=================================================================="
2. echo " 1. Initializing Synthesis Directory"
==================================================================
cd "$SCRIPT_DIR"
mkdir -p reports

# Clean old outputs
rm -f netlist.v reports/stats.txt reports/*.svg reports/*.json reports/*.dot

echo "=================================================================="
echo " 2. Running Yosys RTL Synthesis"
echo "=================================================================="

# Invoke Yosys with the synthesis script
# -s synth.ys runs Yosys script in silent/command mode
if command -v yosys &> /dev/null; then
    yosys -s synth.ys
else
    echo "ERROR: Yosys synthesis suite is not installed on this system!"
    exit 1
fi

echo "=================================================================="
echo " 3. Synthesis Complete!"
echo "=================================================================="
echo " Netlist written to:     synth/netlist.v"
echo " Reports written to:     synth/reports/stats.txt"
echo " Schematics written to:  synth/reports/schematic_soc_top.svg"
echo "                         synth/reports/schematic_cdc_bridge.svg"
echo "=================================================================="
