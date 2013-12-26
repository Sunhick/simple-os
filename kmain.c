/***************************************/
/* kernel main file 		       */
/* Written by sunil <sunilbn@live.com> */
/***************************************/

#include <system.h>

/*copy the specified bytes in count from src to dest*/
unsigned char *memcpy(unsigned char* dest,	/* destination */
		      const unsigned char* src, /* source  */
		      int count)		/* no. of bytes to be copied */
{
  return dest;
}

/*set the value specified in val to dest till count bytes long*/
unsigned char *memset(unsigned char* dest,
		      unsigned char val,
		      int count)
{
  return dest;
}


unsigned short *memsetw(unsigned char* dest,
			unsigned char val, /* value */
			int count)
{
  char *p = dest;
  while(count--) *dest++ = val;
  return p;  
}

int strlen(const char* str)
{
  int length=0;
  return length;		       
}

/*read from the port*/
unsigned char inportb (unsigned short port)
{
  unsigned char rv;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
  return rv;
}

/* output the data to the specified port */
void outportb(unsigned short port,
	     unsigned char data)
{
  __asm__ __volatile__("outb %1, %0" :: "dN"(port),"a"(data));
}

/* kernel main */
void kmain()
{
   volatile unsigned char *videoram = (unsigned char *) 0xB8000; 

   int i = 0;
   for(i;i<100;i++)     videoram[i] = 65+i;
   
   //videoram[1] = 0x07;
  
  //init_video();
  // puts("video graphics are initialized\n");
  /* place your code for kernel startup here */

  /* kernel main should never return */
  while(1);
}
