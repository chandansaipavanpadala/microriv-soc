/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Linker script mapping text, data, and bss segments 
 *               to the SoC's internal 16KB RAM starting at 0x0000_0000.
 */

OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
    ram (rwx) : ORIGIN = 0x00000000, LENGTH = 0x00004000 /* 16KB RAM space */
}

SECTIONS
{
    /* Code segment */
    .text :
    {
        _text = .;
        *(.text.init)    /* Ensure _start runs first */
        *(.text)
        *(.text*)
        _etext = .;
    } > ram

    /* Read-only and read-write data segment */
    .data :
    {
        _data = .;
        *(.rodata)
        *(.rodata*)
        *(.data)
        *(.data*)
        _edata = .;
    } > ram

    /* Uninitialized data segment */
    .bss :
    {
        _bss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > ram

    /* End of memory definitions */
    _end = .;
}
