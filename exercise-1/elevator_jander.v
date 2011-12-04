module elevator(position,clk,button0,button1,button2,button3);
       input clk;
       input button0, button1, button2, button3;
       output position;
       reg [1:0] position;
       reg [3:0] pressed;
       initial begin
        position = 0;
        pressed = 4;
       end

       always @(posedge clk) begin

       pressed=button0+button1+button2+button3;

	if (button0) begin
           if (position == 0)
             pressed = 4;
           else if (position > 0)
             position = position - 1;
         end

         if (button1) begin
           if (position == 1)
             pressed = 4;
           else if (position < 1)
             position = position + 1;
           else if (position > 1)
             position = position - 1;
         end

         if (button2) begin
           if (position == 2)
             pressed = 4;
           else if (position < 2)
             position = position + 1;
           else if (position > 2)
             position = position - 1;
         end

         if (button3) begin
           if (position == 3)
             pressed = 4;
           else if (position < 3)
             position = position + 1;
         end

       end
endmodule
