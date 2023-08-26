module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//

endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );

    always @(*) begin
        case ({a,b}) begin
           2'b00: begin 
               if cin begin
                   cout = 1'b0;
                   sum = 1'b1;
               end
               else begin
                   cout = 1'b0;
                   sum = 1'b0;
               end
           end
           2'b01: begin 
               if cin begin
                   cout = 1'b1;
                   sum = 1'b0;
               end
               else begin
                   cout = 1'b0;
                   sum = 1'b1;
               end
           end
           2'b10: begin 
               if cin begin
                   cout = 1'b1;
                   sum = 1'b0;
               end
               else begin
                   cout = 1'b0;
                   sum = 1'b1;
               end
           end
           2'b11: begin 
               if cin begin
                   cout = 1'b1;
                   sum = 1'b1;
               end
               else begin
                   cout = 1'b1;
                   sum = 1'b0;
               end
           end
    end
// Full adder module here

endmodule



module add1 ( input a, input b, input cin, output sum, output cout );
// Full adder module here
  assign sum = a^b^cin;
    assign cout = a&b|a&cin|b&cin;
endmodule
            
module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    
    wire cin_16;
    wire [15:0] upper_sum;
    wire [15:0] lower_sum;
    
    add16 upper_adder (.a(a[15:0]), .b(b[15:0]), .cout(cin_16), .sum(lower_sum));
    add16 lower_adder (.a(a[31:16]), .b(b[31:16]), .cin(cin_16), .sum(upper_sum));
    
    assign sum = {upper_sum, lower_sum};
                                   
endmodule


module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    
    wire lower_carry;
    wire [15:0] add16_carry_0;
    wire [15:0] add16_carry_1;
    
    wire [15:0] lower_sum;
    wire [15:0] upper_sum;
    
    add16 lower_adder(.a(a[15:0]), .b(b[15:0]), .cin(1'b0), .sum(lower_sum), .cout(lower_carry));
    add16 upper_carry_0 (.a(a[31:16]), .b(b[31:16]), .cin(1'b0), .sum(add16_carry_0));
    add16 upper_carry_1 (.a(a[31:16]), .b(b[31:16]), .cin(1'b1), .sum(add16_carry_1));
    always @(*) begin
         if (lower_carry) begin
                upper_sum = add16_carry_1;
         end else begin
                upper_sum = add16_carry_0;
         end
    end
    assign sum = {upper_sum, lower_sum};
endmodule


module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
    
    wire [31:0] sub_b;
    wire [15:0] lower_sum;
    wire [15:0] upper_sum;
    wire cout_in;

    assign sub_b = b^{32{sub}};
    
    add16 lower (.a(a[15:0]), .b(sub_b[15:0]), .cin(sub), .sum(lower_sum), .cout(cout_in));
    add16 upper (.a(a[31:16]), .b(sub_b[31:16]), .cin(cout_in), .sum(upper_sum));
                 
    assign sum = {upper_sum, lower_sum};
endmodule


// synthesis verilog_input_version verilog_2001
module top_module(
    input a, 
    input b,
    output wire out_assign,
    output reg out_alwaysblock
);
    always @(*) begin
      out_alwaysblock = a*b;
    end
    
    assign out_assign = a*b;

endmodule


module top_module(
    input clk,
    input a,
    input b,
    output wire out_assign,
    output reg out_always_comb,
    output reg out_always_ff   );

    assign out_assign = a ^ b;
    
    always @(posedge clk) begin
        out_always_ff = a ^ b;
    end
    
    always @(*) begin
        out_always_comb = a ^ b;
    end
    
endmodule

module top_module(
    input a,
    input b,
    input sel_b1,
    input sel_b2,
    output wire out_assign,
    output reg out_always   ); 

    assign out_assign = (sel_b1 & sel_b2) ? b : a;
    
    always @(*) begin
        if (sel_b1 & sel_b2) begin
            out_always = b;
        end else begin
          out_always = a;
        end
    end
    
endmodule


// synthesis verilog_input_version verilog_2001
module top_module (
    input      cpu_overheated,
    output reg shut_off_computer,
    input      arrived,
    input      gas_tank_empty,
    output reg keep_driving  ); //

    always @(*) begin
        if (cpu_overheated)
           shut_off_computer = 1;
        else
            shut_off_computer = 0;
    end
    
    always @(*) begin
        if (~arrived)
           keep_driving = ~gas_tank_empty;
        else
            keep_driving = 0;
    end

endmodule

// synthesis verilog_input_version verilog_2001
module top_module ( 
    input [2:0] sel, 
    input [3:0] data0,
    input [3:0] data1,
    input [3:0] data2,
    input [3:0] data3,
    input [3:0] data4,
    input [3:0] data5,
    output reg [3:0] out   );//

    always@(*) begin  // This is a combinational circuit
        case(sel)
            3'b000: out = data0;
            3'b001: out = data1;
            3'b010: out = data2;
            3'b011: out = data3;
            3'b100: out = data4;
            3'b101: out = data5;
            default: out = 3'b000;
        endcase
    end

endmodule

// synthesis verilog_input_version verilog_2001
module top_module (
    input [3:0] in,
    output reg [1:0] pos  );
  
    always @(*) begin 
        case(in)
            4'd0: pos = 2'b00; //0000
            4'd1: pos = 2'b00; //0001
            4'd2: pos = 2'b01; //0010
            4'd3: pos = 2'b00; //0011
            4'd4: pos = 2'b10; //0100
            4'd5: pos = 2'b00; //0101        
            4'd6: pos = 2'b01; //0110
            4'd7: pos = 2'b00; //0111
            4'd8: pos = 2'b11; //1000
            4'd9: pos = 2'b00; //1001
            4'd10: pos = 2'b01; //1010
            4'd11: pos = 2'b00; //1011
            4'd12: pos = 2'b10; //1100
            4'd13: pos = 2'b00; //1101
            4'd14: pos = 2'b01; //1110
            4'd15: pos = 2'b00; //1111
            default: pos = 2'b00;
        endcase
        
    end
endmodule


module top_module (
    input [7:0] in,
    output reg [2:0] pos );

    always @(*) begin
        casez(in) 
            8'b00000000: pos = 3'b000;
            8'bzzzzzzz1: pos = 3'b000;
            8'bzzzzzz10: pos = 3'b001;
            8'bzzzzz100: pos = 3'b010;
            8'bzzzz1000: pos = 3'b011;
            8'bzzz10000: pos = 3'b100;
            8'bzz100000: pos = 3'b101;
            8'bz1000000: pos = 3'b110;
            8'b10000000: pos = 3'b111;
            default: pos = 3'b000;
        endcase
        
    end
endmodule


module top_module (
    input [15:0] scancode,
    output reg left,
    output reg down,
    output reg right,
    output reg up  ); 

    always @(*) begin
        up = 1'b0; down = 1'b0; right = 1'b0; left = 1'b0;
        case(scancode) 
            16'he06b: left = 1'b1;
            16'he072: down = 1'b1;
            16'he074: right = 1'b1;
            16'he075: up = 1'b1;
            default begin
                left = 1'b0;
                down = 1'b0;
                right = 1'b0;
                up = 1'b0;
            end
        endcase
    end
    
endmodule


module top_module (
    input [7:0] a, b, c, d,
    output [7:0] min);//

    wire [7:0] intermediate1;
    wire [7:0] intermediate2;
    
    assign intermediate1 = (a < b ? a : b);
    assign intermediate2 = (c < d ? c : d);
    assign min = (intermediate1 < intermediate2 ? intermediate1 : intermediate2);

endmodule


module top_module (
    input [7:0] in,
    output parity); 

    assign parity = ^in;
endmodule

module top_module( 
    input [99:0] in,
    output out_and,
    output out_or,
    output out_xor 
);

    assign out_and = &in;
    assign out_or = |in;
    assign out_xor = ^in;
    
endmodule

module top_module( 
    input [99:0] in,
    output [99:0] out
);
    integer counter;
    
    always @(*) begin
        for (counter = 0; counter < 100; ++counter) begin
            out[counter] = in[99-counter]; 
        end
    end
    
endmodule


module top_module( 
    input [254:0] in,
    output [7:0] out );

    integer counter; 
    integer num_ones;
    
    always @(*) begin
        num_ones = 0;
        for(counter = 0; counter < $bits(in); ++counter) begin
            if (in[counter] == 1'b1) begin
                ++num_ones;
            end
        end
    end
    
    assign out = num_ones;
    
endmodule


module fadd(input a, b, cin,
            output cout, sum );
    
        assign {cout, sum} = a + b + cin;
    
endmodule

module top_module( 
    input [99:0] a, b,
    input cin,
    output [99:0] cout,
    output [99:0] sum );
    
    genvar i;
    
    generate
        for (i = 0; i < 100; i = i + 1) begin : gen_block_id
            if (i == 0) begin
              fadd full_addr(.a(a[i]), .b(b[i]), .cin(cin), .cout(cout[i]), .sum(sum[i]));  
            end else begin
                fadd full_addr(.a(a[i]), .b(b[i]), .cin(cout[i-1]), .cout(cout[i]), .sum(sum[i]));  
            end
        end
    endgenerate

endmodule




0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0110
7 = 0
'

module top_module( 
    input [399:0] a, b,
    input cin,
    output cout,
    output [399:0] sum);
    
    generate
        genvar i;

        for (i = 1; i < 101; ++i) begin : gen_400
         
            wire carry;
            
            if (i == 1) begin
                bcd_fadd (.a(a[4*i - 1: 4*(i-1)]), .b(b[4*i - 1: 4*(i-1)]), .sum(sum[4*i - 1: 4*(i-1)]), .cin(cin), .cout(carry));
            end else if (i == 100) begin
                bcd_fadd (.a(a[4*i - 1: 4*(i-1)]), .b(b[4*i - 1: 4*(i-1)]), .sum(sum[4*i - 1: 4*(i-1)]), .cin(carry), .cout(cout));
            end else begin
                bcd_fadd (.a(a[4*i - 1: 4*(i-1)]), .b(b[4*i - 1: 4*(i-1)]), .sum(sum[4*i - 1: 4*(i-1)]), .cin(carry), .cout(carry));
            end
        end
    endgenerate
endmodule


module faddr (input a, b, cin,
              output cout, sum );
        assign {cout, sum} = a + b + cin;
endmodule

module top_module( 
    input [2:0] a, b,
    input cin,
    output [2:0] cout,
    output [2:0] sum );
    
    generate 
        genvar i;
        
        for(i = 0; i < 3; i++) begin : addr3
            if (i == 0) begin
                faddr (.a(a[i]), .b(b[i]), .cin(cin), .cout(cout[i]), .sum(sum[i]));
            end else begin
                faddr (.a(a[i]), .b(b[i]), .cin(cout[i -1]), .cout(cout[i]), .sum(sum[i]));
            end
            
        end
    endgenerate

endmodule


module faddr (input x, y, cin,
              output cout, sum );
    assign {cout, sum} = x + y + cin;
endmodule

module top_module (
    input [3:0] x,
    input [3:0] y, 
    output [4:0] sum);
        
    generate
        genvar i;
        
        for (i = 0; i < 4; ++i) begin : fadd
        wire carry;

            if (i == 0) begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cout(carry));
            end else if (i == 3) begin
              faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(carry), .cout(sum[4]));
            end else begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(carry), .cout(carry));
            end
        end
    endgenerate
    
//    assign sum[4] = sum[3] + sum[2] + sum[1] + sum[0];

endmodule


module faddr (input x, y, cin,
              output cout, sum);
    assign {cout, sum} = x + y + cin;
endmodule

module top_module (
    input [3:0] x,
    input [3:0] y, 
    output [4:0] sum);
        
    wire carry1;
    wire carry2;
    wire carry3;
    
    generate
        genvar i;
        
        for (i = 0; i < 4; ++i) begin : faddr
            
            if (i == 0) begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(1'b0), .cout(carry1));
            end else if (i == 3) begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(carry3), .cout(sum[4]));
            end else if (i == 1) begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(carry1), .cout(carry2));
            end else if (i == 2) begin
                faddr (.x(x[i]), .y(y[i]), .sum(sum[i]), .cin(carry2), .cout(carry3));
            end
        end
    endgenerate
    
//    assign sum[4] = sum[3] + sum[2] + sum[1] + sum[0];

endmodule


module top_module (
    input [7:0] a,
    input [7:0] b,
    output [7:0] s,
    output overflow
); //
 
    assign s = a + b;
    assign overflow = (a[7] == 1'b1 & b[7] == 1'b1 & s[7] == 1'b0) | (a[7] == 1'b0 & b[7] == 1'b0 & s[7] == 1'b1) ? 1'b1 : 1'b0;  

endmodule

module top_module( 
    input [99:0] a, b,
    input cin,
    output cout,
    output [99:0] sum );
    
    assign {cout, sum} = a + b + cin;

endmodule

module top_module( 
    input a, b,
    output out_and,
    output out_or,
    output out_xor,
    output out_nand,
    output out_nor,
    output out_xnor,
    output out_anotb
);
    
    assign out_and = a & b;
    assign out_or = a | b;
    assign out_xor = a ^ b;
    assign out_nand = !(a & b);
    assign out_nor = !(a | b);
    assign out_xnor = !(a ^ b);
    assign out_anotb = a & !b;

endmodule

module top_module( 
    input x3,
    input x2,
    input x1,  // three inputs
    output f   // one output
);
    assign f = (x2 & !x3) | (x1 & x3);

endmodule


module A (input x, input y, output z);
    assign z = (x^y) & x;
endmodule

module B (input x, input y, output z);
  assign z = !(x ^ y);
endmodule

module top_module (input x, input y, output z);
    
    wire z1, z2, z3, z4;

    A a1 (.x(x), .y(y), .z(z1));
    A a2 (.x(x), .y(y), .z(z2));
    B ab1 (.x(x), .y(y), .z(z3));
    B ab2 (.x(x), .y(y), .z(z4));
    
    assign z = (z1 | z3) ^ (z2 & z4);
    
endmodule

module top_module (
    input ring,
    input vibrate_mode,
    output ringer,       // Make sound
    output motor         // Vibrate
);
    assign ringer = ring & !vibrate_mode;
    assign motor = ring & vibrate_mode;

endmodule


module top_module (
    input too_cold,
    input too_hot,
    input mode,
    input fan_on,
    output heater,
    output aircon,
    output fan
); 
    
    assign heater = too_cold & mode;
    assign aircon = too_hot & ~mode;
    assign fan = fan_on | heater | aircon;

endmodule

 module top_module( 
    input [2:0] in,
    output [1:0] out );

    assign out = in[2] + in[1] + in[0];
    
endmodule


module bto7s(
        input wire [3:0]   x_in,
        output logic       sa,
        output logic       sb,
        output logic       sc,
        output logic       sd,
        output logic       se,
        output logic       sf,
        output logic       sg
        );

        // array of bits that are "one hot" with numbers 0 through 15
        logic [15:0] num;
        assign num[0] = ~x_in[3] && ~x_in[2] && ~x_in[1] && ~x_in[0];
        assign num[1] = ~x_in[3] && ~x_in[2] && ~x_in[1] && x_in[0];
        assign num[2] = x_in == 4'd2;

        // you do the rest...
  assign num[3] = ~x_in[3] && ~x_in[2] && x_in[1] && x_in[0];
  assign num[4] = ~x_in[3] && x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[5] = ~x_in[3] && x_in[2] && ~x_in[1] && x_in[0];
  assign num[6] = ~x_in[3] && x_in[2] && x_in[1] && ~x_in[0];
  assign num[7] = ~x_in[3] && x_in[2] && ~x_in[1] && x_in[0];
  assign num[8] = x_in[3] && ~x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[9] = x_in[3] && ~x_in[2] && ~x_in[1] && x_in[0];
  assign num[10] = x_in[3] && ~x_in[2] && x_in[1] && ~x_in[0];
  assign num[11] = x_in[3] && ~x_in[2] && x_in[1] && x_in[0];
  assign num[12] = x_in[3] && x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[13] = x_in[3] && x_in[2] && ~x_in[1] && x_in[0];
  assign num[14] = x_in[3] && x_in[2] && x_in[1] && ~x_in[0];
        assign num[15] = x_in == 4'd15;

        /* assign the seven output segments, sa through sg, using a "sum of products"
         * approach and the diagram above.
         *
         * assign sa =
         * assign sb =
         * assign sc =
         * assign sd =
         * assign se =
         * assign sf =
         * assign sg =
         */
  assign sa = ~(num[1] || num[4])
endmodule

module bto7s(
        input wire [3:0]   x_in,
        output logic       sa,
        output logic       sb,
        output logic       sc,
        output logic       sd,
        output logic       se,
        output logic       sf,
        output logic       sg
        );

        // array of bits that are "one hot" with numbers 0 through 15
        logic [15:0] num;
        assign num[0] = ~x_in[3] && ~x_in[2] && ~x_in[1] && ~x_in[0];
        assign num[1] = ~x_in[3] && ~x_in[2] && ~x_in[1] && x_in[0];
        assign num[2] = x_in == 4'd2;

        // you do the rest...
  assign num[3] = ~x_in[3] && ~x_in[2] && x_in[1] && x_in[0];
  assign num[4] = ~x_in[3] && x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[5] = ~x_in[3] && x_in[2] && ~x_in[1] && x_in[0];
  assign num[6] = ~x_in[3] && x_in[2] && x_in[1] && ~x_in[0];
  assign num[7] = ~x_in[3] && x_in[2] && x_in[1] && x_in[0];
  assign num[8] = x_in[3] && ~x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[9] = x_in[3] && ~x_in[2] && ~x_in[1] && x_in[0];
  assign num[10] = x_in[3] && ~x_in[2] && x_in[1] && ~x_in[0];
  assign num[11] = x_in[3] && ~x_in[2] && x_in[1] && x_in[0];
  assign num[12] = x_in[3] && x_in[2] && ~x_in[1] && ~x_in[0];
  assign num[13] = x_in[3] && x_in[2] && ~x_in[1] && x_in[0];
  assign num[14] = x_in[3] && x_in[2] && x_in[1] && ~x_in[0];
        assign num[15] = x_in == 4'd15;

        /* assign the seven output segments, sa through sg, using a "sum of products"
         * approach and the diagram above.
         *
         * assign sa =
         * assign sb =
         * assign sc =
         * assign sd =
         * assign se =
         * assign sf =
         * assign sg =
         */
  assign sa = ~(num[1] || num[4] || num[11] || num[13]);
  assign sb = ~(num[5] || num[6] || num[11] || num[12] || num[14] || num[15]);
  assign sc = ~(num[2] || num[12] || num[14] || num[15]);
  assign sd = ~(num[1] || num[4] || num[7] || num[10] || num[15]);
  assign se = ~(num[1] || num[3] || num[4] || num[5] || num[7] || num[9]);
  assign sf = ~(num[1] || num[2] || num[3] || num[7] || num[13]);
  assign sg = ~(num[0] || num[1] || num[7] || num[12]);
  
endmodule

module top_module(
    input a,
    input b,
    input c,
    output out  ); 

    assign out = b | c | a;
    
endmodule