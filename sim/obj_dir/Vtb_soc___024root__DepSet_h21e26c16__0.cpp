// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_soc.h for the primary calling header

#include "verilated.h"

#include "Vtb_soc__Syms.h"
#include "Vtb_soc__Syms.h"
#include "Vtb_soc___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_soc___024root___eval_initial__TOP__0(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_initial__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    VL_WRITEF("[TB] Starting Phase 4 simulation...\n");
    vlSelf->tb_soc__DOT__clk = 0U;
    vlSelf->tb_soc__DOT__resetn = 0U;
    vlSelf->tb_soc__DOT__sim_started = 0U;
    vlSelf->tb_soc__DOT__raw_periph_edges = 0U;
    vlSelf->tb_soc__DOT__gated_periph_edges = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x666f726dU;
    __Vtemp_1[2U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    co_await vlSelf->__VdlySched.delay(0x186a0ULL, 
                                       nullptr, "/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 
                                       67);
    vlSelf->tb_soc__DOT__resetn = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 
                                       69);
    vlSelf->tb_soc__DOT__sim_started = 1U;
    VL_WRITEF("[TB] Reset released. Core executing...\n");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__act(Vtb_soc___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_soc___024root___eval_triggers__act(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph_raw__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_soc__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__clk__0))));
    vlSelf->__VactTriggered.set(3U, (((IData)(vlSelf->tb_soc__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__resetn__0))));
    vlSelf->__VactTriggered.set(4U, (((IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph__0))) 
                                     | ((~ (IData)(vlSelf->tb_soc__DOT__resetn)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__resetn__0))));
    vlSelf->__VactTriggered.set(5U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph_raw__0 
        = vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph__0 
        = vlSelf->tb_soc__DOT__dut__DOT__clk_periph;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__clk__0 
        = vlSelf->tb_soc__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__resetn__0 
        = vlSelf->tb_soc__DOT__resetn;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_soc___024root___dump_triggers__act(vlSelf);
    }
#endif
}
