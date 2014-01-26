#include <system.h>
#include <string.h>
#include <io.h>
#include <screen.h>
#include <stdarg.h>

/* get access to vga location */
unsigned short *video = (unsigned short *)VGA_MEMORY;
unsigned char x = 0, y = 0; 		/* cursor location */
unsigned char attributes = (black < 4) | (light_blue & 0x0F);

void console_init(void)
{
  //  attributes = (black < 4) | (light_blue & 0x0F); /* Green text on black background */
  unsigned short blank = 0x20 | (attributes << 8);

  //memset(video, blank , SCREEN_SIZE);
  int i = 0;
  for(i = 0; i < SCREEN_SIZE; i++)    *video = blank;
  
  x = 0; y = 0; 		/* reset cursor to (0,0) */
  move_cursor();
}

void move_cursor(void)
{
  unsigned short pos = (y * WIDTH + x);

  // cli();
  /* send command to the control indicating we will be
     sending the high nibble first*/
  outb(0x3d4, 14);
  outb(0x3d5, pos >> 8);
  /* send the lower nibble */
  outb(0x3d4, 15);
  outb(0x3d5, pos);
  //sti();
}

/* Scroll up the contents by n lines */
void scroll_up(unsigned int lines)
{
  unsigned short blank = 0x20 | attributes << 8;

  //were at the last line, move up the content by one line
  if(y >= 25) {
    int i = 0;
    //copy the content of 'i'th line to 'i-1'th line
    for(i = 0*80; i < 24*80; i++) *(video + i) = *(video + i + 80);

    //clear the last line
    for(i = 24*80; i < 25*80; i++) *(video + i) = blank;
    y = 24;
  }
}

void putchar(char c)
{
  /* each character takes 2 bytes(16bits) */
  unsigned short *v = video + (y * WIDTH + x);
  
  /* handle the special chars like \n, \b , \t etc... */
  if(c == '\n') {
    x = 0;
    y++;
  } else if(c == '\t')  {
    x += 8;			/* move by 8 chars */
  } else {
    /* write the character to the vga memory buffer */
    *v = c | (attributes << 8);
    /* forecolor and backcolor to the immediate next byte */
    /* *(v+1) = attributes; */

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

  unsigned int uval;
  unsigned char c;
  char buflim[16];
  int val, buflen;
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
	uval = va_arg(ap, int);
	itoa(buflim, uval, 10);
	buflen = strlen(buflim);
	print(buflim);
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
