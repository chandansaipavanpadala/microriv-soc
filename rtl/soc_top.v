/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Top-level SoC wrapper. Connects PicoRV32 to SRAM and
 *               implements custom simulator control and character outputs.
 */

`timescale 1 ns / 1 ps

module soc_top (
    input             clk,
    input             resetn,
    output            trap,

    // Simulation exit ports
    output reg        sim_exit_req,
    output reg [31:0] sim_exit_code,

    // Debug ports (exposed for tracing or inspection in testbench)
    output            cpu_mem_valid,
    output            cpu_mem_ready,
    output     [31:0] cpu_mem_addr,
    output     [31:0] cpu_mem_wdata,
    output     [ 3:0] cpu_mem_wstrb,
    output     [31:0] cpu_mem_rdata
);

    // =========================================================================
    // Address Map Decoding
    // =========================================================================
    // RAM:      0x0000_0000 -> 0x0000_3FFF (16KB)
    // SIM_OUT:  0x8000_0000 (Console output char write)
    // SIM_EXIT: 0x8000_0004 (Simulation exit status code)
    // =========================================================================
    wire is_ram      = (cpu_mem_addr < 32'h0000_4000);
    wire is_sim_out  = (cpu_mem_addr == 32'h8000_0000);
    wire is_sim_exit = (cpu_mem_addr == 32'h8000_0004);

    // RAM signals
    wire        ram_valid = cpu_mem_valid && is_ram;
    wire [31:0] ram_rdata;
    wire        ram_ready;

    // Simulation output logic (Console character printing)
    reg sim_out_ready;
    always @(posedge clk) begin
        if (!resetn) begin
            sim_out_ready <= 1'b0;
        end else begin
            if (cpu_mem_valid && is_sim_out && !sim_out_ready) begin
                sim_out_ready <= 1'b1;
                if (|cpu_mem_wstrb) begin
                    $write("%c", cpu_mem_wdata[7:0]);
                    $fflush();
                end
            end else begin
                sim_out_ready <= 1'b0;
            end
        end
    end

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

    // =========================================================================
    // Core Memory Bus Multiplexing
    // =========================================================================
    assign cpu_mem_ready = ram_ready | sim_out_ready | sim_exit_ready;
    assign cpu_mem_rdata = ram_ready ? ram_rdata : 32'h0000_0000;

    // =========================================================================
    // PicoRV32 Core Instantiation
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
    // System SRAM Instantiation (16KB)
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

endmodule
