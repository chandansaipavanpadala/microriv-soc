// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_soc.h for the primary calling header

#include "verilated.h"

#include "Vtb_soc__Syms.h"
#include "Vtb_soc__Syms.h"
#include "Vtb_soc___024root.h"

void Vtb_soc___024root___ctor_var_reset(Vtb_soc___024root* vlSelf);

Vtb_soc___024root::Vtb_soc___024root(Vtb_soc__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_soc___024root___ctor_var_reset(this);
}

void Vtb_soc___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_soc___024root::~Vtb_soc___024root() {
}
