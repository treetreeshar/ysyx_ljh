module top(
    input clk,
    input rst,

    output [31:0] pc,inst,
    output [31:0] debug_x4,debug_x10,
    output [31:0] mcycle,mcycleh
);

    always @(posedge clk) begin
        if (!rst && inst_valid && inst == 32'h00100073) begin
            npc_ebreak();
        end
    end

    // IFU接口
    //wire [31:0] pc;
    wire [31:0] jump_pc;
    wire jump;
    wire inst_valid;
    
    // IDU接口
    //wire [31:0] inst;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] imm;
    wire is_addi, is_jalr, is_add, is_lui, is_lw, is_lbu, is_sw, is_sb, is_csrrw;
    
    // EXU接口
    wire [31:0] reg_rdata1, reg_rdata2;
    wire mem_ren, mem_wen, reg_wen, reg_men;
    wire [31:0] reg_wdata, mem_wdata;
    wire [29:0] mem_addr;
    wire [3:0] mem_mask;
    wire [1:0] sel;

    // CSR接口
    wire csr_wen;
    wire [11:0] csr_addr;
    wire [31:0] csr_rdata;

    // LSU接口
    wire [31:0] lsu_addr;
    wire lsu_wen;
    wire [31:0] lsu_wdata;
    wire [3:0] lsu_wmask;
    reg [31:0] lsu_rdata;
    wire mem_data_valid;
    wire inst_done;
    
    // 内存接口
    wire [31:0] mem_rdata;
    
    // DPI-C内存接口
    import "DPI-C" function void npc_ebreak();
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    // SimpleBus 接口
    wire [31:0] ifu_raddr;
    reg [31:0] ifu_rdata;
    wire ifu_reqValid;
    reg ifu_respValid;
    wire lsu_reqValid;
    reg lsu_respValid;

    // 指令执行完成
    assign inst_done = inst_valid && (!(is_lw || is_lbu) || mem_data_valid);

    // 取指
    //assign inst = pmem_read(pc);
    /*
    always @(posedge clk) begin
        if(rst) 
            ifu_rdata <= 32'b0;
        else
            ifu_rdata <= pmem_read(ifu_raddr);
    end
    */
    always @(posedge clk) begin
        if (rst) begin
            ifu_rdata <= 32'b0;
            ifu_respValid <= 1'b0;
        end else begin
            ifu_rdata <= ifu_reqValid ? pmem_read(ifu_raddr) : 32'b0;
            ifu_respValid <= ifu_reqValid;
        end
    end
    

    // 内存访问
    //assign mem_rdata = pmem_read({mem_addr, 2'b0});
    //always @(posedge clk) begin
    //    if (mem_wen) begin
    //        pmem_write({mem_addr, 2'b0}, mem_wdata, {4'b0, mem_mask});
    //    end
    //end
    /*
    always @(posedge clk) begin
        lsu_rdata <= (!lsu_wen) ? pmem_read(lsu_addr) : 32'b0;
        if (lsu_wen) begin
            pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask});
        end
    end
    */
    always @(posedge clk) begin
        lsu_rdata <= (lsu_reqValid && !lsu_wen) ? pmem_read(lsu_addr) : 32'b0;
        if (lsu_reqValid && lsu_wen) begin
            pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask});
        end
        lsu_respValid <= lsu_reqValid;
    end
    

    ysyx_25070198_ifu ysyx_25070198_ifu0(
        .clk(clk),
        .rst(rst),
        .jump_pc(jump_pc),
        .jump(jump),
        .pc(pc),
        .inst(inst),
        .inst_valid(inst_valid),
        .inst_done(inst_done),
        .mem_data_valid(mem_data_valid),
        .mem_ren(mem_ren),
        .ifu_rdata(ifu_rdata),
        .ifu_raddr(ifu_raddr),
        .ifu_reqValid(ifu_reqValid),
        .ifu_respValid(ifu_respValid)
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
        .is_sb(is_sb),
        
        .is_csrrw(is_csrrw)
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
        .jump(jump),

        .inst_valid(inst_valid),
        .mem_data_valid(mem_data_valid),

        .is_csrrw(is_csrrw),
        .csr_rdata(csr_rdata),
        .csr_wen(csr_wen),
        .csr_addr(csr_addr)
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

    ysyx_25070198_csr_reg ysyx_25070198_csr_reg0(
        .clk(clk),
        .rst(rst),
        .csr_wen(csr_wen),
        .csr_addr(csr_addr),
        .csr_wdata(reg_rdata1),
        .csr_rdata(csr_rdata),
        .mcycle(mcycle),
        .mcycleh(mcycleh)
    );

    ysyx_25070198_lsu ysyx_25070198_lsu0(
        .clk(clk),
        .rst(rst),
        .mem_ren(mem_ren),
        .mem_wen(mem_wen),
        .mem_addr({mem_addr, 2'b0}),
        .mem_wdata(mem_wdata),
        .mem_mask(mem_mask),
        .mem_rdata(mem_rdata),
        .mem_data_valid(mem_data_valid),
        .lsu_addr(lsu_addr),
        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_rdata(lsu_rdata),
        .lsu_reqValid(lsu_reqValid),
        .lsu_respValid(lsu_respValid)
    );

endmodule