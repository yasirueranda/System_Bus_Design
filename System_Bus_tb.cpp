#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VSystem_Bus.h"


#define MAX_SIM_TIME 150
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char** argv, char** env) {
    VSystem_Bus *dut = new VSystem_Bus;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut->clock ^= 1;
        dut->eval();
        dut->reset = 0;

        //for synchronous stimulus
        if(dut->clock == 1){
            posedge_cnt++;
        }

        if(posedge_cnt == 1){
            dut->reset = 1;
        }

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}




