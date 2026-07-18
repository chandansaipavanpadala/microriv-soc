/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Verilog-only testbench for the Phase 2 SoC.
 *               Simulates external wiring by looping GPIO outputs directly to inputs.
 */

`timescale 1 ns / 1 ps

module tb_soc;

    reg clk;
    reg resetn;
    wire trap;
    wire sim_exit_req;
    wire [31:0] sim_exit_code;

    // GPIO and Timer external signals
    wire [31:0] gpio_out;
    wire [31:0] gpio_in;
    /* verilator lint_off UNUSEDSIGNAL */
    wire        timer_done;
    /* verilator lint_on UNUSEDSIGNAL */

    // Simulate physical loopback on GPIO pins (Input = Output)
    assign gpio_in = gpio_out;

    // Clock generation (50MHz clock -> 20ns period)
    always #10 clk <= ~clk;

    // Instantiate SoC Top-Level
    /* verilator lint_off PINCONNECTEMPTY */
    /* verilator lint_off PINMISSING */
    soc_top dut (
        .clk           (clk),
        .resetn        (resetn),
        .trap          (trap),
        .sim_exit_req  (sim_exit_req),
        .sim_exit_code (sim_exit_code),
        .gpio_out      (gpio_out),
        .gpio_in       (gpio_in),
        .timer_done    (timer_done)
    );
    /* verilator lint_on PINCONNECTEMPTY */
    /* verilator lint_on PINMISSING */

    reg sim_started;

    reg [31:0] raw_periph_edges;
    reg [31:0] gated_periph_edges;

    initial begin
        $display("[TB] Starting Phase 4 simulation...");
        clk = 0;
        resetn = 0;
        sim_started = 0;
        raw_periph_edges = 0;
        gated_periph_edges = 0;

        // Set up wave tracing
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_soc);

        // Reset sequence (hold reset low for 100 ns)
        #100;
        resetn = 1;
        #20;
        sim_started = 1;
        $display("[TB] Reset released. Core executing...");
    end

    // Track active clock edges to measure clock gating efficiency
    always @(posedge dut.clk_periph_raw) begin
        if (sim_started) begin
            raw_periph_edges <= raw_periph_edges + 1;
        end
    end

    always @(posedge dut.clk_periph) begin
        if (sim_started) begin
            gated_periph_edges <= gated_periph_edges + 1;
        end
    end

    // Monitor exit conditions
    always @(posedge clk) begin
        if (sim_started) begin
            if (trap) begin
                $display("[TB] ERROR: CPU Trap asserted! Halting simulation.");
                $finish;
            end
            if (sim_exit_req) begin
                $display("[TB] Simulation exit requested by firmware.");
                $display("[TB] Exit code: %d", sim_exit_code);
                if (sim_exit_code == 1) begin
                    $display("[TB] SUCCESS: Test program completed successfully!");
                end else begin
                    $display("[TB] FAILURE: Test program failed with code %d", sim_exit_code);
                end
                $display("==================================================================");
                $display(" Clock Gating Performance Statistics (During Active Simulation)");
                $display("==================================================================");
                $display(" Raw Peripheral Clock Edges:   %d", raw_periph_edges);
                $display(" Gated Peripheral Clock Edges: %d", gated_periph_edges);
                $display(" Clock Edges Saved:            %d", raw_periph_edges - gated_periph_edges);
                if (raw_periph_edges > 0) begin
                    $display(" Dynamic Power Reduction:      %d%%", (raw_periph_edges - gated_periph_edges) * 100 / raw_periph_edges);
                end
                $display("==================================================================");
                $finish;
            end
        end
    end

    // Watchdog safety timeout (timeout after 5,000,000 ns / 5 ms)
    initial begin
        #5000000;
        $display("[TB] ERROR: Simulation watchdog timeout after 5ms!");
        $finish;
    end

endmodule
