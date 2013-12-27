/***************************************/
/* kernel main file 		       */
/* Written by sunil <sunilbn@live.com> */
/***************************************/

#include <system.h>
#include <io.h>
#include <string.h>

/* kernel main */
void kmain()
{
   volatile unsigned char *videoram = (unsigned char *) 0xB8000; 

   int i = 0;
   for(i = 0; i < 100; i++)     videoram[i] = 65+i;
   
   //videoram[1] = 0x07;
  
  //init_video();
  // puts("video graphics are initialized\n");
  /* place your code for kernel startup here */

  /* kernel main should never return */
  while(1);
}
