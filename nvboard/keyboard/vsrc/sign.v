module sign(
	input clk,
	input rst,
	input ready,
	input [7:0] data_in,
	output reg pressed,
	output reg pressing,
	output reg [7:0] data_out
);

reg flag=0;//f0
reg [7:0] d1=0;

always @(posedge clk or posedge rst) begin
	if(rst) begin
		pressed<=0;
		pressing<=0;
		data_out<=8'h00;
		d1<=0;
		flag<=0;
	end
	else begin
		if(ready) begin
			if(data_in==8'hf0) begin 
				flag<=1;
				pressing<=0;
			end
			else begin 
				if(flag) begin 
				pressed<=0;
				flag<=0;
				d1<=0;
			end
			else begin
				pressing<=1;
				if(data_in==d1) begin
					pressed<=0;
					data_out<=d1;
				end
				else begin
					pressed<=1;
					d1<=data_in;
					data_out<=data_in;
				end
			end
		end
	end
end
end
endmodule
