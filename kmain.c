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
#include <time.h>

/* kernel main */
void kmain(struct multiboot_info *boot_info)
{
  console_init();
  
  char *version = "0.1\0";
  /*  All strings needs to be terminated with '\0' */
  print("Welcome to Simple OS!\0");
  printf("version: %s\n\0",version);
  print("==============================================\n\0");
  print("VGA setup\t   ... [ok] \n\0");

  /* multiboot data */
  printf("boot loader name: %s\n\0", boot_info->boot_loader_name);
  printf("Lower mem: %u Kb, Upper mem: %u Kb\n\0", (unsigned)boot_info->mem_lower, (unsigned)boot_info->mem_upper);

  /* get real time clock */
  struct time t = get_current_time();
  printf("Time & date ==> %d:%d:%d \t %d/%d/%d\n\0",t.hours, t.minutes, t.seconds, t.month, t.day_of_month, t.year);
  
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
