/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Bare-metal test firmware written in RISC-V assembly.
 *               1. Writes "Hello APB UART!\n" to the UART transmitter.
 *               2. Tests GPIO outputs by writing and reading back looped values.
 *               3. Tests Timer countdown logic by reading active count register.
 *               4. Signals success/failure code to simulation exit register.
 */

.section .text.init
.global _start

_start:
    # 1. Initialize Stack Pointer (sp) to top of 16KB RAM
    li sp, 0x00004000

    # 2. UART test: Print "Hello APB UART!\n"
    la a0, hello_msg
    jal ra, print_str

    # 3. GPIO Loopback test
    # Write a test pattern to GPIO out (0x1001_0000)
    li t0, 0x1001_0000
    li t1, 0x5555AAAA
    sw t1, 0(t0)

    # Read back from GPIO in (0x1001_0004)
    li t2, 0x1001_0004
    lw t3, 0(t2)

    # Check if loops back correctly
    bne t3, t1, fail_gpio

    # 4. Timer decrement test
    # Load count down value of 100 to Timer (0x1002_0000)
    li t0, 0x1002_0000
    li t1, 100
    sw t1, 0(t0)

    # Start the Timer (0x1002_0004)
    li t2, 0x1002_0004
    li t3, 1
    sw t3, 0(t2)

    # Read active counter (0x1002_000c) twice
    li t4, 0x1002_000c
    lw t5, 0(t4)       # Read 1
    lw t6, 0(t4)       # Read 2

    # Check if active counter has decremented (Read 2 < Read 1)
    # If Read 2 >= Read 1 (t6 >= t5), timer countdown is broken!
    bge t6, t5, fail_timer

    # 5. Success exit (write 1 to 0x8000_0004)
    li t0, 0x8000_0004
    li t1, 1
    sw t1, 0(t0)
    j hang

fail_gpio:
    # GPIO Failure exit (write 2 to 0x8000_0004)
    li t0, 0x8000_0004
    li t1, 2
    sw t1, 0(t0)
    j hang

fail_timer:
    # Timer Failure exit (write 3 to 0x8000_0004)
    li t0, 0x8000_0004
    li t1, 3
    sw t1, 0(t0)
    j hang

hang:
    j hang

# =========================================================================
# Subroutines
# =========================================================================
# print_str: Prints a null-terminated string to UART TX
# Inputs: a0 - Address of the string
# Modifies: t0, t1, t2, t3
print_str:
    li t0, 0x1000_0008  # Status register address
    li t1, 0x1000_0000  # TX register address
print_loop:
    lb t2, 0(a0)        # Load next character byte
    beqz t2, print_done # Exit loop if null-terminator
wait_tx_ready:
    lw t3, 0(t0)        # Read status
    andi t3, t3, 2      # Mask bit[1] (tx_busy)
    bnez t3, wait_tx_ready # Loop if transmitter is busy
    sw t2, 0(t1)        # Write byte to TX data register
    addi a0, a0, 1      # Increment pointer address
    j print_loop
print_done:
    ret

# =========================================================================
# Read-only Data Section
# =========================================================================
.section .rodata
hello_msg:
    .asciz "Hello APB UART!\n"
