module elevator(position,clk,button0,button1,button2,button3);
       input clk;
       input button0, button1, button2, button3;
       output position;
       reg [1:0] position;
       reg [2:0] pressed;

       initial begin
        position = 0;
        pressed = 4;
       end

       always @(posedge clk) begin
         if (pressed==4) begin
           if (button0)
             pressed=0;
           if (button1)
             pressed=1;
           if (button2)
             pressed=2;
           if (button3)
             pressed=3;
         end

         if (pressed == 0) begin
           if (position == 0)
             pressed = 4;
           else if (position > 0)
             position = position - 1;
         end

         if (pressed == 1) begin
           if (position == 1)
             pressed = 4;
           else if (position < 1)
             position = position + 1;
           else if (position > 1)
             position = position - 1;
         end

         if (pressed == 2) begin
           if (position == 2)
             pressed = 4;
           else if (position < 2)
             position = position + 1;
           else if (position > 2)
             position = position - 1;
         end

         if (pressed == 3) begin
           if (position == 3)
             pressed = 4;
           else if (position < 3)
             position = position + 1;
         end

       end
endmodule
