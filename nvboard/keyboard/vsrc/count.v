module count(
	input clk,
	input pressed,
	input rst,
	output reg [7:0] h4,
	output reg [7:0] h5
);

reg [7:0] cnt;
reg pressed_prev;

always @(posedge clk or posedge rst) begin
	if(rst) begin 
		cnt<=0;
		pressed_prev<=0;
		end 
	else begin
		pressed_prev<=pressed;
		if(pressed && !pressed_prev) begin 
			cnt<=cnt+1;
			end
		end
	end
	
always @(*) begin
	if(rst) begin
		h4=8'b00000011;
		h5=8'b00000011;
		end
		else begin 
			case(cnt[3:0])
				4'd0:h4=8'b00000011;
				4'd1:h4=8'b10011111;
				4'd2:h4=8'b00100101;
				4'd3:h4=8'b00001101;
				4'd4:h4=8'b10011001;
				4'd5:h4=8'b01001001;
				4'd6:h4=8'b01000001;
				4'd7:h4=8'b00011111;
				4'd8:h4=8'b00000001;
				4'd9:h4=8'b00001001;
				4'd10:h4=8'b00010001;
				4'd11:h4=8'b11000001;
				4'd12:h4=8'b01100011;
				4'd13:h4=8'b10000101;
				4'd14:h4=8'b01100001;
				4'd15:h4=8'b01110001;
				default:h4=8'b11111101;
			endcase
			case(cnt[7:4])
				4'd0:h5=8'b00000011;
				4'd1:h5=8'b10011111;
				4'd2:h5=8'b00100101;
				4'd3:h5=8'b00001101;
				4'd4:h5=8'b10011001;
				4'd5:h5=8'b01001001;
				4'd6:h5=8'b01000001;
				4'd7:h5=8'b00011111;
				4'd8:h5=8'b00000001;
				4'd9:h5=8'b00001001;
				4'd10:h5=8'b00010001;
				4'd11:h5=8'b11000001;
				4'd12:h5=8'b01100011;
				4'd13:h5=8'b10000101;
				4'd14:h5=8'b01100001;
				4'd15:h5=8'b01110001;
				default:h5=8'b11111101;
			endcase
			end
		end
endmodule
