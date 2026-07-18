/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Clock divider dividing clk_in by 4 to generate a slower clock
 *               with a 50% duty cycle.
 */

`timescale 1 ns / 1 ps

module clk_divider (
    input  wire clk_in,
    input  wire rst,
    output reg  clk_out
);

    reg [1:0] counter;

    always @(posedge clk_in or posedge rst) begin
        if (rst) begin
            counter <= 2'b00;
            clk_out <= 1'b0;
        end else begin
            counter <= counter + 1;
            // Toggle clk_out every 2 input clock cycles (at counts 2'b01 and 2'b11)
            // to divide clk_in by 4 with a 50% duty cycle.
            if (counter == 2'b01 || counter == 2'b11) begin
                clk_out <= ~clk_out;
            end
        end
    end

endmodule
