// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_soc.h for the primary calling header

#include "verilated.h"

#include "Vtb_soc__Syms.h"
#include "Vtb_soc___024root.h"

VL_ATTR_COLD void Vtb_soc___024root___eval_static(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_soc___024root___eval_initial__TOP(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x77617265U;
    __Vtemp_1[2U] = 0x6669726dU;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_soc___024root___eval_final(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_soc___024root___eval_triggers__stl(Vtb_soc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__stl(Vtb_soc___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___eval_stl(Vtb_soc___024root* vlSelf);

VL_ATTR_COLD void Vtb_soc___024root___eval_settle(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtb_soc___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtb_soc___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/lab-user/Desktop/microriv-soc/tb/tb_soc.v", 12, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtb_soc___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__stl(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<VlWide<4>/*127:0*/, 256> Vtb_soc__ConstPool__TABLE_h5fec6d0a_0;

VL_ATTR_COLD void Vtb_soc___024root___stl_sequent__TOP__0(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1 
        = ((0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1))
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs
           [vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1]
            : 0U);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2 
        = ((0U != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2))
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs
           [vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2]
            : 0U);
    vlSelf->tb_soc__DOT__dut__DOT__psel_uart = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                & (0U 
                                                   == 
                                                   (0xf0000U 
                                                    & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn 
        = ((0x40U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state)) 
           & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write = 0U;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write 
        = ((IData)(vlSelf->tb_soc__DOT__resetn) & (
                                                   (~ (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state)))) 
                                                   & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)));
    __Vtableidx1 = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[0U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][0U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[1U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][1U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[2U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][2U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state[3U] 
        = Vtb_soc__ConstPool__TABLE_h5fec6d0a_0[__Vtableidx1][3U];
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc 
        = (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch) 
            & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store))
            ? (0xfffffffeU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out)
            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_imm;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_opcode;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs1;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs2;
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rd;
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
    if ((1U & (~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw)))) {
        vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch 
            = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph) 
               | (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu));
    }
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
    vlSelf->tb_soc__DOT__dut__DOT__psel_gpio = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                & (0x10000U 
                                                   == 
                                                   (0xf0000U 
                                                    & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata)));
    vlSelf->tb_soc__DOT__dut__DOT__psel_timer = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph) 
                                                 & (0x20000U 
                                                    == 
                                                    (0xf0000U 
                                                     & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__ram_ready)
            ? vlSelf->tb_soc__DOT__dut__DOT__ram_rdata
            : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready)
                ? vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata
                : 0U));
    if ((0U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb = 0xfU;
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
            = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata;
    } else if ((1U == (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize))) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata 
            = ((vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 
                << 0x10U) | (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2));
        if ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb = 0xcU;
            if ((2U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1)) {
                vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
                    = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata 
                       >> 0x10U);
            }
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb = 3U;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word 
                = (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata);
        }
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
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__ram_ready) 
           | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready) 
              | (IData)(vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready)));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq 
        = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
           == vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts 
        = VL_LTS_III(32, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu 
        = (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
           < vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2);
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
    vlSelf->tb_soc__DOT__dut__DOT__clk_periph = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw) 
                                                 & (IData)(vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch));
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
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready) 
           & (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid));
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 = 0U;
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
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out = 0U;
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
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
        = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_ascii_instr;
    if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next) {
        if (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q) {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_imm;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_opcode;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs1;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs2;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rd;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_ascii_instr;
        } else {
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode 
                = ((3U == (3U & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode))
                    ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode
                    : (0xffffU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode));
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd;
            vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr 
                = vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr;
        }
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle 
        = ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer)
            ? vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata
            : vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q);
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

VL_ATTR_COLD void Vtb_soc___024root___eval_stl(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_soc___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__act(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_soc.dut.clk_periph_raw)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_soc.dut.clk_periph)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_soc.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tb_soc.clk or negedge tb_soc.resetn)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge tb_soc.dut.clk_periph or negedge tb_soc.resetn)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_soc___024root___dump_triggers__nba(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_soc.dut.clk_periph_raw)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_soc.dut.clk_periph)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_soc.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tb_soc.clk or negedge tb_soc.resetn)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge tb_soc.dut.clk_periph or negedge tb_soc.resetn)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_soc___024root___ctor_var_reset(Vtb_soc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_soc__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__resetn = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__trap = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__sim_exit_req = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__sim_exit_code = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__gpio_out = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__timer_done = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__sim_started = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__raw_periph_edges = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__gated_periph_edges = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__clk_periph = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_soc__DOT__dut__DOT__ram_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__ram_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PADDR_cpu = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PENABLE_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PWDATA_cpu = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__PRDATA_cpu = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__psel_uart = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__psel_gpio = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__psel_timer = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__prdata_uart = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__pready_uart = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__prdata_timer = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_insn = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_rd = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__eoi = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_data = VL_RAND_RESET_Q(36);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_cycle = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2 = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_delay = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_active = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_mask = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_pending = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__timer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_secondword = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_firstword_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__last_mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_16bit_buffer = VL_RAND_RESET_I(16);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ecall_ebreak = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_getq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_setq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_maskirq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_waitirq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_timer = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger_q = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slli_srli_srai = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sll_srl_sra = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal_jalr_addi_add_sub = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slti_blt_slt = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sltiu_bltu_sltu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lbu_lhu_lw = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_valid_insn = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_ascii_instr = VL_RAND_RESET_Q(64);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_opcode = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = VL_RAND_RESET_I(8);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_state = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rinst = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rdata = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_wdata = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_compr = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_trace = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_timeout_counter = VL_RAND_RESET_I(4);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_timeout = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_irq_pending = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__do_waitirq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_q = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0_q = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word_q = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1 = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2 = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_soc__DOT__dut__DOT__ram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__addr_hold = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__wdata_hold = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__rdata_hold = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state = VL_RAND_RESET_I(2);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_periph_sync = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_cpu_sync = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_req__DOT__sync_ff1 = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_ack__DOT__sync_ff1 = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__uart_inst__DOT__tx_reg = VL_RAND_RESET_I(8);
    vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count = VL_RAND_RESET_I(32);
    vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvval__tb_soc__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__tb_soc__DOT__clk__v0 = 0;
    vlSelf->__Vdly__tb_soc__DOT__raw_periph_edges = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_soc__DOT__gated_periph_edges = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_bridge_ready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_master__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PWRITE_cpu = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PREADY_cpu = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__PRDATA_cpu = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph_raw__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__dut__DOT__clk_periph__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_soc__DOT__resetn__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
