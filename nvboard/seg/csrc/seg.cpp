#include "Vseg.h" 
#include "nvboard.h" 

static Vseg dut;

void nvboard_bind_all_pins(Vseg* top);

int main() { 
	nvboard_bind_all_pins(&dut); 
	nvboard_init(); 
	
	while (1) { 
		nvboard_update(); 
		dut.eval();
		} 
		
}
