/*
 *  microriv-soc -- A simulation-first RISC-V mini SoC
 *
 *  Copyright (C) 2026
 *
 *  Description: Level-Handshake APB3 Clock Domain Crossing (CDC) Bridge.
 *               Connects CPU domain APB Master to Peripheral domain APB Slaves.
 */

`timescale 1 ns / 1 ps

module apb_cdc_bridge (
    // CPU Domain Signals
    input  wire         clk_cpu,
    input  wire         rst_n_cpu,
    
    // APB Slave port in CPU domain (connects to picorv32_apb_bridge)
    input  wire [31:0]  PADDR_cpu,
    input  wire         PSEL_cpu,
    input  wire         PENABLE_cpu,
    input  wire         PWRITE_cpu,
    input  wire [31:0]  PWDATA_cpu,
    output reg  [31:0]  PRDATA_cpu,
    output reg          PREADY_cpu,

    // Peripheral Domain Signals
    input  wire         clk_periph,
    input  wire         rst_n_periph,

    // APB Master port in Peripheral domain (connects to APB Peripherals)
    output reg  [31:0]  PADDR_periph,
    output reg          PSEL_periph,
    output reg          PENABLE_periph,
    output reg          PWRITE_periph,
    output reg  [31:0]  PWDATA_periph,
    input  wire [31:0]  PRDATA_periph,
    input  wire         PREADY_periph,
    output wire         clk_periph_en
);

    // =========================================================================
    // Control State Machines and Holding Registers
    // =========================================================================
    
    // CPU domain state machine states
    localparam CPU_STATE_IDLE  = 2'b00;
    localparam CPU_STATE_WAIT  = 2'b01;
    localparam CPU_STATE_DONE  = 2'b10;
    localparam CPU_STATE_CLEAR = 2'b11;

    reg [1:0]  cpu_state;
    reg        req_cpu;
    reg [31:0] addr_hold;
    reg [31:0] wdata_hold;
    reg        write_hold;
    reg [31:0] rdata_hold;

    // Peripheral domain state machine states
    localparam PERIPH_STATE_IDLE   = 2'b00;
    localparam PERIPH_STATE_SETUP  = 2'b01;
    localparam PERIPH_STATE_ACCESS = 2'b10;
    localparam PERIPH_STATE_HOLD   = 2'b11;

    reg [1:0]  periph_state;
    reg        ack_periph;
    reg [31:0] PRDATA_from_periph;

    // =========================================================================
    // Synchronizers
    // =========================================================================
    
    // Synchronize req_cpu (CPU domain) -> req_periph_sync (Peripheral domain)
    wire req_periph_sync;
`ifdef BUG_INJECT_CDC_BYPASS
    // Deliberate CDC bug: bypass synchronizer stage entirely, causing raw combinational crossing
    assign req_periph_sync = req_cpu;
`else
    sync2_stage sync_req (
        .clk      (clk_periph),
        .async_in (req_cpu),
        .sync_out (req_periph_sync)
    );
`endif

    // Synchronize ack_periph (Peripheral domain) -> ack_cpu_sync (CPU domain)
    wire ack_cpu_sync;
    sync2_stage sync_ack (
        .clk      (clk_cpu),
        .async_in (ack_periph),
        .sync_out (ack_cpu_sync)
    );

    // =========================================================================
    // CPU Domain Logic
    // =========================================================================
    always @(posedge clk_cpu or negedge rst_n_cpu) begin
        if (!rst_n_cpu) begin
            cpu_state  <= CPU_STATE_IDLE;
            req_cpu    <= 1'b0;
            addr_hold  <= 32'h0;
            wdata_hold <= 32'h0;
            write_hold <= 1'b0;
            rdata_hold <= 32'h0;
            PREADY_cpu <= 1'b0;
            PRDATA_cpu <= 32'h0;
        end else begin
            PREADY_cpu <= 1'b0;
            
            case (cpu_state)
                CPU_STATE_IDLE: begin
                    // Initiate transaction: latch inputs and assert req_cpu
                    if (PSEL_cpu && !PREADY_cpu) begin
                        cpu_state  <= CPU_STATE_WAIT;
                        addr_hold  <= PADDR_cpu;
                        wdata_hold <= PWDATA_cpu;
                        write_hold <= PWRITE_cpu;
                        req_cpu    <= 1'b1;
                    end
                end

                CPU_STATE_WAIT: begin
                    // Wait for acknowledge from peripheral domain
                    if (ack_cpu_sync) begin
                        cpu_state  <= CPU_STATE_DONE;
                        req_cpu    <= 1'b0; // Deassert request
                        if (!write_hold) begin
                            rdata_hold <= PRDATA_from_periph;
                        end
                    end
                end

                CPU_STATE_DONE: begin
                    // Assert ready back to picorv32_apb_bridge
                    PREADY_cpu <= 1'b1;
                    PRDATA_cpu <= rdata_hold;
                    cpu_state  <= CPU_STATE_CLEAR;
                end

                CPU_STATE_CLEAR: begin
                    // Wait for peripheral domain to clear its acknowledge
                    if (!ack_cpu_sync) begin
                        cpu_state <= CPU_STATE_IDLE;
                    end
                end

                default: cpu_state <= CPU_STATE_IDLE;
            endcase
        end
    end

    // =========================================================================
    // Peripheral Domain Logic
    // =========================================================================
    always @(posedge clk_periph or negedge rst_n_periph) begin
        if (!rst_n_periph) begin
            periph_state       <= PERIPH_STATE_IDLE;
            ack_periph         <= 1'b0;
            PADDR_periph       <= 32'h0;
            PSEL_periph        <= 1'b0;
            PENABLE_periph     <= 1'b0;
            PWRITE_periph      <= 1'b0;
            PWDATA_periph      <= 32'h0;
            PRDATA_from_periph <= 32'h0;
        end else begin
            case (periph_state)
                PERIPH_STATE_IDLE: begin
                    // Wait for synchronized request and ensure acknowledge is clear
                    if (req_periph_sync && !ack_periph) begin
                        periph_state   <= PERIPH_STATE_SETUP;
                        PADDR_periph   <= addr_hold;
                        PWRITE_periph  <= write_hold;
                        PWDATA_periph  <= wdata_hold;
                        PSEL_periph    <= 1'b1;
                    end
                end

                PERIPH_STATE_SETUP: begin
                    // APB Setup Phase -> Access Phase
                    periph_state   <= PERIPH_STATE_ACCESS;
                    PENABLE_periph <= 1'b1;
                end

                PERIPH_STATE_ACCESS: begin
                    // APB Access Phase: wait for target peripheral PREADY
                    if (PREADY_periph) begin
                        periph_state   <= PERIPH_STATE_HOLD;
                        PSEL_periph    <= 1'b0;
                        PENABLE_periph <= 1'b0;
                        ack_periph     <= 1'b1; // Assert acknowledge
                        if (!PWRITE_periph) begin
                            PRDATA_from_periph <= PRDATA_periph;
                        end
                    end
                end

                PERIPH_STATE_HOLD: begin
                    // Hold acknowledge until request is cleared by CPU domain
                    if (!req_periph_sync) begin
                        ack_periph   <= 1'b0;
                        periph_state <= PERIPH_STATE_IDLE;
                    end
                end

                default: periph_state <= PERIPH_STATE_IDLE;
            endcase
        end
    end

    // Enable clock gating when a request is active (req_cpu) or peripheral is completing the transaction (ack_periph)
    assign clk_periph_en = req_cpu || ack_periph;

`ifdef ASSERTIONS_ON
    // =========================================================================
    // SystemVerilog Assertions (SVA) & Verification Checkers
    // =========================================================================

    // 1. req_cpu must remain stable (does not deassert/toggle) while synchronizer is settling (until ack_cpu_sync returns)
    assert_req_stable: assert property (
        @(posedge clk_cpu) disable iff (!rst_n_cpu)
        (req_cpu && !ack_cpu_sync) |=> req_cpu
    );

    // 2. addr_hold, wdata_hold, write_hold must remain stable during transaction flight
    assert_addr_stable: assert property (
        @(posedge clk_cpu) disable iff (!rst_n_cpu)
        (req_cpu) |=> ($stable(addr_hold) && $stable(wdata_hold) && $stable(write_hold))
    );

    // 3. Handshake ordering: req_cpu must not re-assert until previous ack_cpu_sync has cleared
    assert_req_handshake_clear: assert property (
        @(posedge clk_cpu) disable iff (!rst_n_cpu)
        (ack_cpu_sync) |-> !req_cpu
    );

    // 4. APB protocol stability - CPU-side: PSEL/PADDR/PWRITE must be stable when PENABLE is asserted
    assert_cpu_apb_stable: assert property (
        @(posedge clk_cpu) disable iff (!rst_n_cpu)
        (PSEL_cpu && PENABLE_cpu) |-> ($stable(PADDR_cpu) && $stable(PWRITE_cpu) && $stable(PSEL_cpu))
    );

    // 5. APB protocol stability - Periph-side: PSEL/PADDR/PWRITE must be stable when PENABLE is asserted
    assert_periph_apb_stable: assert property (
        @(posedge clk_periph) disable iff (!rst_n_periph)
        (PSEL_periph && PENABLE_periph) |-> ($stable(PADDR_periph) && $stable(PWRITE_periph) && $stable(PSEL_periph))
    );

    // 6. Bounded PREADY: PREADY_periph must assert within 100 cycles of PENABLE_periph
    // Implemented as a synthesizable Verilog counter to avoid version-specific SVA dynamic range bugs.
    reg [7:0] pready_counter;
    always @(posedge clk_periph or negedge rst_n_periph) begin
        if (!rst_n_periph) begin
            pready_counter <= 8'd0;
        end else begin
            if (PSEL_periph && PENABLE_periph && !PREADY_periph) begin
                pready_counter <= pready_counter + 8'd1;
                if (pready_counter >= 8'd100) begin
                    $error("[SVA ERROR] PREADY failed to assert within 100 clock cycles of PENABLE!");
                end
            end else begin
                pready_counter <= 8'd0;
            end
        end
    end

    // 7. Detect asynchronous changes on synchronizer outputs
    always @(req_periph_sync) begin
        if (rst_n_periph && req_cpu !== 1'bx) begin
            if (!clk_periph) begin
                $error("[SVA CDC ERROR] Synchronizer output req_periph_sync changed asynchronously while clk_periph is low!");
            end
        end
    end

    always @(ack_cpu_sync) begin
        if (rst_n_cpu && ack_periph !== 1'bx) begin
            if (!clk_cpu) begin
                $error("[SVA CDC ERROR] Synchronizer output ack_cpu_sync changed asynchronously while clk_cpu is low!");
            end
        end
    end
`endif

endmodule
