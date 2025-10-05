/******************ifu********************/
module ysyx_25070198_ifu(
    input clk,
    input rst,

    input [31:0] jump_pc,
    input jump,
    input mem_data_valid,
    input mem_ren,
    input lsu_busy,
    
    output reg [31:0] pc,
    output reg [31:0] inst,
    output reg inst_valid,
    
    output reg [31:0] ifu_raddr,
    input [31:0] ifu_rdata
);

    //状态定义
    typedef enum logic [1:0] {
        IFU_IDLE = 2'b00,
        IFU_WAIT = 2'b01,
        IFU_HOLD = 2'b10
    } ifu_state_t;
    
    ifu_state_t ifu_current_state, ifu_next_state;
    
    always @(posedge clk) begin
        if (rst) begin
            pc <= 32'h80000000;
        end 
        else if (jump) begin
            pc <= jump_pc;
        end
        else if (inst_valid && !lsu_busy) begin //条件。？
            pc <= pc + 32'h4; 
        end
    end
    
    //状态寄存器
    always @(posedge clk) begin
        if (rst) begin
            ifu_current_state <= IFU_IDLE;
        end else begin
            ifu_current_state <= ifu_next_state;
        end
    end
    
    //输出逻辑和下一状态逻辑
    always @(*) begin
        case (ifu_current_state)
            IFU_IDLE: begin   //00
                ifu_raddr = pc;
                inst_valid = 1'b0;
                inst = 32'h0;
                //如果LSU忙或者需要读内存，进入HOLD；否则正常取指
                if (lsu_busy || (mem_ren && !mem_data_valid)) begin
                    ifu_next_state = IFU_HOLD;
                end else begin
                    ifu_next_state = IFU_WAIT;
                end
            end
            
            IFU_WAIT: begin   //01
                ifu_raddr = pc;
                inst_valid = 1'b1;
                inst = ifu_rdata;

                //只要当前指令是内存操作，就进入HOLD等待。？？
                if (mem_ren || lsu_busy) begin
                    ifu_next_state = IFU_HOLD;
                end else begin
                    ifu_next_state = IFU_IDLE;
                end
            end
            
            IFU_HOLD: begin   //10
                ifu_raddr = pc;        // 保持当前地址
                inst_valid = 1'b0;     // 指令无效
                inst = 32'h0;
                
                //等待所有条件满足：LSU不忙且内存操作完成。？？
                if (!lsu_busy && (!mem_ren || mem_data_valid)) begin
                    ifu_next_state = IFU_WAIT;
                end else begin
                    ifu_next_state = IFU_HOLD;
                end
            end
            
            default: begin
                ifu_raddr = 32'h0;
                inst_valid = 1'b0;
                inst = 32'h0;
                ifu_next_state = IFU_IDLE;
            end
        endcase
    end

endmodule

/******************idu********************/
module ysyx_25070198_idu(
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
    output is_sb,
    
    output is_csrrw

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

    assign is_csrrw = (opcode == 7'b1110011) && (funct3 == 3'b001);   //I
    
    wire [31:0] i_imm = {{20{inst[31]}}, inst[31:20]};
    wire [31:0] s_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    wire [31:0] u_imm = {inst[31:12], 12'b0};
    //r型无立即数 有funct7
    wire [31:0] csr_imm = {20'b0, inst[31:20]};

    assign imm = (is_addi || is_jalr || is_lw || is_lbu ) ? i_imm :
                 (is_lui) ? u_imm :
                 (is_sw || is_sb) ? s_imm :
                 (is_csrrw) ? csr_imm :
                 32'b0;
   
endmodule


/******************exu********************/
module ysyx_25070198_exu(
    input clk,
    input rst,

    input inst_valid,

    input is_addi,
    input is_jalr,
    input is_add,
    input is_lui,
    input is_lw,
    input is_lbu,
    input is_sw,
    input is_sb,

    input is_csrrw,
    input [31:0] csr_rdata,
    output csr_wen,
    output [11:0] csr_addr,

    input mem_data_valid,

    input [31:0] pc,
    input [31:0] reg_rdata1,reg_rdata2,imm,
    output mem_ren,mem_wen,reg_wen,reg_men,
    output [31:0] reg_wdata,mem_wdata,
    output [29:0] mem_addr,
    output [3:0] mem_mask, 
    output [1:0] sel,

    output [31:0] jump_pc,
    output jump
);
assign jump_pc = is_jalr ? (reg_rdata1 + imm) & 32'hFFFFFFFE : 32'b0;
assign jump = is_jalr;

assign reg_wen = ((is_add || is_addi || is_jalr || is_lui || is_csrrw) && inst_valid) || 
                 ((is_lw || is_lbu) && mem_data_valid);
assign reg_men = (is_lw || is_lbu) && inst_valid;

assign mem_ren = (is_lw || is_lbu) && inst_valid && !mem_data_valid;
assign mem_wen = (is_sw || is_sb) && inst_valid;// && !mem_data_valid;

assign sel = {reg_rdata1 + imm}[1:0];

assign mem_addr = (mem_ren || mem_wen) ? {reg_rdata1 + imm}[31:2] : 30'b0;
assign mem_mask = (is_sb) ? (4'b0001 << sel):
                    (is_sw) ? 4'b1111 :
                    4'b0;

assign reg_wdata = (is_jalr) ? pc + 32'h4 : 
                    (is_addi) ? reg_rdata1 + imm :
                    (is_add) ? reg_rdata1 + reg_rdata2 :
                    (is_lui) ? imm :
                    (is_csrrw) ? csr_rdata :
                    32'b0;

assign mem_wdata = (is_sw) ? reg_rdata2 : 
                    (is_sb && mem_mask == 4'd1) ? {24'b0, reg_rdata2[7:0]} :
                    (is_sb && mem_mask == 4'd2) ? {16'b0, reg_rdata2[7:0], 8'b0} :
                    (is_sb && mem_mask == 4'd4) ? {8'b0, reg_rdata2[7:0], 16'b0} :
                    (is_sb && mem_mask == 4'd8) ? {reg_rdata2[7:0], 24'b0} :
                    0;

assign csr_wen = is_csrrw && inst_valid;
assign csr_addr = imm[11:0];

endmodule


/******************reg********************/
module ysyx_25070198_rf(
    input clk,
    input rst,

    input [31:0] reg_wdata,mem_rdata,
    input [4:0] reg_waddr,
    input reg_wen,reg_men,is_lbu,
    input [1:0] sel,

    input [4:0] reg_raddr1,reg_raddr2,
    output [31:0] reg_rdata1,reg_rdata2,

    output [31:0] debug_x4,debug_x10

);
reg [31:0] rf [0:31];

assign debug_x4 = rf[5];
assign debug_x10 = rf[10];

wire [7:0] mem_rdatas = (sel == 2'd0) ? mem_rdata[7:0] :
                        (sel == 2'd1) ? mem_rdata[15:8] :
                        (sel == 2'd2) ? mem_rdata[23:16] :
                        (sel == 2'd3) ? mem_rdata[31:24] :
                        0;

integer i;
/*
always@(posedge clk or posedge rst) begin
    if(rst) begin
        for(i=0; i<32; i=i+1) rf[i] <= 0;
    end
    else if(reg_wen && reg_waddr != 5'b0) begin
        rf[reg_waddr] <= reg_wdata;
    end
    else if(reg_men && reg_waddr != 5'b0) begin
        rf[reg_waddr] <= (is_lbu) ? {24'b0, mem_rdatas} : mem_rdata;
    end
end
*/
always@(posedge clk or posedge rst) begin
    if(rst) begin
        for(i=0; i<32; i=i+1) rf[i] <= 0;
    end
    else if(reg_wen && reg_waddr != 5'b0) begin
        // 如果是内存读取操作，使用mem_rdata；否则使用reg_wdata
        if(reg_men) begin
            rf[reg_waddr] <= (is_lbu) ? {24'b0, mem_rdatas} : mem_rdata;
        end else begin
            rf[reg_waddr] <= reg_wdata;
        end
    end
end

assign reg_rdata1 = rf[reg_raddr1];
assign reg_rdata2 = rf[reg_raddr2];

endmodule

