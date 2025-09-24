module ysyx_25070198_csr_reg (
    input clk,
    input rst,
    input csr_wen,
    input [11:0] csr_addr,
    input [31:0] csr_wdata,//rs1 reg_rdata1
    output [31:0] csr_rdata
);
    reg [31:0] mcycle;
    reg [31:0] mcycleh;
    reg [31:0] mvendorid;
    reg [31:0] marchid;

    always @(posedge clk) begin
        if (rst) begin
            {mcycleh, mcycle} <= 64'b0;
            mvendorid <= 32'h79737978;
            marchid <= 32'd25070198;
        end
        else if (csr_wen) begin
            case (csr_addr)
                12'hB00: mcycle  <= csr_wdata;
                12'hB80: mcycleh <= csr_wdata;
                default: {mcycleh, mcycle} <= {mcycleh, mcycle} + 64'b1;
            endcase
        end
        else begin
            {mcycleh, mcycle} <= {mcycleh, mcycle} + 64'b1;
        end
    end

    assign csr_rdata = (csr_addr == 12'hB00) ? mcycle :
                      (csr_addr == 12'hB80) ? mcycleh :
                      (csr_addr == 12'hF11) ? mvendorid :
                      (csr_addr == 12'hF12) ? marchid :
                      32'b0;


endmodule