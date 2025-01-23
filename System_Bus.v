module Master_1(
    input        clock,
    input        reset,
    output request,     // request to arbiter
    output control,     // read or write
    output [13:0] address,   // address for write data or read data
    output valid,       // request is valid
    output [7:0] wdata, // write data
    input [7:0] rdata,      // read data
    input done,             // signal from slave if the read data is valid or write data is done (transaction has completed)
    input grant             // signal from arbiter to indicate whether shared bus access is granted
);

    // all outputs should be synchronous
    reg request_reg;
    reg [13:0] address_reg;
    reg [7:0] wdata_reg;
    reg valid_reg;

    // 4-bit up counter for internal tracking
    reg [3:0] countreg;
    always @(posedge clock) begin
        if (reset) begin
            countreg <= 4'b0000;
        end else if (countreg == 4'd15) begin
            countreg <= 4'b0000;
        end else begin
            countreg <= countreg + 1;
        end
    end

    // Transaction address order
    reg [13:0] addr[0:7];
    initial begin
        addr[0] = 14'b10_00_0000000001;
        addr[1] = 14'b10_00_0000000001;
        addr[2] = 14'b00_00_0000000001;
        addr[3] = 14'b01_00_0000001001;
        addr[4] = 14'b00_00_0000000010;
        addr[5] = 14'b01_00_0000001010;
        addr[6] = 14'b00_00_0000000011;
        addr[7] = 14'b01_00_0000001011;
    end
    reg rwreg [0:7]; // 0 is for read, 1 is for write
    initial begin
      rwreg[0] = 1'b0;
      rwreg[1] = 1'b1;
      rwreg[2] = 1'b0;
      rwreg[3] = 1'b1;
      rwreg[4] = 1'b0;
      rwreg[5] = 1'b1;
      rwreg[6] = 1'b0;
      rwreg[7] = 1'b1;
    end


    reg [2:0] order_index = 3'b000;

    // FSM state register
    reg [1:0] stateReg; // 00: idle, 01: request, 10: response

    always @(posedge clock) begin
        if(reset) begin
          stateReg <= 2'b00;
          request_reg <= 1'b0;
          address_reg <= 14'b0000_0000000000;
          wdata_reg <= 8'b00000000;
          valid_reg <= 1'b0;
          order_index <= 3'b000;
        end
        else begin
          case (stateReg)
              2'b00: begin  // Idle state
                  if (countreg == 4'd2 || countreg == 4'd13) begin
                      stateReg <= 2'b01;
                      request_reg <= 1'b1;
                  end else begin
                      stateReg <= 2'b00;
                  end
              end
              2'b01: begin  // Request state
                  if (grant) begin
                      address_reg <= addr[order_index];
                      valid_reg <= 1'b1;
                      wdata_reg <= wdata_reg + 8'b1;
                      stateReg <= 2'b10;
                  end else begin
                      stateReg <= 2'b01;
                  end
              end
              2'b10: begin  // Response state
                  if (done && grant) begin
                      stateReg <= 2'b00;
                      wdata_reg <= rdata;
                      request_reg <= 1'b0;
                      valid_reg <= 1'b0;
                      order_index <= order_index + 3'b001;
                  end else begin
                      stateReg <= 2'b10;
                  end
              end
          endcase
        end
    end

    assign request = request_reg;
    assign control = rwreg[order_index];
    assign address = address_reg;
    assign wdata = wdata_reg;
    assign valid = valid_reg;

endmodule


module Master_2(
    input        clock,
    input        reset,
    output request,     // request to arbiter
    output control,     // read or write
    output [13:0] address,   // address for write data or read data
    output valid,       // request is valid
    output [7:0] wdata, // write data
    input [7:0] rdata,      // read data
    input done,             // signal from slave if the read data is valid or write data is done (transaction has completed)
    input grant             // signal from arbiter to indicate whether shared bus access is granted
);

    // all outputs should be synchronous
    reg request_reg;
    reg [13:0] address_reg;
    reg [7:0] wdata_reg;
    reg valid_reg;

    // 4-bit up counter for internal tracking
    reg [3:0] countreg;
    always @(posedge clock) begin
        if (reset) begin
            countreg <= 4'b0000;
        end else if (countreg == 4'd15) begin
            countreg <= 4'b0000;
        end else begin
            countreg <= countreg + 1;
        end
    end

    // Transaction address order
    reg [13:0] addr[0:7];
    initial begin
        addr[0] = 14'b01_00_0000000000;
        addr[1] = 14'b00_00_0000001000;
        addr[2] = 14'b01_00_0000000001;
        addr[3] = 14'b00_00_0000001001;
        addr[4] = 14'b01_00_0000000010;
        addr[5] = 14'b00_00_0000001010;
        addr[6] = 14'b01_00_0000000011;
        addr[7] = 14'b00_00_0000001011;
    end
    reg rwreg [0:7]; // 0 is for read, 1 is for write
    initial begin
      rwreg[0] = 1'b0;
      rwreg[1] = 1'b1;
      rwreg[2] = 1'b0;
      rwreg[3] = 1'b1;
      rwreg[4] = 1'b0;
      rwreg[5] = 1'b1;
      rwreg[6] = 1'b0;
      rwreg[7] = 1'b1;
    end


    reg [2:0] order_index = 3'b000;

    // FSM state register
    reg [1:0] stateReg; // 00: idle, 01: request, 10: response

    always @(posedge clock) begin
        if(reset) begin
          stateReg <= 2'b00;
          request_reg <= 1'b0;
          address_reg <= 14'b0000_0000000000;
          wdata_reg <= 8'b00000000;
          valid_reg <= 1'b0;
          order_index <= 3'b000;
        end
        else begin
          case (stateReg)
              2'b00: begin  // Idle state
                  if (countreg == 4'd2 || countreg == 4'd13) begin
                      stateReg <= 2'b01;
                      request_reg <= 1'b1;
                  end else begin
                      stateReg <= 2'b00;
                  end
              end
              2'b01: begin  // Request state
                  if (grant) begin
                      address_reg <= addr[order_index];
                      valid_reg <= 1'b1;
                      wdata_reg <= wdata_reg + 8'b1;
                      stateReg <= 2'b10;
                  end else begin
                      stateReg <= 2'b01;
                  end
              end
              2'b10: begin  // Response state
                  if (done && grant) begin
                      stateReg <= 2'b00;
                      wdata_reg <= rdata;
                      request_reg <= 1'b0;
                      valid_reg <= 1'b0;
                      order_index <= order_index + 3'b001;
                  end else begin
                      stateReg <= 2'b10;
                  end
              end
          endcase
        end
    end

    assign request = request_reg;
    assign control = rwreg[order_index];
    assign address = address_reg;
    assign wdata = wdata_reg;
    assign valid = valid_reg;

endmodule

module Slave_1 (
  input  [13:0] io_addr,        // 6-bit address
  input  [7:0] io_wrData,      // 8-bit write data
  input        io_wrEnable,    // Write enable
  input        io_valid,       // Valid input
  output [7:0] io_rdData,  // 8-bit read data
  output       io_done,        // Done signal
  input        clock,         // Clock signal
  input        reset        // Reset signal
);
  //all outputs should be synchronous
  reg [7:0] rdata_reg;
  reg       done_reg;

  //Input Buffers
  reg [13:0] addr_reg;
  reg [7:0] wdata_reg;
  reg       control_reg;

  //latency genrate counter
  reg [3:0] countreg;

  reg [7:0] mem [0:2047];  // 2048 words of 8-bit wide memory

  reg [1:0] stateReg;   // 0: idle, 1: servicing, 2: response

  // State encoding
  localparam IDLE = 2'b00;
  localparam SERVICING = 2'b01;
  localparam RESPONSE = 2'b10;

  // Synchronous logic
  always @(posedge clock) begin
    if (reset) begin
      done_reg    <= 1'b0;
      addr_reg    <= 6'b0;
      wdata_reg   <= 8'b0;
      control_reg <= 1'b0;
      countreg    <= 4'b0;
      stateReg    <= IDLE;
    end else begin
      case (stateReg)
        IDLE: begin
          if (io_addr[13:12] == 2'b00 && io_valid) begin
            stateReg    <= SERVICING;
            addr_reg    <= io_addr;
            wdata_reg   <= io_wrData;
            control_reg <= io_wrEnable;
            countreg    <= 4'b0001;
          end else begin
            stateReg <= IDLE;
          end
        end
        SERVICING: begin
          if (countreg == 4'b0011) begin  // Memory latency of 3 + 1 cycles
            stateReg <= RESPONSE;
            done_reg <= 1'b1;
          end else begin
            countreg <= countreg + 1'b1;
            stateReg <= SERVICING;
          end
        end
        RESPONSE: begin
          stateReg <= IDLE;
          done_reg <= 1'b0;
        end
      endcase
    end
  end


  assign io_rdData = rdata_reg;
  assign io_done   = done_reg;

  // Memory access (synchronous write and read)
  always @(posedge clock) begin
    if (control_reg) begin
      // Write operation
      mem[addr_reg[10:0]] <= wdata_reg;
    end else begin
      // Read operation
      rdata_reg <= mem[addr_reg[10:0]];
    end
  end

  // Initialize memory values
  initial begin
    mem[0] = 8'hA5; // Example initialization
    mem[1] = 8'h5A;
    mem[2] = 8'hFF;
    mem[3] = 8'h00;
    mem[4] = 8'hC3;
    mem[5] = 8'h3C;
    mem[6] = 8'h12;
    mem[7] = 8'h34;
    // Add more initialization as needed
  end

endmodule

module Slave_2 (
  input  [13:0] io_addr,        // 6-bit address
  input  [7:0] io_wrData,      // 8-bit write data
  input        io_wrEnable,    // Write enable
  input        io_valid,       // Valid input
  output [7:0] io_rdData,  // 8-bit read data
  output       io_done,        // Done signal
  input        clock,         // Clock signal
  input        reset        // Reset signal
);
  //all outputs should be synchronous
  reg [7:0] rdata_reg;
  reg       done_reg;

  //Input Buffers
  reg [13:0] addr_reg;
  reg [7:0] wdata_reg;
  reg       control_reg;

  //latency genrate counter
  reg [3:0] countreg;

  reg [7:0] mem [0:4095];  // 8 words of 8-bit wide memory

  reg [1:0] stateReg;   // 0: idle, 1: servicing, 2: response

  // State encoding
  localparam IDLE = 2'b00;
  localparam SERVICING = 2'b01;
  localparam RESPONSE = 2'b10;

  // Synchronous logic
  always @(posedge clock) begin
    if (reset) begin
      done_reg    <= 1'b0;
      addr_reg    <= 14'b0;
      wdata_reg   <= 8'b0;
      control_reg <= 1'b0;
      countreg    <= 4'b0;
      stateReg    <= IDLE;
    end else begin
      case (stateReg)
        IDLE: begin
          if (io_addr[13:12] == 2'b01 && io_valid) begin
            stateReg    <= SERVICING;
            addr_reg    <= io_addr;
            wdata_reg   <= io_wrData;
            control_reg <= io_wrEnable;
            countreg    <= 4'b0001;
          end else begin
            stateReg <= IDLE;
          end
        end
        SERVICING: begin
          if (countreg == 4'b0011) begin  // Memory latency of 3 + 1 cycles
            stateReg <= RESPONSE;
            done_reg <= 1'b1;
          end else begin
            countreg <= countreg + 1'b1;
            stateReg <= SERVICING;
          end
        end
        RESPONSE: begin
          stateReg <= IDLE;
          done_reg <= 1'b0;
        end
      endcase
    end
  end


  assign io_rdData = rdata_reg;
  assign io_done   = done_reg;

  // Memory access (synchronous write and read)
  always @(posedge clock) begin
    if (control_reg) begin
      // Write operation
      mem[addr_reg[11:0]] <= wdata_reg;
    end else begin
      // Read operation
      rdata_reg <= mem[addr_reg[11:0]];
    end
  end

  initial begin
    mem[0] = 8'h1A; // Example initialization
    mem[1] = 8'hB7;
    mem[2] = 8'h3E;
    mem[3] = 8'h9C;
    mem[4] = 8'h4F;
    mem[5] = 8'hE2;
    mem[6] = 8'h7D;
    mem[7] = 8'h08;
    // Add more initialization as needed
  end

endmodule

module Slave_3 (
  input  [13:0] io_addr,        // 6-bit address
  input  [7:0] io_wrData,      // 8-bit write data
  input        io_wrEnable,    // Write enable
  input        io_valid,       // Valid input
  output [7:0] io_rdData,      // 8-bit read data
  output       io_done,        // Done signal
  output       split,          //Split signal
  input        clock,          // Clock signal
  input        reset,          // Reset signal
  output       arb_req,            // arbiter request
  input        arb_grant           // arbiter grant
);
  //all outputs should be synchronous
  reg [7:0] rdata_reg;
  reg       done_reg;
  reg       arb_req_reg;
  reg      split_req_reg;

  //Input Buffers
  reg [13:0] addr_reg;
  reg [7:0] wdata_reg;
  reg       control_reg;

  //latency genrate counter
  reg [3:0] countreg;

  reg [7:0] mem [0:4095];  // 8 words of 8-bit wide memory

  reg [2:0] stateReg;   // 0: idle, 1: servicing, 2: response

  //hard code split
  reg split_reg;

  // State encoding
  localparam IDLE = 3'b000;
  localparam SERVICING = 3'b001;
  localparam RESPONSE = 3'b010;
  localparam SPLIT = 3'b011;
  localparam ARB_REQ = 3'b100;

  // Synchronous logic
  always @(posedge clock) begin
    if (reset) begin
      done_reg    <= 1'b0;
      addr_reg    <= 14'b0;
      wdata_reg   <= 8'b0;
      control_reg <= 1'b0;
      countreg    <= 4'b0;
      arb_req_reg <= 1'b0;
      stateReg    <= IDLE;
      split_reg   <= 1'b0; //hard code to not to split support
      split_req_reg <= 1'b0;
    end else begin
      case (stateReg)
        IDLE: begin
          if (io_addr[13:12] == 2'b10 && io_valid) begin
            addr_reg    <= io_addr;
            wdata_reg   <= io_wrData;
            control_reg <= io_wrEnable;
            countreg    <= 4'b0001;
            if (split_reg) begin
              stateReg <= SPLIT;
              split_req_reg <= 1'b1;
            end else begin
              stateReg    <= SERVICING;
            end
          end else begin
            stateReg <= IDLE;
          end
        end
        SERVICING: begin
          if (countreg == 4'b0011) begin  // Memory latency of 3 + 1 cycles
            if (split_reg) begin
              stateReg <= ARB_REQ;
              arb_req_reg <= 1'b1;
            end else begin
              stateReg <= RESPONSE;
              done_reg <= 1'b1;
            end
          end else begin
            countreg <= countreg + 1'b1;
            stateReg <= SERVICING;
          end
        end
        RESPONSE: begin
          stateReg <= IDLE;
          done_reg <= 1'b0;
        end
        SPLIT: begin
          split_req_reg <= 1'b0;
          stateReg <= SERVICING;
        end
        ARB_REQ: begin
          if (arb_grant) begin
            stateReg <= RESPONSE;
            done_reg <= 1'b1;
            arb_req_reg <= 1'b0;
          end else begin
            stateReg <= ARB_REQ;
          end
        end
      endcase
    end
  end


  assign io_rdData = rdata_reg;
  assign io_done   = done_reg;
  assign arb_req   = arb_req_reg;
  assign split     = split_req_reg;

  // Memory access (synchronous write and read)
  always @(posedge clock) begin
    if (control_reg) begin
      // Write operation
      mem[addr_reg[11:0]] <= wdata_reg;
    end else begin
      // Read operation
      rdata_reg <= mem[addr_reg[11:0]];
    end
  end

  initial begin
    mem[0] = 8'h9E; // Example initialization
    mem[1] = 8'h29;
    mem[2] = 8'h47;
    mem[3] = 8'h6B;
    mem[4] = 8'hD1;
    mem[5] = 8'h8F;
    mem[6] = 8'h5C;
    mem[7] = 8'h3A;
    // Add more initialization as needed
  end

endmodule

module Arbiter(
    input io_req0,          // Request from master 0
    input io_req1,          // Request from master 1
    output io_grant0,   // Grant signal for master 0
    output io_grant1,   // Grant signal for master 1
    output io_masterSel, // Master selector
    input  clock,         // Clock signal
    input  reset,        // Reset signal
    input  split,
    input  split_req,
    output split_grant
);

    // Registers for grants(to remember the last request granted)
    reg grant0Reg;
    reg grant1Reg;
    reg masterSelReg;
    reg split_grant_reg;
    reg [3:0] timer;

    reg split_remember; // remeber if arbiter in middle of a split transaction.

    reg [2:0] stateReg;

    //state encoding
    localparam IDLE = 3'b000;
    localparam GRANT0 = 3'b001;
    localparam GRANT1 = 3'b010;

    // Arbiter logic with priority given to req0
    always @(posedge clock) begin
        if (reset) begin
          grant0Reg <= 1'b0;
          grant1Reg <= 1'b0;
          masterSelReg <= 1'b0;
          split_grant_reg <= 1'b0;
          split_remember <= 1'b0;
          timer <= 4'b0000;
        end else begin
            case(stateReg)
                IDLE: begin
                    if (io_req0) begin
                        stateReg <= GRANT0;
                        grant0Reg <= 1'b1;
                        grant1Reg <= 1'b0;
                        masterSelReg <= 1'b0;
                        timer <= timer + 4'b0001;
                    end else if (io_req1) begin
                        stateReg <= GRANT1;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b1;
                        masterSelReg <= 1'b1;
                        timer <= timer + 4'b0001;
                    end else begin
                        stateReg <= IDLE;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b0;
                        timer <= 4'b0000;
                    end
                end
                GRANT0: begin
                    if (split) begin
                        split_remember <= 1'b1;
                        stateReg <= GRANT1;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b1;
                        masterSelReg <= 1'b1;
                        timer <= 4'b0000;
                    end else if (io_req0 && !(timer[3] && timer[2] && timer[1] && timer[0])) begin
                        stateReg <= GRANT0;
                        split_grant_reg <= 1'b0;
                        timer <= timer + 4'b0001;
                    end else if (!split_req && split_remember) begin
                        stateReg <= GRANT0;
                        timer <= timer + 4'b0001;
                    end else if (split_req) begin
                        split_remember <= 1'b0;
                        split_grant_reg <= 1'b1;
                        stateReg <= GRANT1;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b1;
                        masterSelReg <= 1'b1;
                        timer <= 4'b0000;
                    end else if (io_req1) begin
                        stateReg <= GRANT1;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b1;
                        masterSelReg <= 1'b1;
                        timer <= 4'b0000;
                    end else begin
                        stateReg <= IDLE;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b0;
                        timer <= 4'b0000;
                    end
                end
                GRANT1: begin
                    if (split) begin
                        split_remember <= 1'b1;
                        stateReg <= GRANT0;
                        grant0Reg <= 1'b1;
                        grant1Reg <= 1'b0;
                        masterSelReg <= 1'b0;
                        timer <= 4'b0000;
                    end else if (io_req1 && !(timer[3] && timer[2] && timer[1] && timer[0])) begin
                        stateReg <= GRANT1;
                        split_grant_reg <= 1'b0;
                        timer <= timer + 4'b0001;
                    end else if (!split_req && split_remember) begin
                        stateReg <= GRANT1;
                        timer <= timer + 4'b0001;
                    end else if (split_req) begin
                        split_remember <= 1'b0;
                        split_grant_reg <= 1'b1;
                        stateReg <= GRANT0;
                        grant0Reg <= 1'b1;
                        grant1Reg <= 1'b0;
                        masterSelReg <= 1'b0;
                        timer <= 4'b0000;
                    end else if (io_req0) begin
                        stateReg <= GRANT0;
                        grant0Reg <= 1'b1;
                        grant1Reg <= 1'b0;
                        masterSelReg <= 1'b0;
                        timer <= 4'b0000;
                    end else begin
                        stateReg <= IDLE;
                        grant0Reg <= 1'b0;
                        grant1Reg <= 1'b0;
                        timer <= 4'b0000;
                    end
                end
            endcase
        end
    end




    // Assign the register values to the outputs
    assign io_grant0 = grant0Reg;
    assign io_grant1 = grant1Reg;
    assign io_masterSel = masterSelReg;
    assign split_grant = split_grant_reg;
endmodule


module System_Bus(
  input        clock,
  input        reset
);
  wire  M1_clock;
  wire  M1_reset;
  wire  M1_request;
  wire  M1_control;
  wire [13:0] M1_address;
  wire  M1_valid;
  wire [7:0] M1_wdata;
  wire [7:0] M1_rdata;
  wire  M1_done;
  wire  M1_grant;
  wire  M2_clock;
  wire  M2_reset;
  wire  M2_request;
  wire  M2_control;
  wire [13:0] M2_address;
  wire  M2_valid;
  wire [7:0] M2_wdata;
  wire [7:0] M2_rdata;
  wire  M2_done;
  wire  M2_grant;
  wire  S1_clock;
  wire  S1_reset;
  wire [13:0] S1_io_addr;
  wire [7:0] S1_io_wrData;
  wire  S1_io_wrEnable;
  wire  S1_io_valid;
  wire [7:0] S1_io_rdData;
  wire  S1_io_done;
  wire  S2_clock;
  wire  S2_reset;
  wire [13:0] S2_io_addr;
  wire [7:0] S2_io_wrData;
  wire  S2_io_wrEnable;
  wire  S2_io_valid;
  wire [7:0] S2_io_rdData;
  wire  S2_io_done;
  wire  S3_clock;
  wire  S3_reset;
  wire [13:0] S3_io_addr;
  wire [7:0] S3_io_wrData;
  wire  S3_io_wrEnable;
  wire  S3_io_valid;
  wire [7:0] S3_io_rdData;
  wire  S3_io_done;
  wire  arbiter_clock;
  wire  arbiter_reset;
  wire  arbiter_io_req0;
  wire  arbiter_io_req1;
  wire  arbiter_io_grant0;
  wire  arbiter_io_grant1;
  wire  arbiter_io_masterSel;

  //selection MUX
  wire [13:0] addr = ~arbiter_io_masterSel ? M1_address : M2_address; //Address selection MUX
  assign S1_io_addr = ~arbiter_io_masterSel ? M1_address : M2_address;
  assign S1_io_wrData = ~arbiter_io_masterSel ? M1_wdata : M2_wdata;
  assign S1_io_wrEnable = ~arbiter_io_masterSel ? M1_control : M2_control;
  assign S1_io_valid = ~arbiter_io_masterSel ? M1_valid : M2_valid;
  assign S2_io_addr = ~arbiter_io_masterSel ? M1_address : M2_address;
  assign S2_io_wrData = ~arbiter_io_masterSel ? M1_wdata : M2_wdata;
  assign S2_io_wrEnable = ~arbiter_io_masterSel ? M1_control : M2_control;
  assign S2_io_valid = ~arbiter_io_masterSel ? M1_valid : M2_valid;
  assign S3_io_addr = ~arbiter_io_masterSel ? M1_address : M2_address;
  assign S3_io_wrData = ~arbiter_io_masterSel ? M1_wdata : M2_wdata;
  assign S3_io_wrEnable = ~arbiter_io_masterSel ? M1_control : M2_control;
  assign S3_io_valid = ~arbiter_io_masterSel ? M1_valid : M2_valid;

  //decoder
  assign M1_rdata = addr[13:12] == 2'h0 ? S1_io_rdData : (addr[13:12] == 2'h1 ? S2_io_rdData : (addr[13:12] == 2'h2 ? S3_io_rdData : 8'h0));
  assign M1_done = addr[13:12] == 2'h0 ? S1_io_done : (addr[13:12] == 2'h1 ? S2_io_done : (addr[13:12] == 2'h2 ? S3_io_done : 1'b0));
  assign M2_rdata = addr[13:12] == 2'h0 ? S1_io_rdData : (addr[13:12] == 2'h1 ? S2_io_rdData : (addr[13:12] == 2'h2 ? S3_io_rdData : 8'h0));
  assign M2_done = addr[13:12] == 2'h0 ? S1_io_done : (addr[13:12] == 2'h1 ? S2_io_done : (addr[13:12] == 2'h2 ? S3_io_done : 1'b0));


  wire split_wire;
  wire arb_req_wire;
  wire arb_grant_wire;

  Master_1 M1 (
    .clock(M1_clock),
    .reset(M1_reset),
    .request(M1_request),
    .control(M1_control),
    .address(M1_address),
    .valid(M1_valid),
    .wdata(M1_wdata),
    .rdata(M1_rdata),
    .done(M1_done),
    .grant(M1_grant)
  );
  Master_2 M2 (
    .clock(M2_clock),
    .reset(M2_reset),
    .request(M2_request),
    .control(M2_control),
    .address(M2_address),
    .valid(M2_valid),
    .wdata(M2_wdata),
    .rdata(M2_rdata),
    .done(M2_done),
    .grant(M2_grant)
  );
  Slave_1 S1 (
    .clock(S1_clock),
    .reset(S1_reset),
    .io_addr(S1_io_addr),
    .io_wrData(S1_io_wrData),
    .io_wrEnable(S1_io_wrEnable),
    .io_valid(S1_io_valid),
    .io_rdData(S1_io_rdData),
    .io_done(S1_io_done)
  );
  Slave_2 S2 (
    .clock(S2_clock),
    .reset(S2_reset),
    .io_addr(S2_io_addr),
    .io_wrData(S2_io_wrData),
    .io_wrEnable(S2_io_wrEnable),
    .io_valid(S2_io_valid),
    .io_rdData(S2_io_rdData),
    .io_done(S2_io_done)
  );
  Slave_3 S3 (
    .clock(S3_clock),
    .reset(S3_reset),
    .io_addr(S3_io_addr),
    .io_wrData(S3_io_wrData),
    .io_wrEnable(S3_io_wrEnable),
    .io_valid(S3_io_valid),
    .io_rdData(S3_io_rdData),
    .io_done(S3_io_done),
    .split(split_wire),
    .arb_req(arb_req_wire),
    .arb_grant(arb_grant_wire)
  );
  Arbiter arbiter (
    .clock(arbiter_clock),
    .reset(arbiter_reset),
    .io_req0(arbiter_io_req0),
    .io_req1(arbiter_io_req1),
    .io_grant0(arbiter_io_grant0),
    .io_grant1(arbiter_io_grant1),
    .io_masterSel(arbiter_io_masterSel),
    .split(split_wire),
    .split_req(arb_req_wire),
    .split_grant(arb_grant_wire)
  );


  assign M1_clock = clock;
  assign M1_reset = reset;

  assign M1_grant = arbiter_io_grant0;
  assign M2_clock = clock;
  assign M2_reset = reset;

  assign M2_grant = arbiter_io_grant1;
  assign S1_clock = clock;
  assign S1_reset = reset;

  assign S2_clock = clock;
  assign S2_reset = reset;

  assign S3_clock = clock;
  assign S3_reset = reset;

  assign arbiter_clock = clock;
  assign arbiter_reset = reset;
  assign arbiter_io_req0 = M1_request;
  assign arbiter_io_req1 = M2_request;
endmodule

