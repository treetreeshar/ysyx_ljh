#include "Vtop.h"
#include "verilated.h"
#include <iostream>
//#include "verilated_vcd_c.h"

// 全局仿真对象
static Vtop dut;
//static VerilatedVcdC* tfp;  // 全局波形对象
static vluint64_t cycle_count = 0;  // 全局周期计数

// 全局仿真结束标志
bool simulation_finished = false;

// DPI-C 函数实现
extern "C" void npc_ebreak() {
    simulation_finished = true;
}

static void single_cycle() {
    dut.clk = 0; dut.eval();
    //if (tfp) tfp->dump(cycle_count);  // 记录下降沿
    
    dut.clk = 1; dut.eval();
    //if (tfp) tfp->dump(cycle_count + 1);  // 记录上升沿
    
    cycle_count += 2;  // 每个完整周期计数+2（下降沿+上升沿）
}

static void reset(int n) {
    dut.rst = 1;
    while (n-- > 0) single_cycle();
    dut.rst = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;
    //Verilated::traceEverOn(true);
    
    // 初始化波形
    //tfp = new VerilatedVcdC;
    //dut.trace(tfp, 99);
    //tfp->open("wave.vcd");
    
    // 初始化指令存储器
    uint32_t mem[6] = {
        0x01400513,
        0x010000e7,
        0x00c000e7,
        0x00100073,//ebreak
        0x00a50513,
        0x00008067
    };
    
    reset(4);

    while (!Verilated::gotFinish() && !simulation_finished) {
        // 取指令（带边界检查）
        dut.inst = (dut.pc < sizeof(mem)) ? mem[dut.pc/4] : 0;
        
        single_cycle();
        
        // 打印状态（每完整周期打印一次）
        if (cycle_count % 2 == 0) {  // 只在完整周期结束时打印
            std::cout << "Cycle " << cycle_count/2 
                      << ": PC=0x" << std::hex << dut.pc
                      << " Inst=0x" << dut.inst
                      << " x1=0x" << dut.debug_x1
                      << " x10=0x" << dut.debug_x10
                      << std::dec << std::endl;
        }
    }
    
    // 清理
    //if (tfp) {
    //    tfp->close();
    //    delete tfp;
    //}
    delete top;
    return 0;
}