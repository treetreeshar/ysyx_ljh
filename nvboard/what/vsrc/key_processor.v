module key_processor(
    input clk,
    input clrn,
    input data_ready,      // 来自 ps2_keyboard
    input [7:0] scancode,  // 来自 ps2_keyboard
    output reg [7:0] current_scan,
    output reg key_event,  // 有效按键事件
    output reg key_release // 按键松开信号
);
    reg state;  // 0: IDLE, 1: BREAK
    always @(posedge clk or negedge clrn) begin
        if (!clrn) begin
            state <= 0;
            current_scan <= 0;
            key_event <= 0;
            key_release <= 0;
        end else begin
            key_event <= 0;
            key_release <= 0;
            
            if (data_ready) begin
                case (state)
                    0: // IDLE
                        if (scancode == 8'hF0) state <= 1; 
                        else begin
                            current_scan <= scancode;
                            key_event <= 1;
                        end
                    1: // BREAK
                        begin
                            key_release <= 1;
                            state <= 0;
                        end
                endcase
            end
        end
    end
endmodule
