/******************lsu********************/
module ysyx_25070198_lsu(
    input clock,
    input reset,
    
    //来自EXU
    input mem_ren,
    input mem_wen,
    input [31:0] mem_addr,
    input [31:0] mem_wdata,
    input [3:0] mem_mask,
    
    //到寄存器堆
    output reg [31:0] mem_rdata,
    
    //SimpleBus接口
    output reg [31:0] io_lsu_addr,
    output reg io_lsu_wen,
    output reg [31:0] io_lsu_wdata,
    output reg [3:0] io_lsu_wmask,
    input [31:0] io_lsu_rdata,

    output reg io_lsu_reqValid,
    input io_lsu_respValid
);

    //状态定义
    typedef enum logic {
        LSU_IDLE = 1'b0,
        LSU_WAIT = 1'b1
    } lsu_state_t;
    
    lsu_state_t lsu_current_state, lsu_next_state;

    //状态寄存器
    always @(posedge clock) begin
        if (reset) begin
            lsu_current_state <= LSU_IDLE;
        end else begin
            lsu_current_state <= lsu_next_state;
        end
    end
    
    //下一状态逻辑
    always @(*) begin
        case (lsu_current_state)
            LSU_IDLE: begin    //0
                if (mem_ren || mem_wen) begin
                    lsu_next_state = LSU_WAIT;  //读写操作->等待
                end else begin
                    lsu_next_state = LSU_IDLE;
                end
            end

            LSU_WAIT: begin    //1
                if(io_lsu_respValid) 
                    lsu_next_state = LSU_IDLE;  //完成返回IDLE
                else
                    lsu_next_state = LSU_WAIT;  //继续等待
            end
            
            default: begin
                lsu_next_state = LSU_IDLE;
            end
        endcase
    end
    
    //输出逻辑
    always @(*) begin
        case (lsu_current_state)
            LSU_IDLE: begin   //0
                io_lsu_reqValid = mem_ren || mem_wen;
                io_lsu_addr = mem_addr;
                io_lsu_wen = mem_wen;
                io_lsu_wdata = mem_wdata;
                io_lsu_wmask = mem_mask;
                mem_rdata = 32'b0;
            end
            
            LSU_WAIT: begin   //1
                io_lsu_reqValid = 1'b1;      //保持请求有效
                io_lsu_addr = mem_addr;      //保持地址不变
                io_lsu_wen = mem_wen;        //保持写使能状态
                io_lsu_wdata = mem_wdata;    //保持写数据
                io_lsu_wmask = mem_mask;     //保持写掩码
                mem_rdata = io_lsu_rdata;    //使用从内存读取的数据
            end

            default: begin
                io_lsu_reqValid = 1'b0;
                io_lsu_addr = 32'b0;
                io_lsu_wen = 1'b0;
                io_lsu_wdata = 32'b0;
                io_lsu_wmask = 4'b0;
                mem_rdata = 32'b0;
            end
        endcase
    end

endmodule