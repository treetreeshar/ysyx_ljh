module top(
    input clk,
    input clrn,
    input ps2_clk,
    input ps2_data,
    output [7:0] seg,
    output [5:0] an
);
    // PS/2接口信号
    wire [7:0] ps2_data_out;
    wire ready;
    wire nextdata_n = 0;  // 持续读取
    
    // 处理信号
    wire [7:0] current_scan;
    wire key_event, key_release;
    wire key_pressed;
    wire [7:0] key_count;
    wire [7:0] ascii_code;
    
    // 模块实例化
    ps2_keyboard ps2(.*);
    
    key_processor processor(
        .clk(clk),
        .clrn(clrn),
        .data_ready(ready),
        .scancode(ps2_data_out),
        .*
    );
    
    key_counter counter(.*);
    
    scan2ascii converter(
        .scan_code(current_scan),
        .*
    );
    
    seg7_display display(
        .key_count(key_count),
        .ascii_code(ascii_code),
        .scan_code(current_scan),
        .key_pressed(key_pressed),
        .*
    );
    
    // 按键状态跟踪
    always @(posedge clk or negedge clrn) begin
        if (!clrn) key_pressed <= 0;
        else begin
            if (key_event) key_pressed <= 1;
            if (key_release) key_pressed <= 0;
        end
    end
endmodule
