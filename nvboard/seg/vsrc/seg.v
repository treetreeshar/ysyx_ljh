module bcd7seg(
	input [3:0] b,
	output reg [7:0] h
);
	always@(*)begin
		case(b)
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
			default:h=8'b11111101;
		endcase
	end
endmodule

module seg(
	input [7:0] a,
	input en,
	output reg [2:0] f,
	output reg in,
	output reg [7:0] h
);
always@(*) begin
	if(en) begin
	in=1;
	casez(a)
		8'b1???????:f=3'b111;
		8'b01??????:f=3'b110;
		8'b001?????:f=3'b101;
		8'b0001????:f=3'b100;
		8'b00001???:f=3'b011;
		8'b000001??:f=3'b010;
		8'b0000001?:f=3'b001;
		8'b00000001:f=3'b000;
		default:begin
			f=3'b000;
			in=0;
			end
	endcase
end
else begin
	in=0;
	f=3'b000;
	end
end

bcd7seg hex0(
	.b({1'b0,f}),
	.h(h)
);

endmodule


