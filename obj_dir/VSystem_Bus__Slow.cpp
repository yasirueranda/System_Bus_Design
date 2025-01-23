// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSystem_Bus.h for the primary calling header

#include "VSystem_Bus.h"
#include "VSystem_Bus__Syms.h"

//==========

VL_CTOR_IMP(VSystem_Bus) {
    VSystem_Bus__Syms* __restrict vlSymsp = __VlSymsp = new VSystem_Bus__Syms(this, name());
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VSystem_Bus::__Vconfigure(VSystem_Bus__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VSystem_Bus::~VSystem_Bus() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VSystem_Bus::_initial__TOP__1(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_initial__TOP__1\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[0U] = 0U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[1U] = 1U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[2U] = 0U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[3U] = 1U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[4U] = 0U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[5U] = 1U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[6U] = 0U;
    vlTOPp->System_Bus__DOT__M1__DOT__rwreg[7U] = 1U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[0U] = 0U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[1U] = 1U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[2U] = 0U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[3U] = 1U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[4U] = 0U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[5U] = 1U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[6U] = 0U;
    vlTOPp->System_Bus__DOT__M2__DOT__rwreg[7U] = 1U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[0U] = 0x2001U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[1U] = 0x2001U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[2U] = 1U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[3U] = 0x1009U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[4U] = 2U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[5U] = 0x100aU;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[6U] = 3U;
    vlTOPp->System_Bus__DOT__M1__DOT__addr[7U] = 0x100bU;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[0U] = 0x1000U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[1U] = 8U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[2U] = 0x1001U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[3U] = 9U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[4U] = 0x1002U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[5U] = 0xaU;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[6U] = 0x1003U;
    vlTOPp->System_Bus__DOT__M2__DOT__addr[7U] = 0xbU;
    vlTOPp->System_Bus__DOT__M1__DOT__order_index = 0U;
    vlTOPp->System_Bus__DOT__M2__DOT__order_index = 0U;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[0U] = 0xa5U;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[1U] = 0x5aU;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[2U] = 0xffU;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[3U] = 0U;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[4U] = 0xc3U;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[5U] = 0x3cU;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[6U] = 0x12U;
    vlTOPp->System_Bus__DOT__S1__DOT__mem[7U] = 0x34U;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[0U] = 0x1aU;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[1U] = 0xb7U;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[2U] = 0x3eU;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[3U] = 0x9cU;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[4U] = 0x4fU;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[5U] = 0xe2U;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[6U] = 0x7dU;
    vlTOPp->System_Bus__DOT__S2__DOT__mem[7U] = 8U;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[0U] = 0x9eU;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[1U] = 0x29U;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[2U] = 0x47U;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[3U] = 0x6bU;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[4U] = 0xd1U;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[5U] = 0x8fU;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[6U] = 0x5cU;
    vlTOPp->System_Bus__DOT__S3__DOT__mem[7U] = 0x3aU;
}

void VSystem_Bus::_settle__TOP__3(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_settle__TOP__3\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg) {
        vlTOPp->System_Bus__DOT__addr = vlTOPp->System_Bus__DOT__M2__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S1_io_addr = vlTOPp->System_Bus__DOT__M2__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S2_io_addr = vlTOPp->System_Bus__DOT__M2__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S3_io_addr = vlTOPp->System_Bus__DOT__M2__DOT__address_reg;
    } else {
        vlTOPp->System_Bus__DOT__addr = vlTOPp->System_Bus__DOT__M1__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S1_io_addr = vlTOPp->System_Bus__DOT__M1__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S2_io_addr = vlTOPp->System_Bus__DOT__M1__DOT__address_reg;
        vlTOPp->System_Bus__DOT__S3_io_addr = vlTOPp->System_Bus__DOT__M1__DOT__address_reg;
    }
    vlTOPp->System_Bus__DOT__M1_control = vlTOPp->System_Bus__DOT__M1__DOT__rwreg
        [vlTOPp->System_Bus__DOT__M1__DOT__order_index];
    vlTOPp->System_Bus__DOT__M2_control = vlTOPp->System_Bus__DOT__M2__DOT__rwreg
        [vlTOPp->System_Bus__DOT__M2__DOT__order_index];
}

void VSystem_Bus::_eval_initial(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_eval_initial\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VSystem_Bus::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::final\n"); );
    // Variables
    VSystem_Bus__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSystem_Bus::_eval_settle(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_eval_settle\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VSystem_Bus::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    System_Bus__DOT__M1_control = VL_RAND_RESET_I(1);
    System_Bus__DOT__M2_control = VL_RAND_RESET_I(1);
    System_Bus__DOT__S1_io_addr = VL_RAND_RESET_I(14);
    System_Bus__DOT__S2_io_addr = VL_RAND_RESET_I(14);
    System_Bus__DOT__S3_io_addr = VL_RAND_RESET_I(14);
    System_Bus__DOT__addr = VL_RAND_RESET_I(14);
    System_Bus__DOT__M1__DOT__request_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__M1__DOT__address_reg = VL_RAND_RESET_I(14);
    System_Bus__DOT__M1__DOT__wdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__M1__DOT__valid_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__M1__DOT__countreg = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            System_Bus__DOT__M1__DOT__addr[__Vi0] = VL_RAND_RESET_I(14);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            System_Bus__DOT__M1__DOT__rwreg[__Vi0] = VL_RAND_RESET_I(1);
    }}
    System_Bus__DOT__M1__DOT__order_index = VL_RAND_RESET_I(3);
    System_Bus__DOT__M1__DOT__stateReg = VL_RAND_RESET_I(2);
    System_Bus__DOT__M2__DOT__request_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__M2__DOT__address_reg = VL_RAND_RESET_I(14);
    System_Bus__DOT__M2__DOT__wdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__M2__DOT__valid_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__M2__DOT__countreg = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            System_Bus__DOT__M2__DOT__addr[__Vi0] = VL_RAND_RESET_I(14);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            System_Bus__DOT__M2__DOT__rwreg[__Vi0] = VL_RAND_RESET_I(1);
    }}
    System_Bus__DOT__M2__DOT__order_index = VL_RAND_RESET_I(3);
    System_Bus__DOT__M2__DOT__stateReg = VL_RAND_RESET_I(2);
    System_Bus__DOT__S1__DOT__rdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S1__DOT__done_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S1__DOT__addr_reg = VL_RAND_RESET_I(14);
    System_Bus__DOT__S1__DOT__wdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S1__DOT__control_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S1__DOT__countreg = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
            System_Bus__DOT__S1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    System_Bus__DOT__S1__DOT__stateReg = VL_RAND_RESET_I(2);
    System_Bus__DOT__S2__DOT__rdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S2__DOT__done_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S2__DOT__addr_reg = VL_RAND_RESET_I(14);
    System_Bus__DOT__S2__DOT__wdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S2__DOT__control_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S2__DOT__countreg = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            System_Bus__DOT__S2__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    System_Bus__DOT__S2__DOT__stateReg = VL_RAND_RESET_I(2);
    System_Bus__DOT__S3__DOT__rdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S3__DOT__done_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S3__DOT__arb_req_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S3__DOT__split_req_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S3__DOT__addr_reg = VL_RAND_RESET_I(14);
    System_Bus__DOT__S3__DOT__wdata_reg = VL_RAND_RESET_I(8);
    System_Bus__DOT__S3__DOT__control_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__S3__DOT__countreg = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            System_Bus__DOT__S3__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    System_Bus__DOT__S3__DOT__stateReg = VL_RAND_RESET_I(3);
    System_Bus__DOT__S3__DOT__split_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__grant0Reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__grant1Reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__masterSelReg = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__split_grant_reg = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__timer = VL_RAND_RESET_I(4);
    System_Bus__DOT__arbiter__DOT__split_remember = VL_RAND_RESET_I(1);
    System_Bus__DOT__arbiter__DOT__stateReg = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
