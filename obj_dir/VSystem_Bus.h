// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSYSTEM_BUS_H_
#define _VSYSTEM_BUS_H_  // guard

#include "verilated.h"

//==========

class VSystem_Bus__Syms;
class VSystem_Bus_VerilatedVcd;


//----------

VL_MODULE(VSystem_Bus) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ System_Bus__DOT__M1_control;
    CData/*0:0*/ System_Bus__DOT__M2_control;
    CData/*0:0*/ System_Bus__DOT__M1__DOT__request_reg;
    CData/*7:0*/ System_Bus__DOT__M1__DOT__wdata_reg;
    CData/*0:0*/ System_Bus__DOT__M1__DOT__valid_reg;
    CData/*3:0*/ System_Bus__DOT__M1__DOT__countreg;
    CData/*2:0*/ System_Bus__DOT__M1__DOT__order_index;
    CData/*1:0*/ System_Bus__DOT__M1__DOT__stateReg;
    CData/*0:0*/ System_Bus__DOT__M2__DOT__request_reg;
    CData/*7:0*/ System_Bus__DOT__M2__DOT__wdata_reg;
    CData/*0:0*/ System_Bus__DOT__M2__DOT__valid_reg;
    CData/*3:0*/ System_Bus__DOT__M2__DOT__countreg;
    CData/*2:0*/ System_Bus__DOT__M2__DOT__order_index;
    CData/*1:0*/ System_Bus__DOT__M2__DOT__stateReg;
    CData/*7:0*/ System_Bus__DOT__S1__DOT__rdata_reg;
    CData/*0:0*/ System_Bus__DOT__S1__DOT__done_reg;
    CData/*7:0*/ System_Bus__DOT__S1__DOT__wdata_reg;
    CData/*0:0*/ System_Bus__DOT__S1__DOT__control_reg;
    CData/*3:0*/ System_Bus__DOT__S1__DOT__countreg;
    CData/*1:0*/ System_Bus__DOT__S1__DOT__stateReg;
    CData/*7:0*/ System_Bus__DOT__S2__DOT__rdata_reg;
    CData/*0:0*/ System_Bus__DOT__S2__DOT__done_reg;
    CData/*7:0*/ System_Bus__DOT__S2__DOT__wdata_reg;
    CData/*0:0*/ System_Bus__DOT__S2__DOT__control_reg;
    CData/*3:0*/ System_Bus__DOT__S2__DOT__countreg;
    CData/*1:0*/ System_Bus__DOT__S2__DOT__stateReg;
    CData/*7:0*/ System_Bus__DOT__S3__DOT__rdata_reg;
    CData/*0:0*/ System_Bus__DOT__S3__DOT__done_reg;
    CData/*0:0*/ System_Bus__DOT__S3__DOT__arb_req_reg;
    CData/*0:0*/ System_Bus__DOT__S3__DOT__split_req_reg;
    CData/*7:0*/ System_Bus__DOT__S3__DOT__wdata_reg;
    CData/*0:0*/ System_Bus__DOT__S3__DOT__control_reg;
    CData/*3:0*/ System_Bus__DOT__S3__DOT__countreg;
    CData/*2:0*/ System_Bus__DOT__S3__DOT__stateReg;
    CData/*0:0*/ System_Bus__DOT__S3__DOT__split_reg;
    CData/*0:0*/ System_Bus__DOT__arbiter__DOT__grant0Reg;
    CData/*0:0*/ System_Bus__DOT__arbiter__DOT__grant1Reg;
    CData/*0:0*/ System_Bus__DOT__arbiter__DOT__masterSelReg;
    CData/*0:0*/ System_Bus__DOT__arbiter__DOT__split_grant_reg;
    CData/*3:0*/ System_Bus__DOT__arbiter__DOT__timer;
    CData/*0:0*/ System_Bus__DOT__arbiter__DOT__split_remember;
    CData/*2:0*/ System_Bus__DOT__arbiter__DOT__stateReg;
    SData/*13:0*/ System_Bus__DOT__S1_io_addr;
    SData/*13:0*/ System_Bus__DOT__S2_io_addr;
    SData/*13:0*/ System_Bus__DOT__S3_io_addr;
    SData/*13:0*/ System_Bus__DOT__addr;
    SData/*13:0*/ System_Bus__DOT__M1__DOT__address_reg;
    SData/*13:0*/ System_Bus__DOT__M2__DOT__address_reg;
    SData/*13:0*/ System_Bus__DOT__S1__DOT__addr_reg;
    SData/*13:0*/ System_Bus__DOT__S2__DOT__addr_reg;
    SData/*13:0*/ System_Bus__DOT__S3__DOT__addr_reg;
    SData/*13:0*/ System_Bus__DOT__M1__DOT__addr[8];
    CData/*0:0*/ System_Bus__DOT__M1__DOT__rwreg[8];
    SData/*13:0*/ System_Bus__DOT__M2__DOT__addr[8];
    CData/*0:0*/ System_Bus__DOT__M2__DOT__rwreg[8];
    CData/*7:0*/ System_Bus__DOT__S1__DOT__mem[2048];
    CData/*7:0*/ System_Bus__DOT__S2__DOT__mem[4096];
    CData/*7:0*/ System_Bus__DOT__S3__DOT__mem[4096];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSystem_Bus__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSystem_Bus);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSystem_Bus(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSystem_Bus();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VSystem_Bus__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSystem_Bus__Syms* symsp, bool first);
  private:
    static QData _change_request(VSystem_Bus__Syms* __restrict vlSymsp);
    static QData _change_request_1(VSystem_Bus__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSystem_Bus__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSystem_Bus__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSystem_Bus__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VSystem_Bus__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VSystem_Bus__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VSystem_Bus__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
