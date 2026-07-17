/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Verilator C++ testbench for the Phase 1 SoC simulation.
 *               Generates clocks, monitors simulation termination conditions,
 *               and outputs VCD waveforms.
 */

#include <iostream>
#include <memory>
#include <iomanip>
#include <verilated.h>
#include "Vsoc_top.h"

#if VM_TRACE
#include <verilated_vcd_c.h>
#endif

// Track simulation time (in steps/ticks)
vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator command line arguments
    Verilated::commandArgs(argc, argv);

    // Instantiate the top module
    std::unique_ptr<Vsoc_top> top = std::make_unique<Vsoc_top>();

    // VCD wave tracing setup
#if VM_TRACE
    Verilated::traceEverOn(true);
    std::unique_ptr<VerilatedVcdC> tfp = std::make_unique<VerilatedVcdC>();
    top->trace(tfp.get(), 99); // Trace 99 levels of hierarchy
    tfp->open("waveform.vcd");
    std::cout << "[TB] Waveform dumping enabled (waveform.vcd)" << std::endl;
#endif

    // Initial state: reset asserted, clock low
    top->clk = 0;
    top->resetn = 0;

    std::cout << "[TB] Starting reset sequence..." << std::endl;
    // Hold reset for 10 clock cycles (20 ticks)
    for (int i = 0; i < 20; ++i) {
        top->clk = !top->clk;
        top->eval();
#if VM_TRACE
        tfp->dump(main_time++);
#endif
    }

    // Release reset
    top->resetn = 1;
    std::cout << "[TB] Reset released. Simulation running..." << std::endl;

    unsigned long max_cycles = 100000; // Protection timeout
    unsigned long cycle_count = 0;
    bool success = false;
    int exit_status = 0;

    while (!Verilated::gotFinish() && (cycle_count < max_cycles)) {
        // Toggle clock: falling edge
        top->clk = 0;
        top->eval();
#if VM_TRACE
        tfp->dump(main_time++);
#endif

        // Toggle clock: rising edge
        top->clk = 1;
        top->eval();
#if VM_TRACE
        tfp->dump(main_time++);
#endif

        cycle_count++;

        // 1. Check for trap asserted (CPU error / instruction exception)
        if (top->trap) {
            std::cerr << "[TB] ERROR: CPU Trap asserted at cycle " << cycle_count 
                      << "! Execution halted." << std::endl;
            exit_status = 1;
            break;
        }

        // 2. Check if the firmware requested simulation exit
        if (top->sim_exit_req) {
            std::cout << "[TB] Simulation exit requested by firmware at cycle " 
                      << cycle_count << "." << std::endl;
            std::cout << "[TB] Exit code returned: " << top->sim_exit_code << std::endl;
            
            if (top->sim_exit_code == 1) {
                std::cout << "[TB] SUCCESS: Test firmware executed correctly!" << std::endl;
                success = true;
                exit_status = 0;
            } else {
                std::cerr << "[TB] FAILURE: Test firmware exited with error code " 
                          << top->sim_exit_code << std::endl;
                exit_status = top->sim_exit_code;
            }
            break;
        }
    }

    // Check for simulation timeout
    if (cycle_count >= max_cycles) {
        std::cerr << "[TB] ERROR: Simulation timed out after " << max_cycles 
                  << " cycles without completion!" << std::endl;
        exit_status = 2;
    }

    // Close waveform dump if enabled
#if VM_TRACE
    if (tfp) {
        tfp->close();
        std::cout << "[TB] Waveform dump closed." << std::endl;
    }
#endif

    std::cout << "[TB] Simulation finished at cycle " << cycle_count << "." << std::endl;
    return exit_status;
}
