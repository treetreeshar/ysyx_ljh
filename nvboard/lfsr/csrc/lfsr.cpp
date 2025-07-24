#include "Vlfsr.h" 
#include "nvboard.h" 

static Vlfsr dut;

void nvboard_bind_all_pins(Vlfsr* top);

int main() { 
	nvboard_bind_all_pins(&dut); 
	nvboard_init(); 
	
	while (1) { 
		nvboard_update(); 
		dut.eval();
		} 
		
}
