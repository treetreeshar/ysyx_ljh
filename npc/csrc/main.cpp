#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>
#include <map>
#include <fstream>
//#include <cstring>
#include <cstdlib>
#include <sstream>
//#include "verilated_vcd_c.h"

static Vtop dut;
static vluint64_t cycle_count = 0;
bool simulation_finished = false;
std::map<uint32_t, uint32_t> memory;
//static VerilatedVcdC* tfp;

extern "C" void npc_ebreak() {
    simulation_finished = true;
}

extern "C" int pmem_read(int raddr) {
    uint32_t aligned_addr = raddr & ~0x3u;//~0x3u = 111...11100 使地址向下对齐4字节
    return memory[aligned_addr];
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t aligned_addr = waddr & ~0x3u;
    uint32_t& mem_word = memory[aligned_addr]; //&：定义一个引用（别名）此地址的值
    
    for (int i = 0; i < 4; i++) {
        if (wmask & (1 << i)) {
            uint8_t byte = (wdata >> (8 * i)) & 0xFF;
            mem_word = (mem_word & ~(0xFF << (8 * i))) | (byte << (8 * i));
        }
    }
}

void load_bin(const std::string& filename, uint32_t base_address) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    // 获取文件大小
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    // 按4字节对齐读取
    size_t total_words = (size + 3) / 4; // 向上取整
    std::vector<uint8_t> buffer(total_words * 4, 0); // 填充0保证对齐

    file.read(reinterpret_cast<char*>(buffer.data()), size);
    file.close();

    // 写入内存（按小端序解析）
    for (size_t i = 0; i < total_words; i++) {
        uint32_t word = 0;
        for (int j = 0; j < 4; j++) {
            word |= buffer[i * 4 + j] << (8 * j);
        }
        memory[base_address + i * 4] = word;
    }

    std::cout << "Loaded " << total_words << " words ("
              << total_words * 4 << " bytes) from " << filename 
              << " starting from 0x" << std::hex << base_address << std::dec << std::endl;
}

void load_custom_hex(const std::string& filename, uint32_t base_address) {
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    size_t total_words = 0;
    
    std::getline(file, line);//跳过首行
    
    while (std::getline(file, line)) {//getline自动丢弃\n
        //移除可能的windows回车符
        if (!line.empty() && line.back() == '\r') {//非空 && 最后一个字符是换行符
            line.pop_back();//删除字符串最后一个字符
        }
        
        //分割地址和数据部分
        size_t colon_pos = line.find(':');
        if (colon_pos == std::string::npos) continue;//无冒号：跳过当前行
        
        //解析行地址
        uint32_t line_addr = std::stoul(line.substr(0, colon_pos), nullptr, 16);//提取行头地址
        uint32_t full_addr = base_address + line_addr * 4;//实际地址
        
        //分割数据部分
        std::string data_str = line.substr(colon_pos + 1);
        std::istringstream iss(data_str);//定义输入字符串流类 iss
        std::string word_str;
        
        while (iss >> word_str) {//从流中提取以空格分隔的子字符串
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
    
    const char* program_path = argv[1];
    uint32_t base_address = 0x80000000; // 默认基地址
    
    if (argc >= 3) {
        char* end;
        base_address = strtoul(argv[2], &end, 0);
        if (*end != '\0') {
            std::cerr << "Invalid base address: " << argv[2] << std::endl;
            return 1;
        }
    }

    // 根据文件扩展名选择加载方式
    std::string filename(program_path);
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".hex") {
        load_custom_hex(program_path, base_address);
    } else if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".bin") {
        load_bin(program_path, base_address);
    } else {
        std::cerr << "Error: Unsupported file format (must be .hex or .bin)" << std::endl;
        return 1;
    }

    // 初始化波形
    //Verilated::traceEverOn(true);
    //tfp = new VerilatedVcdC;
    //dut.trace(tfp, 99);
    //tfp->open("wave.vcd");
    
    
    reset(4);
    int turn = 0;

    while (turn < 7000 && !Verilated::gotFinish() && !simulation_finished) { //
        uint32_t current_pc = dut.pc;
        uint32_t current_inst = dut.inst;
        
        single_cycle();
        turn++;
        /**/
        if (cycle_count % 2000 == 0) {
            std::cout << "Cycle " << cycle_count/2 
                    << ": PC=0x" << std::hex << current_pc
                    << " Inst=0x" << current_inst
                    << " x10=0x" << dut.debug_x4
                    << " x11=0x" <<dut.debug_x10
                    << std::dec << std::endl;
            }
        
        // 检查当前指令是否为 ebreak
        bool is_ebreak = (current_inst == 0x00100073);
        if (is_ebreak) {
            // 获取 a0 寄存器的值（RISC-V x10）
            uint32_t a0 = dut.debug_x4; 
            
            // 输出程序状态
            printf("%s\n", (a0 == 0) ? "HIT GOOD TRAP" : "HIT BAD TRAP");
            
            // 停止仿真
            simulation_finished = true;
            break;
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