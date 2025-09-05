module top(
    input clk,
    input rst,

    output [31:0] pc,inst,
    output [31:0] debug_x4,debug_x10
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
    wire [29:0] mem_addr;
    wire [3:0] mem_mask;
    wire [1:0] sel;
    
    // 内存接口
    wire [31:0] mem_rdata;
    
    // DPI-C内存接口
    import "DPI-C" function void npc_ebreak();
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    
    // 取指
    assign inst = pmem_read(pc);

    // 内存访问
    assign mem_rdata = pmem_read({mem_addr, 2'b0});
    always @(posedge clk) begin
        if (mem_wen) begin
            pmem_write({mem_addr, 2'b0}, mem_wdata, {4'b0, mem_mask});
        end
    end
    
    ysyx_25070198_ifu ysyx_25070198_ifu0(
        .clk(clk),
        .rst(rst),
        .jump_pc(jump_pc),
        .jump(jump),
        .pc(pc)
    );
    
    ysyx_25070198_idu ysyx_25070198_idu0(
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

    ysyx_25070198_exu ysyx_25070198_exu0(
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
        .sel(sel),
        .jump_pc(jump_pc),
        .jump(jump)
    );

    ysyx_25070198_rf ysyx_25070198_rf0(
        .clk(clk),
        .rst(rst),
        .reg_wdata(reg_wdata),
        .mem_rdata(mem_rdata),
        .reg_waddr(rd),
        .reg_wen(reg_wen),
        .reg_men(reg_men),
        .is_lbu(is_lbu),
        .sel(sel),
        .reg_raddr1(rs1),
        .reg_raddr2(rs2),
        .reg_rdata1(reg_rdata1),
        .reg_rdata2(reg_rdata2),
        .debug_x4(debug_x4),
        .debug_x10(debug_x10)
    );

endmodule