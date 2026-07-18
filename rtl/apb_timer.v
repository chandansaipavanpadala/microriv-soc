/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: APB-based countdown timer peripheral.
 *               Adapted from Reference bootcamp implementation.
 *               Added PREADY and read-back for active count register.
 */

`timescale 1 ns / 1 ps

module apb_timer #(
    parameter WIDTH = 32 // Set default to 32-bit
) (
    // APB interface
    input  wire        PCLK,
    input  wire        PRESETn,
    input  wire        PSEL,
    input  wire        PENABLE,
    input  wire        PWRITE,
    input  wire [7:0]  PADDR,
    input  wire [31:0] PWDATA,
    output reg  [31:0] PRDATA,
    output wire        PREADY,

    // Timer status output
    output reg         timer_done
);

    // Internal timer registers
    reg [WIDTH-1:0] load_val; // Programmed load value
    reg [WIDTH-1:0] count;    // Active countdown counter
    reg             running;  // Timer running flag

    // PREADY is tied to 1 (0 wait-states for registers)
    assign PREADY = 1'b1;

    // APB Write Register Path
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            load_val   <= 0;
            running    <= 0;
        end else if (PSEL && PENABLE && PWRITE) begin
            case (PADDR)
                8'h00: load_val <= PWDATA[WIDTH-1:0];
                8'h04: running  <= PWDATA[0];
                default: ; // Do nothing
            endcase
        end
    end

    // APB Read Register Path
    always @(*) begin
        PRDATA = 32'h0;
        if (PSEL && !PWRITE) begin
            case (PADDR)
                8'h00: PRDATA = {{(32-WIDTH){1'b0}}, load_val};
                8'h04: PRDATA = {31'b0, running};
                8'h08: PRDATA = {31'b0, timer_done};
                8'h0c: PRDATA = {{(32-WIDTH){1'b0}}, count}; // Expose counter register for firmware inspection
                default: PRDATA = 32'h0;
            endcase
        end
    end

    // Countdown logic
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            count      <= 0;
            timer_done <= 0;
        end else begin
            if (running) begin
                if (count == 0) begin
                    count      <= load_val;
                    timer_done <= 1'b1;
                    running    <= 1'b0; // Stop on completion
                end else begin
                    count      <= count - 1;
                    timer_done <= 1'b0;
                end
            end else begin
                // If not running, keep counter initialized to the load value
                if (PSEL && PENABLE && PWRITE && (PADDR == 8'h00)) begin
                    count <= PWDATA[WIDTH-1:0];
                end else if (!running && count == 0) begin
                    count <= load_val;
                end
            end
        end
    end

endmodule
