#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

while (1) {
	int a = rand() & 1;
	int b = rand() & 1;
	top->a = a;
	top->b = b;
	top->eval();
	printf("a = %d, b = %d, f = %d\n", a, b, top->f);
	assert(top->f == (a^b));
}

/*
#include <stdlib.h>
#include <assert.h>
#include "nvboard.h"
#include "Vtop.h"  // 修改为你的 Verilog 模块头文件
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <unistd.h>
#include "/home/treetree/ysyx-workbench/nvboard/include/nvboard.h"

// NVBoard 引脚绑定函数
static void nvboard_bind_all_pins(Vtop* top) {
    nvboard_bind_pin(&top->a, false, "SW1");  // 绑定输入 a 到 NVBoard 的 A 引脚
    nvboard_bind_pin(&top->b, false, "SW2");  // 绑定输入 b 到 NVBoard 的 B 引脚
    nvboard_bind_pin(&top->f, true,  "LD0");  // 绑定输出 f 到 NVBoard 的 F 引脚
}

int main(int argc, char** argv) {
    // 初始化 Verilator
    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;  // 实例化 Verilog 模块

    // 初始化 NVBoard
    nvboard_bind_all_pins(top);  // 绑定引脚
    nvboard_init();              // 初始化 NVBoard

    // 初始化波形跟踪（可选）
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 9);
    tfp->open("top.vcd");

    int i = 0;
    int max = 100;
    while (i < max) {
        // 随机生成输入 a 和 b
        int a = rand() & 1;
        int b = rand() & 1;

        // 设置输入信号
        top->a = a;
        top->b = b;

        // 更新模块状态
        top->eval();

        // 打印结果
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);

        // 更新 NVBoard 显示
        nvboard_update();

        // 记录波形（可选）
        tfp->dump(i);

        // 检查输出是否正确
        assert(top->f == (a ^ b));

        // 延时
        usleep(100000);

        i++;
    }

    // 清理
    tfp->close();
    nvboard_quit();
    delete top;
    delete tfp;
    return 0;
}


*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <unistd.h>
#include <nvboard.h>

int main (int argc,char** argv){
	Verilated::commandArgs(argc,argv);
	Vdswitch* Vtop = new Vtop;

	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp=new VerilatedVcdC;
	tfp->trace(tfp,9);
	tfp->open("dswitch.vcd");

	int i = 0;
	int max = 100;
	while (i < max){
		int a = rand() & 1;
		int b = rand() & 1;

		top ->a=a;
		top ->b=b;
		top ->eval();

		printf("a = %d,b = %d,f = %d\n",a,b,top->f);
		usleep(100000);

		tfp->dump(i);
		i++;
		assert(top->f==(a^b));
	}

	tfp->close();
	delete top;
	delete tfp;
	return 0;
}
*/
