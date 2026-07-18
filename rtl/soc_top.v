/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Top-level SoC wrapper. Clock domains are split:
 *               1. clk_cpu (CPU domain) runs PicoRV32, SRAM, and APB Master Bridge.
 *               2. clk_periph (Peripheral domain, divided-by-4) runs UART, GPIO,
 *                  and countdown Timer.
 *               Boundary crossing is synchronized via apb_cdc_bridge.
 */

`timescale 1 ns / 1 ps

module soc_top (
    input             clk,
    input             resetn,
    output            trap,

    // Simulation exit ports
    output reg        sim_exit_req,
    output reg [31:0] sim_exit_code,

    // External peripheral connections
    output     [31:0] gpio_out,
    input      [31:0] gpio_in,
    output            timer_done
);

    // =========================================================================
    // Clock Domain Generation
    // =========================================================================
    wire clk_periph;

    // Instantiate clock divider to divide clk by 4 to generate clk_periph
    clk_divider periph_clk_div (
        .clk_in  (clk),
        .rst     (!resetn),
        .clk_out (clk_periph)
    );

    // =========================================================================
    // Internal Wires
    // =========================================================================
    wire        cpu_mem_valid;
    wire        cpu_mem_ready;
    wire [31:0] cpu_mem_addr;
    wire [31:0] cpu_mem_wdata;
    wire [ 3:0] cpu_mem_wstrb;
    wire [31:0] cpu_mem_rdata;

    // =========================================================================
    // Address Decoding (Main Bus)
    // =========================================================================
    // SRAM:     0x0000_0000 -> 0x0000_3FFF (16KB)
    // APB Base: 0x1000_0000 -> 0x1002_FFFF (UART, GPIO, Timer ranges)
    // SIM_EXIT: 0x8000_0004
    // =========================================================================
    wire is_ram      = (cpu_mem_addr < 32'h0000_4000);
    wire is_apb      = (cpu_mem_addr >= 32'h1000_0000) && (cpu_mem_addr < 32'h1003_0000);
    wire is_sim_exit = (cpu_mem_addr == 32'h8000_0004);

    // RAM signals
    wire        ram_valid = cpu_mem_valid && is_ram;
    wire [31:0] ram_rdata;
    wire        ram_ready;

    // APB master bridge enable
    wire        apb_bridge_valid = cpu_mem_valid && is_apb;
    wire [31:0] apb_bridge_rdata;
    wire        apb_bridge_ready;

    // Simulation exit control logic
    reg sim_exit_ready;
    always @(posedge clk) begin
        if (!resetn) begin
            sim_exit_ready <= 1'b0;
            sim_exit_req   <= 1'b0;
            sim_exit_code  <= 32'h0;
        end else begin
            if (cpu_mem_valid && is_sim_exit && !sim_exit_ready) begin
                sim_exit_ready <= 1'b1;
                if (|cpu_mem_wstrb) begin
                    sim_exit_req  <= 1'b1;
                    sim_exit_code <= cpu_mem_wdata;
                end
            end else begin
                sim_exit_ready <= 1'b0;
            end
        end
    end

    // Core Memory Bus Multiplexing
    assign cpu_mem_ready = ram_ready | apb_bridge_ready | sim_exit_ready;
    assign cpu_mem_rdata = ram_ready         ? ram_rdata         :
                           apb_bridge_ready  ? apb_bridge_rdata  :
                           32'h0000_0000;

    // =========================================================================
    // PicoRV32 Core Instantiation (CPU Domain - clk)
    // =========================================================================
    /* verilator lint_off PINCONNECTEMPTY */
    /* verilator lint_off PINMISSING */
    picorv32 #(
        .ENABLE_COUNTERS     (1'b0),
        .ENABLE_COUNTERS64   (1'b0),
        .TWO_STAGE_SHIFT     (1'b1),
        .BARREL_SHIFTER      (1'b1),
        .COMPRESSED_ISA      (1'b0),
        .ENABLE_MUL          (1'b0),
        .ENABLE_DIV          (1'b0),
        .ENABLE_IRQ          (1'b0),
        .PROGADDR_RESET      (32'h0000_0000)
    ) cpu (
        .clk        (clk),
        .resetn     (resetn),
        .trap       (trap),
        .mem_valid  (cpu_mem_valid),
        .mem_instr  (),
        .mem_ready  (cpu_mem_ready),
        .mem_addr   (cpu_mem_addr),
        .mem_wdata  (cpu_mem_wdata),
        .mem_wstrb  (cpu_mem_wstrb),
        .mem_rdata  (cpu_mem_rdata)
    );
    /* verilator lint_on PINCONNECTEMPTY */
    /* verilator lint_on PINMISSING */

    // =========================================================================
    // System SRAM Instantiation (16KB) (CPU Domain - clk)
    // =========================================================================
    soc_ram #(
        .MEM_SIZE(16384)
    ) ram (
        .clk    (clk),
        .rst_n  (resetn),
        .valid  (ram_valid),
        .addr   (cpu_mem_addr),
        .wdata  (cpu_mem_wdata),
        .wstrb  (cpu_mem_wstrb),
        .rdata  (ram_rdata),
        .ready  (ram_ready)
    );

    // =========================================================================
    // APB Interconnect and CDC Crossing
    // =========================================================================
    
    // CPU Domain APB signals (connect Master Bridge to CDC input)
    wire [31:0] PADDR_cpu;
    wire        PSEL_cpu;
    wire        PENABLE_cpu;
    wire        PWRITE_cpu;
    wire [31:0] PWDATA_cpu;
    wire [31:0] PRDATA_cpu;
    wire        PREADY_cpu;

    // Instantiate Master APB Bridge (in CPU domain)
    picorv32_apb_bridge apb_master (
        .clk       (clk),
        .rst_n     (resetn),
        .mem_valid (apb_bridge_valid),
        .mem_ready (apb_bridge_ready),
        .mem_addr  (cpu_mem_addr),
        .mem_wdata (cpu_mem_wdata),
        .mem_wstrb (cpu_mem_wstrb),
        .mem_rdata (apb_bridge_rdata),
        
        .PADDR     (PADDR_cpu),
        .PSEL      (PSEL_cpu),
        .PENABLE   (PENABLE_cpu),
        .PWRITE    (PWRITE_cpu),
        .PWDATA    (PWDATA_cpu),
        .PRDATA    (PRDATA_cpu),
        .PREADY    (PREADY_cpu)
    );

    // Peripheral Domain APB signals (connect CDC output to Slaves)
    wire [31:0] PADDR_periph;
    wire        PSEL_periph;
    wire        PENABLE_periph;
    wire        PWRITE_periph;
    wire [31:0] PWDATA_periph;
    wire [31:0] PRDATA_periph;
    wire        PREADY_periph;

    // Instantiate Level-Handshake CDC Bridge between CPU and Peripheral domains
    apb_cdc_bridge apb_cdc (
        .clk_cpu         (clk),
        .rst_n_cpu       (resetn),
        .PADDR_cpu       (PADDR_cpu),
        .PSEL_cpu        (PSEL_cpu),
        .PENABLE_cpu     (PENABLE_cpu),
        .PWRITE_cpu      (PWRITE_cpu),
        .PWDATA_cpu      (PWDATA_cpu),
        .PRDATA_cpu      (PRDATA_cpu),
        .PREADY_cpu      (PREADY_cpu),

        .clk_periph      (clk_periph),
        .rst_n_periph    (resetn),
        .PADDR_periph    (PADDR_periph),
        .PSEL_periph     (PSEL_periph),
        .PENABLE_periph  (PENABLE_periph),
        .PWRITE_periph   (PWRITE_periph),
        .PWDATA_periph   (PWDATA_periph),
        .PRDATA_periph   (PRDATA_periph),
        .PREADY_periph   (PREADY_periph)
    );

    // =========================================================================
    // APB Slave Select Decoding (Peripheral Domain - clk_periph)
    // =========================================================================
    wire psel_uart  = PSEL_periph && (PADDR_periph[19:16] == 4'h0);
    wire psel_gpio  = PSEL_periph && (PADDR_periph[19:16] == 4'h1);
    wire psel_timer = PSEL_periph && (PADDR_periph[19:16] == 4'h2);

    wire [31:0] prdata_uart;
    wire        pready_uart;

    wire [31:0] prdata_gpio;
    wire        pready_gpio;

    wire [31:0] prdata_timer;
    wire        pready_timer;

    // Multiplex peripheral responses back to APB CDC Bridge
    assign PRDATA_periph = psel_uart  ? prdata_uart  :
                           psel_gpio  ? prdata_gpio  :
                           psel_timer ? prdata_timer :
                           32'h0000_0000;

    assign PREADY_periph = psel_uart  ? pready_uart  :
                           psel_gpio  ? pready_gpio  :
                           psel_timer ? pready_timer :
                           1'b1; // Default ready for unmapped APB accesses

    // =========================================================================
    // Peripherals Instantiations (Peripheral Domain - clk_periph)
    // =========================================================================

    // 1. APB UART Peripheral
    apb_uart_bridge uart_peripheral (
        .clk     (clk_periph),
        .rst_n   (resetn),
        .PADDR   (PADDR_periph),
        .PWDATA  (PWDATA_periph),
        .PWRITE  (PWRITE_periph),
        .PSEL    (psel_uart),
        .PENABLE (PENABLE_periph),
        .PRDATA  (prdata_uart),
        .PREADY  (pready_uart)
    );

    // 2. APB GPIO Peripheral
    apb_gpio gpio_peripheral (
        .PCLK     (clk_periph),
        .PRESETn  (resetn),
        .PSEL     (psel_gpio),
        .PENABLE  (PENABLE_periph),
        .PWRITE   (PWRITE_periph),
        .PADDR    (PADDR_periph[7:0]),
        .PWDATA   (PWDATA_periph),
        .PRDATA   (prdata_gpio),
        .PREADY   (pready_gpio),
        .gpio_out (gpio_out),
        .gpio_in  (gpio_in)
    );

    // 3. APB Timer Peripheral (Width set to 32-bit countdown)
    apb_timer #(
        .WIDTH(32)
    ) timer_peripheral (
        .PCLK       (clk_periph),
        .PRESETn    (resetn),
        .PSEL       (psel_timer),
        .PENABLE    (PENABLE_periph),
        .PWRITE     (PWRITE_periph),
        .PADDR      (PADDR_periph[7:0]),
        .PWDATA     (PWDATA_periph),
        .PRDATA     (prdata_timer),
        .PREADY     (pready_timer),
        .timer_done (timer_done)
    );

endmodule
