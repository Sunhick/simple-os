#ifndef _STRING_H
#define _STRING_H

extern unsigned char *memcpy(unsigned char* dest, const unsigned char* src,int count);
extern unsigned char *memset(unsigned char* dest,unsigned char val,int count);
extern int strlen(const char* str);
extern void print(char *s);

#endif
