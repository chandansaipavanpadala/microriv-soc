// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_soc.h for the primary calling header

#include "verilated.h"

#include "Vtb_soc__Syms.h"
#include "Vtb_soc___024root.h"

VL_ATTR_COLD void Vtb_soc___024root___eval_initial__TOP(Vtb_soc___024root* vlSelf);
VlCoroutine Vtb_soc___024root___eval_initial__TOP__0(Vtb_soc___024root* vlSelf);
VlCoroutine Vtb_soc___024root___eval_initial__TOP__1(Vtb_soc___024root* vlSelf);
VlCoroutine Vtb_soc___024root___eval_initial__TOP__2(Vtb_soc___024root* vlSelf);

void Vtb_soc___024root___eval_initial(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_initial\n"); );
    // Body
    Vtb_soc___024root___eval_initial__TOP(vlSelf);
    Vtb_soc___024root___eval_initial__TOP__0(vlSelf);
    Vtb_soc___024root___eval_initial__TOP__1(vlSelf);
    Vtb_soc___024root___eval_initial__TOP__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph_raw__0 
        = vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph__0 
        = vlSelf->tb_soc__DOT__dut__DOT__clk_periph;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__clk__0 
        = vlSelf->tb_soc__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__resetn__0 
        = vlSelf->tb_soc__DOT__resetn;
}

VL_INLINE_OPT VlCoroutine Vtb_soc___024root___eval_initial__TOP__1(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_initial__TOP__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x12a05f200ULL, 
                                       nullptr, "/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 
                                       119);
    VL_WRITEF("[TB] ERROR: Simulation watchdog timeout after 5ms!\n");
    VL_FINISH_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 121, "");
}

VL_INLINE_OPT VlCoroutine Vtb_soc___024root___eval_initial__TOP__2(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_initial__TOP__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x2710ULL, 
                                           nullptr, 
                                           "/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 
                                           31);
        vlSelf->__Vdlyvval__tb_soc__DOT__clk__v0 = 
            (1U & (~ (IData)(vlSelf->tb_soc__DOT__clk)));
        vlSelf->__Vdlyvset__tb_soc__DOT__clk__v0 = 1U;
    }
}

VL_INLINE_OPT void Vtb_soc___024root___act_sequent__TOP__0(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   (~ (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)))) 
                                                   & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word_q;
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word = 0U;
    }
    if ((1U & (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) 
                | (0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_state))) 
               | (~ (IData)(vlSelf->tb_soc__DOT__resetn))))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   (~ (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)))) 
                                                   & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
                                                      | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                                                         | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata)))));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) 
                                                    & ((0U 
                                                        != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)) 
                                                       & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0))) 
                                                   | ((3U 
                                                       == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)) 
                                                      & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst))));
}

void Vtb_soc___024root___eval_act(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_act\n"); );
    // Body
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_soc___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__0(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__tb_soc__DOT__raw_periph_edges = vlSelf->tb_soc__DOT__raw_periph_edges;
    if (vlSelf->tb_soc__DOT__sim_started) {
        vlSelf->__Vdly__tb_soc__DOT__raw_periph_edges 
            = ((IData)(1U) + vlSelf->tb_soc__DOT__raw_periph_edges);
    }
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__1(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdly__tb_soc__DOT__gated_periph_edges 
        = vlSelf->tb_soc__DOT__gated_periph_edges;
    if (vlSelf->tb_soc__DOT__sim_started) {
        vlSelf->__Vdly__tb_soc__DOT__gated_periph_edges 
            = ((IData)(1U) + vlSelf->tb_soc__DOT__gated_periph_edges);
    }
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__2(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter;
    __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter = 0;
    // Body
    __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter 
        = vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PWRITE_cpu 
        = vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PRDATA_cpu 
        = vlSelf->tb_soc__DOT__dut__DOT__PRDATA_cpu;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu 
        = vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu;
    if (vlSelf->tb_soc__DOT__resetn) {
        __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter 
            = (3U & ((IData)(1U) + (IData)(vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter)));
        if (((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter)) 
             | (3U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter)))) {
            vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw 
                = (1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw)));
        }
    } else {
        __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter 
        = __Vdly__tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__3(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state;
    __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph = 0;
    IData/*31:0*/ __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph = 0;
    IData/*31:0*/ __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running;
    __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running = 0;
    IData/*31:0*/ __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count;
    __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count = 0;
    // Body
    __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
        = vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count;
    __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running 
        = vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running;
    __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph = vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph = vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph;
    __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph = vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph;
    __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph = vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph;
    if (vlSelf->tb_soc__DOT__resetn) {
        if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_gpio) 
              & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph)) 
             & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph))) {
            if ((0U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))) {
                vlSelf->tb_soc__DOT__gpio_out = vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph;
            }
        }
        if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer) 
              & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph)) 
             & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph))) {
            if ((0U != (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))) {
                if ((4U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))) {
                    __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running 
                        = (1U & vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph);
                }
            }
        }
        if (vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running) {
            if ((0U == vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count)) {
                __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
                    = vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val;
                vlSelf->tb_soc__DOT__timer_done = 1U;
                __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running = 0U;
            } else {
                __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
                    = (vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
                       - (IData)(1U));
                vlSelf->tb_soc__DOT__timer_done = 0U;
            }
        } else if (((((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer) 
                      & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph)) 
                     & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph)) 
                    & (0U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)))) {
            __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
                = vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph;
        } else if (((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running)) 
                    & (0U == vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count))) {
            __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
                = vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val;
        }
        if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer) 
              & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph)) 
             & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph))) {
            if ((0U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))) {
                vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val 
                    = vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph;
            }
        }
        vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
            = __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count;
        vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running 
            = __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running;
        if ((2U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state))) {
            if ((1U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state))) {
                if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_periph_sync)))) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph = 0U;
                    __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 0U;
                }
            } else if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart)) 
                              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__pready_uart)))) {
                __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 3U;
                vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph = 0U;
                __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph = 1U;
                if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph)))) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph 
                        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart)
                            ? vlSelf->tb_soc__DOT__dut__DOT__prdata_uart
                            : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_gpio)
                                ? vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio
                                : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer)
                                    ? vlSelf->tb_soc__DOT__dut__DOT__prdata_timer
                                    : 0U)));
                }
            }
        } else if ((1U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state))) {
            __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 2U;
            __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph = 1U;
        } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_periph_sync) 
                    & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph)))) {
            __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 1U;
            __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph 
                = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__addr_hold;
            __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph 
                = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold;
            __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph 
                = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__wdata_hold;
            vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph = 1U;
        }
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state 
            = __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state;
        if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart) 
             & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph))) {
            if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph)))) {
                vlSelf->tb_soc__DOT__dut__DOT__prdata_uart 
                    = ((4U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                        ? (IData)(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_data)
                        : ((8U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                            ? (((IData)(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy) 
                                << 1U) | (IData)(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready))
                            : 0U));
            }
        }
    } else {
        __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running = 0U;
        vlSelf->tb_soc__DOT__gpio_out = 0U;
        __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count = 0U;
        vlSelf->tb_soc__DOT__timer_done = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count 
            = __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count;
        vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running 
            = __Vdly__tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running;
        __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph = 0U;
        __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph = 0U;
        __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph = 0U;
        __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph = 0U;
        __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state 
            = __Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state;
        vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__prdata_uart = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph = __Vdly__tb_soc__DOT__dut__DOT__PADDR_periph;
    vlSelf->tb_soc__DOT__dut__DOT__psel_gpio = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                & (0x10000U 
                                                   == 
                                                   (0xf0000U 
                                                    & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    vlSelf->tb_soc__DOT__dut__DOT__psel_timer = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                 & (0x20000U 
                                                    == 
                                                    (0xf0000U 
                                                     & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    if (vlSelf->tb_soc__DOT__resetn) {
        vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready = 0U;
        if (VL_UNLIKELY(((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart) 
                         & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph) 
                            & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph) 
                               & (IData)(vlSelf->tb_soc__DOT__dut__DOT__pready_uart)))))) {
            VL_WRITEF("%c",8,(0xffU & vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph));
            vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__uart_inst__DOT__tx_reg 
                = (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph);
            vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy = 1U;
            vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_data 
                = (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph);
            vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready = 1U;
            Verilated::runFlushCallbacks();
            vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy = 0U;
        }
    } else {
        vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__uart_inst__DOT__tx_reg = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_data = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy = 0U;
    }
    if (vlSelf->tb_soc__DOT__resetn) {
        vlSelf->tb_soc__DOT__dut__DOT__pready_uart = 0U;
        if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart) 
             & (IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph))) {
            vlSelf->tb_soc__DOT__dut__DOT__pready_uart = 1U;
        }
    } else {
        vlSelf->tb_soc__DOT__dut__DOT__pready_uart = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph = __Vdly__tb_soc__DOT__dut__DOT__PWDATA_periph;
    vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph = __Vdly__tb_soc__DOT__dut__DOT__PWRITE_periph;
    vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio = 0U;
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_gpio) 
         & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph)))) {
        vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio 
            = ((0U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                ? vlSelf->tb_soc__DOT__gpio_out : (
                                                   (4U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                                                    ? vlSelf->tb_soc__DOT__gpio_out
                                                    : 0U));
    }
    vlSelf->tb_soc__DOT__dut__DOT__prdata_timer = 0U;
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer) 
         & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph)))) {
        vlSelf->tb_soc__DOT__dut__DOT__prdata_timer 
            = ((0U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                ? vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val
                : ((4U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                    ? (IData)(vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running)
                    : ((8U == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                        ? (IData)(vlSelf->tb_soc__DOT__timer_done)
                        : ((0xcU == (0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph))
                            ? vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count
                            : 0U))));
    }
    vlSelf->tb_soc__DOT__dut__DOT__psel_uart = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                & (0U 
                                                   == 
                                                   (0xf0000U 
                                                    & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph = __Vdly__tb_soc__DOT__dut__DOT__PENABLE_periph;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__4(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__4\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0;
    __Vdlyvdim0__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0;
    __Vdlyvval__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0;
    __Vdlyvset__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 = 0;
    CData/*4:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh = 0;
    IData/*31:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0;
    __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0;
    __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0;
    __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1;
    __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1;
    __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1;
    __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2;
    __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2;
    __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2;
    __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3;
    __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3;
    __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3;
    __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0;
    // Body
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1;
    __Vdlyvset__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 = 0U;
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0U;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 0U;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0U;
    __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0U;
    if (vlSelf->tb_soc__DOT__sim_started) {
        if (VL_UNLIKELY(vlSelf->tb_soc__DOT__trap)) {
            VL_WRITEF("[TB] ERROR: CPU Trap asserted! Halting simulation.\n");
            VL_FINISH_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 92, "");
        }
        if (VL_UNLIKELY(vlSelf->tb_soc__DOT__sim_exit_req)) {
            VL_WRITEF("[TB] Simulation exit requested by firmware.\n[TB] Exit code: %10#\n",
                      32,vlSelf->tb_soc__DOT__sim_exit_code);
            if ((1U == vlSelf->tb_soc__DOT__sim_exit_code)) {
                VL_WRITEF("[TB] SUCCESS: Test program completed successfully!\n");
            } else {
                VL_WRITEF("[TB] FAILURE: Test program failed with code %10#\n",
                          32,vlSelf->tb_soc__DOT__sim_exit_code);
            }
            VL_WRITEF("==================================================================\n Clock Gating Performance Statistics (During Active Simulation)\n==================================================================\n Raw Peripheral Clock Edges:   %10#\n Gated Peripheral Clock Edges: %10#\n Clock Edges Saved:            %10#\n",
                      32,vlSelf->tb_soc__DOT__raw_periph_edges,
                      32,vlSelf->tb_soc__DOT__gated_periph_edges,
                      32,(vlSelf->tb_soc__DOT__raw_periph_edges 
                          - vlSelf->tb_soc__DOT__gated_periph_edges));
            if (VL_UNLIKELY((0U < vlSelf->tb_soc__DOT__raw_periph_edges))) {
                VL_WRITEF(" Dynamic Power Reduction:      %10#%%\n",
                          32,VL_DIV_III(32, ((IData)(0x64U) 
                                             * (vlSelf->tb_soc__DOT__raw_periph_edges 
                                                - vlSelf->tb_soc__DOT__gated_periph_edges)), vlSelf->tb_soc__DOT__raw_periph_edges));
            }
            VL_WRITEF("==================================================================\n");
            VL_FINISH_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 112, "");
        }
    }
    if ((((IData)(vlSelf->tb_soc__DOT__resetn) & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write)) 
         & (0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd)))) {
        __Vdlyvval__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata;
        __Vdlyvset__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 = 1U;
        __Vdlyvdim0__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_instr = 0ULL;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_cycle = 0ULL;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_valid = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_data = 0ULL;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait_2 = 0U;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_addr 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_ascii_instr 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_imm 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_opcode 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs1 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs2 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rd 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word_q 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0_q 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0;
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger) 
         & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_insn = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ecall_ebreak 
            = (((0x73U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)) 
                & (~ (IData)((0U != (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                     >> 0x15U))))) 
               & (~ (IData)((0U != (0x1fffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                               >> 7U))))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_setq = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_getq = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_maskirq = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_timer = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence 
            = ((0xfU == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)) 
               & (~ (IData)((0U != (7U & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                          >> 0xcU))))));
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_irq_pending = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__resetn)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__eoi = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_mask = 0xffffffffU;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_timeout = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_valid = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_trace = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_irq_pending = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_state = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_pending 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_irq_pending;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger_q) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_ascii_instr 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_opcode 
            = ((3U == (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode))
                ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode
                : (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rd 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs1 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1;
    }
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
         & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_waitirq = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1 
            = (0x1fU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                        >> 0xfU));
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger_q) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs2 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_imm 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
               | (IData)(vlSelf->tb_soc__DOT__trap)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_valid_insn = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word = 0U;
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_valid_insn = 1U;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word = 0U;
    }
    if (vlSelf->tb_soc__DOT__resetn) {
        if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__last_mem_valid)))) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_firstword_reg = 0U;
        }
        if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
              & (0x4000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr)) 
             & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__ram_ready)))) {
            vlSelf->tb_soc__DOT__dut__DOT__ram_ready = 1U;
            vlSelf->tb_soc__DOT__dut__DOT__ram_rdata 
                = vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem
                [(0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                            >> 2U))];
            if ((1U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb))) {
                __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 
                    = (0xffU & vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata);
                __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 1U;
                __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 = 0U;
                __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0 
                    = (0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                                 >> 2U));
            }
            if ((2U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb))) {
                __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 
                    = (0xffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata 
                                >> 8U));
                __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 1U;
                __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 = 8U;
                __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1 
                    = (0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                                 >> 2U));
            }
            if ((4U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb))) {
                __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 
                    = (0xffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata 
                                >> 0x10U));
                __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 1U;
                __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 = 0x10U;
                __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2 
                    = (0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                                 >> 2U));
            }
            if ((8U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb))) {
                __Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 
                    = (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata 
                       >> 0x18U);
                __Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 1U;
                __Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 = 0x18U;
                __Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3 
                    = (0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                                 >> 2U));
            }
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__ram_ready = 0U;
        }
        if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
              & (0x80000004U == vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr)) 
             & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready)))) {
            vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready = 1U;
            if ((0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb))) {
                vlSelf->tb_soc__DOT__sim_exit_req = 1U;
                vlSelf->tb_soc__DOT__sim_exit_code 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata;
            }
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready = 0U;
        }
    } else {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_firstword_reg = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__ram_ready = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready = 0U;
        vlSelf->tb_soc__DOT__sim_exit_req = 0U;
        vlSelf->tb_soc__DOT__sim_exit_code = 0U;
    }
    if (__Vdlyvset__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[__Vdlyvdim0__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0] 
            = __Vdlyvval__tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs__v0;
    }
    if (__Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0) {
        vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem[__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0))) 
                & vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem
                [__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0) 
                                   << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v0))));
    }
    if (__Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1) {
        vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem[__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1))) 
                & vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem
                [__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1) 
                                   << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v1))));
    }
    if (__Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2) {
        vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem[__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2))) 
                & vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem
                [__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2) 
                                   << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v2))));
    }
    if (__Vdlyvset__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3) {
        vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem[__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3))) 
                & vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem
                [__Vdlyvdim0__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3) 
                                   << (IData)(__Vdlyvlsb__tb_soc__DOT__dut__DOT__ram__DOT__mem__v3))));
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__last_mem_valid 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
                                                   & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready))));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_opcode;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs1;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next) {
        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_opcode;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs1;
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
                = ((3U == (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode))
                    ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode
                    : (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode));
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1;
        }
    }
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__5(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__5\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tb_soc__DOT__clk__v0) {
        vlSelf->tb_soc__DOT__clk = vlSelf->__Vdlyvval__tb_soc__DOT__clk__v0;
        vlSelf->__Vdlyvset__tb_soc__DOT__clk__v0 = 0U;
    }
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__7(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->tb_soc__DOT__gated_periph_edges = vlSelf->__Vdly__tb_soc__DOT__gated_periph_edges;
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_periph_sync 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_req__DOT__sync_ff1;
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_req__DOT__sync_ff1 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__8(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__8\n"); );
    // Body
    vlSelf->tb_soc__DOT__raw_periph_edges = vlSelf->__Vdly__tb_soc__DOT__raw_periph_edges;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__9(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__9\n"); );
    // Body
    if (vlSelf->tb_soc__DOT__resetn) {
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu = 0U;
        if ((2U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state))) {
            if ((1U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state))) {
                if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_cpu_sync)))) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = 0U;
                }
            } else {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu = 1U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PRDATA_cpu 
                    = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__rdata_hold;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state))) {
            if (vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_cpu_sync) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = 2U;
                vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu = 0U;
                if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold)))) {
                    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__rdata_hold 
                        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph;
                }
            }
        } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu) 
                    & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu)))) {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = 1U;
            vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__addr_hold 
                = vlSelf->tb_soc__DOT__dut__DOT__PADDR_cpu;
            vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__wdata_hold 
                = vlSelf->tb_soc__DOT__dut__DOT__PWDATA_cpu;
            vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold 
                = vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu;
            vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu = 1U;
        }
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready = 0U;
        if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state))) {
            if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
                  & ((0x10000000U <= vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr) 
                     & (0x10030000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr))) 
                 & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready)))) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = 1U;
                vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu = 1U;
                vlSelf->tb_soc__DOT__dut__DOT__PADDR_cpu 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PWRITE_cpu 
                    = (0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb));
                vlSelf->tb_soc__DOT__dut__DOT__PWDATA_cpu 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata;
            }
        } else if ((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state))) {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = 2U;
            vlSelf->tb_soc__DOT__dut__DOT__PENABLE_cpu = 1U;
        } else if ((2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state))) {
            if (vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__PENABLE_cpu = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready = 1U;
                if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu)))) {
                    vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata 
                        = vlSelf->tb_soc__DOT__dut__DOT__PRDATA_cpu;
                }
            }
        } else {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = 0U;
        }
    } else {
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__addr_hold = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__wdata_hold = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__rdata_hold = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PRDATA_cpu = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__PADDR_cpu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__PENABLE_cpu = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PWRITE_cpu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__PWDATA_cpu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state;
    vlSelf->tb_soc__DOT__dut__DOT__PRDATA_cpu = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PRDATA_cpu;
    vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state;
    vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu;
    vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PWRITE_cpu;
    vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__10(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__10\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph;
}

extern const VlUnpacked<VlWide<4>/*127:0*/, 256> Vtb_soc__ConstPool__TABLE_h5fec6d0a_0;

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__11(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__11\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh = 0;
    IData/*31:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = 0;
    CData/*0:0*/ __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = 0;
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_cpu_sync 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_ack__DOT__sync_ff1;
    if ((1U & (~ ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
                  | (IData)(vlSelf->tb_soc__DOT__trap))))) {
        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata;
        }
        if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read) 
             | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write))) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                = (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                    | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst))
                    ? (0xfffffffcU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc)
                    : (0xfffffffcU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1));
        }
    }
    if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
               | (IData)(vlSelf->tb_soc__DOT__trap)))) {
        if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__resetn)))) {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = 0U;
        }
        if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
                   | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready)))) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = 0U;
        }
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_secondword = 0U;
    } else {
        if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read) 
             | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write))) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb 
                = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb) 
                   & (- (IData)((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write))));
        }
        if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state))) {
            if ((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                  | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst)) 
                 | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata))) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = 1U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_instr 
                    = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                       | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst));
                vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = 1U;
            }
            if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = 1U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_instr = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = 2U;
            }
        } else if ((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state))) {
            if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_secondword = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state 
                    = (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
                        | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata))
                        ? 0U : 3U);
            }
        } else if ((2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state))) {
            if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = 0U;
            }
        } else if ((3U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state))) {
            if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = 0U;
            }
        }
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state;
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_ack__DOT__sync_ff1 
        = vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph;
    vlSelf->tb_soc__DOT__trap = 0U;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh = 0U;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rinst = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rdata = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_wdata = 0U;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val_valid = 0U;
    }
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
           & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger_q 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger;
    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = 0U;
    if (vlSelf->tb_soc__DOT__resetn) {
        if (((((((((0x80U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state)) 
                   | (0x40U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
                  | (0x20U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
                 | (0x10U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
                | (8U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
               | (4U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
              | (2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) 
             | (1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state)))) {
            if ((0x80U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                vlSelf->tb_soc__DOT__trap = 1U;
            } else if ((0x40U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                    = (1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger)) 
                             & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__do_waitirq))));
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh = 0U;
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_compr 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc;
                if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) {
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc 
                        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store)
                            ? (0xfffffffeU & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu)
                                               ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_q
                                               : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out))
                            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc);
                }
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch = 0U;
                if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger) {
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_delay 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_active;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc 
                        = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc 
                           + ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr)
                               ? 2U : 4U));
                    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 1U;
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc 
                               + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j);
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch = 1U;
                    } else {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 0U;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch 
                            = (1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr)) 
                                     & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr))));
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x20U;
                    }
                }
            } else if ((0x20U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 = 0U;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 = 0U;
                if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap) 
                     | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal))) {
                    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x80U;
                    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui)
                                ? 0U : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc);
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 8U;
                    } else {
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 1U;
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__timer;
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = 1U;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__timer 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    }
                } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
                            & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap)))) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = 1U;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 1U;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 1U;
                } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi) 
                            | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slli_srli_srai))) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = 1U;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slli_srli_srai)
                            ? (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2)
                            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm);
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 8U;
                } else {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = 1U;
                    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
                        = (0x1fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2);
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val_valid = 1U;
                    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 2U;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 1U;
                    } else {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 8U;
                    }
                }
            } else if ((0x10U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
                    = (0x1fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2);
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val 
                    = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2;
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val_valid = 1U;
                if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw) {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 2U;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 1U;
                } else {
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 8U;
                }
            } else if ((8U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                    = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc 
                       + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm);
                if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) {
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd = 0U;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0;
                    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                    }
                    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0) {
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rinst = 1U;
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = 0U;
                    }
                } else {
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 1U;
                    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu = 1U;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                }
            } else if ((4U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 1U;
                if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh))) {
                    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
                        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
                    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                } else if ((4U <= (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh))) {
                    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli) 
                         | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               << 4U);
                    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli) 
                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               >> 4U);
                    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai) 
                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = VL_SHIFTRS_III(32,32,32, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1, 4U);
                    }
                    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
                        = (0x1fU & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh) 
                                    - (IData)(4U)));
                } else {
                    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli) 
                         | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               << 1U);
                    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli) 
                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               >> 1U);
                    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai) 
                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = VL_SHIFTRS_III(32,32,32, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1, 1U);
                    }
                    __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
                        = (0x1fU & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh) 
                                    - (IData)(1U)));
                }
            } else if ((2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
                if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch)) 
                           | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done)))) {
                    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm);
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_wdata = 1U;
                        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 2U;
                        } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 1U;
                        } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 0U;
                        }
                    }
                    if (((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch)) 
                         & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = 1U;
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = 1U;
                    }
                }
            } else {
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 1U;
                if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch)) 
                           | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done)))) {
                    if (((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch)) 
                         & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done))) {
                        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu) {
                            __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word;
                        } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh) {
                            __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                                = VL_EXTENDS_II(32,16, 
                                                (0xffffU 
                                                 & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word));
                        } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb) {
                            __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
                                = VL_EXTENDS_II(32,8, 
                                                (0xffU 
                                                 & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word));
                        }
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = 1U;
                        __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = 1U;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
                    }
                    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata)))) {
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                               + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm);
                        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rdata = 1U;
                        if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb) 
                             | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu))) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 2U;
                        } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh) 
                                    | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu))) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 1U;
                        } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw) {
                            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = 0U;
                        }
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lbu_lhu_lw;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh;
                        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb 
                            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb;
                    }
                }
            }
        }
    } else {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__timer = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_delay = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x40U;
    }
    if (((IData)(vlSelf->tb_soc__DOT__resetn) & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata) 
                                                 | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)))) {
        if (((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize)) 
             & (0U != (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)))) {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x80U;
        }
        if (((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize)) 
             & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)) {
            vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x80U;
        }
    }
    if ((((IData)(vlSelf->tb_soc__DOT__resetn) & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst)) 
         & (0U != (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc)))) {
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = 0x80U;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
               | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done)))) {
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch = 0U;
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata = 0U;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rinst) {
        vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = 1U;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rdata) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata = 1U;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_wdata) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata = 1U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh 
        = __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1 
        = ((0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1))
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs
           [vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1]
            : 0U);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out 
        = __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_out;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__do_waitirq = 0U;
    __Vtableidx1 = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[0U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][0U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[1U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][1U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[2U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][2U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[3U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][3U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc 
        = (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) 
            & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store))
            ? (0xfffffffeU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out)
            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_q 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out;
    if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb = 0xfU;
    } else if ((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata 
            = ((vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                << 0x10U) | (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb 
            = ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)
                ? 0xcU : 3U);
    } else if ((2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata 
            = ((vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                << 0x18U) | ((0xff0000U & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                                           << 0x10U)) 
                             | ((0xff00U & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                                            << 8U)) 
                                | (0xffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb 
            = (0xfU & ((IData)(1U) << (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)));
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq 
        = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
           == vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts 
        = VL_LTS_III(32, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu 
        = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
           < vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lbu_lhu_lw 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata = 0U;
    if ((0x40U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state))) {
        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write = 1U;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata 
                = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc 
                   + ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_compr)
                       ? 2U : 4U));
        } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store) 
                    & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch)))) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write = 1U;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata 
                = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu)
                    ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_q
                    : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out);
        }
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rd;
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
         & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd 
            = (0x1fU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                        >> 7U));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2 
            = (0x1fU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                        >> 0x14U));
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2 
        = ((0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2))
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs
           [vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2]
            : 0U);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs2;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal_jalr_addi_add_sub 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc) 
              | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal) 
                 | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr) 
                    | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi) 
                       | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add) 
                          | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub)))))));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slti_blt_slt 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sltiu_bltu_sltu 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti) 
              | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt) 
                 | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu) 
                    | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu)))));
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger) 
         & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0x1000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0x4000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0x5000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0x6000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0x7000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
               & (0U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
               & (0x1000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
               & (0x2000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
               & (0x4000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
               & (0x5000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw) 
               & (0U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw) 
               & (0x1000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw) 
               & (0x2000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x2000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x3000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x4000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x6000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x7000U == (0x7000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x1000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x5000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & (0x40005000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slli_srli_srai 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
               & ((IData)((0x1000U == (0xfe007000U 
                                       & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))) 
                  | ((IData)((0x5000U == (0xfe007000U 
                                          & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))) 
                     | (IData)((0x40005000U == (0xfe007000U 
                                                & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr) 
               | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm) 
                  & ((0U == (7U & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                   >> 0xcU))) | ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                      >> 0xcU))) 
                                                 | ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                         >> 0xcU))) 
                                                    | ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                            >> 0xcU))) 
                                                       | ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                               >> 0xcU))) 
                                                          | (7U 
                                                             == 
                                                             (7U 
                                                              & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                                 >> 0xcU))))))))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal_jalr_addi_add_sub = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal)
                ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j
                : (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui) 
                    | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc))
                    ? (0xfffff000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)
                    : (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr) 
                        | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu) 
                           | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm)))
                        ? VL_EXTENDS_II(32,12, (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                >> 0x14U))
                        : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu)
                            ? VL_EXTENDS_II(32,13, 
                                            ((0x1000U 
                                              & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                 >> 0x13U)) 
                                             | ((0x800U 
                                                 & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                         >> 7U))))))
                            : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw)
                                ? VL_EXTENDS_II(32,12, 
                                                ((0xfe0U 
                                                  & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
                                                       >> 7U))))
                                : 0U)))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x40000000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x1000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x2000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x3000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x4000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x5000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x40005000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x6000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & (0x7000U == (0xfe007000U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sll_srl_sra 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg) 
               & ((IData)((0x1000U == (0xfe007000U 
                                       & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))) 
                  | ((IData)((0x5000U == (0xfe007000U 
                                          & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))) 
                     | (IData)((0x40005000U == (0xfe007000U 
                                                & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q))))));
    }
    if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
         & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm 
            = (0x13U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu 
            = (3U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw 
            = (0x23U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j 
            = ((0xfffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j) 
               | (0xfff00000U & VL_EXTENDS_II(32,21, 
                                              (0x1ffffeU 
                                               & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                                                  >> 0xbU)))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j 
            = ((0xfffff801U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j) 
               | (0x7feU & (VL_EXTENDS_II(32,21, (0x1ffffeU 
                                                  & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                                                     >> 0xbU))) 
                            >> 9U)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j 
            = ((0xfffff7ffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j) 
               | (0x800U & (VL_EXTENDS_II(32,21, (0x1ffffeU 
                                                  & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                                                     >> 0xbU))) 
                            << 2U)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j 
            = ((0xfff00fffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j) 
               | (0xff000U & (VL_EXTENDS_II(32,21, 
                                            (0x1ffffeU 
                                             & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                                                >> 0xbU))) 
                              << 0xbU)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j 
            = ((0xfffffffeU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j) 
               | (1U & VL_EXTENDS_II(1,21, (0x1ffffeU 
                                            & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
                                               >> 0xbU)))));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu 
            = (0x63U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc 
            = (0x17U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui 
            = (0x37U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal 
            = (0x6fU == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr 
            = (IData)((0x67U == (0x707fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle)));
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg 
            = (0x33U == (0x7fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle));
    }
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__resetn)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_active = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or = 0U;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_imm;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger 
        = __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger 
        = __Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn 
        = ((0x40U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state)) 
           & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger));
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out = 0U;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq;
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = (1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq)));
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = (1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts)));
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = (1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu)));
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slti_blt_slt) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts;
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sltiu_bltu_sltu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal_jalr_addi_add_sub) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub)
                ? (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                   - vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2)
                : (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                   + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2));
    } else if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0;
    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori) 
                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
               ^ vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori) 
                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
               | vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi) 
                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
               & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    } else if (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll) 
                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
               << (0x1fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2));
    } else if (((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl) 
                  | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli)) 
                 | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra)) 
                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out 
            = (IData)((0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, 
                                                       (((QData)((IData)(
                                                                         (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra) 
                                                                           | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai)) 
                                                                          & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                                                                             >> 0x1fU)))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1))), 
                                                       (0x1fU 
                                                        & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2))));
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap 
        = (1U & (~ ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui) 
                    | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc) 
                       | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal) 
                          | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr) 
                             | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq) 
                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne) 
                                   | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt) 
                                      | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge) 
                                         | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu) 
                                            | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu) 
                                               | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb) 
                                                  | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh) 
                                                     | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw) 
                                                        | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu) 
                                                           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu) 
                                                              | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb) 
                                                                 | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh) 
                                                                    | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw) 
                                                                       | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi) 
                                                                          | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti) 
                                                                             | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_getq) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_setq) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_maskirq) 
                                                                                | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_timer) 
                                                                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_waitirq))))))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0ULL;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c7569ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6175697063ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6a616cULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6a616c72ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x626571ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x626e65ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x626c74ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x626765ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x626c7475ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x62676575ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c62ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c68ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c77ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c6275ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6c6875ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x7362ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x7368ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x7377ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x61646469ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c7469ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c746975ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x786f7269ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6f7269ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x616e6469ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c6c69ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x73726c69ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x73726169ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x616464ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x737562ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c6cULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c74ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x736c7475ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x786f72ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x73726cULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x737261ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6f72ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x616e64ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x72646379636c65ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x72646379636c6568ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x7264696e737472ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x7264696e73747268ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x66656e6365ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_getq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x67657471ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_setq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x73657471ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x726574697271ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_maskirq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x6d61736b697271ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_waitirq) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x77616974697271ULL;
    }
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_timer) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = 0x74696d6572ULL;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_ascii_instr;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next) {
        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rd;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs2;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_imm;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_ascii_instr;
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr;
        }
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)));
}

VL_INLINE_OPT void Vtb_soc___024root___nba_comb__TOP__0(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__ram_ready) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__ram_ready)
            ? vlSelf->tb_soc__DOT__dut__DOT__ram_rdata
            : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready)
                ? vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata
                : 0U));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready) 
           & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid));
    if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata;
    } else if ((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        if ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)) {
            if ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
                    = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
                       >> 0x10U);
            }
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
                = (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata);
        }
    } else if ((2U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
            = ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)
                ? ((1U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)
                    ? (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
                       >> 0x18U) : (0xffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
                                             >> 0x10U)))
                : ((1U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)
                    ? (0xffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
                                >> 8U)) : (0xffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata)));
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer)
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata
            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q);
}

VL_INLINE_OPT void Vtb_soc___024root___nba_sequent__TOP__12(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_sequent__TOP__12\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph 
        = vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph;
}

VL_INLINE_OPT void Vtb_soc___024root___nba_comb__TOP__1(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   (~ (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)))) 
                                                   & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word_q;
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word)))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word = 0U;
    }
    if ((1U & (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) 
                | (0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_state))) 
               | (~ (IData)(vlSelf->tb_soc__DOT__resetn))))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word = 0U;
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   (~ (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)))) 
                                                   & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
                                                      | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                                                         | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata)))));
}

VL_INLINE_OPT void Vtb_soc___024root___nba_comb__TOP__2(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer) 
                                                    & ((0U 
                                                        != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)) 
                                                       & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0))) 
                                                   | ((3U 
                                                       == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)) 
                                                      & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst))));
}

VL_INLINE_OPT void Vtb_soc___024root___nba_comb__TOP__3(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___nba_comb__TOP__3\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw)))) {
        vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph) 
               | (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu));
    }
    vlSelf->tb_soc__DOT__dut__DOT__clk_periph = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw) 
                                                 & (IData)(vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch));
}

void Vtb_soc___024root___eval_nba(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__9(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__11(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x24ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x2cULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x18ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_soc___024root___nba_comb__TOP__3(vlSelf);
    }
}

void Vtb_soc___024root___eval_triggers__act(Vtb_soc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__act(Vtb_soc___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_soc___024root___timing_resume(Vtb_soc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__nba(Vtb_soc___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_soc___024root___eval(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval\n"); );
    // Init
    VlTriggerVec<6> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtb_soc___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtb_soc___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 12, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vtb_soc___024root___timing_resume(vlSelf);
                Vtb_soc___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtb_soc___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 12, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtb_soc___024root___eval_nba(vlSelf);
        }
    }
}

void Vtb_soc___024root___timing_resume(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___timing_resume\n"); );
    // Body
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

#ifdef VL_DEBUG
void Vtb_soc___024root___eval_debug_assertions(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
