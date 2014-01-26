#include <string.h>

/*copy the specified bytes in count from src to dest*/
unsigned char *memcpy(unsigned char* dest,	/* destination */
		      const unsigned char* src, /* source  */
		      int count)		/* no. of bytes to be copied */
{
  char *d = dest, *s = src;
  /* copy the bytes */
  while(count--)    *d++ = *s++;
  return dest;
}

/*set the value specified in val to dest till count bytes long*/
unsigned char *memset(unsigned char* dest,
		      unsigned char val,
		      int count)
{
  unsigned char *p = dest;
  while(count--) *dest++ = val;
  return p;
}

int strlen(const char* str)
{
  int i = 0;
  char *p = str;

  while(*p++) i++;
  return i;		       
}

char *strncpy(unsigned char *dest, const unsigned char *src, int size)
{
  char *s = src, *d = dest;
  while(size--) *d++ = *s++;
  return d;
}

int strcmp(const unsigned char *dest, char *src)
{
  int i = 0;
  while(*(dest + i) == *(src + i)) {
    if(*(src + i++) == 0) return 0;
  }
  return 1;
}

void itoa(char *buflim, int val, int base)
{
  int n = val, i = 0;
  int temp ;
  do {
    temp = n % base;
    *(buflim + i++) = temp + '0';
  }while(n /= base);

  *(buflim + i) = '\0';		/* terminate with null char */
  reverse(buflim, i-1);		/* reverse the string */
}

void reverse(char *s, int length)
{
  int start = 0, end = length;
  char temp;
  while(start < end)  {
    temp = *(s + start);
    *(s + start) = *(s + end) ;
    *(s + end) = temp;

    start++;
    end--;
  }
}
