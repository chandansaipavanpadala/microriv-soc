#
#  microriv-soc -- A simulation-first RISC-V mini SoC
#
#  Copyright (C) 2026
#
#  Description: Makefile to compile firmware using a RISC-V GCC cross-toolchain
#               and convert it to a 32-bit hex file.
#

# Automatic toolchain detection
ifneq ($(shell which riscv32-unknown-elf-gcc 2>/dev/null),)
    TOOLCHAIN_PREFIX ?= riscv32-unknown-elf-
else ifneq ($(shell which riscv64-unknown-elf-gcc 2>/dev/null),)
    TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-
else ifneq ($(shell which riscv-none-elf-gcc 2>/dev/null),)
    TOOLCHAIN_PREFIX ?= riscv-none-elf-
else ifneq ($(shell which riscv-none-embed-gcc 2>/dev/null),)
    TOOLCHAIN_PREFIX ?= riscv-none-embed-
else
    TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-
endif

CC      = $(TOOLCHAIN_PREFIX)gcc
LD      = $(TOOLCHAIN_PREFIX)ld
OBJCOPY = $(TOOLCHAIN_PREFIX)objcopy
OBJDUMP = $(TOOLCHAIN_PREFIX)objdump

# RV32I architecture flags (ensure no compressed instructions or multiplication/division)
ASFLAGS = -march=rv32i -mabi=ilp32
LDFLAGS = -T sections.lds -m elf32lriscv

# Memory size parameter in bytes (must match RAM size in soc_top.v)
MEM_SIZE = 16384

all: firmware.hex firmware.dump

firmware.elf: start.S sections.lds
	$(CC) $(ASFLAGS) -c start.S -o start.o
	$(LD) $(LDFLAGS) start.o -o firmware.elf

firmware.bin: firmware.elf
	$(OBJCOPY) -O binary firmware.elf firmware.bin

firmware.hex: firmware.bin makehex.py
	python makehex.py firmware.bin firmware.hex $(MEM_SIZE)

firmware.dump: firmware.elf
	$(OBJDUMP) -d firmware.elf > firmware.dump

clean:
	rm -f *.o *.elf *.bin *.hex *.dump

.PHONY: all clean
