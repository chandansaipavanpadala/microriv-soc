/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Glitch-free Integrated Clock Gating (ICG) cell.
 *               Uses an active-low transparent latch (transparent when clk is low)
 *               and an AND gate to gate the clock cleanly without pulse shortening
 *               or glitches.
 */

`timescale 1 ns / 1 ps

module icg (
    input  wire clk_in,
    input  wire en,
    output wire clk_out
);

    reg en_latch;

    // Latch is transparent when clock is low (clk_in == 0).
    // It latches the value of 'en' on the rising edge of clk_in.
    always_latch begin
        if (!clk_in) begin
            en_latch = en;
        end
    end

    // Gated clock output is ANDed with the latched enable
    assign clk_out = clk_in & en_latch;

`ifdef ASSERTIONS_ON
    // Assertion 8: en_latch must be stable when clk_in transitions from 0 to 1
    assert_icg_clk_stable: assert property (
        @(posedge clk_in)
        $stable(en_latch)
    );

    // Assertion 9: en_latch must never change while clk_in is high (1)
    always @(en_latch) begin
        if (clk_in) begin
            $error("[SVA ERROR] ICG latch en_latch changed while clk_in is high!");
        end
    end
`endif

endmodule
