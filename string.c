#include <string.h>

/*copy the specified bytes in count from src to dest*/
unsigned char *memcpy(unsigned char* dest,	/* destination */
		      const unsigned char* src, /* source  */
		      int count)		/* no. of bytes to be copied */
{
 // char *d = dest, *s = src;
  /* copy the bytes */
  //while(count--)    *d++ = *s++;
  return dest;
}

/*set the value specified in val to dest till count bytes long*/
unsigned char *memset(unsigned char* dest,
		      unsigned char val,
		      int count)
{
  char *p = dest;
  while(count--) *dest++ = val;
  return p;
}

int strlen(const char* str)
{
  int length = 0;
  char *p = str;

  /* determine the length  */
  while(*p++)    length++;

  return length;		       
}

