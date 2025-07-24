module top(
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output [7:0] h0,
    output [7:0] h1,
    output [7:0] h2,
    output [7:0] h3,
    output [7:0] h4,
    output [7:0] h5
);

    wire [7:0] data_in;
    wire [7:0] data_out;
    wire data_ready;
    wire pressing;
    wire pressed;
    
    ps2_keyboard keyboard1(
        .clk(clk),
        .rst(rst),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .data(data_in),
        .data_ready(data_ready)
    );
    
    sign sign1(
    	.clk(clk),
    	.rst(rst),
    	.ready(data_ready),
    	.data_in(data_in),
    	.pressing(pressing),
    	.pressed(pressed),
    	.data_out(data_out)
    );
    
    led led1(
        .clk(clk),
        .data(data_out),
        .data_ready(data_ready),
        .pressing(pressing),
        .h0(h0),
        .h1(h1),
        .h2(h2),
        .h3(h3)
    );
    
    count count1(
    	.clk(clk),
    	.rst(rst),
    	.pressed(pressed),
        .h4(h4),
        .h5(h5)
    );

endmodule

