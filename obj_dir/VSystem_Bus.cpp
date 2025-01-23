// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSystem_Bus.h for the primary calling header

#include "VSystem_Bus.h"
#include "VSystem_Bus__Syms.h"

//==========

void VSystem_Bus::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSystem_Bus::eval\n"); );
    VSystem_Bus__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("System_Bus.v", 711, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSystem_Bus::_eval_initial_loop(VSystem_Bus__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("System_Bus.v", 711, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VSystem_Bus::_sequent__TOP__2(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_sequent__TOP__2\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__System_Bus__DOT__M1__DOT__countreg;
    CData/*1:0*/ __Vdly__System_Bus__DOT__M1__DOT__stateReg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__M1__DOT__request_reg;
    CData/*7:0*/ __Vdly__System_Bus__DOT__M1__DOT__wdata_reg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__M1__DOT__valid_reg;
    CData/*2:0*/ __Vdly__System_Bus__DOT__M1__DOT__order_index;
    CData/*3:0*/ __Vdly__System_Bus__DOT__M2__DOT__countreg;
    CData/*1:0*/ __Vdly__System_Bus__DOT__M2__DOT__stateReg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__M2__DOT__request_reg;
    CData/*7:0*/ __Vdly__System_Bus__DOT__M2__DOT__wdata_reg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__M2__DOT__valid_reg;
    CData/*2:0*/ __Vdly__System_Bus__DOT__M2__DOT__order_index;
    CData/*3:0*/ __Vdly__System_Bus__DOT__S1__DOT__countreg;
    CData/*1:0*/ __Vdly__System_Bus__DOT__S1__DOT__stateReg;
    CData/*7:0*/ __Vdlyvval__System_Bus__DOT__S1__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__System_Bus__DOT__S1__DOT__mem__v0;
    CData/*3:0*/ __Vdly__System_Bus__DOT__S2__DOT__countreg;
    CData/*1:0*/ __Vdly__System_Bus__DOT__S2__DOT__stateReg;
    CData/*7:0*/ __Vdlyvval__System_Bus__DOT__S2__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__System_Bus__DOT__S2__DOT__mem__v0;
    CData/*3:0*/ __Vdly__System_Bus__DOT__S3__DOT__countreg;
    CData/*2:0*/ __Vdly__System_Bus__DOT__S3__DOT__stateReg;
    CData/*7:0*/ __Vdlyvval__System_Bus__DOT__S3__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__System_Bus__DOT__S3__DOT__mem__v0;
    CData/*0:0*/ __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg;
    CData/*0:0*/ __Vdly__System_Bus__DOT__arbiter__DOT__split_remember;
    CData/*3:0*/ __Vdly__System_Bus__DOT__arbiter__DOT__timer;
    CData/*2:0*/ __Vdly__System_Bus__DOT__arbiter__DOT__stateReg;
    SData/*10:0*/ __Vdlyvdim0__System_Bus__DOT__S1__DOT__mem__v0;
    SData/*11:0*/ __Vdlyvdim0__System_Bus__DOT__S2__DOT__mem__v0;
    SData/*11:0*/ __Vdlyvdim0__System_Bus__DOT__S3__DOT__mem__v0;
    // Body
    __Vdly__System_Bus__DOT__M1__DOT__countreg = vlTOPp->System_Bus__DOT__M1__DOT__countreg;
    __Vdly__System_Bus__DOT__M2__DOT__countreg = vlTOPp->System_Bus__DOT__M2__DOT__countreg;
    __Vdly__System_Bus__DOT__S1__DOT__stateReg = vlTOPp->System_Bus__DOT__S1__DOT__stateReg;
    __Vdly__System_Bus__DOT__S1__DOT__countreg = vlTOPp->System_Bus__DOT__S1__DOT__countreg;
    __Vdly__System_Bus__DOT__S2__DOT__stateReg = vlTOPp->System_Bus__DOT__S2__DOT__stateReg;
    __Vdly__System_Bus__DOT__S2__DOT__countreg = vlTOPp->System_Bus__DOT__S2__DOT__countreg;
    __Vdly__System_Bus__DOT__S3__DOT__stateReg = vlTOPp->System_Bus__DOT__S3__DOT__stateReg;
    __Vdly__System_Bus__DOT__S3__DOT__countreg = vlTOPp->System_Bus__DOT__S3__DOT__countreg;
    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg 
        = vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg;
    __Vdly__System_Bus__DOT__arbiter__DOT__timer = vlTOPp->System_Bus__DOT__arbiter__DOT__timer;
    __Vdly__System_Bus__DOT__arbiter__DOT__split_remember 
        = vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember;
    __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg 
        = vlTOPp->System_Bus__DOT__arbiter__DOT__split_grant_reg;
    __Vdlyvset__System_Bus__DOT__S1__DOT__mem__v0 = 0U;
    __Vdlyvset__System_Bus__DOT__S2__DOT__mem__v0 = 0U;
    __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg 
        = vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg;
    __Vdlyvset__System_Bus__DOT__S3__DOT__mem__v0 = 0U;
    __Vdly__System_Bus__DOT__M1__DOT__valid_reg = vlTOPp->System_Bus__DOT__M1__DOT__valid_reg;
    __Vdly__System_Bus__DOT__M1__DOT__wdata_reg = vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg;
    __Vdly__System_Bus__DOT__M1__DOT__request_reg = vlTOPp->System_Bus__DOT__M1__DOT__request_reg;
    __Vdly__System_Bus__DOT__M1__DOT__stateReg = vlTOPp->System_Bus__DOT__M1__DOT__stateReg;
    __Vdly__System_Bus__DOT__M2__DOT__valid_reg = vlTOPp->System_Bus__DOT__M2__DOT__valid_reg;
    __Vdly__System_Bus__DOT__M2__DOT__wdata_reg = vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg;
    __Vdly__System_Bus__DOT__M2__DOT__request_reg = vlTOPp->System_Bus__DOT__M2__DOT__request_reg;
    __Vdly__System_Bus__DOT__M2__DOT__stateReg = vlTOPp->System_Bus__DOT__M2__DOT__stateReg;
    __Vdly__System_Bus__DOT__M1__DOT__order_index = vlTOPp->System_Bus__DOT__M1__DOT__order_index;
    __Vdly__System_Bus__DOT__M2__DOT__order_index = vlTOPp->System_Bus__DOT__M2__DOT__order_index;
    if (vlTOPp->reset) {
        __Vdly__System_Bus__DOT__M1__DOT__countreg = 0U;
        __Vdly__System_Bus__DOT__M2__DOT__countreg = 0U;
    } else {
        __Vdly__System_Bus__DOT__M1__DOT__countreg 
            = ((0xfU == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__countreg))
                ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M1__DOT__countreg))));
        __Vdly__System_Bus__DOT__M2__DOT__countreg 
            = ((0xfU == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__countreg))
                ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M2__DOT__countreg))));
    }
    if (vlTOPp->System_Bus__DOT__S1__DOT__control_reg) {
        __Vdlyvval__System_Bus__DOT__S1__DOT__mem__v0 
            = vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg;
        __Vdlyvset__System_Bus__DOT__S1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__System_Bus__DOT__S1__DOT__mem__v0 
            = (0x7ffU & (IData)(vlTOPp->System_Bus__DOT__S1__DOT__addr_reg));
    }
    if (vlTOPp->System_Bus__DOT__S2__DOT__control_reg) {
        __Vdlyvval__System_Bus__DOT__S2__DOT__mem__v0 
            = vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg;
        __Vdlyvset__System_Bus__DOT__S2__DOT__mem__v0 = 1U;
        __Vdlyvdim0__System_Bus__DOT__S2__DOT__mem__v0 
            = (0xfffU & (IData)(vlTOPp->System_Bus__DOT__S2__DOT__addr_reg));
    }
    if (vlTOPp->System_Bus__DOT__S3__DOT__control_reg) {
        __Vdlyvval__System_Bus__DOT__S3__DOT__mem__v0 
            = vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg;
        __Vdlyvset__System_Bus__DOT__S3__DOT__mem__v0 = 1U;
        __Vdlyvdim0__System_Bus__DOT__S3__DOT__mem__v0 
            = (0xfffU & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__addr_reg));
    }
    if (vlTOPp->reset) {
        __Vdly__System_Bus__DOT__M1__DOT__stateReg = 0U;
        __Vdly__System_Bus__DOT__M1__DOT__request_reg = 0U;
        vlTOPp->System_Bus__DOT__M1__DOT__address_reg = 0U;
        __Vdly__System_Bus__DOT__M1__DOT__wdata_reg = 0U;
        __Vdly__System_Bus__DOT__M1__DOT__valid_reg = 0U;
        __Vdly__System_Bus__DOT__M1__DOT__order_index = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__stateReg))) {
            if (((2U == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__countreg)) 
                 | (0xdU == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__countreg)))) {
                __Vdly__System_Bus__DOT__M1__DOT__stateReg = 1U;
                __Vdly__System_Bus__DOT__M1__DOT__request_reg = 1U;
            } else {
                __Vdly__System_Bus__DOT__M1__DOT__stateReg = 0U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__stateReg))) {
                if (vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg) {
                    __Vdly__System_Bus__DOT__M1__DOT__wdata_reg 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg)));
                    vlTOPp->System_Bus__DOT__M1__DOT__address_reg 
                        = vlTOPp->System_Bus__DOT__M1__DOT__addr
                        [vlTOPp->System_Bus__DOT__M1__DOT__order_index];
                    __Vdly__System_Bus__DOT__M1__DOT__valid_reg = 1U;
                    __Vdly__System_Bus__DOT__M1__DOT__stateReg = 2U;
                } else {
                    __Vdly__System_Bus__DOT__M1__DOT__stateReg = 1U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__M1__DOT__stateReg))) {
                    if ((((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                        >> 0xcU))) ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__done_reg)
                           : ((1U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                            >> 0xcU)))
                               ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__done_reg)
                               : ((2U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU))) 
                                  & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__done_reg)))) 
                         & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg))) {
                        __Vdly__System_Bus__DOT__M1__DOT__order_index 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M1__DOT__order_index)));
                        __Vdly__System_Bus__DOT__M1__DOT__stateReg = 0U;
                        __Vdly__System_Bus__DOT__M1__DOT__wdata_reg 
                            = ((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                             >> 0xcU)))
                                ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg)
                                : ((1U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                 >> 0xcU)))
                                    ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg)
                                    : ((2U == (3U & 
                                               ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU)))
                                        ? (IData)(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg)
                                        : 0U)));
                        __Vdly__System_Bus__DOT__M1__DOT__request_reg = 0U;
                        __Vdly__System_Bus__DOT__M1__DOT__valid_reg = 0U;
                    } else {
                        __Vdly__System_Bus__DOT__M1__DOT__stateReg = 2U;
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__System_Bus__DOT__M2__DOT__stateReg = 0U;
        __Vdly__System_Bus__DOT__M2__DOT__request_reg = 0U;
        vlTOPp->System_Bus__DOT__M2__DOT__address_reg = 0U;
        __Vdly__System_Bus__DOT__M2__DOT__wdata_reg = 0U;
        __Vdly__System_Bus__DOT__M2__DOT__valid_reg = 0U;
        __Vdly__System_Bus__DOT__M2__DOT__order_index = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__stateReg))) {
            if (((2U == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__countreg)) 
                 | (0xdU == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__countreg)))) {
                __Vdly__System_Bus__DOT__M2__DOT__stateReg = 1U;
                __Vdly__System_Bus__DOT__M2__DOT__request_reg = 1U;
            } else {
                __Vdly__System_Bus__DOT__M2__DOT__stateReg = 0U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__stateReg))) {
                if (vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg) {
                    __Vdly__System_Bus__DOT__M2__DOT__wdata_reg 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg)));
                    vlTOPp->System_Bus__DOT__M2__DOT__address_reg 
                        = vlTOPp->System_Bus__DOT__M2__DOT__addr
                        [vlTOPp->System_Bus__DOT__M2__DOT__order_index];
                    __Vdly__System_Bus__DOT__M2__DOT__valid_reg = 1U;
                    __Vdly__System_Bus__DOT__M2__DOT__stateReg = 2U;
                } else {
                    __Vdly__System_Bus__DOT__M2__DOT__stateReg = 1U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__M2__DOT__stateReg))) {
                    if ((((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                        >> 0xcU))) ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__done_reg)
                           : ((1U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                            >> 0xcU)))
                               ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__done_reg)
                               : ((2U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU))) 
                                  & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__done_reg)))) 
                         & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg))) {
                        __Vdly__System_Bus__DOT__M2__DOT__order_index 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__M2__DOT__order_index)));
                        __Vdly__System_Bus__DOT__M2__DOT__stateReg = 0U;
                        __Vdly__System_Bus__DOT__M2__DOT__wdata_reg 
                            = ((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                             >> 0xcU)))
                                ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg)
                                : ((1U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                 >> 0xcU)))
                                    ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg)
                                    : ((2U == (3U & 
                                               ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU)))
                                        ? (IData)(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg)
                                        : 0U)));
                        __Vdly__System_Bus__DOT__M2__DOT__request_reg = 0U;
                        __Vdly__System_Bus__DOT__M2__DOT__valid_reg = 0U;
                    } else {
                        __Vdly__System_Bus__DOT__M2__DOT__stateReg = 2U;
                    }
                }
            }
        }
    }
    vlTOPp->System_Bus__DOT__M1__DOT__stateReg = __Vdly__System_Bus__DOT__M1__DOT__stateReg;
    vlTOPp->System_Bus__DOT__M1__DOT__countreg = __Vdly__System_Bus__DOT__M1__DOT__countreg;
    vlTOPp->System_Bus__DOT__M1__DOT__order_index = __Vdly__System_Bus__DOT__M1__DOT__order_index;
    vlTOPp->System_Bus__DOT__M2__DOT__stateReg = __Vdly__System_Bus__DOT__M2__DOT__stateReg;
    vlTOPp->System_Bus__DOT__M2__DOT__countreg = __Vdly__System_Bus__DOT__M2__DOT__countreg;
    vlTOPp->System_Bus__DOT__M2__DOT__order_index = __Vdly__System_Bus__DOT__M2__DOT__order_index;
    if ((1U & (~ (IData)(vlTOPp->System_Bus__DOT__S1__DOT__control_reg)))) {
        vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg 
            = vlTOPp->System_Bus__DOT__S1__DOT__mem
            [(0x7ffU & (IData)(vlTOPp->System_Bus__DOT__S1__DOT__addr_reg))];
    }
    if ((1U & (~ (IData)(vlTOPp->System_Bus__DOT__S2__DOT__control_reg)))) {
        vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg 
            = vlTOPp->System_Bus__DOT__S2__DOT__mem
            [(0xfffU & (IData)(vlTOPp->System_Bus__DOT__S2__DOT__addr_reg))];
    }
    if ((1U & (~ (IData)(vlTOPp->System_Bus__DOT__S3__DOT__control_reg)))) {
        vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg 
            = vlTOPp->System_Bus__DOT__S3__DOT__mem
            [(0xfffU & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__addr_reg))];
    }
    if (vlTOPp->reset) {
        vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
        vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
        __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 0U;
        __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg = 0U;
        __Vdly__System_Bus__DOT__arbiter__DOT__split_remember = 0U;
        __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg))) {
            if (vlTOPp->System_Bus__DOT__M1__DOT__request_reg) {
                __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 1U;
                vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 0U;
            } else {
                if (vlTOPp->System_Bus__DOT__M2__DOT__request_reg) {
                    __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 1U;
                    __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 1U;
                } else {
                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 0U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                    __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg))) {
                if (vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg) {
                    __Vdly__System_Bus__DOT__arbiter__DOT__split_remember = 1U;
                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 1U;
                    __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 1U;
                    __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                } else {
                    if (((IData)(vlTOPp->System_Bus__DOT__M1__DOT__request_reg) 
                         & (~ (((((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                  >> 3U) & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                            >> 2U)) 
                                & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                   >> 1U)) & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer))))) {
                        __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                        __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                        __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg = 0U;
                    } else {
                        if (((~ (IData)(vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg)) 
                             & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember))) {
                            __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                            __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                        } else {
                            if (vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg) {
                                __Vdly__System_Bus__DOT__arbiter__DOT__split_remember = 0U;
                                __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg = 1U;
                                __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                                vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                                vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 1U;
                                __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 1U;
                                __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                            } else {
                                if (vlTOPp->System_Bus__DOT__M2__DOT__request_reg) {
                                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 1U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 1U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                                } else {
                                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 0U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg))) {
                    if (vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg) {
                        __Vdly__System_Bus__DOT__arbiter__DOT__split_remember = 1U;
                        __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 1U;
                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                        __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 0U;
                        __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                    } else {
                        if (((IData)(vlTOPp->System_Bus__DOT__M2__DOT__request_reg) 
                             & (~ (((((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                      >> 3U) & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                                >> 2U)) 
                                    & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer) 
                                       >> 1U)) & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer))))) {
                            __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                            __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                            __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg = 0U;
                        } else {
                            if (((~ (IData)(vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg)) 
                                 & (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember))) {
                                __Vdly__System_Bus__DOT__arbiter__DOT__timer 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__timer)));
                                __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 2U;
                            } else {
                                if (vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg) {
                                    __Vdly__System_Bus__DOT__arbiter__DOT__split_remember = 0U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg = 1U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 1U;
                                    vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 0U;
                                    __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                                } else {
                                    if (vlTOPp->System_Bus__DOT__M1__DOT__request_reg) {
                                        __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 1U;
                                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 1U;
                                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                                        __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg = 0U;
                                        __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                                    } else {
                                        __Vdly__System_Bus__DOT__arbiter__DOT__stateReg = 0U;
                                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg = 0U;
                                        vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg = 0U;
                                        __Vdly__System_Bus__DOT__arbiter__DOT__timer = 0U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__System_Bus__DOT__S1__DOT__mem__v0) {
        vlTOPp->System_Bus__DOT__S1__DOT__mem[__Vdlyvdim0__System_Bus__DOT__S1__DOT__mem__v0] 
            = __Vdlyvval__System_Bus__DOT__S1__DOT__mem__v0;
    }
    if (__Vdlyvset__System_Bus__DOT__S2__DOT__mem__v0) {
        vlTOPp->System_Bus__DOT__S2__DOT__mem[__Vdlyvdim0__System_Bus__DOT__S2__DOT__mem__v0] 
            = __Vdlyvval__System_Bus__DOT__S2__DOT__mem__v0;
    }
    if (__Vdlyvset__System_Bus__DOT__S3__DOT__mem__v0) {
        vlTOPp->System_Bus__DOT__S3__DOT__mem[__Vdlyvdim0__System_Bus__DOT__S3__DOT__mem__v0] 
            = __Vdlyvval__System_Bus__DOT__S3__DOT__mem__v0;
    }
    vlTOPp->System_Bus__DOT__M1__DOT__request_reg = __Vdly__System_Bus__DOT__M1__DOT__request_reg;
    vlTOPp->System_Bus__DOT__M2__DOT__request_reg = __Vdly__System_Bus__DOT__M2__DOT__request_reg;
    vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember 
        = __Vdly__System_Bus__DOT__arbiter__DOT__split_remember;
    vlTOPp->System_Bus__DOT__arbiter__DOT__timer = __Vdly__System_Bus__DOT__arbiter__DOT__timer;
    vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg 
        = __Vdly__System_Bus__DOT__arbiter__DOT__stateReg;
    if (vlTOPp->reset) {
        vlTOPp->System_Bus__DOT__S1__DOT__done_reg = 0U;
        vlTOPp->System_Bus__DOT__S1__DOT__addr_reg = 0U;
        vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg = 0U;
        vlTOPp->System_Bus__DOT__S1__DOT__control_reg = 0U;
        __Vdly__System_Bus__DOT__S1__DOT__countreg = 0U;
        __Vdly__System_Bus__DOT__S1__DOT__stateReg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__S1__DOT__stateReg))) {
            if (((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__S1_io_addr) 
                               >> 0xcU))) & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                              ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg)
                                              : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg)))) {
                __Vdly__System_Bus__DOT__S1__DOT__stateReg = 1U;
                vlTOPp->System_Bus__DOT__S1__DOT__addr_reg 
                    = vlTOPp->System_Bus__DOT__S1_io_addr;
                if (vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg) {
                    vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S1__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M2_control;
                } else {
                    vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S1__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M1_control;
                }
                __Vdly__System_Bus__DOT__S1__DOT__countreg = 1U;
            } else {
                __Vdly__System_Bus__DOT__S1__DOT__stateReg = 0U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__S1__DOT__stateReg))) {
                if ((3U == (IData)(vlTOPp->System_Bus__DOT__S1__DOT__countreg))) {
                    __Vdly__System_Bus__DOT__S1__DOT__stateReg = 2U;
                    vlTOPp->System_Bus__DOT__S1__DOT__done_reg = 1U;
                } else {
                    __Vdly__System_Bus__DOT__S1__DOT__countreg 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__S1__DOT__countreg)));
                    __Vdly__System_Bus__DOT__S1__DOT__stateReg = 1U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__S1__DOT__stateReg))) {
                    __Vdly__System_Bus__DOT__S1__DOT__stateReg = 0U;
                    vlTOPp->System_Bus__DOT__S1__DOT__done_reg = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->System_Bus__DOT__S2__DOT__done_reg = 0U;
        vlTOPp->System_Bus__DOT__S2__DOT__addr_reg = 0U;
        vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg = 0U;
        vlTOPp->System_Bus__DOT__S2__DOT__control_reg = 0U;
        __Vdly__System_Bus__DOT__S2__DOT__countreg = 0U;
        __Vdly__System_Bus__DOT__S2__DOT__stateReg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__S2__DOT__stateReg))) {
            if (((1U == (3U & ((IData)(vlTOPp->System_Bus__DOT__S2_io_addr) 
                               >> 0xcU))) & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                              ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg)
                                              : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg)))) {
                __Vdly__System_Bus__DOT__S2__DOT__stateReg = 1U;
                vlTOPp->System_Bus__DOT__S2__DOT__addr_reg 
                    = vlTOPp->System_Bus__DOT__S2_io_addr;
                if (vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg) {
                    vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S2__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M2_control;
                } else {
                    vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S2__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M1_control;
                }
                __Vdly__System_Bus__DOT__S2__DOT__countreg = 1U;
            } else {
                __Vdly__System_Bus__DOT__S2__DOT__stateReg = 0U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__S2__DOT__stateReg))) {
                if ((3U == (IData)(vlTOPp->System_Bus__DOT__S2__DOT__countreg))) {
                    __Vdly__System_Bus__DOT__S2__DOT__stateReg = 2U;
                    vlTOPp->System_Bus__DOT__S2__DOT__done_reg = 1U;
                } else {
                    __Vdly__System_Bus__DOT__S2__DOT__countreg 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__S2__DOT__countreg)));
                    __Vdly__System_Bus__DOT__S2__DOT__stateReg = 1U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__S2__DOT__stateReg))) {
                    __Vdly__System_Bus__DOT__S2__DOT__stateReg = 0U;
                    vlTOPp->System_Bus__DOT__S2__DOT__done_reg = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->System_Bus__DOT__S3__DOT__done_reg = 0U;
        vlTOPp->System_Bus__DOT__S3__DOT__addr_reg = 0U;
        vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg = 0U;
        vlTOPp->System_Bus__DOT__S3__DOT__control_reg = 0U;
        __Vdly__System_Bus__DOT__S3__DOT__countreg = 0U;
        vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg = 0U;
        __Vdly__System_Bus__DOT__S3__DOT__stateReg = 0U;
        vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__stateReg))) {
            if (((2U == (3U & ((IData)(vlTOPp->System_Bus__DOT__S3_io_addr) 
                               >> 0xcU))) & ((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                              ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg)
                                              : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg)))) {
                vlTOPp->System_Bus__DOT__S3__DOT__addr_reg 
                    = vlTOPp->System_Bus__DOT__S3_io_addr;
                if (vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg) {
                    vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S3__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M2_control;
                } else {
                    vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg 
                        = vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg;
                    vlTOPp->System_Bus__DOT__S3__DOT__control_reg 
                        = vlTOPp->System_Bus__DOT__M1_control;
                }
                __Vdly__System_Bus__DOT__S3__DOT__countreg = 1U;
                if (vlTOPp->System_Bus__DOT__S3__DOT__split_reg) {
                    __Vdly__System_Bus__DOT__S3__DOT__stateReg = 3U;
                    vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg = 1U;
                } else {
                    __Vdly__System_Bus__DOT__S3__DOT__stateReg = 1U;
                }
            } else {
                __Vdly__System_Bus__DOT__S3__DOT__stateReg = 0U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__stateReg))) {
                if ((3U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__countreg))) {
                    if (vlTOPp->System_Bus__DOT__S3__DOT__split_reg) {
                        __Vdly__System_Bus__DOT__S3__DOT__stateReg = 4U;
                        vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg = 1U;
                    } else {
                        __Vdly__System_Bus__DOT__S3__DOT__stateReg = 2U;
                        vlTOPp->System_Bus__DOT__S3__DOT__done_reg = 1U;
                    }
                } else {
                    __Vdly__System_Bus__DOT__S3__DOT__countreg 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->System_Bus__DOT__S3__DOT__countreg)));
                    __Vdly__System_Bus__DOT__S3__DOT__stateReg = 1U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__stateReg))) {
                    __Vdly__System_Bus__DOT__S3__DOT__stateReg = 0U;
                    vlTOPp->System_Bus__DOT__S3__DOT__done_reg = 0U;
                } else {
                    if ((3U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__stateReg))) {
                        vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg = 0U;
                        __Vdly__System_Bus__DOT__S3__DOT__stateReg = 1U;
                    } else {
                        if ((4U == (IData)(vlTOPp->System_Bus__DOT__S3__DOT__stateReg))) {
                            if (vlTOPp->System_Bus__DOT__arbiter__DOT__split_grant_reg) {
                                __Vdly__System_Bus__DOT__S3__DOT__stateReg = 2U;
                                vlTOPp->System_Bus__DOT__S3__DOT__done_reg = 1U;
                                vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg = 0U;
                            } else {
                                __Vdly__System_Bus__DOT__S3__DOT__stateReg = 4U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->System_Bus__DOT__S1__DOT__countreg = __Vdly__System_Bus__DOT__S1__DOT__countreg;
    vlTOPp->System_Bus__DOT__S1__DOT__stateReg = __Vdly__System_Bus__DOT__S1__DOT__stateReg;
    vlTOPp->System_Bus__DOT__S2__DOT__countreg = __Vdly__System_Bus__DOT__S2__DOT__countreg;
    vlTOPp->System_Bus__DOT__S2__DOT__stateReg = __Vdly__System_Bus__DOT__S2__DOT__stateReg;
    vlTOPp->System_Bus__DOT__arbiter__DOT__split_grant_reg 
        = __Vdly__System_Bus__DOT__arbiter__DOT__split_grant_reg;
    vlTOPp->System_Bus__DOT__S3__DOT__countreg = __Vdly__System_Bus__DOT__S3__DOT__countreg;
    vlTOPp->System_Bus__DOT__S3__DOT__stateReg = __Vdly__System_Bus__DOT__S3__DOT__stateReg;
    vlTOPp->System_Bus__DOT__M2__DOT__valid_reg = __Vdly__System_Bus__DOT__M2__DOT__valid_reg;
    vlTOPp->System_Bus__DOT__M1__DOT__valid_reg = __Vdly__System_Bus__DOT__M1__DOT__valid_reg;
    vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg = __Vdly__System_Bus__DOT__M2__DOT__wdata_reg;
    vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg = __Vdly__System_Bus__DOT__M1__DOT__wdata_reg;
    vlTOPp->System_Bus__DOT__M2_control = vlTOPp->System_Bus__DOT__M2__DOT__rwreg
        [vlTOPp->System_Bus__DOT__M2__DOT__order_index];
    vlTOPp->System_Bus__DOT__M1_control = vlTOPp->System_Bus__DOT__M1__DOT__rwreg
        [vlTOPp->System_Bus__DOT__M1__DOT__order_index];
    vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg 
        = __Vdly__System_Bus__DOT__arbiter__DOT__masterSelReg;
    if (vlTOPp->reset) {
        vlTOPp->System_Bus__DOT__S3__DOT__split_reg = 0U;
    }
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
}

void VSystem_Bus::_eval(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_eval\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VSystem_Bus::_change_request(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_change_request\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VSystem_Bus::_change_request_1(VSystem_Bus__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_change_request_1\n"); );
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSystem_Bus::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSystem_Bus::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
