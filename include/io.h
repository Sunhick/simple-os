#ifndef _IO_H
#define _IO_H

extern unsigned char inb (unsigned short port);
extern void outb(unsigned short port, unsigned char data);
extern void console_init();
extern void move_cursor();
extern void putchar(char c);
extern void scroll_up(unsigned int lines); /* number of lines to scroll up */
extern void printf(const char *s, ...);

#endif
