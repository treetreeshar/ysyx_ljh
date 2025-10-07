module ysyx_25070198(
    input clock,
    input reset,

    output io_ifu_reqValid,
    output [31:0] io_ifu_addr,
    input io_ifu_respValid,
    input [31:0] io_ifu_rdata,

    output io_lsu_reqValid,
    output [31:0] io_lsu_addr,

    output [1:0] io_lsu_size,

    output io_lsu_wen,
    output [31:0] io_lsu_wdata,
    output [3:0] io_lsu_wmask,
    input io_lsu_respValid,
    input [31:0] io_lsu_rdata

);

    always @(posedge clock) begin
        if (!reset && inst_valid && inst == 32'h00100073) begin
            npc_ebreak();
        end
    end

    // IFU接口
    wire [31:0] pc;
    wire [31:0] jump_pc;
    wire jump;
    wire inst_valid;
    
    // IDU接口
    wire [31:0] inst;
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
    wire inst_done;
    
    // 内存接口
    wire [31:0] mem_rdata;
    
    // DPI-C内存接口
    import "DPI-C" function void trans(input int pc0, input int inst0, input int a00);
    import "DPI-C" function void npc_ebreak();
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    // SimpleBus 接口
    wire [31:0] ifu_raddr;
    assign io_ifu_addr = ifu_raddr;

    // 指令执行完成
    assign inst_done = inst_valid && (!(is_lw || is_lbu || is_sb || is_sw) || io_lsu_respValid);

    always @(posedge clock) begin
        trans(pc, inst, debug_x10);
    end
    wire [31:0] debug_x10;

    //reg [5:0] cnt1, cnt2;
    // 取指
    //assign inst = pmem_read(pc);
    /*
    always @(posedge clock) begin
        if(reset) 
            io_ifu_rdata <= 32'b0;
        else
            io_ifu_rdata <= pmem_read(ifu_raddr);
    end
    
    always @(posedge clock) begin
        if (reset) begin
            io_ifu_rdata <= 32'b0;
            io_ifu_respValid <= 1'b0;
        end else begin
            io_ifu_rdata <= io_ifu_reqValid ? pmem_read(ifu_raddr) : 32'b0;
            if (cnt1 == 6'd0) begin
                io_ifu_respValid <= io_ifu_reqValid;
                cnt1 <= 6'b0;
            end
            else begin
                io_ifu_respValid <= 1'b0;
                cnt1 <= cnt1 + 6'b1;
            end
        end
    end
    */

    // 内存访问
    //assign mem_rdata = pmem_read({mem_addr, 2'b0});
    //always @(posedge clock) begin
    //    if (mem_wen) begin
    //        pmem_write({mem_addr, 2'b0}, mem_wdata, {4'b0, mem_mask});
    //    end
    //end
    /*
    always @(posedge clock) begin
        io_lsu_rdata <= (!io_lsu_wen) ? pmem_read(io_lsu_addr) : 32'b0;
        if (io_lsu_wen) begin
            pmem_write(io_lsu_addr, io_lsu_wdata, {4'b0, io_lsu_wmask});
        end
    end
    
    always @(posedge clock) begin
        io_lsu_rdata <= (io_lsu_reqValid && !io_lsu_wen) ? pmem_read(io_lsu_addr) : 32'b0;
        if (io_lsu_reqValid && io_lsu_wen) begin
            pmem_write(io_lsu_addr, io_lsu_wdata, {4'b0, io_lsu_wmask});
        end
        if (cnt2 == 6'd0) begin
            io_lsu_respValid <= io_lsu_reqValid;
            cnt2 <= 6'b0;
        end
        else begin
            io_lsu_respValid <= 1'b0;
            cnt2 <= cnt2 + 6'b1;
        end
    end
    */

    ysyx_25070198_ifu ysyx_25070198_ifu0(
        .clock(clock),
        .reset(reset),
        .jump_pc(jump_pc),
        .jump(jump),
        .pc(pc),
        .inst(inst),
        .inst_valid(inst_valid),
        .inst_done(inst_done),
        .io_lsu_respValid(io_lsu_respValid),
        .mem_ren(mem_ren),
        .io_ifu_rdata(io_ifu_rdata),
        .ifu_raddr(ifu_raddr),
        .io_ifu_reqValid(io_ifu_reqValid),
        .io_ifu_respValid(io_ifu_respValid)
    );
    
    ysyx_25070198_idu ysyx_25070198_idu0(
        .clock(clock),
        .reset(reset),
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
        
        .is_csrrw(is_csrrw),
        .io_lsu_size(io_lsu_size)
    );

    ysyx_25070198_exu ysyx_25070198_exu0(
        .clock(clock),
        .reset(reset),
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
        .io_lsu_respValid(io_lsu_respValid),

        .is_csrrw(is_csrrw),
        .csr_rdata(csr_rdata),
        .csr_wen(csr_wen),
        .csr_addr(csr_addr)
    );

    ysyx_25070198_rf ysyx_25070198_rf0(
        .clock(clock),
        .reset(reset),
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
        .debug_x10(debug_x10)
    );

    ysyx_25070198_csr_reg ysyx_25070198_csr_reg0(
        .clock(clock),
        .reset(reset),
        .csr_wen(csr_wen),
        .csr_addr(csr_addr),
        .csr_wdata(reg_rdata1),
        .csr_rdata(csr_rdata)
    );

    ysyx_25070198_lsu ysyx_25070198_lsu0(
        .clock(clock),
        .reset(reset),
        .mem_ren(mem_ren),
        .mem_wen(mem_wen),
        .mem_addr({mem_addr, 2'b0}),
        .mem_wdata(mem_wdata),
        .mem_mask(mem_mask),
        .mem_rdata(mem_rdata),
        .io_lsu_respValid(io_lsu_respValid),
        .io_lsu_addr(io_lsu_addr),
        .io_lsu_wen(io_lsu_wen),
        .io_lsu_wdata(io_lsu_wdata),
        .io_lsu_wmask(io_lsu_wmask),
        .io_lsu_rdata(io_lsu_rdata),
        .io_lsu_reqValid(io_lsu_reqValid)
    );

endmodule