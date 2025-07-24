module led(
	input clk,
	input [7:0] data,
	input data_ready,
	input pressing,
	output reg [7:0] h0,
	output reg [7:0] h1,
	output reg [7:0] h2,
	output reg [7:0] h3
);

reg [7:0] ascii_data;
always @(*) begin
        case(data)
            8'h45: ascii_data = 8'h30; // 0
            8'h16: ascii_data = 8'h31; // 1
            8'h1E: ascii_data = 8'h32; // 2
            8'h26: ascii_data = 8'h33; // 3
            8'h25: ascii_data = 8'h34; // 4
            8'h2E: ascii_data = 8'h35; // 5
            8'h36: ascii_data = 8'h36; // 6
            8'h3D: ascii_data = 8'h37; // 7
            8'h3E: ascii_data = 8'h38; // 8
            8'h46: ascii_data = 8'h39; // 9
            
            
            8'h15: ascii_data = 8'h61; // q
            8'h1D: ascii_data = 8'h62; // w
            8'h24: ascii_data = 8'h63; // e
            8'h2D: ascii_data = 8'h61; // r
            8'h2C: ascii_data = 8'h62; // t
            8'h35: ascii_data = 8'h63; // y
            8'h3C: ascii_data = 8'h61; // u
            8'h43: ascii_data = 8'h62; // i
            8'h44: ascii_data = 8'h63; // o
            8'h4D: ascii_data = 8'h61; // p
            
            8'h1C: ascii_data = 8'h62; // a
            8'h1B: ascii_data = 8'h63; // s
            8'h23: ascii_data = 8'h61; // d
            8'h2B: ascii_data = 8'h62; // f
            8'h34: ascii_data = 8'h63; // g
            8'h33: ascii_data = 8'h61; // h
            8'h3B: ascii_data = 8'h62; // j
            8'h42: ascii_data = 8'h63; // k
            8'h4B: ascii_data = 8'h61; // l
            
            8'h1A: ascii_data = 8'h62; // z
            8'h22: ascii_data = 8'h63; // x
            8'h21: ascii_data = 8'h61; // c
            8'h2A: ascii_data = 8'h62; // v
            8'h32: ascii_data = 8'h63; // b
            8'h31: ascii_data = 8'h61; // n
            8'h3A: ascii_data = 8'h62; // m
            
            default: ascii_data = 8'h00;
        endcase
    end
    
always @(posedge clk) begin
	if (pressing) begin
		case(data[3:0])
			4'd0:h0<=8'b00000011;
			4'd1:h0<=8'b10011111;
			4'd2:h0<=8'b00100101;
			4'd3:h0<=8'b00001101;
			4'd4:h0<=8'b10011001;
			4'd5:h0<=8'b01001001;
			4'd6:h0<=8'b01000001;
			4'd7:h0<=8'b00011111;
			4'd8:h0<=8'b00000001;
			4'd9:h0<=8'b00001001;
			4'd10:h0<=8'b00010001;
			4'd11:h0<=8'b11000001;
			4'd12:h0<=8'b01100011;
			4'd13:h0<=8'b10000101;
			4'd14:h0<=8'b01100001;
			4'd15:h0<=8'b01110001;
			default:h0<=8'b11111101;
		endcase
		case(data[7:4])
			4'd0:h1<=8'b00000011;
			4'd1:h1<=8'b10011111;
			4'd2:h1<=8'b00100101;
			4'd3:h1<=8'b00001101;
			4'd4:h1<=8'b10011001;
			4'd5:h1<=8'b01001001;
			4'd6:h1<=8'b01000001;
			4'd7:h1<=8'b00011111;
			4'd8:h1<=8'b00000001;
			4'd9:h1<=8'b00001001;
			4'd10:h1<=8'b00010001;
			4'd11:h1<=8'b11000001;
			4'd12:h1<=8'b01100011;
			4'd13:h1<=8'b10000101;
			4'd14:h1<=8'b01100001;
			4'd15:h1<=8'b01110001;
			default:h1<=8'b11111101;
		endcase
		
		
		case(ascii_data[3:0])
			4'd0:h2<=8'b00000011;
			4'd1:h2<=8'b10011111;
			4'd2:h2<=8'b00100101;
			4'd3:h2<=8'b00001101;
			4'd4:h2<=8'b10011001;
			4'd5:h2<=8'b01001001;
			4'd6:h2<=8'b01000001;
			4'd7:h2<=8'b00011111;
			4'd8:h2<=8'b00000001;
			4'd9:h2<=8'b00001001;
			4'd10:h2<=8'b00010001;
			4'd11:h2<=8'b11000001;
			4'd12:h2<=8'b01100011;
			4'd13:h2<=8'b10000101;
			4'd14:h2<=8'b01100001;
			4'd15:h2<=8'b01110001;
			default:h2<=8'b11111101;
		endcase
		case(ascii_data[7:4])
			4'd0:h3<=8'b00000011;
			4'd1:h3<=8'b10011111;
			4'd2:h3<=8'b00100101;
			4'd3:h3<=8'b00001101;
			4'd4:h3<=8'b10011001;
			4'd5:h3<=8'b01001001;
			4'd6:h3<=8'b01000001;
			4'd7:h3<=8'b00011111;
			4'd8:h3<=8'b00000001;
			4'd9:h3<=8'b00001001;
			4'd10:h3<=8'b00010001;
			4'd11:h3<=8'b11000001;
			4'd12:h3<=8'b01100011;
			4'd13:h3<=8'b10000101;
			4'd14:h3<=8'b01100001;
			4'd15:h3<=8'b01110001;
			default:h3<=8'b11111101;
		endcase
	end
	else begin 
		h0<=8'b11111111;
		h1<=8'b11111111;
		h2<=8'b11111111;
		h3<=8'b11111111;
		end
end
endmodule
