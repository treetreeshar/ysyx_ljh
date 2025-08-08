#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}
/**/
static int int_to_str(char *buf, int num) {
  int len = 0;
  if (num < 0) {
    buf[len++] = '-';
    num = -num;
  }

  char tmp[20];
  int tmp_pos = 0;
  do {
    tmp[tmp_pos++] = '0' + (num % 10);
    num /= 10;
  } while (num > 0);

  while (tmp_pos > 0) {
    buf[len++] = tmp[--tmp_pos];
  }
  return len;
} 

int sprintf(char *out, const char *fmt, ...) {
  
  va_list args;
  va_start(args, fmt);
  int pos = 0;

  for (int i = 0; fmt[i] != '\0'; i++) {
    if (fmt[i] == '%') {
      i++;
      switch (fmt[i]) {
        case 's': {
          char *str = va_arg(args, char *);
          strcpy(out + pos, str);
          pos += strlen(str);
          break;
        }
        case 'd': {
          int num = va_arg(args, int);
          pos += int_to_str(out + pos, num);
          break;
        }
        default: {
          out[pos++] = fmt[i];
          break;
        }
      }
    } else {
      out[pos++] = fmt[i];
    }
}
out[pos] = '\0';
va_end(args);
return pos;
/*
  panic("Not implemented");*/
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
