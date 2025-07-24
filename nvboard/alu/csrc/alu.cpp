#include "Valu.h" 
#include "nvboard.h" 

static Valu dut;

void nvboard_bind_all_pins(Valu* top);

int main() { 
	nvboard_bind_all_pins(&dut); 
	nvboard_init(); 
	
	while (1) { 
		nvboard_update(); 
		dut.eval();
		} 
		
}
