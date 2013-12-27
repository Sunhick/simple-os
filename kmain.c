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
  console_init();
  print("Welcome to Simple OS Version:0.1!\n\0");
  print("==============================================\n\0");
  print("VGA setup\t   ... [ok] \n\0");

  print("Loading virtual memory\t...[Not ok]\n\0");
  
  print("Loading filesystem\t...[Not ok]\n\0");

  print("Loading system call interface\t...[Not ok]\n\0");

  print("Loading system\t...[Not ok]\n\0");

  print("Loading modules\t...[Not ok]\n\0");

  /* place your code for kernel startup here */

  /* kernel main should never return */
  while(1);
}
