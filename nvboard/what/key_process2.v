module key_processor(
    input clk,
    input rst,
    input ready,
    input [7:0] data,
    output reg key_pressed,
    output reg is_pressed, 
    output reg [7:0] current_key
);


localparam IDLE = 1'b0;
localparam RELEASE_WAIT = 1'b1;

reg state;

always @(posedge clk or posedge reset) begin
    if (rst) begin
        state <= IDLE;
        key_pressed <= 1'b0;
        is_pressed <= 1'b0;
        current_key <= 8'h00;
    end
    else begin
        // 默认值：脉冲信号只持续一个周期
        key_pressed <= 1'b0;
        
        // 状态机逻辑
        case (state)
            IDLE: begin
                if (ready) begin
                    if (data == 8'hF0) begin
                        // 收到松开前缀，进入松开等待状态
                        state <= RELEASE_WAIT;
                    end
                    else if (!is_pressed || (data != current_key)) begin
                        // 新按键按下（或切换按键）
                        current_key <= data;
                        key_pressed <= 1'b1;  // 触发按键事件
                        is_pressed <= 1'b1;   // 设置持续按下状态
                    end
                end
            end
            
            RELEASE_WAIT: begin
                if (ready) begin
                    // 收到松开键的扫描码，返回空闲状态
                    state <= IDLE;
                    is_pressed <= 1'b0;  // 清除持续按下状态
                end
            end
        endcase
    end
end

endmodule
