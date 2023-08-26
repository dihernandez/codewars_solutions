module top_module ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    wire p2n_1;
    wire p2n_2;
    wire p1n_1;
    wire p1n_2;
    
    assign p2n_1 = (p2a & p2b);
    assign p2n_2 = (p2c * p2d);
    
    assign p1n_1 = (p1a & p1b & p1c);
    assign p1n_2 = (p1d & p1e & p1f);
    
    assign p2y = p2n_1 | p2n_2;
    assign p1y = p1n_1 | p1n_2;

endmodule

module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    wire clk_wire;
    wire [7:0] out1;
    wire [7:0] out2;
    wire [7:0] out3;
    
    my_dff8 instance1 (.clk(clk_wire), .d(d), .q(out1));
    my_dff8 instance2 (.clk(clk_wire), .d(out1), .q(out2));
    my_dff8 instance3 (.clk(clk_wire), .d(out2), .q(out3));
    
    always @(sel) begin
        case (sel)
            2'b00: q = d; 
            2'b01: q = out1;
            2'b10: q = out2;
            2'b11: q = out3; 
        endcase
            
    end

    assign clk_wire = clk;
    
endmodule

module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);

    wire carry_out;
    wire [15:0] lower_sum;
    wire [15:0] upper_sum;
    
    add16 first_adder (.a(a[15:0]), .b(b[15:0]), .sum(lower_sum), .cout(carry_out));
    add16 second_adder(.a(a[31:16]), .b(b[31:16]), .cin(carry_out), .sum(upper_sum));
    
    assign sum = {upper_sum, lower_sum};
    
endmodule