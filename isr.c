#include <screen.h>
#include <isr.h>
#include <io.h>

/* list of interrupt handlers */
isr_t interrupt_handlers[256];

void register_interrupt_handler(u8 index, isr_t handler)
{
  printf("registering for %d", index);
  interrupt_handlers[index] = handler;
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
  printf("received interrupt>>>>! %d\n", regs.int_no);
}

void irq_handler(registers_t regs)
{
  /* send the acknowledgement about the interrupt */
  if (regs.int_no >= 40) {
    /* inform the slave pic */
    outb(0xA0, 0x20);
  }
  /* ack to master pic */
  outb(0x20, 0x20);

  if (interrupt_handlers[regs.int_no] != 0) {
    isr_t handler = interrupt_handlers[regs.int_no];
    handler(regs);
  }
}
