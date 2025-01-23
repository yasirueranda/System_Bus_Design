// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSystem_Bus__Syms.h"


//======================

void VSystem_Bus::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VSystem_Bus::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSystem_Bus::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VSystem_Bus::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VSystem_Bus::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+89,"clock", false,-1);
        tracep->declBit(c+90,"reset", false,-1);
        tracep->declBit(c+89,"System_Bus clock", false,-1);
        tracep->declBit(c+90,"System_Bus reset", false,-1);
        tracep->declBit(c+89,"System_Bus M1_clock", false,-1);
        tracep->declBit(c+90,"System_Bus M1_reset", false,-1);
        tracep->declBit(c+33,"System_Bus M1_request", false,-1);
        tracep->declBit(c+34,"System_Bus M1_control", false,-1);
        tracep->declBus(c+35,"System_Bus M1_address", false,-1, 13,0);
        tracep->declBit(c+36,"System_Bus M1_valid", false,-1);
        tracep->declBus(c+37,"System_Bus M1_wdata", false,-1, 7,0);
        tracep->declBus(c+38,"System_Bus M1_rdata", false,-1, 7,0);
        tracep->declBit(c+39,"System_Bus M1_done", false,-1);
        tracep->declBit(c+40,"System_Bus M1_grant", false,-1);
        tracep->declBit(c+89,"System_Bus M2_clock", false,-1);
        tracep->declBit(c+90,"System_Bus M2_reset", false,-1);
        tracep->declBit(c+41,"System_Bus M2_request", false,-1);
        tracep->declBit(c+42,"System_Bus M2_control", false,-1);
        tracep->declBus(c+43,"System_Bus M2_address", false,-1, 13,0);
        tracep->declBit(c+44,"System_Bus M2_valid", false,-1);
        tracep->declBus(c+45,"System_Bus M2_wdata", false,-1, 7,0);
        tracep->declBus(c+38,"System_Bus M2_rdata", false,-1, 7,0);
        tracep->declBit(c+39,"System_Bus M2_done", false,-1);
        tracep->declBit(c+46,"System_Bus M2_grant", false,-1);
        tracep->declBit(c+89,"System_Bus S1_clock", false,-1);
        tracep->declBit(c+90,"System_Bus S1_reset", false,-1);
        tracep->declBus(c+47,"System_Bus S1_io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S1_io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S1_io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S1_io_valid", false,-1);
        tracep->declBus(c+51,"System_Bus S1_io_rdData", false,-1, 7,0);
        tracep->declBit(c+52,"System_Bus S1_io_done", false,-1);
        tracep->declBit(c+89,"System_Bus S2_clock", false,-1);
        tracep->declBit(c+90,"System_Bus S2_reset", false,-1);
        tracep->declBus(c+53,"System_Bus S2_io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S2_io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S2_io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S2_io_valid", false,-1);
        tracep->declBus(c+54,"System_Bus S2_io_rdData", false,-1, 7,0);
        tracep->declBit(c+55,"System_Bus S2_io_done", false,-1);
        tracep->declBit(c+89,"System_Bus S3_clock", false,-1);
        tracep->declBit(c+90,"System_Bus S3_reset", false,-1);
        tracep->declBus(c+56,"System_Bus S3_io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S3_io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S3_io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S3_io_valid", false,-1);
        tracep->declBus(c+57,"System_Bus S3_io_rdData", false,-1, 7,0);
        tracep->declBit(c+58,"System_Bus S3_io_done", false,-1);
        tracep->declBit(c+89,"System_Bus arbiter_clock", false,-1);
        tracep->declBit(c+90,"System_Bus arbiter_reset", false,-1);
        tracep->declBit(c+33,"System_Bus arbiter_io_req0", false,-1);
        tracep->declBit(c+41,"System_Bus arbiter_io_req1", false,-1);
        tracep->declBit(c+40,"System_Bus arbiter_io_grant0", false,-1);
        tracep->declBit(c+46,"System_Bus arbiter_io_grant1", false,-1);
        tracep->declBit(c+59,"System_Bus arbiter_io_masterSel", false,-1);
        tracep->declBus(c+60,"System_Bus addr", false,-1, 13,0);
        tracep->declBit(c+61,"System_Bus split_wire", false,-1);
        tracep->declBit(c+62,"System_Bus arb_req_wire", false,-1);
        tracep->declBit(c+63,"System_Bus arb_grant_wire", false,-1);
        tracep->declBit(c+89,"System_Bus M1 clock", false,-1);
        tracep->declBit(c+90,"System_Bus M1 reset", false,-1);
        tracep->declBit(c+33,"System_Bus M1 request", false,-1);
        tracep->declBit(c+34,"System_Bus M1 control", false,-1);
        tracep->declBus(c+35,"System_Bus M1 address", false,-1, 13,0);
        tracep->declBit(c+36,"System_Bus M1 valid", false,-1);
        tracep->declBus(c+37,"System_Bus M1 wdata", false,-1, 7,0);
        tracep->declBus(c+38,"System_Bus M1 rdata", false,-1, 7,0);
        tracep->declBit(c+39,"System_Bus M1 done", false,-1);
        tracep->declBit(c+40,"System_Bus M1 grant", false,-1);
        tracep->declBit(c+33,"System_Bus M1 request_reg", false,-1);
        tracep->declBus(c+35,"System_Bus M1 address_reg", false,-1, 13,0);
        tracep->declBus(c+37,"System_Bus M1 wdata_reg", false,-1, 7,0);
        tracep->declBit(c+36,"System_Bus M1 valid_reg", false,-1);
        tracep->declBus(c+64,"System_Bus M1 countreg", false,-1, 3,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+1+i*1,"System_Bus M1 addr", true,(i+0), 13,0);}}
        {int i; for (i=0; i<8; i++) {
                tracep->declBit(c+9+i*1,"System_Bus M1 rwreg", true,(i+0));}}
        tracep->declBus(c+65,"System_Bus M1 order_index", false,-1, 2,0);
        tracep->declBus(c+66,"System_Bus M1 stateReg", false,-1, 1,0);
        tracep->declBit(c+89,"System_Bus M2 clock", false,-1);
        tracep->declBit(c+90,"System_Bus M2 reset", false,-1);
        tracep->declBit(c+41,"System_Bus M2 request", false,-1);
        tracep->declBit(c+42,"System_Bus M2 control", false,-1);
        tracep->declBus(c+43,"System_Bus M2 address", false,-1, 13,0);
        tracep->declBit(c+44,"System_Bus M2 valid", false,-1);
        tracep->declBus(c+45,"System_Bus M2 wdata", false,-1, 7,0);
        tracep->declBus(c+38,"System_Bus M2 rdata", false,-1, 7,0);
        tracep->declBit(c+39,"System_Bus M2 done", false,-1);
        tracep->declBit(c+46,"System_Bus M2 grant", false,-1);
        tracep->declBit(c+41,"System_Bus M2 request_reg", false,-1);
        tracep->declBus(c+43,"System_Bus M2 address_reg", false,-1, 13,0);
        tracep->declBus(c+45,"System_Bus M2 wdata_reg", false,-1, 7,0);
        tracep->declBit(c+44,"System_Bus M2 valid_reg", false,-1);
        tracep->declBus(c+67,"System_Bus M2 countreg", false,-1, 3,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+17+i*1,"System_Bus M2 addr", true,(i+0), 13,0);}}
        {int i; for (i=0; i<8; i++) {
                tracep->declBit(c+25+i*1,"System_Bus M2 rwreg", true,(i+0));}}
        tracep->declBus(c+68,"System_Bus M2 order_index", false,-1, 2,0);
        tracep->declBus(c+69,"System_Bus M2 stateReg", false,-1, 1,0);
        tracep->declBus(c+47,"System_Bus S1 io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S1 io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S1 io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S1 io_valid", false,-1);
        tracep->declBus(c+51,"System_Bus S1 io_rdData", false,-1, 7,0);
        tracep->declBit(c+52,"System_Bus S1 io_done", false,-1);
        tracep->declBit(c+89,"System_Bus S1 clock", false,-1);
        tracep->declBit(c+90,"System_Bus S1 reset", false,-1);
        tracep->declBus(c+51,"System_Bus S1 rdata_reg", false,-1, 7,0);
        tracep->declBit(c+52,"System_Bus S1 done_reg", false,-1);
        tracep->declBus(c+70,"System_Bus S1 addr_reg", false,-1, 13,0);
        tracep->declBus(c+71,"System_Bus S1 wdata_reg", false,-1, 7,0);
        tracep->declBit(c+72,"System_Bus S1 control_reg", false,-1);
        tracep->declBus(c+73,"System_Bus S1 countreg", false,-1, 3,0);
        tracep->declBus(c+74,"System_Bus S1 stateReg", false,-1, 1,0);
        tracep->declBus(c+91,"System_Bus S1 IDLE", false,-1, 1,0);
        tracep->declBus(c+92,"System_Bus S1 SERVICING", false,-1, 1,0);
        tracep->declBus(c+93,"System_Bus S1 RESPONSE", false,-1, 1,0);
        tracep->declBus(c+53,"System_Bus S2 io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S2 io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S2 io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S2 io_valid", false,-1);
        tracep->declBus(c+54,"System_Bus S2 io_rdData", false,-1, 7,0);
        tracep->declBit(c+55,"System_Bus S2 io_done", false,-1);
        tracep->declBit(c+89,"System_Bus S2 clock", false,-1);
        tracep->declBit(c+90,"System_Bus S2 reset", false,-1);
        tracep->declBus(c+54,"System_Bus S2 rdata_reg", false,-1, 7,0);
        tracep->declBit(c+55,"System_Bus S2 done_reg", false,-1);
        tracep->declBus(c+75,"System_Bus S2 addr_reg", false,-1, 13,0);
        tracep->declBus(c+76,"System_Bus S2 wdata_reg", false,-1, 7,0);
        tracep->declBit(c+77,"System_Bus S2 control_reg", false,-1);
        tracep->declBus(c+78,"System_Bus S2 countreg", false,-1, 3,0);
        tracep->declBus(c+79,"System_Bus S2 stateReg", false,-1, 1,0);
        tracep->declBus(c+91,"System_Bus S2 IDLE", false,-1, 1,0);
        tracep->declBus(c+92,"System_Bus S2 SERVICING", false,-1, 1,0);
        tracep->declBus(c+93,"System_Bus S2 RESPONSE", false,-1, 1,0);
        tracep->declBus(c+56,"System_Bus S3 io_addr", false,-1, 13,0);
        tracep->declBus(c+48,"System_Bus S3 io_wrData", false,-1, 7,0);
        tracep->declBit(c+49,"System_Bus S3 io_wrEnable", false,-1);
        tracep->declBit(c+50,"System_Bus S3 io_valid", false,-1);
        tracep->declBus(c+57,"System_Bus S3 io_rdData", false,-1, 7,0);
        tracep->declBit(c+58,"System_Bus S3 io_done", false,-1);
        tracep->declBit(c+61,"System_Bus S3 split", false,-1);
        tracep->declBit(c+89,"System_Bus S3 clock", false,-1);
        tracep->declBit(c+90,"System_Bus S3 reset", false,-1);
        tracep->declBit(c+62,"System_Bus S3 arb_req", false,-1);
        tracep->declBit(c+63,"System_Bus S3 arb_grant", false,-1);
        tracep->declBus(c+57,"System_Bus S3 rdata_reg", false,-1, 7,0);
        tracep->declBit(c+58,"System_Bus S3 done_reg", false,-1);
        tracep->declBit(c+62,"System_Bus S3 arb_req_reg", false,-1);
        tracep->declBit(c+61,"System_Bus S3 split_req_reg", false,-1);
        tracep->declBus(c+80,"System_Bus S3 addr_reg", false,-1, 13,0);
        tracep->declBus(c+81,"System_Bus S3 wdata_reg", false,-1, 7,0);
        tracep->declBit(c+82,"System_Bus S3 control_reg", false,-1);
        tracep->declBus(c+83,"System_Bus S3 countreg", false,-1, 3,0);
        tracep->declBus(c+84,"System_Bus S3 stateReg", false,-1, 2,0);
        tracep->declBit(c+85,"System_Bus S3 split_reg", false,-1);
        tracep->declBus(c+94,"System_Bus S3 IDLE", false,-1, 2,0);
        tracep->declBus(c+95,"System_Bus S3 SERVICING", false,-1, 2,0);
        tracep->declBus(c+96,"System_Bus S3 RESPONSE", false,-1, 2,0);
        tracep->declBus(c+97,"System_Bus S3 SPLIT", false,-1, 2,0);
        tracep->declBus(c+98,"System_Bus S3 ARB_REQ", false,-1, 2,0);
        tracep->declBit(c+33,"System_Bus arbiter io_req0", false,-1);
        tracep->declBit(c+41,"System_Bus arbiter io_req1", false,-1);
        tracep->declBit(c+40,"System_Bus arbiter io_grant0", false,-1);
        tracep->declBit(c+46,"System_Bus arbiter io_grant1", false,-1);
        tracep->declBit(c+59,"System_Bus arbiter io_masterSel", false,-1);
        tracep->declBit(c+89,"System_Bus arbiter clock", false,-1);
        tracep->declBit(c+90,"System_Bus arbiter reset", false,-1);
        tracep->declBit(c+61,"System_Bus arbiter split", false,-1);
        tracep->declBit(c+62,"System_Bus arbiter split_req", false,-1);
        tracep->declBit(c+63,"System_Bus arbiter split_grant", false,-1);
        tracep->declBit(c+40,"System_Bus arbiter grant0Reg", false,-1);
        tracep->declBit(c+46,"System_Bus arbiter grant1Reg", false,-1);
        tracep->declBit(c+59,"System_Bus arbiter masterSelReg", false,-1);
        tracep->declBit(c+63,"System_Bus arbiter split_grant_reg", false,-1);
        tracep->declBus(c+86,"System_Bus arbiter timer", false,-1, 3,0);
        tracep->declBit(c+87,"System_Bus arbiter split_remember", false,-1);
        tracep->declBus(c+88,"System_Bus arbiter stateReg", false,-1, 2,0);
        tracep->declBus(c+94,"System_Bus arbiter IDLE", false,-1, 2,0);
        tracep->declBus(c+95,"System_Bus arbiter GRANT0", false,-1, 2,0);
        tracep->declBus(c+96,"System_Bus arbiter GRANT1", false,-1, 2,0);
    }
}

void VSystem_Bus::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VSystem_Bus::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VSystem_Bus::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VSystem_Bus__Syms* __restrict vlSymsp = static_cast<VSystem_Bus__Syms*>(userp);
    VSystem_Bus* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->System_Bus__DOT__M1__DOT__addr[0]),14);
        tracep->fullSData(oldp+2,(vlTOPp->System_Bus__DOT__M1__DOT__addr[1]),14);
        tracep->fullSData(oldp+3,(vlTOPp->System_Bus__DOT__M1__DOT__addr[2]),14);
        tracep->fullSData(oldp+4,(vlTOPp->System_Bus__DOT__M1__DOT__addr[3]),14);
        tracep->fullSData(oldp+5,(vlTOPp->System_Bus__DOT__M1__DOT__addr[4]),14);
        tracep->fullSData(oldp+6,(vlTOPp->System_Bus__DOT__M1__DOT__addr[5]),14);
        tracep->fullSData(oldp+7,(vlTOPp->System_Bus__DOT__M1__DOT__addr[6]),14);
        tracep->fullSData(oldp+8,(vlTOPp->System_Bus__DOT__M1__DOT__addr[7]),14);
        tracep->fullBit(oldp+9,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[0]));
        tracep->fullBit(oldp+10,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[1]));
        tracep->fullBit(oldp+11,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[2]));
        tracep->fullBit(oldp+12,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[3]));
        tracep->fullBit(oldp+13,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[4]));
        tracep->fullBit(oldp+14,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[5]));
        tracep->fullBit(oldp+15,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[6]));
        tracep->fullBit(oldp+16,(vlTOPp->System_Bus__DOT__M1__DOT__rwreg[7]));
        tracep->fullSData(oldp+17,(vlTOPp->System_Bus__DOT__M2__DOT__addr[0]),14);
        tracep->fullSData(oldp+18,(vlTOPp->System_Bus__DOT__M2__DOT__addr[1]),14);
        tracep->fullSData(oldp+19,(vlTOPp->System_Bus__DOT__M2__DOT__addr[2]),14);
        tracep->fullSData(oldp+20,(vlTOPp->System_Bus__DOT__M2__DOT__addr[3]),14);
        tracep->fullSData(oldp+21,(vlTOPp->System_Bus__DOT__M2__DOT__addr[4]),14);
        tracep->fullSData(oldp+22,(vlTOPp->System_Bus__DOT__M2__DOT__addr[5]),14);
        tracep->fullSData(oldp+23,(vlTOPp->System_Bus__DOT__M2__DOT__addr[6]),14);
        tracep->fullSData(oldp+24,(vlTOPp->System_Bus__DOT__M2__DOT__addr[7]),14);
        tracep->fullBit(oldp+25,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[0]));
        tracep->fullBit(oldp+26,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[1]));
        tracep->fullBit(oldp+27,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[2]));
        tracep->fullBit(oldp+28,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[3]));
        tracep->fullBit(oldp+29,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[4]));
        tracep->fullBit(oldp+30,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[5]));
        tracep->fullBit(oldp+31,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[6]));
        tracep->fullBit(oldp+32,(vlTOPp->System_Bus__DOT__M2__DOT__rwreg[7]));
        tracep->fullBit(oldp+33,(vlTOPp->System_Bus__DOT__M1__DOT__request_reg));
        tracep->fullBit(oldp+34,(vlTOPp->System_Bus__DOT__M1_control));
        tracep->fullSData(oldp+35,(vlTOPp->System_Bus__DOT__M1__DOT__address_reg),14);
        tracep->fullBit(oldp+36,(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg));
        tracep->fullCData(oldp+37,(vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg),8);
        tracep->fullCData(oldp+38,(((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                  >> 0xcU)))
                                     ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg)
                                     : ((1U == (3U 
                                                & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                   >> 0xcU)))
                                         ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg)
                                         : ((2U == 
                                             (3U & 
                                              ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                               >> 0xcU)))
                                             ? (IData)(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg)
                                             : 0U)))),8);
        tracep->fullBit(oldp+39,(((0U == (3U & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                >> 0xcU)))
                                   ? (IData)(vlTOPp->System_Bus__DOT__S1__DOT__done_reg)
                                   : ((1U == (3U & 
                                              ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                               >> 0xcU)))
                                       ? (IData)(vlTOPp->System_Bus__DOT__S2__DOT__done_reg)
                                       : ((2U == (3U 
                                                  & ((IData)(vlTOPp->System_Bus__DOT__addr) 
                                                     >> 0xcU))) 
                                          & (IData)(vlTOPp->System_Bus__DOT__S3__DOT__done_reg))))));
        tracep->fullBit(oldp+40,(vlTOPp->System_Bus__DOT__arbiter__DOT__grant0Reg));
        tracep->fullBit(oldp+41,(vlTOPp->System_Bus__DOT__M2__DOT__request_reg));
        tracep->fullBit(oldp+42,(vlTOPp->System_Bus__DOT__M2_control));
        tracep->fullSData(oldp+43,(vlTOPp->System_Bus__DOT__M2__DOT__address_reg),14);
        tracep->fullBit(oldp+44,(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg));
        tracep->fullCData(oldp+45,(vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg),8);
        tracep->fullBit(oldp+46,(vlTOPp->System_Bus__DOT__arbiter__DOT__grant1Reg));
        tracep->fullSData(oldp+47,(vlTOPp->System_Bus__DOT__S1_io_addr),14);
        tracep->fullCData(oldp+48,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                     ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__wdata_reg)
                                     : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__wdata_reg))),8);
        tracep->fullBit(oldp+49,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                   ? (IData)(vlTOPp->System_Bus__DOT__M2_control)
                                   : (IData)(vlTOPp->System_Bus__DOT__M1_control))));
        tracep->fullBit(oldp+50,(((IData)(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg)
                                   ? (IData)(vlTOPp->System_Bus__DOT__M2__DOT__valid_reg)
                                   : (IData)(vlTOPp->System_Bus__DOT__M1__DOT__valid_reg))));
        tracep->fullCData(oldp+51,(vlTOPp->System_Bus__DOT__S1__DOT__rdata_reg),8);
        tracep->fullBit(oldp+52,(vlTOPp->System_Bus__DOT__S1__DOT__done_reg));
        tracep->fullSData(oldp+53,(vlTOPp->System_Bus__DOT__S2_io_addr),14);
        tracep->fullCData(oldp+54,(vlTOPp->System_Bus__DOT__S2__DOT__rdata_reg),8);
        tracep->fullBit(oldp+55,(vlTOPp->System_Bus__DOT__S2__DOT__done_reg));
        tracep->fullSData(oldp+56,(vlTOPp->System_Bus__DOT__S3_io_addr),14);
        tracep->fullCData(oldp+57,(vlTOPp->System_Bus__DOT__S3__DOT__rdata_reg),8);
        tracep->fullBit(oldp+58,(vlTOPp->System_Bus__DOT__S3__DOT__done_reg));
        tracep->fullBit(oldp+59,(vlTOPp->System_Bus__DOT__arbiter__DOT__masterSelReg));
        tracep->fullSData(oldp+60,(vlTOPp->System_Bus__DOT__addr),14);
        tracep->fullBit(oldp+61,(vlTOPp->System_Bus__DOT__S3__DOT__split_req_reg));
        tracep->fullBit(oldp+62,(vlTOPp->System_Bus__DOT__S3__DOT__arb_req_reg));
        tracep->fullBit(oldp+63,(vlTOPp->System_Bus__DOT__arbiter__DOT__split_grant_reg));
        tracep->fullCData(oldp+64,(vlTOPp->System_Bus__DOT__M1__DOT__countreg),4);
        tracep->fullCData(oldp+65,(vlTOPp->System_Bus__DOT__M1__DOT__order_index),3);
        tracep->fullCData(oldp+66,(vlTOPp->System_Bus__DOT__M1__DOT__stateReg),2);
        tracep->fullCData(oldp+67,(vlTOPp->System_Bus__DOT__M2__DOT__countreg),4);
        tracep->fullCData(oldp+68,(vlTOPp->System_Bus__DOT__M2__DOT__order_index),3);
        tracep->fullCData(oldp+69,(vlTOPp->System_Bus__DOT__M2__DOT__stateReg),2);
        tracep->fullSData(oldp+70,(vlTOPp->System_Bus__DOT__S1__DOT__addr_reg),14);
        tracep->fullCData(oldp+71,(vlTOPp->System_Bus__DOT__S1__DOT__wdata_reg),8);
        tracep->fullBit(oldp+72,(vlTOPp->System_Bus__DOT__S1__DOT__control_reg));
        tracep->fullCData(oldp+73,(vlTOPp->System_Bus__DOT__S1__DOT__countreg),4);
        tracep->fullCData(oldp+74,(vlTOPp->System_Bus__DOT__S1__DOT__stateReg),2);
        tracep->fullSData(oldp+75,(vlTOPp->System_Bus__DOT__S2__DOT__addr_reg),14);
        tracep->fullCData(oldp+76,(vlTOPp->System_Bus__DOT__S2__DOT__wdata_reg),8);
        tracep->fullBit(oldp+77,(vlTOPp->System_Bus__DOT__S2__DOT__control_reg));
        tracep->fullCData(oldp+78,(vlTOPp->System_Bus__DOT__S2__DOT__countreg),4);
        tracep->fullCData(oldp+79,(vlTOPp->System_Bus__DOT__S2__DOT__stateReg),2);
        tracep->fullSData(oldp+80,(vlTOPp->System_Bus__DOT__S3__DOT__addr_reg),14);
        tracep->fullCData(oldp+81,(vlTOPp->System_Bus__DOT__S3__DOT__wdata_reg),8);
        tracep->fullBit(oldp+82,(vlTOPp->System_Bus__DOT__S3__DOT__control_reg));
        tracep->fullCData(oldp+83,(vlTOPp->System_Bus__DOT__S3__DOT__countreg),4);
        tracep->fullCData(oldp+84,(vlTOPp->System_Bus__DOT__S3__DOT__stateReg),3);
        tracep->fullBit(oldp+85,(vlTOPp->System_Bus__DOT__S3__DOT__split_reg));
        tracep->fullCData(oldp+86,(vlTOPp->System_Bus__DOT__arbiter__DOT__timer),4);
        tracep->fullBit(oldp+87,(vlTOPp->System_Bus__DOT__arbiter__DOT__split_remember));
        tracep->fullCData(oldp+88,(vlTOPp->System_Bus__DOT__arbiter__DOT__stateReg),3);
        tracep->fullBit(oldp+89,(vlTOPp->clock));
        tracep->fullBit(oldp+90,(vlTOPp->reset));
        tracep->fullCData(oldp+91,(0U),2);
        tracep->fullCData(oldp+92,(1U),2);
        tracep->fullCData(oldp+93,(2U),2);
        tracep->fullCData(oldp+94,(0U),3);
        tracep->fullCData(oldp+95,(1U),3);
        tracep->fullCData(oldp+96,(2U),3);
        tracep->fullCData(oldp+97,(3U),3);
        tracep->fullCData(oldp+98,(4U),3);
    }
}
