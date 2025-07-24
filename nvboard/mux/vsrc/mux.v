module mux(
	input [1:0] key,
	input [7:0] lut,
	output reg [1:0] out
);

always@(*) begin
	case(key)
	2'b00:out=lut[1:0];
	2'b01:out=lut[3:2];
	2'b10:out=lut[5:4];
	2'b11:out=lut[7:6];
	default:out=2'b00;
	endcase
end
endmodule
