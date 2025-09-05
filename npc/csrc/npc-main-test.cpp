/*#include "Vtop.h"
#include "verilated.h"
//#include "verilated_vcd_c.h"

static Vtop dut;
static uint64_t start_time_us = 0;
//static VerilatedVcdC* tfp;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    const char* program_path = argv[1];
    uint32_t base_address = argv[2] ? strtoul(argv[2], NULL, 0) : 0x80000000;

    load_file(program_path, base_address);

    // 初始化波形
    //Verilated::traceEverOn(true);
    //tfp = new VerilatedVcdC;
    //dut.trace(tfp, 99);
    //tfp->open("wave.vcd");

    start_time_us = get_current_time_us();   

    reset(4);

    return 0;
}
*/