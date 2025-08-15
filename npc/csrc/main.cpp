#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sstream>
//#include "verilated_vcd_c.h"

// 全局仿真对象
static Vtop dut;
static vluint64_t cycle_count = 0;  // 全局周期计数
bool simulation_finished = false;
std::map<uint32_t, uint32_t> memory;
//static VerilatedVcdC* tfp;  // 全局波形对象

// DPI-C 函数实现
extern "C" void npc_ebreak() {
    simulation_finished = true;
}

extern "C" int pmem_read(int raddr) {
    uint32_t aligned_addr = raddr & ~0x3u;
    return memory[aligned_addr]; // 返回对齐的4字节数据
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t aligned_addr = waddr & ~0x3u;
    uint32_t& mem_word = memory[aligned_addr];
    
    if (memory.find(aligned_addr) == memory.end()) {
        mem_word = 0;
    }
    
    for (int i = 0; i < 4; i++) {
        if (wmask & (1 << i)) {
            uint8_t byte = (wdata >> (8 * i)) & 0xFF;
            mem_word = (mem_word & ~(0xFF << (8 * i))) | (byte << (8 * i));
        }
    }
}

// 加载 HEX 文件到内存
void load_custom_hex(const std::string& filename, uint32_t base_address) {
    const uint32_t MEM_SIZE = 0x100000; // 例如1MB内存
    for (uint32_t addr = 0; addr < MEM_SIZE; addr += 4) {
        memory[addr] = 0x00000000;
    }//
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    size_t total_words = 0;
    
    // 跳过可能的文件头
    std::getline(file, line); // 跳过 "v3.0 hex words addressed" 行
    
    while (std::getline(file, line)) {
        // 移除可能的回车符
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        // 分割地址和数据部分
        size_t colon_pos = line.find(':');
        if (colon_pos == std::string::npos) continue;
        
        // 解析行地址
        uint32_t line_addr = std::stoul(line.substr(0, colon_pos), nullptr, 16);
        uint32_t full_addr = base_address + line_addr * 4; // 每行地址代表4字节的倍数
        
        // 分割数据部分
        std::string data_str = line.substr(colon_pos + 1);
        std::istringstream iss(data_str);
        std::string word_str;
        
        while (iss >> word_str) {
            uint32_t word = std::stoul(word_str, nullptr, 16);
            memory[full_addr] = word;
            full_addr += 4;
            total_words++;
        }
    }
    
    std::cout << "Loaded " << total_words << " words ("
              << total_words * 4 << " bytes) from " << filename 
              << " starting from 0x" << std::hex << base_address << std::dec << std::endl;
}

static void single_cycle() {
    dut.clk = 0; dut.eval();
    //if (tfp) tfp->dump(cycle_count);  // 记录下降沿
    dut.clk = 1; dut.eval();
    //if (tfp) tfp->dump(cycle_count + 1);  // 记录上升沿
    cycle_count += 2;
}

static void reset(int n) {
    dut.rst = 1;
    while (n-- > 0) single_cycle();
    dut.rst = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <program.hex> [base_address]\n";
        return 1;
    }
    
    const char* program_path = argv[1];
    uint32_t base_address = 0x00000000; // 默认基地址
    
    if (argc >= 3) {
        char* end;
        base_address = strtoul(argv[2], &end, 0);
        if (*end != '\0') {
            std::cerr << "Invalid base address: " << argv[2] << std::endl;
            return 1;
        }
    }

    // 加载HEX文件
    load_custom_hex(program_path, base_address);

    // 初始化波形
    //Verilated::traceEverOn(true);
    //tfp = new VerilatedVcdC;
    //dut.trace(tfp, 99);
    //tfp->open("wave.vcd");
    
    
    reset(4);
    int turn = 0;

    while (turn < 7000 && !Verilated::gotFinish() && !simulation_finished) { //
        uint32_t current_pc = dut.pc;
    uint32_t current_inst = pmem_read(current_pc);
    
    dut.inst = current_inst;
    
    single_cycle();
    turn++;
    
    if (cycle_count % 2 == 0) {
        std::cout << "Cycle " << cycle_count/2 
                  << ": PC=0x" << std::hex << current_pc
                  << " Inst=0x" << current_inst
                  << " x10=0x" << dut.debug_x4
                  << " x11=0x" <<dut.debug_x10
                  << std::dec << std::endl;
        }
    }
    
    // 清理
    //if (tfp) {
    //    tfp->close();
    //    delete tfp;
    //}
    dut.final();
    return 0;
}