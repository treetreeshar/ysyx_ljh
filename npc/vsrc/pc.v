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

    output [4:0] rs1,//什么时候reg??
    output [4:0] rs2,
    output [4:0] rd,
    output [31:0] imm,
    output is_jalr
    //output [6:0] opcode,
    //output [2:0] funct3,
    //output [6:0] funct7
);

    wire [6:0] opcode;
    wire [2:0] funct3;

    assign opcode = inst[6:0];
    assign rd = inst[11:7];
    assign funct3 = inst[14:12];
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    //assign funct7 = inst[31:25];


    assign is_jalr = (opcode == 7'b1100111) && (funct3 == 3'b000);
    
    wire [31:0] i_imm = {{20{inst[31]}}, inst[31:20]};
    //wire [31:0] s_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    //wire [31:0] u_imm = {inst[31:12], 12'b0};
    
    assign imm = i_imm;//(opcode == 7'b0010011) ? i_imm :   I-type (addi)
                //(opcode == 7'b0110111) ? u_imm :   U-type (lui)
                //32'b0;
endmodule


/******************exu********************/
module exu(
    input clk,
    input rst,

    input is_jalr,
    input [31:0] pc,

    input [31:0] reg_rdata1,reg_rdata2,imm,
    output [31:0] ans,
    output [31:0] jump_pc,
    output jump
);
assign jump_pc = is_jalr ? (reg_rdata1 + imm) & 32'hFFFFFFFE : 32'b0;
assign ans = (is_jalr) ? pc + 4 : reg_rdata1 + imm;
assign jump = is_jalr;
endmodule


/******************reg********************/
module rf(
    input clk,
    input rst,

    input [31:0] reg_wdata,
    input [4:0] reg_waddr,
    input reg_wen,

    input [4:0] reg_raddr1,reg_raddr2,
    output [31:0] reg_rdata1,reg_rdata2,

    output [31:0] debug_x1,
    output [31:0] debug_x10
);
reg [31:0] rf [0:31];

assign debug_x1 = rf[1];
assign debug_x10 = rf[10];

integer i;
always@(posedge clk or posedge rst) begin
    if(rst) begin
        for(i=0; i<32; i=i+1) rf[i] <= 0;
    end
    else if(reg_wen && reg_waddr!=5'd0) begin
        rf[reg_waddr] <= reg_wdata;
    end
end

assign reg_rdata1 = rf[reg_raddr1];
assign reg_rdata2 = rf[reg_raddr2];

endmodule

