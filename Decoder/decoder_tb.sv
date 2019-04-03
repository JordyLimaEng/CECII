`timescale 1ns/10ps

module decoder_tb();
	logic clk, reset;
	logic [4:0] sel;
	logic [31:0] output_selector;
	logic	[31:0] output_selector_expected;
	logic [31:0] vectornum, errors;
	logic [36:0] testvectors[10000:0];
	
	decoder duv(.sel(sel), .output_selector(output_selector));

	always
		begin
			clk = 1; #10; clk = 0; #5;
		end
		
		initial
			begin 
				$readmemb("decoder.tv", testvectors);
				vectornum = 0;
				errors = 0;
				reset = 1; #8; reset = 0;
			end
			
		always @ (posedge clk)
			begin
				#1 {sel[4:0], output_selector_expected[31:0]} = testvectors[vectornum];
			end
		always @ (negedge clk)
			if (~reset) begin
				for(reg[5:0] i = 6'b000000; i < 6'b100000; i++) begin
					assert (output_selector[i] === output_selector_expected[i]) else 
					 begin
						if(output_selector_expected[i] !== 1'bx) begin
							$display("Line with error: %1d", vectornum + 1);
							$display("Error: input (%b) in position %d = %b", sel, i, sel[i]);
							$display(" output = %b, (%b expected)", output_selector[i], output_selector_expected[i]);
						
							errors = errors + 1;
						end
					 end
				end
				
				vectornum = vectornum + 1;
				
				if(testvectors[vectornum] === 37'bx) begin
					$display("%d tests completed with %d errors", vectornum, errors);
					$finish;
				end
			end
endmodule
