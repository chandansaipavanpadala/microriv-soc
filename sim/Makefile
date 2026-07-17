#
#  microriv-soc -- A simulation-first RISC-V mini SoC
#
#  Copyright (C) 2026
#
#  Description: Makefile to compile and run the Verilator simulation.
#               Supports both Windows and Linux environments.
#

VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-fatal --cc --exe --top-module soc_top -I../rtl

# Enable waveform tracing if TRACE=1 is specified (e.g., make run TRACE=1)
ifeq ($(TRACE),1)
    VERILATOR_FLAGS += --trace -CFLAGS "-DVM_TRACE=1"
endif

# Platform-specific command abstractions
ifeq ($(OS),Windows_NT)
    RM = rmdir /S /Q
    DEL = del /Q
    EXE = obj_dir\Vsoc_top.exe
    COPY_HEX = copy /Y ..\firmware\firmware.hex .\firmware.hex > nul
else
    RM = rm -rf
    DEL = rm -f
    EXE = ./obj_dir/Vsoc_top
    COPY_HEX = cp -f ../firmware/firmware.hex ./firmware.hex
endif

# Source paths
RTL_SRCS = ../rtl/soc_top.v ../rtl/picorv32.v ../rtl/soc_ram.v
TB_SRC = ../tb/tb_soc.cpp

all: sim

# Copy the compiled firmware hex file into the simulation execution folder
firmware.hex: ../firmware/firmware.hex
	$(COPY_HEX)

../firmware/firmware.hex:
	$(MAKE) -C ../firmware

sim: $(RTL_SRCS) $(TB_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) $(RTL_SRCS) $(TB_SRC) --prefix Vsoc_top -Mdir obj_dir
	$(MAKE) -C obj_dir -f Vsoc_top.mk

run: sim firmware.hex
	$(EXE)

clean:
ifeq ($(OS),Windows_NT)
	if exist obj_dir $(RM) obj_dir
	if exist firmware.hex $(DEL) firmware.hex
	if exist waveform.vcd $(DEL) waveform.vcd
else
	$(RM) obj_dir
	$(DEL) firmware.hex waveform.vcd
endif

.PHONY: all sim run clean
