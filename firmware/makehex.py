#!/usr/bin/env python3
#
#  microriv-soc -- A simulation-first RISC-V mini SoC
#
#  Copyright (C) 2026
#
#  Description: Helper script to convert firmware binary into a 32-bit
#               hexadecimal memory file format used by Verilog $readmemh.
#               Pads the remaining memory space with zeros to ensure
#               no uninitialized read warnings in simulation.
#

import sys

def main():
    if len(sys.argv) < 3:
        print("Usage: makehex.py <input.bin> <output.hex> [mem_size_bytes]")
        sys.exit(1)
        
    bin_file = sys.argv[1]
    out_hex = sys.argv[2]
    mem_size = int(sys.argv[3]) if len(sys.argv) > 3 else 16384
    
    with open(bin_file, "rb") as f:
        bindata = f.read()
        
    if len(bindata) > mem_size:
        print(f"Error: Binary size ({len(bindata)} B) exceeds memory limit ({mem_size} B)")
        sys.exit(1)
        
    # Standard $readmemh reads 32-bit words line-by-line.
    # On little-endian architectures like RISC-V, bytes are packed as:
    # word = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | byte0
    with open(out_hex, "w") as f:
        for i in range(0, mem_size, 4):
            if i < len(bindata):
                word = 0
                for j in range(4):
                    if i + j < len(bindata):
                        word |= bindata[i+j] << (8 * j)
                f.write(f"{word:08x}\n")
            else:
                # Pad remaining RAM space with zeroes
                f.write("00000000\n")
                
    print(f"Successfully converted {bin_file} to {out_hex} (padded to {mem_size} B / {mem_size//4} words)")

if __name__ == "__main__":
    main()
