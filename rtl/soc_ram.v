/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: A simple 1-wait-state SRAM module with byte write enables.
 *               Loads firmware from a hex file using $readmemh.
 */

`timescale 1 ns / 1 ps

module soc_ram #(
    parameter MEM_SIZE = 16384 // 16KB RAM by default
) (
    input             clk,
    input             rst_n,
    input             valid,
    input      [31:0] addr,
    input      [31:0] wdata,
    input      [ 3:0] wstrb,
    output reg [31:0] rdata,
    output reg        ready
);
    localparam WORDS = MEM_SIZE / 4;
    reg [31:0] mem [0:WORDS-1];

    // Safely wrap the word index to avoid out-of-bound array accesses in simulation
    wire [31:0] word_idx = (addr >> 2) % WORDS;

    // Load compiled firmware hex at startup
    initial begin
        $readmemh("firmware.hex", mem);
    end

    // Memory read/write logic with 1-wait-state response
    always @(posedge clk) begin
        if (!rst_n) begin
            ready <= 1'b0;
        end else begin
            if (valid && !ready) begin
                ready <= 1'b1;
                
                // Write path (byte-enabled writes)
                if (wstrb[0]) mem[word_idx][7:0]   <= wdata[7:0];
                if (wstrb[1]) mem[word_idx][15:8]  <= wdata[15:8];
                if (wstrb[2]) mem[word_idx][23:16] <= wdata[23:16];
                if (wstrb[3]) mem[word_idx][31:24] <= wdata[31:24];
                
                // Read path
                rdata <= mem[word_idx];
            end else begin
                ready <= 1'b0;
            end
        end
    end

endmodule
