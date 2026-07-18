/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Two flip-flop stage synchronizer to resolve metastability.
 *               Copied from Reference boot camp modules.
 */

`timescale 1 ns / 1 ps

module sync2_stage (
    input  wire clk,
    input  wire async_in,
    output reg  sync_out
);

    reg sync_ff1;

    always @(posedge clk) begin
        sync_ff1 <= async_in; // First stage
        sync_out <= sync_ff1; // Second stage
    end

endmodule
