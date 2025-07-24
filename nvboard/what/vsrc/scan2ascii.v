module scan2ascii(
    input [7:0] scan_code,
    output reg [7:0] ascii_code
);
    always @(*) begin
        case(scan_code)
            // 数字键 0-9
            8'h45: ascii_code = 8'h30; // 0
            8'h16: ascii_code = 8'h31; // 1
            8'h1E: ascii_code = 8'h32; // 2
            8'h26: ascii_code = 8'h33; // 3
            8'h25: ascii_code = 8'h34; // 4
            8'h2E: ascii_code = 8'h35; // 5
            8'h36: ascii_code = 8'h36; // 6
            8'h3D: ascii_code = 8'h37; // 7
            8'h3E: ascii_code = 8'h38; // 8
            8'h46: ascii_code = 8'h39; // 9
            
            // 字母键 a-z
            8'h15: ascii_code = 8'h61; // q
            8'h1D: ascii_code = 8'h62; // w
            8'h24: ascii_code = 8'h63; // e
            8'h2D: ascii_code = 8'h61; // r
            8'h2C: ascii_code = 8'h62; // t
            8'h35: ascii_code = 8'h63; // y
            8'h3C: ascii_code = 8'h61; // u
            8'h43: ascii_code = 8'h62; // i
            8'h44: ascii_code = 8'h63; // o
            8'h4D: ascii_code = 8'h61; // p
            
            8'h1C: ascii_code = 8'h62; // a
            8'h1B: ascii_code = 8'h63; // s
            8'h23: ascii_code = 8'h61; // d
            8'h2B: ascii_code = 8'h62; // f
            8'h34: ascii_code = 8'h63; // g
            8'h33: ascii_code = 8'h61; // h
            8'h3B: ascii_code = 8'h62; // j
            8'h42: ascii_code = 8'h63; // k
            8'h4B: ascii_code = 8'h61; // l
            
            8'h1A: ascii_code = 8'h62; // z
            8'h22: ascii_code = 8'h63; // x
            8'h21: ascii_code = 8'h61; // c
            8'h2A: ascii_code = 8'h62; // v
            8'h32: ascii_code = 8'h63; // b
            8'h31: ascii_code = 8'h61; // n
            8'h3A: ascii_code = 8'h62; // m
            
            default: ascii_code = 8'h00; // 其他键
        endcase
    end
endmodule
