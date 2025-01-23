# System Bus Design

## Description
This project involves the design and implementation of a parallel bus system with the following components:
- **2 Masters**
- **3 Slaves**: 
  - Slave 1: 2K memory (8-bit wide)
  - Slave 2: 4K memory (8-bit wide)
  - Slave 3: 4K memory (8-bit wide, split transaction supported)

### Overview of the Design
The system bus facilitates communication between masters and slaves, governed by an arbiter and an address decoder. 

### Components and Functionality
#### **Masters**
Each master contains:
- A ROM table with transaction data (read/write and address).
- An interface connected to the system bus.

**Finite State Machine (FSM):**
1. **IDLE:** Waits for an event trigger (triggered through a counter).
2. **REQUEST:** Requests bus access from the arbiter. Upon receiving the grant, the transaction data is placed on the system bus.
3. **RESPONSE:** Waits for a response from the bus.

#### **Slaves**
Each slave contains:
- Memory (size varies as specified).
- An interface with the following FSM states:
  - **IDLE:** Waits for a valid request from the bus.
  - **SERVICING:** Processes the request (read/write) and generates a response.
  - **RESPONSE:** Sends the response to the bus and transitions back to IDLE.

**Slave 3 (Split Transaction Supported):**
In addition to the standard states, Slave 3's interface includes:
- **SPLIT:** Temporarily stores the transaction data and notifies the arbiter to grant bus access to other masters.
- **ARB_REQ:** Requests the bus again to send the response to the original requesting master.

#### **System Bus**
- **Arbiter:** Manages bus access among the masters.
- **Address Decoder:** Maps the responses to the corresponding masters.

## Testing and Verification
The system was verified for functional correctness using Verilator testbenches. The testbench ensures:
- Correct state transitions for all FSMs.
- Proper handling of read and write transactions.
- Split transaction functionality for Slave 3.

## Physical Demonstration
The design was physically demonstrated on a DE0 Nano board. Functionality was verified using the **In-System Memory Content Editor** tool in Intel Quartus software. The tool allowed real-time monitoring of slave memory values. A very low clock frequency was used to observe and verify system behavior.

## Features
- Support for split transactions in Slave 3.
- Multi-master, multi-slave configuration.
- Real-time verification on FPGA.
- Modular design suitable for extension.

or further inquiries, reach out at [yasirueranda20@gmail.com].
