module ps2_keyboard(
    input clk, rst, ps2_clk, ps2_data,
    output reg [7:0] data,
    output reg data_ready
);

    reg [9:0] buffer;   
    reg [3:0] count;   
    reg [2:0] ps2_clk_sync;
    reg data_ready2;

    always @(posedge clk) begin 
        ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (rst) begin 
            count <= 0;
            data <= 0;
            data_ready <= 0;
            data_ready2 <= 0;
        end
        else begin
            data_ready <= 0;
            
            if (data_ready2) begin
                data_ready <= 1;
                data_ready2 <= 0;
            end

            if (sampling) begin
                if (count == 4'd10) begin
                    if ((buffer[0] == 0) && 
                        (ps2_data)       &&
                        (^buffer[9:1]))   
                    begin
                        $display("receive %x", buffer[8:1]);
                        data <= buffer[8:1];
                        data_ready2 <= 1;
                    end
                    count <= 0;
                end else begin
                    buffer[count] <= ps2_data;  
                    count <= count + 1;
                end
            end
        end
    end
endmodule
