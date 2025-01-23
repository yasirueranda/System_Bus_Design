// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSystem_Bus__Syms.h"


void VSystem_Bus::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VSystem_Bus::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgSData(oldp+0,(vlTOPp->System_Bus__DOT__M1__DOT__addr[0]),14);
            tracep->chgSData(oldp+1,(vlTOPp->System_Bus__DOT__M1__DOT__addr[1]),14);
            tracep->chgSData(oldp+2,(vlTOPp->System_Bus__DOT__M1__DOT__addr[2]),14);
            tracep->chgSData(oldp+3,(vlTOPp->System_Bus__DOT__M1__DOT__addr[3]),14);
            tracep->chgSData(oldp+4,(vlTOPp->System_Bus__DOT__M1__DOT__addr[4]),14);
            tracep->chgSData(oldp+5,(vlTOPp->System_Bus__DOT__M1__DOT__addr[5]),14);
            tracep->chgSData(oldp+6,(vlTOPp->System_Bus__DOT__M1__DOT__addr[6]),14);
            tracep->chgSData(oldp+7,(vlTOPp->System_Bus__DOT__M1__DOT__addr[7]),14);
            tracep->chgBit(oldp+8,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[0]));
            tracep->chgBit(oldp+9,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[1]));
            tracep->chgBit(oldp+10,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[2]));
            tracep->chgBit(oldp+11,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[3]));
            tracep->chgBit(oldp+12,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[4]));
            tracep->chgBit(oldp+13,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[5]));
            tracep->chgBit(oldp+14,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[6]));
            tracep->chgBit(oldp+15,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[7]));
            tracep->chgSData(oldp+16,(vlTOPp->System_Bus__DOT__M2__DOT__addr[0]),14);
            tracep->chgSData(oldp+17,(vlTOPp->System_Bus__DOT__M2__DOT__addr[1]),14);
            tracep->chgSData(oldp+18,(vlTOPp->System_Bus__DOT__M2__DOT__addr[2]),14);
            tracep->chgSData(oldp+19,(vlTOPp->System_Bus__DOT__M2__DOT__addr[3]),14);
            tracep->chgSData(oldp+20,(vlTOPp->System_Bus__DOT__M2__DOT__addr[4]),14);
            tracep->chgSData(oldp+21,(vlTOPp->System_Bus__DOT__M2__DOT__addr[5]),14);
            tracep->chgSData(oldp+22,(vlTOPp->System_Bus__DOT__M2__DOT__addr[6]),14);
            tracep->chgSData(oldp+23,(vlTOPp->System_Bus__DOT__M2__DOT__addr[7]),14);
            tracep->chgBit(oldp+24,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[0]));
            tracep->chgBit(oldp+25,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[1]));
            tracep->chgBit(oldp+26,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[2]));
            tracep->chgBit(oldp+27,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[3]));
            tracep->chgBit(oldp+28,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[4]));
            tracep->chgBit(oldp+29,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[5]));
            tracep->chgBit(oldp+30,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[6]));
            tracep->chgBit(oldp+31,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[7]));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+32,(vlTOPp->System_Bus__DOT__M1__DOT__request_reg));
            tracep->chgBit(oldp+33,(vlTOPp->System_Bus__DOT__M1_control));
            tracep->chgSData(oldp+34,(vlTOPp->System_Bus__DOT__M1__DOT__address_reg),14);
            tracep->chgBit(oldp+35,(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg));
            tracep->chgCData(oldp+36,(vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg),8);
            tracep->chgCData(oldp+37,(((0U == (3U & 
                                               ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU)))
                                        ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg)
                                        : ((1U == (3U 
                                                   & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                      >> 0xcU)))
                                            ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg)
                                            : ((2U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                    >> 0xcU)))
                                                ? (IData)(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg)
                                                : 0U)))),8);
            tracep->chgBit(oldp+38,(((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                   >> 0xcU)))
                                      ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__done_reg)
                                      : ((1U == (3U 
                                                 & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                    >> 0xcU)))
                                          ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__done_reg)
                                          : ((2U == 
                                              (3U & 
                                               ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU))) 
                                             & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__done_reg))))));
            tracep->chgBit(oldp+39,(vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg));
            tracep->chgBit(oldp+40,(vlTOPp->System_Bus__DOT__M2__DOT__request_reg));
            tracep->chgBit(oldp+41,(vlTOPp->System_Bus__DOT__M2_control));
            tracep->chgSData(oldp+42,(vlTOPp->System_Bus__DOT__M2__DOT__address_reg),14);
            tracep->chgBit(oldp+43,(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg));
            tracep->chgCData(oldp+44,(vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg),8);
            tracep->chgBit(oldp+45,(vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg));
            tracep->chgSData(oldp+46,(vlTOPp->System_Bus__DOT__S1_io_addr),14);
            tracep->chgCData(oldp+47,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                        ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg)
                                        : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg))),8);
            tracep->chgBit(oldp+48,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                      ? (IData)(vlTOPp->System_Bus__DOT__M2_control)
                                      : (IData)(vlTOPp->System_Bus__DOT__M1_control))));
            tracep->chgBit(oldp+49,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                      ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg)
                                      : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg))));
            tracep->chgCData(oldp+50,(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg),8);
            tracep->chgBit(oldp+51,(vlTOPp->System_Bus__DOT__S1__DOT__done_reg));
            tracep->chgSData(oldp+52,(vlTOPp->System_Bus__DOT__S2_io_addr),14);
            tracep->chgCData(oldp+53,(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg),8);
            tracep->chgBit(oldp+54,(vlTOPp->System_Bus__DOT__S2__DOT__done_reg));
            tracep->chgSData(oldp+55,(vlTOPp->System_Bus__DOT__S3_io_addr),14);
            tracep->chgCData(oldp+56,(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg),8);
            tracep->chgBit(oldp+57,(vlTOPp->System_Bus__DOT__S3__DOT__done_reg));
            tracep->chgBit(oldp+58,(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg));
            tracep->chgSData(oldp+59,(vlTOPp->System_Bus__DOT__addr),14);
            tracep->chgBit(oldp+60,(vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg));
            tracep->chgBit(oldp+61,(vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg));
            tracep->chgBit(oldp+62,(vlTOPp->System_Bus__DOT__arbiter__DOT__split_grant_reg));
            tracep->chgCData(oldp+63,(vlTOPp->System_Bus__DOT__M1__DOT__countreg),4);
            tracep->chgCData(oldp+64,(vlTOPp->System_Bus__DOT__M1__DOT__order_index),3);
            tracep->chgCData(oldp+65,(vlTOPp->System_Bus__DOT__M1__DOT__stateReg),2);
            tracep->chgCData(oldp+66,(vlTOPp->System_Bus__DOT__M2__DOT__countreg),4);
            tracep->chgCData(oldp+67,(vlTOPp->System_Bus__DOT__M2__DOT__order_index),3);
            tracep->chgCData(oldp+68,(vlTOPp->System_Bus__DOT__M2__DOT__stateReg),2);
            tracep->chgSData(oldp+69,(vlTOPp->System_Bus__DOT__S1__DOT__addr_reg),14);
            tracep->chgCData(oldp+70,(vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg),8);
            tracep->chgBit(oldp+71,(vlTOPp->System_Bus__DOT__S1__DOT__control_reg));
            tracep->chgCData(oldp+72,(vlTOPp->System_Bus__DOT__S1__DOT__countreg),4);
            tracep->chgCData(oldp+73,(vlTOPp->System_Bus__DOT__S1__DOT__stateReg),2);
            tracep->chgSData(oldp+74,(vlTOPp->System_Bus__DOT__S2__DOT__addr_reg),14);
            tracep->chgCData(oldp+75,(vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg),8);
            tracep->chgBit(oldp+76,(vlTOPp->System_Bus__DOT__S2__DOT__control_reg));
            tracep->chgCData(oldp+77,(vlTOPp->System_Bus__DOT__S2__DOT__countreg),4);
            tracep->chgCData(oldp+78,(vlTOPp->System_Bus__DOT__S2__DOT__stateReg),2);
            tracep->chgSData(oldp+79,(vlTOPp->System_Bus__DOT__S3__DOT__addr_reg),14);
            tracep->chgCData(oldp+80,(vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg),8);
            tracep->chgBit(oldp+81,(vlTOPp->System_Bus__DOT__S3__DOT__control_reg));
            tracep->chgCData(oldp+82,(vlTOPp->System_Bus__DOT__S3__DOT__countreg),4);
            tracep->chgCData(oldp+83,(vlTOPp->System_Bus__DOT__S3__DOT__stateReg),3);
            tracep->chgBit(oldp+84,(vlTOPp->System_Bus__DOT__S3__DOT__split_reg));
            tracep->chgCData(oldp+85,(vlTOPp->System_Bus__DOT__arbiter__DOT__timer),4);
            tracep->chgBit(oldp+86,(vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember));
            tracep->chgCData(oldp+87,(vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg),3);
        }
        tracep->chgBit(oldp+88,(vlTOPp->clock));
        tracep->chgBit(oldp+89,(vlTOPp->reset));
    }
}

void VSystem_Bus::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
