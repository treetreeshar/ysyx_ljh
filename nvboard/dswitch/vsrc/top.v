module top(
	input a,
	input b,
	output f
);
	assign f = a ^ b ;

	/*
	initial begin
		$dumpfile("top.vcd");
		$dumpvars(0,top);
	end
	*/
endmodule
