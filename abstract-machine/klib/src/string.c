#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while(s[len] != '\0'){
      len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  if(dst == NULL || src == NULL){
    return dst;
  }

  int i = 0;
  do {
    dst[i] = src[i];
  } while (src[i++] != '\0'); 
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  if(dst == NULL || src == NULL){
    return dst;
  }

  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++){
      dst[i] = src[i];
  }
  for (; i < n; i++){
      dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  if(dst == NULL || src == NULL){
    return dst;
  }

  char *p = dst;
  while (*p != '\0'){
    p++;
  }
  while (*src != '\0'){
    *p++ = *src++;
  }
  *p = '\0';
  return dst;
  /*char *p = dst;
    while (*p) {
        p++;
    }
    while ((*p++ = *src++) != '\0');*/
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 > *s2) {return 1;} 
    else if (*s1 < *s2) {return -1;}
    s1++;
    s2++;
  }
  if (*s1 == '\0' && *s2 == '\0') {return 0;} 
  else if (*s1 == '\0') {return -1;} 
  else {return 1;}
  /*while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 > *s2) - (*s1 < *s2); */
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n-- > 0) {
    if (*s1 == '\0' || *s1 != *s2) {
      break;
    }
    s1++;
    s2++;
    }
  return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void *memset(void *s, int c, size_t n) {
  if (n == 0) {
    return s;
  }

  unsigned char *p = (unsigned char *)s;
  unsigned char value = (unsigned char)c;

  for (size_t i = 0; i < n; i++) {
    p[i] = value;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  if (n == 0) {
    return dst;
  }

  char *d = (char *)dst;
  const char *s = (const char *)src;

  if (d < s) {
    for (size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else {
    for (size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }

  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  if (n == 0) {
    return out;
  }

  char *dst = (char *)out;
  const char *src = (const char *)in;

  for (size_t i = 0; i < n; i++) {
    dst[i] = src[i];
  }

  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  if (n == 0) {
    return 0;
  }

  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;

  for (size_t i = 0; i < n; i++) {
    if (p1[i] != p2[i]) {
      return (p1[i] > p2[i]) ? 1 : -1;
    }
  }

  return 0;
}

#endif
