/***************************************/
/* kernel main file 		       */
/* Written by sunil <sunilbn@live.com> */
/***************************************/

#include <system.h>
#include <multiboot.h>
#include <io.h>
#include <string.h>
#include <types.h>
#include <vmemory.h>

/* kernel main */
void kmain(struct multiboot_info *boot_info)
{
  console_init();

  /* Fix: printf function by defining for va_list, va_start, va_end, va_arg */
  /*  All strings needs to be terminated with '\0' */
  print("Welcome to Simple OS!\t\0");
  char b[10];
  itoa(b, 1, 10);
  print("version:\0");print(b);print("\n\0");
  print("==============================================\n\0");
  print("VGA setup\t   ... [ok] \n\0");

  print("Loading virtual memory\t...[Not ok]\n\0");
  vmem_init();  
  
  print("Loading filesystem\t...[Not ok]\n\0");

  print("Loading system call interface\t...[Not ok]\n\0");

  print("Loading system\t...[Not ok]\n\0");

  print("Loading modules\t...[Not ok]\n\0");

  
  /* place your code for kernel startup here */

  /* kernel main should never return */
  while(1);
}
