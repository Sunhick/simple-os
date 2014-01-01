#include <system.h>
#include <string.h>
#include <io.h>
#include <screen.h>
#include <stdarg.h>

/* get access to vga location */
unsigned char *video = (unsigned char *)VGA_MEMORY;
int x = 0, y = 0; 		/* cursor location */
int attributes = 0x07;

void console_init(void)
{
  memset(video, 0, SCREEN_LIMIT);
  x = 0; y = 0; 		/* reset cursor to (0,0) */
}

void move_cursor(void)
{
  unsigned int pos = (y * WIDTH + x) << 1;
  
  cli();
  /* send command to the control indicating we will be
     sending the high nibble first*/
  outb(0x3d4, 14);
  outb(0x3d4, pos >> 9);
  /* send the lower nibble */
  outb(0x3d4, 15);
  outb(0x3d4, pos >> 1);
  sti();
}

/* Scroll up the contents by n lines */
/* Fix: Scroll isn't working correctly*/
void scroll_up(unsigned int lines)
{
  /* move contents at offset to the origin of the screen */
  unsigned char *v, *offset;
  for(v = video; v < (unsigned char *)SCREEN_LIMIT; v += 2) {
    offset =  (unsigned char *)(v  + lines + (WIDTH << 1));

    if(offset < (unsigned char *)SCREEN_LIMIT)  {
      *v = *offset;
      *(v + 1) = *(offset + 1);
    } else {
      *offset = 0;
      *(offset + 1) = attributes;
    }
  }
  
  y -= lines;
  if(y < 0) y = 0;
}

void putchar(char c)
{
  /* each character takes 2 bytes(16bits) */
  unsigned char *v =(unsigned char *)(video + ((y * WIDTH + x) << 1));
  
  /* handle the special chars like \n, \b , \t etc... */
  if(c == '\n') {
    x = 0;
    y++;
  } else if(c == '\t')  {
    x += 8;			/* move by 8 chars */
  } else {
    /* write the character to the vga memory buffer */
    *v = c;
    /* forecolor and backcolor to the immediate next byte */
    *(v+1) = attributes;

    if(x >= WIDTH) {		/* end of line */
      x = 0;
      y++;
    }else {
      x++;
    }
  }

  if(y >= HEIGHT)  scroll_up(y - HEIGHT);
  move_cursor();
}

void print(char *s)
{
  unsigned char c;
  while((c = *s++)) {
    putchar(c);
  }
}

/* Fix this method */
/* puts the string on the screen after evaluating the format specifier */
void printf(const char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  unsigned char c;
  char buflim[16];
  int val;
  char *tmp;
  
  while((c = *s++))  {
    if(c == 0)break;
    else if(c == '%') {
      c = *s++;
      switch(c)  {
      case 's':
	tmp  = va_arg(ap, char *);
  	print(tmp);
  	break;
      case 'u':
  	break;
      case 'd':
  	val = va_arg(ap, int);
  	itoa(buflim, val, 10); 	/* base 10 */
  	print(buflim);
  	break;
      case 'x':
      case 'X':
  	break;
      case 'p':
  	break;
      }
    } else putchar(c);
  }
  /* clean up */
  va_end(list);
}
