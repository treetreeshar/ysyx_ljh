module alu(
	input [3:0] a,
	input [3:0] b,
	input [2:0] sel,
	output reg [3:0] out,
	output reg zero,overflow,c //LD6,LD5,LD4
);
	always@(*) begin
	out = 4'b0000;
        zero = 0;
        overflow = 0;
        c = 0;
		case(sel)
			3'b000:begin
				{c,out}={1'b0,a}+{1'b0,b};
				zero=~(| out);
				overflow=(a[3]==b[3])&&(out[3]!=a[3]);
				end
			3'b001:begin
				{c,out}={1'b0,a}-{1'b0,b};
				zero=~(| out);
				overflow=(a[3]!=b[3])&&(out[3]!=a[3]);
				end
			3'b010:out=~a;
			3'b011:out=a&b;
			3'b100:out=a|b;
			3'b101:out=a^b;
			3'b110:out = ($signed(a) < $signed(b)) ? 4'b0001:4'b0000;
			3'b111:out=(a==b)?4'b0001:4'b0000;
			default:out=4'b0000;
		endcase
	end
endmodule
