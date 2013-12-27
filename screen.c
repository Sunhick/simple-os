#include <system.h>
#include <string.h>
#include <io.h>
#include <screen.h>

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
  /* code to move cursor */
}

void putchar(char c)
{
  unsigned char *v =(unsigned char *)(video + (y * 160) + (2 * x));
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

  if(y >= HEIGHT)  {
    /* do scroll  */
  }
}

void print(char *s)
{
  unsigned char c;
  while((c = *s++)) {
    putchar(c);
  }
}
