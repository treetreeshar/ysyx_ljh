module key_counter(
    input clk,
    input clrn,
    input key_event,  // 来自状态机
    output reg [7:0] count
);
    always @(posedge clk or negedge clrn) begin
        if (!clrn) count <= 0;
        else if (key_event) count <= count + 1;
    end
endmodule
