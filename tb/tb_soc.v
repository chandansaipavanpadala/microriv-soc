/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Verilog-only testbench for the SoC. Compatible with Verilator 5.x
 *               using --timing and --binary execution mode.
 */

`timescale 1 ns / 1 ps

module tb_soc;

    reg clk;
    reg resetn;
    wire trap;
    wire sim_exit_req;
    wire [31:0] sim_exit_code;

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
        
        // Debug port placeholders
        .cpu_mem_valid (),
        .cpu_mem_ready (),
        .cpu_mem_addr  (),
        .cpu_mem_wdata (),
        .cpu_mem_wstrb (),
        .cpu_mem_rdata ()
    );
    /* verilator lint_on PINCONNECTEMPTY */
    /* verilator lint_on PINMISSING */

    initial begin
        $display("[TB] Starting simulation...");
        clk = 0;
        resetn = 0;

        // Set up wave tracing
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_soc);

        // Reset sequence (hold reset low for 100 ns)
        #100;
        resetn = 1;
        $display("[TB] Reset released. Core executing...");
    end

    // Monitor exit conditions
    always @(posedge clk) begin
        if (resetn) begin
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
