module lfsr(
	input clk,
	input rst,
	output reg [7:0] random_num,
	output reg [7:0] hex0,
	output reg [7:0] hex1
);

wire feedback = random_num[0] ^ random_num[2] ^ random_num[3] ^ random_num[4];

always @(posedge clk or posedge rst) begin
	if (rst) begin
		random_num <= 8'b00000001;
		end
	else begin
		random_num <= {feedback, random_num[7:1]};
	end
end

always @(*) begin
	case (random_num[3:0])
		4'd0:hex0=8'b00000011;
		4'd1:hex0=8'b10011111;
		4'd2:hex0=8'b00100101;
		4'd3:hex0=8'b00001101;
		4'd4:hex0=8'b10011001;
		4'd5:hex0=8'b01001001;
		4'd6:hex0=8'b01000001;
		4'd7:hex0=8'b00011111;
		4'd8:hex0=8'b00000001;
		4'd9:hex0=8'b00001001;
		4'd10:hex0=8'b00010001;
		4'd11:hex0=8'b11000001;
		4'd12:hex0=8'b01100011;
		4'd13:hex0=8'b10000101;
		4'd14:hex0=8'b01100001;
		4'd15:hex0=8'b01110001;
		default:hex0=8'b11111101;
	endcase

	case (random_num[7:4])
		4'd0:hex1=8'b00000011;
		4'd1:hex1=8'b10011111;
		4'd2:hex1=8'b00100101;
		4'd3:hex1=8'b00001101;
		4'd4:hex1=8'b10011001;
		4'd5:hex1=8'b01001001;
		4'd6:hex1=8'b01000001;
		4'd7:hex1=8'b00011111;
		4'd8:hex1=8'b00000001;
		4'd9:hex1=8'b00001001;
		4'd10:hex1=8'b00010001;
		4'd11:hex1=8'b11000001;
		4'd12:hex1=8'b01100011;
		4'd13:hex1=8'b10000101;
		4'd14:hex1=8'b01100001;
		4'd15:hex1=8'b01110001;
		default:hex1=8'b11111101;
	endcase
end

endmodule
