#include <am.h>
#include <riscv/riscv.h> // for inl/outb

void __am_timer_init() {
}
/*
#define RTC_ADDR_LO ((volatile uint32_t *)0xa0000048)
#define RTC_ADDR_HI ((volatile uint32_t *)0xa000004C)

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t hi, lo;
  do {
    lo = *RTC_ADDR_LO;
    hi = *RTC_ADDR_HI;
  } while (hi != *RTC_ADDR_HI);//检查高位是否变化
  
  uptime->us = ((uint64_t)hi << 32) | lo;
}
*/
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t hi, lo;
  /*do {
    lo = inl(0xa0000048);
    hi = inl(0xa000004C);
  } while (hi != inl(0xa000004C));//防止还在读取过程中就进位了
   */
  asm volatile ("csrr %0, mcycle" : "=r"(lo));
  asm volatile ("csrr %0, mcycleh" : "=r"(hi));

  uptime->us = ((uint64_t)hi << 32) | lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
