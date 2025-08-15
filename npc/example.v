module example();
endmodule

// 触发器模板
module Reg #(WIDTH = 1, RESET_VAL = 0) (
  input clk,
  input rst,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk) begin
    if (rst) dout <= RESET_VAL;
    else if (wen) dout <= din;
  end
endmodule

/* 使用触发器模板的示例
module example(
  input clk,
  input rst,
  input [3:0] in,
  output [3:0] out
);
  // 位宽为1比特, 复位值为1'b1, 写使能一直有效
  Reg #(1, 1'b1) i0 (clk, rst, in[0], out[0], 1'b1);
  // 位宽为3比特, 复位值为3'b0, 写使能为out[0]
  Reg #(3, 3'b0) i1 (clk, rst, in[3:1], out[3:1], out[0]);
endmodule
*/

// 选择器模板内部实现 替代case
module MuxKeyInternal #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1, HAS_DEFAULT = 0) (
  output reg [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);

  localparam PAIR_LEN = KEY_LEN + DATA_LEN;
  wire [PAIR_LEN-1:0] pair_list [NR_KEY-1:0];
  wire [KEY_LEN-1:0] key_list [NR_KEY-1:0];
  wire [DATA_LEN-1:0] data_list [NR_KEY-1:0];

  genvar n;
  generate
    for (n = 0; n < NR_KEY; n = n + 1) begin
      assign pair_list[n] = lut[PAIR_LEN*(n+1)-1 : PAIR_LEN*n];
      assign data_list[n] = pair_list[n][DATA_LEN-1:0];
      assign key_list[n]  = pair_list[n][PAIR_LEN-1:DATA_LEN];
    end
  endgenerate

  reg [DATA_LEN-1 : 0] lut_out;
  reg hit;
  integer i;
  always @(*) begin
    lut_out = 0;
    hit = 0;
    for (i = 0; i < NR_KEY; i = i + 1) begin
      lut_out = lut_out | ({DATA_LEN{key == key_list[i]}} & data_list[i]);
      hit = hit | (key == key_list[i]);
    end
    if (!HAS_DEFAULT) out = lut_out;
    else out = (hit ? lut_out : default_out);
  end
endmodule

// 不带默认值的选择器模板
module MuxKey #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0) i0 (out, key, {DATA_LEN{1'b0}}, lut);
endmodule

// 带默认值的选择器模板
module MuxKeyWithDefault #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 1) i0 (out, key, default_out, lut);
endmodule

module top(
    input clk,
    input rst,

    input [31:0] inst,
    output [31:0] debug_x1,debug_x10,
    output [31:0] pc
);

    always @(posedge clk) begin
        if (!rst && inst == 32'h00100073) begin
            npc_ebreak();
        end
    end

    // IFU接口
    //wire [31:0] pc;
    wire [31:0] jump_pc;
    wire jump;
    
    // IDU接口
    //wire [31:0] inst;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] imm;
    wire is_addi, is_jalr, is_add, is_lui, is_lw, is_lbu, is_sw, is_sb;
    
    // EXU接口
    wire [31:0] reg_rdata1, reg_rdata2;
    wire mem_ren, mem_wen, reg_wen, reg_men;
    wire [31:0] reg_wdata, mem_wdata;
    wire [23:0] mem_addr;
    wire [3:0] mem_mask;
    
    // 内存接口
    wire [31:0] mem_rdata;
    
    // DPI-C内存接口
    import "DPI-C" function void npc_ebreak();
    //import "DPI-C" function int pmem_read(input int raddr);
    //import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    
    // 取指
    //assign inst = pmem_read(pc);
    
    // 内存访问
    //assign mem_rdata = pmem_read({8'b0, mem_addr});
    //always @(*) begin
    //    if (mem_wen) begin
    //        pmem_write({8'b0, mem_addr}, mem_wdata, {4'b0, mem_mask});
    //    end
    //end
    
    ifu ifu0(
        .clk(clk),
        .rst(rst),
        .jump_pc(jump_pc),
        .jump(jump),
        .pc(pc)
    );
    
    idu idu0(
        .clk(clk),
        .rst(rst),
        .inst(inst),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm),
        .is_addi(is_addi),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_lw(is_lw),
        .is_lbu(is_lbu),
        .is_sw(is_sw),
        .is_sb(is_sb)
    );
    
    exu exu0(
        .clk(clk),
        .rst(rst),
        .is_addi(is_addi),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_lw(is_lw),
        .is_lbu(is_lbu),
        .is_sw(is_sw),
        .is_sb(is_sb),
        .pc(pc),
        .reg_rdata1(reg_rdata1),
        .reg_rdata2(reg_rdata2),
        .imm(imm),
        .mem_ren(mem_ren),
        .mem_wen(mem_wen),
        .reg_wen(reg_wen),
        .reg_men(reg_men),
        .reg_wdata(reg_wdata),
        .mem_wdata(mem_wdata),
        .mem_addr(mem_addr),
        .mem_mask(mem_mask),
        .jump_pc(jump_pc),
        .jump(jump)
    );
    
    rf rf0(
        .clk(clk),
        .rst(rst),
        .reg_wdata(reg_wdata),
        .mem_rdata(mem_rdata),
        .reg_waddr(rd),
        .reg_wen(reg_wen),
        .reg_men(reg_men),
        .is_lbu(is_lbu),
        .reg_raddr1(rs1),
        .reg_raddr2(rs2),
        .reg_rdata1(reg_rdata1),
        .reg_rdata2(reg_rdata2),
        .debug_x1(debug_x1),
        .debug_x10(debug_x10)
    );
/*
    always @(posedge clk) begin
        if (!rst) begin
            // 全局监控
            $display("[TOP] pc=%h, inst=%h, jump=%b, jump_pc=%h",
                     pc, inst, jump, jump_pc);
            
            // 专门监控JALR信号链
            $display("[TOP-SIG] is_jalr=%b, jump=%b, jump_pc=%h",
                     u_idu.is_jalr, u_exu.jump, u_exu.jump_pc);
            
            // 监控寄存器状态
            $display("[REG] x1=%h, x10=%h", 
                     u_rf.debug_x1, u_rf.debug_x10);
            
            // 检查关键指令
            if (inst == 32'h010000e7) begin
                $display("[TOP] !!! JALR INSTRUCTION DETECTED !!!");
            end
        end
    end
    
    // 添加仿真结束检测
    always @(posedge clk) begin
        if (!rst && inst == 32'h00100073) begin
            $display("EBREAK detected. Simulation ending.");
            npc_ebreak();
        end
    end
    */
endmodule

/******************ifu********************/
module ifu(
    input clk,
    input rst,

    input [31:0] jump_pc,
    input jump,
    output reg [31:0] pc
);
always@(posedge clk) begin
    if(rst) begin
        pc <= 32'h0;//80000000
    end
    else begin
        if(jump) pc <= jump_pc;
        else pc <= pc + 32'h4;
    end
end

endmodule


/******************idu********************/
module idu(
    input clk,
    input rst,

    input [31:0] inst,

    output [4:0] rs1,
    output [4:0] rs2,
    output [4:0] rd,
    output [31:0] imm,

    output is_addi,
    output is_jalr,
    output is_add,
    output is_lui,
    output is_lw,
    output is_lbu,
    output is_sw,
    output is_sb

);

    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;

    assign opcode = inst[6:0];
    assign rd = inst[11:7];
    assign funct3 = inst[14:12];
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    assign funct7 = inst[31:25];

    assign is_addi = (opcode == 7'b0010011) && (funct3 == 3'b000);    //I
    assign is_jalr = (opcode == 7'b1100111) && (funct3 == 3'b000);    //I
    assign is_add  = (opcode == 7'b0110011) && (funct3 == 3'b000);    //R
    assign is_lui  = (opcode == 7'b0110111);                          //U
    assign is_lw   = (opcode == 7'b0000011) && (funct3 == 3'b010);    //I
    assign is_lbu  = (opcode == 7'b0000011) && (funct3 == 3'b100);    //I
    assign is_sw   = (opcode == 7'b0100011) && (funct3 == 3'b010);    //S
    assign is_sb   = (opcode == 7'b0100011) && (funct3 == 3'b000);    //S
    
    wire [31:0] i_imm = {{20{inst[31]}}, inst[31:20]};
    wire [31:0] s_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    wire [31:0] u_imm = {inst[31:12], 12'b0};
    //r型无立即数 有funct7
    
    assign imm = (is_addi || is_jalr || is_lw || is_lbu) ? i_imm :
                 (is_lui) ? u_imm :
                 (is_sw || is_sb) ? s_imm :
                 32'b0;
   
endmodule


/******************exu********************/
module exu(
    input clk,
    input rst,

    input is_addi,
    input is_jalr,
    input is_add,
    input is_lui,
    input is_lw,
    input is_lbu,
    input is_sw,
    input is_sb,

    input [31:0] pc,
    input [31:0] reg_rdata1,reg_rdata2,imm,
    output mem_ren,mem_wen,reg_wen,reg_men,
    output [31:0] reg_wdata,mem_wdata,
    output [23:0] mem_addr,
    output [3:0] mem_mask, 

    output [31:0] jump_pc,
    output jump
);
assign jump_pc = is_jalr ? (reg_rdata1 + imm) & ~32'b1 : 32'b0;
assign jump = is_jalr;

assign reg_wen = is_add || is_addi || is_jalr || is_lui;
assign reg_men = is_lw || is_lbu;

assign reg_wdata = (is_jalr) ? pc + 4 : 
                    (is_addi) ? reg_rdata1 + imm :
                    (is_add) ? reg_rdata1 + reg_rdata2 :
                    (is_lui) ? imm :
                    32'b0;
assign mem_wdata = (is_sw || is_sb) ? reg_rdata2 : 0;

assign mem_ren = (is_lw || is_lbu) ? 1 : 0;
assign mem_wen = (is_sw || is_sb) ? 1 : 0;

assign mem_addr = (mem_ren || mem_wen) ? {reg_rdata1 + imm}[25:2] : 24'b0;
assign mem_mask = (is_sb) ? 4'b0001 << (mem_addr[1:0]) :
                    (is_sw) ? 4'b1111 :
                    4'b0;

endmodule


/******************reg********************/
module rf(
    input clk,
    input rst,

    input [31:0] reg_wdata,mem_rdata,
    input [4:0] reg_waddr,
    input reg_wen,reg_men,is_lbu,

    input [4:0] reg_raddr1,reg_raddr2,
    output [31:0] reg_rdata1,reg_rdata2,

    output [31:0] debug_x1,debug_x10

);
reg [31:0] rf [0:31];

assign debug_x1 = rf[1];
assign debug_x10 = rf[10];

integer i;
always@(posedge clk or posedge rst) begin
    if(rst) begin
        for(i=0; i<32; i=i+1) rf[i] <= 0;
    end
    else if(reg_wen && reg_waddr != 5'b0) begin
        rf[reg_waddr] <= reg_wdata;
    end
    else if(reg_men && reg_waddr != 5'b0) begin
        rf[reg_waddr] <= (is_lbu) ? {24'b0, mem_rdata[7:0]} : mem_rdata;
    end
end

assign reg_rdata1 = rf[reg_raddr1];
assign reg_rdata2 = rf[reg_raddr2];

endmodule

#include "Vtop.h"
#include "verilated.h"
#include <iostream>
//#include "verilated_vcd_c.h"

// 全局仿真对象
static Vtop dut;
//static VerilatedVcdC* tfp;   全局波形对象
static vluint64_t cycle_count = 0;  // 全局周期计数

// 全局仿真结束标志
bool simulation_finished = false;

// DPI-C 函数实现
extern "C" void npc_ebreak() {
    simulation_finished = true;
}

//extern "C" int pmem_read(input int raddr){
//}
//extern "C" void pmem_write(input int waddr, input int wdata, input byte wmask){
//}

/*
extern "C" int pmem_read(int raddr) {
    uint32_t aligned_addr = raddr & ~0x3u;
    return memory[aligned_addr]; // 返回对齐的4字节数据
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t aligned_addr = waddr & ~0x3u;
    uint32_t& mem_word = memory[aligned_addr];
    
    // 初始化为0如果地址不存在
    if (memory.find(aligned_addr) == memory.end()) {
        mem_word = 0;
    }
    
    // 根据掩码更新各个字节
    for (int i = 0; i < 4; i++) {
        if (wmask & (1 << i)) {
            uint8_t byte = (wdata >> (8 * i)) & 0xFF;
            mem_word = (mem_word & ~(0xFF << (8 * i))) | (byte << (8 * i));
        }
    }
}*/

static void single_cycle() {
    dut.clk = 0; dut.eval();
    //if (tfp) tfp->dump(cycle_count);   记录下降沿
    
    dut.clk = 1; dut.eval();
    //if (tfp) tfp->dump(cycle_count + 1);   记录上升沿
    
    cycle_count += 2;  // 每个完整周期计数+2（下降沿+上升沿）
}

static void reset(int n) {
    dut.rst = 1;
    while (n-- > 0) single_cycle();
    dut.rst = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    //Vtop* top = new Vtop;
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