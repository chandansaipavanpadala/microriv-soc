/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: APB-based General Purpose Input/Output (GPIO) peripheral.
 *               Provides a 32-bit output register and a 32-bit input pin monitor.
 */

`timescale 1 ns / 1 ps

module apb_gpio (
    input  wire        PCLK,
    input  wire        PRESETn,
    input  wire        PSEL,
    input  wire        PENABLE,
    input  wire        PWRITE,
    input  wire [7:0]  PADDR,
    input  wire [31:0] PWDATA,
    output reg  [31:0] PRDATA,
    output wire        PREADY,

    // External GPIO pins
    output reg  [31:0] gpio_out,
    input  wire [31:0] gpio_in
);

    // GPIO is ready immediately (0 wait-states)
    assign PREADY = 1'b1;

    // APB Write Register Path
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            gpio_out <= 32'h0000_0000;
        end else if (PSEL && PENABLE && PWRITE) begin
            case (PADDR[7:0])
                8'h00: gpio_out <= PWDATA; // Update outputs
            endcase
        end
    end

    // APB Read Register Path
    always @(*) begin
        PRDATA = 32'h0000_0000;
        if (PSEL && !PWRITE) begin
            case (PADDR[7:0])
                8'h00: PRDATA = gpio_out;
                8'h04: PRDATA = gpio_in; // Read physical pins
                default: PRDATA = 32'h0000_0000;
            endcase
        end
    end

endmodule
