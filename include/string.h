#ifndef _STRING_H
#define _STRING_H

extern unsigned char *memcpy(unsigned char* dest, const unsigned char* src,int count);
extern unsigned char *memset(unsigned char* dest,unsigned char val,int count);
extern int strlen(const char* str);
extern void print(char *s);
extern char *strncpy(unsigned char *dest, const unsigned char *src, int size);
extern int strcmp(const unsigned char *dest, char *src);
extern void printf(const char *s, ...);
extern void itoa(char *buflim, int val, int base);
extern void reverse(char *str, int length);

#endif
