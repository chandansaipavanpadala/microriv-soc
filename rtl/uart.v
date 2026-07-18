/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: UART transmitter/receiver stub.
 *               Simulates loopback by putting tx_data immediately in rx_data,
 *               and outputs bytes to the simulation terminal via $write.
 */

`timescale 1 ns / 1 ps

module uart (
    input  wire       clk,
    input  wire       rst_n,
    input  wire [7:0] tx_data,
    input  wire       tx_write,
    output reg  [7:0] rx_data,
    output reg        rx_ready,
    output reg        tx_busy
);

    reg [7:0] tx_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tx_reg   <= 8'h00;
            rx_data  <= 8'h00;
            rx_ready <= 1'b0;
            tx_busy  <= 1'b0;
        end else begin
            rx_ready <= 1'b0;
            if (tx_write) begin
                tx_reg   <= tx_data;
                tx_busy  <= 1'b1;
                rx_data  <= tx_data;
                rx_ready <= 1'b1;
                tx_busy  <= 1'b0; // Immediate ready (stub behavior)
                
                // Echo TX byte to the simulation console
                $write("%c", tx_data);
                $fflush();
            end
        end
    end

endmodule
