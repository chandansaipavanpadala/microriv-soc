/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Trivial startup firmware written in RISC-V assembly.
 *               Performs a simple computation in a loop, prints "PASS"
 *               to the console output port, and requests simulation exit.
 */

.section .text.init
.global _start

_start:
    # 1. Initialize Stack Pointer (sp) to the top of the 16KB RAM (0x0000_4000)
    li sp, 0x00004000

    # 2. Initialize test registers
    li x1, 0
    li x2, 10      # loop limit
    li x3, 0       # loop counter (i)
    li x4, 0       # accumulator (accum)

loop:
    # 3. Accumulate: accum = accum + 5
    addi x4, x4, 5
    
    # 4. Increment loop counter: i = i + 1
    addi x3, x3, 1
    
    # 5. Check if i != loop limit, branch back if true
    bne x3, x2, loop

    # =========================================================================
    // Write characters to simulation console port (0x8000_0000)
    // =========================================================================
    li x5, 0x80000000
    
    li x6, 0x50     # 'P'
    sw x6, 0(x5)
    li x6, 0x41     # 'A'
    sw x6, 0(x5)
    li x6, 0x53     # 'S'
    sw x6, 0(x5)    # 'S'
    sw x6, 0(x5)    # 'S'
    li x6, 0x0a     # '\n'
    sw x6, 0(x5)

    # =========================================================================
    // Write success status (1) to simulation exit port (0x8000_0004)
    // =========================================================================
    li x5, 0x80000004
    li x6, 1
    sw x6, 0(x5)

    # Infinite loop just in case simulation doesn't terminate immediately
hang:
    j hang
