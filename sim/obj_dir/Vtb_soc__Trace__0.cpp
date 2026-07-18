// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_soc__Syms.h"


void Vtb_soc___024root__trace_chg_sub_0(Vtb_soc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_soc___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root__trace_chg_top_0\n"); );
    // Init
    Vtb_soc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_soc___024root*>(voidSelf);
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_soc___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_soc___024root__trace_chg_sub_0(Vtb_soc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_soc__DOT__gpio_out),32);
        bufp->chgBit(oldp+1,(vlSelf->tb_soc__DOT__timer_done));
        bufp->chgIData(oldp+2,(vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph),32);
        bufp->chgBit(oldp+3,(vlSelf->tb_soc__DOT__dut__DOT__PSEL_periph));
        bufp->chgBit(oldp+4,(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph));
        bufp->chgBit(oldp+5,(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph));
        bufp->chgIData(oldp+6,(vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph),32);
        bufp->chgIData(oldp+7,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart)
                                 ? vlSelf->tb_soc__DOT__dut__DOT__prdata_uart
                                 : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_gpio)
                                     ? vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio
                                     : ((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_timer)
                                         ? vlSelf->tb_soc__DOT__dut__DOT__prdata_timer
                                         : 0U)))),32);
        bufp->chgBit(oldp+8,((1U & ((~ (IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart)) 
                                    | (IData)(vlSelf->tb_soc__DOT__dut__DOT__pready_uart)))));
        bufp->chgBit(oldp+9,(vlSelf->tb_soc__DOT__dut__DOT__psel_uart));
        bufp->chgBit(oldp+10,(vlSelf->tb_soc__DOT__dut__DOT__psel_gpio));
        bufp->chgBit(oldp+11,(vlSelf->tb_soc__DOT__dut__DOT__psel_timer));
        bufp->chgIData(oldp+12,(vlSelf->tb_soc__DOT__dut__DOT__prdata_uart),32);
        bufp->chgBit(oldp+13,(vlSelf->tb_soc__DOT__dut__DOT__pready_uart));
        bufp->chgIData(oldp+14,(vlSelf->tb_soc__DOT__dut__DOT__prdata_gpio),32);
        bufp->chgIData(oldp+15,(vlSelf->tb_soc__DOT__dut__DOT__prdata_timer),32);
        bufp->chgCData(oldp+16,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__periph_state),2);
        bufp->chgCData(oldp+17,((0xffU & vlSelf->tb_soc__DOT__dut__DOT__PADDR_periph)),8);
        bufp->chgIData(oldp+18,(vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__load_val),32);
        bufp->chgIData(oldp+19,(vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__count),32);
        bufp->chgBit(oldp+20,(vlSelf->tb_soc__DOT__dut__DOT__timer_peripheral__DOT__running));
        bufp->chgCData(oldp+21,((0xffU & vlSelf->tb_soc__DOT__dut__DOT__PWDATA_periph)),8);
        bufp->chgBit(oldp+22,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__psel_uart) 
                               & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_periph) 
                                  & ((IData)(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_periph) 
                                     & (IData)(vlSelf->tb_soc__DOT__dut__DOT__pready_uart))))));
        bufp->chgCData(oldp+23,(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_data),8);
        bufp->chgBit(oldp+24,(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__rx_ready));
        bufp->chgBit(oldp+25,(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__tx_busy));
        bufp->chgCData(oldp+26,(vlSelf->tb_soc__DOT__dut__DOT__uart_peripheral__DOT__uart_inst__DOT__tx_reg),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+27,(vlSelf->tb_soc__DOT__sim_exit_req));
        bufp->chgIData(oldp+28,(vlSelf->tb_soc__DOT__sim_exit_code),32);
        bufp->chgIData(oldp+29,(vlSelf->tb_soc__DOT__dut__DOT__ram_rdata),32);
        bufp->chgBit(oldp+30,(vlSelf->tb_soc__DOT__dut__DOT__ram_ready));
        bufp->chgBit(oldp+31,(vlSelf->tb_soc__DOT__dut__DOT__sim_exit_ready));
        bufp->chgBit(oldp+32,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_valid));
        bufp->chgIData(oldp+33,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_insn),32);
        bufp->chgIData(oldp+34,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__eoi),32);
        bufp->chgBit(oldp+35,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_valid));
        bufp->chgQData(oldp+36,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__trace_data),36);
        bufp->chgQData(oldp+38,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_cycle),64);
        bufp->chgQData(oldp+40,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__count_instr),64);
        bufp->chgIData(oldp+42,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_insn_opcode),32);
        bufp->chgIData(oldp+43,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_opcode),32);
        bufp->chgIData(oldp+44,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_addr),32);
        bufp->chgIData(oldp+45,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_mask),32);
        bufp->chgIData(oldp+46,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_pending),32);
        bufp->chgIData(oldp+47,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[0]),32);
        bufp->chgIData(oldp+48,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[1]),32);
        bufp->chgIData(oldp+49,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[2]),32);
        bufp->chgIData(oldp+50,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[3]),32);
        bufp->chgIData(oldp+51,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[4]),32);
        bufp->chgIData(oldp+52,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[5]),32);
        bufp->chgIData(oldp+53,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[6]),32);
        bufp->chgIData(oldp+54,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[7]),32);
        bufp->chgIData(oldp+55,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[8]),32);
        bufp->chgIData(oldp+56,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[9]),32);
        bufp->chgIData(oldp+57,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[10]),32);
        bufp->chgIData(oldp+58,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[11]),32);
        bufp->chgIData(oldp+59,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[12]),32);
        bufp->chgIData(oldp+60,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[13]),32);
        bufp->chgIData(oldp+61,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[14]),32);
        bufp->chgIData(oldp+62,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[15]),32);
        bufp->chgIData(oldp+63,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[16]),32);
        bufp->chgIData(oldp+64,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[17]),32);
        bufp->chgIData(oldp+65,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[18]),32);
        bufp->chgIData(oldp+66,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[19]),32);
        bufp->chgIData(oldp+67,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[20]),32);
        bufp->chgIData(oldp+68,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[21]),32);
        bufp->chgIData(oldp+69,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[22]),32);
        bufp->chgIData(oldp+70,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[23]),32);
        bufp->chgIData(oldp+71,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[24]),32);
        bufp->chgIData(oldp+72,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[25]),32);
        bufp->chgIData(oldp+73,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[26]),32);
        bufp->chgIData(oldp+74,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[27]),32);
        bufp->chgIData(oldp+75,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[28]),32);
        bufp->chgIData(oldp+76,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[29]),32);
        bufp->chgIData(oldp+77,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[30]),32);
        bufp->chgIData(oldp+78,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs[31]),32);
        bufp->chgBit(oldp+79,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_firstword_reg));
        bufp->chgBit(oldp+80,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__last_mem_valid));
        bufp->chgBit(oldp+81,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__prefetched_high_word));
        bufp->chgBit(oldp+82,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle));
        bufp->chgBit(oldp+83,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh));
        bufp->chgBit(oldp+84,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr));
        bufp->chgBit(oldp+85,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh));
        bufp->chgBit(oldp+86,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ecall_ebreak));
        bufp->chgBit(oldp+87,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_fence));
        bufp->chgBit(oldp+88,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_getq));
        bufp->chgBit(oldp+89,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_setq));
        bufp->chgBit(oldp+90,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_maskirq));
        bufp->chgBit(oldp+91,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_waitirq));
        bufp->chgBit(oldp+92,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_timer));
        bufp->chgCData(oldp+93,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs1),5);
        bufp->chgBit(oldp+94,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger_q));
        bufp->chgBit(oldp+95,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycle) 
                               | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdcycleh) 
                                  | ((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstr) 
                                     | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_rdinstrh))))));
        bufp->chgCData(oldp+96,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs1),5);
        bufp->chgQData(oldp+97,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_ascii_instr),64);
        bufp->chgIData(oldp+99,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_imm),32);
        bufp->chgIData(oldp+100,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_opcode),32);
        bufp->chgCData(oldp+101,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs1),5);
        bufp->chgCData(oldp+102,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rs2),5);
        bufp->chgCData(oldp+103,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__q_insn_rd),5);
        bufp->chgBit(oldp+104,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_next));
        bufp->chgBit(oldp+105,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_valid_insn));
        bufp->chgQData(oldp+106,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_ascii_instr),64);
        bufp->chgIData(oldp+108,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_imm),32);
        bufp->chgIData(oldp+109,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_opcode),32);
        bufp->chgCData(oldp+110,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs1),5);
        bufp->chgCData(oldp+111,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rs2),5);
        bufp->chgCData(oldp+112,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cached_insn_rd),5);
        bufp->chgCData(oldp+113,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_state),2);
        bufp->chgBit(oldp+114,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_trace));
        bufp->chgBit(oldp+115,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__pcpi_timeout));
        bufp->chgIData(oldp+116,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_irq_pending),32);
        bufp->chgBit(oldp+117,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0_q));
        bufp->chgBit(oldp+118,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait));
        bufp->chgBit(oldp+119,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_wait_2));
        bufp->chgBit(oldp+120,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word_q));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+121,(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_rdata),32);
        bufp->chgBit(oldp+122,(vlSelf->tb_soc__DOT__dut__DOT__apb_bridge_ready));
        bufp->chgIData(oldp+123,(vlSelf->tb_soc__DOT__dut__DOT__PADDR_cpu),32);
        bufp->chgBit(oldp+124,(vlSelf->tb_soc__DOT__dut__DOT__PSEL_cpu));
        bufp->chgBit(oldp+125,(vlSelf->tb_soc__DOT__dut__DOT__PENABLE_cpu));
        bufp->chgBit(oldp+126,(vlSelf->tb_soc__DOT__dut__DOT__PWRITE_cpu));
        bufp->chgIData(oldp+127,(vlSelf->tb_soc__DOT__dut__DOT__PWDATA_cpu),32);
        bufp->chgIData(oldp+128,(vlSelf->tb_soc__DOT__dut__DOT__PRDATA_cpu),32);
        bufp->chgBit(oldp+129,(vlSelf->tb_soc__DOT__dut__DOT__PREADY_cpu));
        bufp->chgCData(oldp+130,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__cpu_state),2);
        bufp->chgBit(oldp+131,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu));
        bufp->chgIData(oldp+132,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__addr_hold),32);
        bufp->chgIData(oldp+133,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__wdata_hold),32);
        bufp->chgBit(oldp+134,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__write_hold));
        bufp->chgIData(oldp+135,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__rdata_hold),32);
        bufp->chgCData(oldp+136,(vlSelf->tb_soc__DOT__dut__DOT__apb_master__DOT__state),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+137,(vlSelf->tb_soc__DOT__trap));
        bufp->chgBit(oldp+138,(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid));
        bufp->chgIData(oldp+139,(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr),32);
        bufp->chgIData(oldp+140,(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wdata),32);
        bufp->chgCData(oldp+141,(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_wstrb),4);
        bufp->chgBit(oldp+142,((0x4000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr)));
        bufp->chgBit(oldp+143,(((0x10000000U <= vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr) 
                                & (0x10030000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr))));
        bufp->chgBit(oldp+144,((0x80000004U == vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr)));
        bufp->chgBit(oldp+145,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
                                & (0x4000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr))));
        bufp->chgBit(oldp+146,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_valid) 
                                & ((0x10000000U <= vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr) 
                                   & (0x10030000U > vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr)))));
        bufp->chgBit(oldp+147,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_cpu_sync));
        bufp->chgBit(oldp+148,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_ack__DOT__sync_ff1));
        bufp->chgBit(oldp+149,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_instr));
        bufp->chgIData(oldp+150,((((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                                   | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst))
                                   ? (0xfffffffcU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc)
                                   : (0xfffffffcU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1))),32);
        bufp->chgIData(oldp+151,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wdata),32);
        bufp->chgCData(oldp+152,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_wstrb),4);
        bufp->chgIData(oldp+153,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1),32);
        bufp->chgIData(oldp+154,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2),32);
        bufp->chgIData(oldp+155,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_pc),32);
        bufp->chgIData(oldp+156,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_next_pc),32);
        bufp->chgIData(oldp+157,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_out),32);
        bufp->chgCData(oldp+158,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_sh),5);
        bufp->chgIData(oldp+159,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__next_pc),32);
        bufp->chgBit(oldp+160,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_delay));
        bufp->chgBit(oldp+161,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__irq_active));
        bufp->chgIData(oldp+162,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__timer),32);
        bufp->chgCData(oldp+163,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_state),2);
        bufp->chgCData(oldp+164,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_wordsize),2);
        bufp->chgIData(oldp+165,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_q),32);
        bufp->chgBit(oldp+166,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch));
        bufp->chgBit(oldp+167,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rinst));
        bufp->chgBit(oldp+168,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_rdata));
        bufp->chgBit(oldp+169,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_wdata));
        bufp->chgBit(oldp+170,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_secondword));
        bufp->chgBit(oldp+171,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_do_prefetch) 
                                | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT____VdfgTmp_hb06275b1__0))));
        bufp->chgBit(oldp+172,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lui));
        bufp->chgBit(oldp+173,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_auipc));
        bufp->chgBit(oldp+174,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jal));
        bufp->chgBit(oldp+175,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_jalr));
        bufp->chgBit(oldp+176,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_beq));
        bufp->chgBit(oldp+177,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bne));
        bufp->chgBit(oldp+178,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_blt));
        bufp->chgBit(oldp+179,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bge));
        bufp->chgBit(oldp+180,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bltu));
        bufp->chgBit(oldp+181,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_bgeu));
        bufp->chgBit(oldp+182,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lb));
        bufp->chgBit(oldp+183,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lh));
        bufp->chgBit(oldp+184,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lw));
        bufp->chgBit(oldp+185,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lbu));
        bufp->chgBit(oldp+186,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_lhu));
        bufp->chgBit(oldp+187,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sb));
        bufp->chgBit(oldp+188,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sh));
        bufp->chgBit(oldp+189,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sw));
        bufp->chgBit(oldp+190,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_addi));
        bufp->chgBit(oldp+191,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slti));
        bufp->chgBit(oldp+192,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltiu));
        bufp->chgBit(oldp+193,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xori));
        bufp->chgBit(oldp+194,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_ori));
        bufp->chgBit(oldp+195,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_andi));
        bufp->chgBit(oldp+196,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slli));
        bufp->chgBit(oldp+197,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srli));
        bufp->chgBit(oldp+198,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai));
        bufp->chgBit(oldp+199,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_add));
        bufp->chgBit(oldp+200,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub));
        bufp->chgBit(oldp+201,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sll));
        bufp->chgBit(oldp+202,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_slt));
        bufp->chgBit(oldp+203,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sltu));
        bufp->chgBit(oldp+204,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_xor));
        bufp->chgBit(oldp+205,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srl));
        bufp->chgBit(oldp+206,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra));
        bufp->chgBit(oldp+207,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_or));
        bufp->chgBit(oldp+208,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_and));
        bufp->chgBit(oldp+209,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__compressed_instr));
        bufp->chgBit(oldp+210,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_trap));
        bufp->chgCData(oldp+211,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rd),5);
        bufp->chgCData(oldp+212,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_rs2),5);
        bufp->chgIData(oldp+213,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm),32);
        bufp->chgIData(oldp+214,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoded_imm_j),32);
        bufp->chgBit(oldp+215,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger));
        bufp->chgBit(oldp+216,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_trigger_q));
        bufp->chgBit(oldp+217,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__decoder_pseudo_trigger));
        bufp->chgBit(oldp+218,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal));
        bufp->chgBit(oldp+219,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lb_lh_lw_lbu_lhu));
        bufp->chgBit(oldp+220,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slli_srli_srai));
        bufp->chgBit(oldp+221,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi));
        bufp->chgBit(oldp+222,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sb_sh_sw));
        bufp->chgBit(oldp+223,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sll_srl_sra));
        bufp->chgBit(oldp+224,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lui_auipc_jal_jalr_addi_add_sub));
        bufp->chgBit(oldp+225,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_slti_blt_slt));
        bufp->chgBit(oldp+226,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_sltiu_bltu_sltu));
        bufp->chgBit(oldp+227,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_beq_bne_blt_bge_bltu_bgeu));
        bufp->chgBit(oldp+228,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_lbu_lhu_lw));
        bufp->chgBit(oldp+229,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_imm));
        bufp->chgBit(oldp+230,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_alu_reg_reg));
        bufp->chgBit(oldp+231,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__is_compare));
        bufp->chgQData(oldp+232,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__new_ascii_instr),64);
        bufp->chgQData(oldp+234,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_instr),64);
        bufp->chgIData(oldp+236,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_imm),32);
        bufp->chgCData(oldp+237,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rs2),5);
        bufp->chgCData(oldp+238,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_insn_rd),5);
        bufp->chgIData(oldp+239,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val),32);
        bufp->chgIData(oldp+240,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val),32);
        bufp->chgBit(oldp+241,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs1val_valid));
        bufp->chgBit(oldp+242,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_rs2val_valid));
        bufp->chgBit(oldp+243,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__launch_next_insn));
        bufp->chgCData(oldp+244,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpu_state),8);
        bufp->chgWData(oldp+245,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_ascii_state),128);
        bufp->chgBit(oldp+249,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rinst));
        bufp->chgBit(oldp+250,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_rdata));
        bufp->chgBit(oldp+251,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__set_mem_do_wdata));
        bufp->chgBit(oldp+252,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_store));
        bufp->chgBit(oldp+253,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_stalu));
        bufp->chgBit(oldp+254,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_branch));
        bufp->chgBit(oldp+255,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_compr));
        bufp->chgBit(oldp+256,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lu));
        bufp->chgBit(oldp+257,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lh));
        bufp->chgBit(oldp+258,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_is_lb));
        bufp->chgCData(oldp+259,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__latched_rd),5);
        bufp->chgIData(oldp+260,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__current_pc),32);
        bufp->chgBit(oldp+261,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__do_waitirq));
        bufp->chgIData(oldp+262,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out),32);
        bufp->chgIData(oldp+263,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_q),32);
        bufp->chgBit(oldp+264,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_out_0));
        bufp->chgIData(oldp+265,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sub)
                                   ? (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                                      - vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2)
                                   : (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                                      + vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2))),32);
        bufp->chgIData(oldp+266,((vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                                  << (0x1fU & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2))),32);
        bufp->chgIData(oldp+267,((IData)((0x1ffffffffULL 
                                          & VL_SHIFTRS_QQI(33,33,5, 
                                                           (((QData)((IData)(
                                                                             (((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_sra) 
                                                                               | (IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__instr_srai)) 
                                                                              & (vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1 
                                                                                >> 0x1fU)))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op1))), 
                                                           (0x1fU 
                                                            & vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__reg_op2))))),32);
        bufp->chgBit(oldp+268,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_eq));
        bufp->chgBit(oldp+269,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_ltu));
        bufp->chgBit(oldp+270,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__alu_lts));
        bufp->chgBit(oldp+271,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_write));
        bufp->chgIData(oldp+272,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_wrdata),32);
        bufp->chgIData(oldp+273,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs1),32);
        bufp->chgIData(oldp+274,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__cpuregs_rs2),32);
        bufp->chgIData(oldp+275,((0xfffU & (vlSelf->tb_soc__DOT__dut__DOT__cpu_mem_addr 
                                            >> 2U))),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+276,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_ready));
        bufp->chgIData(oldp+277,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__dbg_mem_rdata),32);
        bufp->chgIData(oldp+278,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_word),32);
        bufp->chgBit(oldp+279,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_xfer));
        bufp->chgIData(oldp+280,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_rdata_latched_noshuffle),32);
    }
    bufp->chgBit(oldp+281,(vlSelf->tb_soc__DOT__clk));
    bufp->chgBit(oldp+282,(vlSelf->tb_soc__DOT__resetn));
    bufp->chgBit(oldp+283,(vlSelf->tb_soc__DOT__sim_started));
    bufp->chgIData(oldp+284,(vlSelf->tb_soc__DOT__raw_periph_edges),32);
    bufp->chgIData(oldp+285,(vlSelf->tb_soc__DOT__gated_periph_edges),32);
    bufp->chgBit(oldp+286,(vlSelf->tb_soc__DOT__dut__DOT__clk_periph_raw));
    bufp->chgBit(oldp+287,(((IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph) 
                            | (IData)(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_cpu))));
    bufp->chgBit(oldp+288,(vlSelf->tb_soc__DOT__dut__DOT__clk_periph));
    bufp->chgBit(oldp+289,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__ack_periph));
    bufp->chgIData(oldp+290,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__PRDATA_from_periph),32);
    bufp->chgBit(oldp+291,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__req_periph_sync));
    bufp->chgBit(oldp+292,(vlSelf->tb_soc__DOT__dut__DOT__apb_cdc__DOT__sync_req__DOT__sync_ff1));
    bufp->chgBit(oldp+293,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_read));
    bufp->chgBit(oldp+294,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_la_write));
    bufp->chgBit(oldp+295,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__clear_prefetched_high_word));
    bufp->chgBit(oldp+296,(vlSelf->tb_soc__DOT__dut__DOT__cpu__DOT__mem_done));
    bufp->chgBit(oldp+297,((1U & (~ (IData)(vlSelf->tb_soc__DOT__resetn)))));
    bufp->chgCData(oldp+298,(vlSelf->tb_soc__DOT__dut__DOT__periph_clk_div__DOT__counter),2);
    bufp->chgBit(oldp+299,(vlSelf->tb_soc__DOT__dut__DOT__periph_icg__DOT__en_latch));
}

void Vtb_soc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_soc___024root__trace_cleanup\n"); );
    // Init
    Vtb_soc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_soc___024root*>(voidSelf);
    Vtb_soc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
