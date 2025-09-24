#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

/**/
static void print_num(int num) {
  if (num < 0) {
    putch('-');
    num = -num;
  }

  char tmp[12];
  int tmp_pos = 0;

  do {
    tmp[tmp_pos++] = '0' + (num % 10);
    num /= 10;
  } while (num > 0);

  while (tmp_pos > 0) {
    putch(tmp[--tmp_pos]);
  }
}

static void print_hex(unsigned int num) {
  char tmp[20];
  int tmp_pos = 0;
  
  // 处理0的特殊情况
  if (num == 0) {
    putch('0');
    return;
  }
  
  // 将数字转换为十六进制（逆序）
  while (num > 0) {
    int digit = num % 16;
    tmp[tmp_pos++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
    num /= 16;
  }
  
  // 逆序输出（正确的顺序）
  while (tmp_pos > 0) {
    putch(tmp[--tmp_pos]);
  }
}

static int hex_to_str(char *buf, unsigned int num) {
  int len = 0;
  
  if (num == 0) {
    buf[len++] = '0';
    return len;
  }
  
  char tmp[20];
  int tmp_pos = 0;
  
  while (num > 0) {
    int digit = num % 16;
    tmp[tmp_pos++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
    num /= 16;
  }
  
  while (tmp_pos > 0) {
    buf[len++] = tmp[--tmp_pos];
  }
  return len;
}

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int chars_printed = 0;

  for (int i = 0; fmt[i] != '\0'; i++) {
    if (fmt[i] == '%') {
      i++;
      switch (fmt[i]) {
        case 's': {
          char *str = va_arg(args, char *);
          while (*str) {
            putch(*str++);
            chars_printed++;
          }
          break;
        }
        case 'd': {
          int num = va_arg(args, int);
          print_num(num);
          int tmp = num < 0 ? -num : num;
          do {
            chars_printed++;
            tmp /= 10;
          } while (tmp > 0);
          if (num < 0) chars_printed++;
            break;
        }
        case 'x': {
          unsigned int num = va_arg(args, unsigned int);
          print_hex(num);
          unsigned int tmp = num;
          do {
            chars_printed++;
            tmp /= 16;
          } while (tmp > 0);
          break;
        }
        default: {  // 其他格式（如 %%）
          putch(fmt[i]);
          chars_printed++;
          break;
        }
      }
    } else {
      putch(fmt[i]);
      chars_printed++;
      }
  }

  va_end(args);
  return chars_printed;
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
        case 'x': {
          unsigned int num = va_arg(args, unsigned int);
          pos += hex_to_str(out + pos, num);
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
