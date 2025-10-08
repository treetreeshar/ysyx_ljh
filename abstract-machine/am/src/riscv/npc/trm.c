#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h> // for outb/inl
#include <stdio.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

static void uart_init(){
  unsigned int divisor = 1;
  uint32_t lcr = 0x03;

  outb(UART_LCR, 0x80 | lcr);//enable divisor latch
  outb(UART_MSB, 0xff & (divisor >> 8));
  outb(UART_LSB, 0xff & divisor);
  outb(UART_LCR, lcr);// resume
}


void putch(char ch) {
  /*
  volatile uint32_t *uart = (volatile uint32_t *)0xa00003f8;
  *uart = ch;
  
  outb(0xa00003f8, ch);
  */
  if(*(volatile char *)UART_LCR == 0x03){
    while(!(*(volatile char *)UART_LSR & 0x20));//查询串口发送队列的情况？
  }
  outb(UART_TX, ch);
}

void halt(int code) {
  register int a0 asm("a0") = code;
  asm volatile("ebreak" : : "r"(a0));
  while (1);
}

void _trm_init() {
  uart_init();
  uint32_t mvendorid, marchid;
  asm volatile ("csrrw %0, 0xF11, x0" : "=r"(mvendorid));
  asm volatile ("csrrw %0, 0xF12, x0" : "=r"(marchid));
  printf("mvendorid: 0x%x\n", mvendorid);
  printf("marchid: %d\n", marchid);

  int ret = main(mainargs);
  halt(ret);
}
