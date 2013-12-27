#include <io.h>

/*read from the port*/
unsigned char inb (unsigned short port)
{
  unsigned char rv;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
  return rv;
}

/* output the data to the specified port */
void outb(unsigned short port,
	     unsigned char data)
{
  __asm__ __volatile__("outb %1, %0" :: "dN"(port),"a"(data));
}
