module seg7_display(
    input clk,
    input clrn,
    input [7:0] key_count,   // 按键次数
    input [7:0] ascii_code,  // ASCII码
    input [7:0] scan_code,   // 扫描码
    input key_pressed,       // 按键状态
    output reg [7:0] seg,    // 段码
    output reg [5:0] an      // 位选(6位数码管)
);
    // 拆分显示数据
    wire [3:0] digits[5:0];
    assign digits[5] = key_count[7:4];   // 按键次数高4位
    assign digits[4] = key_count[3:0];   // 按键次数低4位
    assign digits[3] = ascii_code[7:4];  // ASCII高4位
    assign digits[2] = ascii_code[3:0];  // ASCII低4位
    assign digits[1] = scan_code[7:4];   // 扫描码高4位
    assign digits[0] = scan_code[3:0];   // 扫描码低4位
    
    // 扫描计数器
    reg [19:0] refresh_cnt;
    reg [2:0] sel;
    
    always @(posedge clk) refresh_cnt <= refresh_cnt + 1;
    always @(posedge clk) sel <= refresh_cnt[19:17];  // 分频
    
    // 位选控制
    always @(*) begin
        an = 6'b111111;
        if (sel < 6) an[sel] = 0;
    end
    
    // 段码生成（带低四位消隐）
    always @(*) begin
        case(digits[sel])
           	4'd0:h=8'b00000011;
		4'd1:h=8'b10011111;
		4'd2:h=8'b00100101;
		4'd3:h=8'b00001101;
		4'd4:h=8'b10011001;
		4'd5:h=8'b01001001;
		4'd6:h=8'b01000001;
		4'd7:h=8'b00011111;
		4'd8:h=8'b00000001;
		4'd9:h=8'b00001001;
		4'd10:h=8'b00010001;
		4'd11:h=8'b11000001;
		4'd12:h=8'b01100011;
		4'd13:h=8'b10000101;
		4'd14:h=8'b01100001;
		4'd15:h=8'b01110001;
		default:h=8'b11111101; // 消隐
        endcase
        
        // 按键松开时消隐低四位
        if (!key_pressed && (sel < 4)) seg = 8'b11111111;
    end
endmodule
