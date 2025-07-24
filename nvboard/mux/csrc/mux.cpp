
#include "Vmux.h" 
#include "nvboard.h" 

static Vmux dut;

void nvboard_bind_all_pins(Vmux* top);

int main() { 
	nvboard_bind_all_pins(&dut); 
	nvboard_init(); 
	
	while (1) { 
		nvboard_update(); 
		dut.eval();
		} 
		
}





/*
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmux.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux* top;

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}
void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vmux;
	contextp->traceEverOn(true);
	top->trace(tfp, 9);
	tfp->open("dump.vcd");
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}

int main() {
	sim_init();
	top->key=0b00; top->lut=0b1110000000000000; step_and_dump_wave();
			top->lut=0b0001000000001111; step_and_dump_wave();
	top->key=0b01; top->lut=0b1110000000000000; step_and_dump_wave();
			top->lut=0b0010000011110000; step_and_dump_wave();
	top->key=0b10; top->lut=0b1010000000000000; step_and_dump_wave();
			top->lut=0b0100000000000000; step_and_dump_wave();
	top->key=0b11; top->lut=0b0111000000000000; step_and_dump_wave();
			top->lut=0b1001000000000000; step_and_dump_wave();
	sim_exit();
}
*/




/*
#include <iostream>
#include "verilated.h" 
#include "Vmux.h" 
#include <bitset> 

int main(int argc, char** argv) { 

	Verilated::commandArgs(argc, argv); 
	Vmux* top = new Vmux; 
	
	 const int NR_KEY = 4; 
	 const int KEY_LEN = 2; 
	 const int DATA_LEN = 2; 
	 
	 top->lut = 0b0000010110101111;
	  
	  for (int i = 0; i < (1 << KEY_LEN); ++i) { 
	  top->key = i; 
	   
	  top->eval(); 
	  std::cout << "Key: " << std::bitset<2>(top->key) << ", Out: " << std::bitset<2>(top->out) << std::endl;
    } 
    
	  top->final(); 
	  delete top; 
	  return 0;
}
*/
