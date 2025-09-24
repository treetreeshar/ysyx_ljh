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

void putch(char ch) {
  /*
  volatile uint32_t *uart = (volatile uint32_t *)0xa00003f8;
  *uart = ch;
  */
  outb(0xa00003f8, ch);
}

void halt(int code) {
  register int a0 asm("a0") = code;
  asm volatile("ebreak" : : "r"(a0));
  while (1);
}

void _trm_init() {
  uint32_t mvendorid, marchid;
  asm volatile ("csrrw %0, 0xF11, x0" : "=r"(mvendorid));
  asm volatile ("csrrw %0, 0xF12, x0" : "=r"(marchid));
  printf("mvendorid: 0x%x\n", mvendorid);
  printf("marchid: %d\n", marchid);

  int ret = main(mainargs);
  halt(ret);
}
