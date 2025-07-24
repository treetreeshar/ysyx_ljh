#include <nvboard.h>
#include <Vtop.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  while(1) {
    nvboard_update();
    dut.eval();//更新电路状态！！
  }
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include <time.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <unistd.h>
#include "nvboard.h"

int main(int argc, char** argv) {

	srand(time(NULL));

	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

Vtop* top = new Vtop;

	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp, 9);
	tfp->open("waveform.vcd"); 

vluint64_t main_time =0;
int max=100;

while (main_time<max) {
	int a = rand() & 1;
	int b = rand() & 1;
	
	top->a = a;
	top->b = b;
	top->eval();
	
	printf("a = %d, b = %d, f = %d\n", a, b, top->f);
	usleep(100000);
	tfp->dump(main_time);
	main_time++;
	assert(top->f == (a^b));
}
tfp->close();
delete top;
delete tfp;
return 0;
}
*/
