/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: APB3 Master Bridge for PicoRV32 CPU.
 *               Converts PicoRV32 native memory interface protocol to APB3.
 */

`timescale 1 ns / 1 ps

module picorv32_apb_bridge (
    input wire         clk,
    input wire         rst_n,

    // PicoRV32 Native Memory Interface
    input wire         mem_valid,
    output reg         mem_ready,
    input wire  [31:0] mem_addr,
    input wire  [31:0] mem_wdata,
    input wire  [ 3:0] mem_wstrb,
    output reg  [31:0] mem_rdata,

    // APB Master Interface
    output reg  [31:0] PADDR,
    output reg         PSEL,
    output reg         PENABLE,
    output reg         PWRITE,
    output reg  [31:0] PWDATA,
    input wire  [31:0] PRDATA,
    input wire         PREADY
);

    // APB Master State Machine States
    localparam STATE_IDLE   = 2'b00;
    localparam STATE_SETUP  = 2'b01;
    localparam STATE_ACCESS = 2'b10;

    reg [1:0] state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state     <= STATE_IDLE;
            PADDR     <= 32'h0;
            PSEL      <= 1'b0;
            PENABLE   <= 1'b0;
            PWRITE    <= 1'b0;
            PWDATA    <= 32'h0;
            mem_ready <= 1'b0;
            mem_rdata <= 32'h0;
        end else begin
            mem_ready <= 1'b0;
            
            case (state)
                STATE_IDLE: begin
                    if (mem_valid) begin
                        state   <= STATE_SETUP;
                        PSEL    <= 1'b1;
                        PADDR   <= mem_addr;
                        PWRITE  <= |mem_wstrb;
                        PWDATA  <= mem_wdata;
                    end
                end

                STATE_SETUP: begin
                    state   <= STATE_ACCESS;
                    PENABLE <= 1'b1;
                end

                STATE_ACCESS: begin
                    if (PREADY) begin
                        state     <= STATE_IDLE;
                        PSEL      <= 1'b0;
                        PENABLE   <= 1'b0;
                        mem_ready <= 1'b1;
                        if (!PWRITE) begin
                            mem_rdata <= PRDATA;
                        end
                    end
                end

                default: state <= STATE_IDLE;
            endcase
        end
    end

endmodule
