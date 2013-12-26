#ifndef _SYSTEM_H
#define _SYSTEM_H

/* kmain.c */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned char *dest, unsigned char val, int count);
extern int strlen(const char *str);
extern unsigned char inportb(unsigned short port);
extern void outportb(unsigned short port, unsigned char data);

/* screen.c */
extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

#endif
