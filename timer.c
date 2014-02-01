#include <types.h>
#include <io.h>
#include <isr.h>

u32 tick = 0;

void timer_callback(registers_t regs)
{
    tick++;
    //    printf("Tick = %d\n", tick);
}

void set_frequency(int f)
{
  //register_interrupt_handler(IRQ0, &timer_callback);
  
  u32 div = 1193180 / f;
  outb(0x43, 0x36);
  outb(0x40, div & 0xFF);		// Low byte
  outb(0x40, (div >> 8) & 0xFF);		// Hight byte
}
