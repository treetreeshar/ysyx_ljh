module top(
    input rst,
    input clk,

    input [31:0] inst,
    output [31:0] pc,

    output [31:0] debug_x1,debug_x10

);

wire [4:0] rs1,rs2,rd;
wire [31:0] imm,ans,reg_rdata1,reg_rdata2,jump_pc;
wire jump,is_jalr;

always @(posedge clk) begin
        if (!rst && inst == 32'h00100073) begin
            npc_ebreak();
        end
    end

import "DPI-C" function void npc_ebreak();

ifu ifu0(
    .clk(clk),
    .rst(rst),

    .jump(jump),
    .jump_pc(jump_pc),
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
    .is_jalr(is_jalr)
    //.opcode(opcode),
    //.funct3(funct3),
    //.funct7()

);

exu exu0(
    .clk(clk),
    .rst(rst),

    .pc(pc),
    .reg_rdata1(reg_rdata1),
    .reg_rdata2(reg_rdata2),
    .imm(imm),

    .ans(ans),
    .is_jalr(is_jalr),
    .jump_pc(jump_pc),
    .jump(jump)
);

rf rf0(
    .clk(clk),
    .rst(rst),

    .reg_wdata(ans),
    .reg_waddr(rd),
    .reg_wen(1'b1),

    .reg_raddr1(rs1),
    .reg_raddr2(rs2),
    .reg_rdata1(reg_rdata1),
    .reg_rdata2(reg_rdata2),

    .debug_x1(debug_x1),
    .debug_x10(debug_x10)
);

endmodule