#include <gdt.h>
#include <types.h>
#include <string.h>
#include <isr.h>

extern void flush_gdt(u32);

struct gdt_entry gdt_entries[5];
struct gdt_ptr gdt_ptr;

struct idt_entry idt_entries[256];
struct idt_ptr idt_ptr;

extern void flush_idt();
extern isr_t interrupt_handlers[];

/* add entry into the gdt table */
void add_gdt_entry(int index,
		   u32 base,
		   u32 limit,
		   u8 access,
		   u8 granularity)
{
  gdt_entries[index].base_low = (base & 0xFFFF);
  gdt_entries[index].base_middle = ((base >> 16) & 0xFF);
  gdt_entries[index].base_high = (base >> 24) & 0xFF;

  gdt_entries[index].limit_low = (limit & 0xFFFF);
  gdt_entries[index].granularity = (limit >> 16) & 0x0F;

  gdt_entries[index].granularity |= granularity & 0xF0;
  gdt_entries[index].access = access;
}

void gdt_init()
{
  gdt_ptr.limit = (sizeof(struct gdt_entry) * 5) - 1;
  gdt_ptr.base = (u32)&gdt_entries;

  add_gdt_entry(0, 0, 0, 0, 0);	/* null segment */
  add_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* kernel code segment */
  add_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); /* kernel data segment */
  add_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); /* user code segment */
  add_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); /* user data segment */

  flush_gdt((u32)&gdt_ptr);
}

void add_idt_entry(u8 index,
		   u32 base,
		   u16 sel,
		   u8 flags)
{
   idt_entries[index].base_lo = base & 0xFFFF;
   idt_entries[index].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[index].sel     = sel;
   idt_entries[index].always0 = 0;

   idt_entries[index].flags   = flags /* | 0x60 */;
}

void irq_remap()
{
  // Remap the irq table.
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x0);
  outb(0xA1, 0x0);
}

void irq_init()
{
  irq_remap();
}

void idt_init()
{
  idt_ptr.limit = sizeof(struct idt_entry)*256 - 1;
  idt_ptr.base = (u32)&idt_entries;

  //  irq_remap();
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x0);
  outb(0xA1, 0x0);

  memset(&interrupt_handlers, 0, sizeof(isr_t)*256);
  memset(&idt_entries, 0, sizeof(struct idt_entry)*256);

  add_idt_entry(0, (u32)isr0, 0x08, 0x8E);
  add_idt_entry(1, (u32)isr1, 0x08, 0x8E);
  add_idt_entry(2, (u32)isr2, 0x08, 0x8E);
  add_idt_entry(3, (u32)isr3, 0x08, 0x8E);
  add_idt_entry(4, (u32)isr4, 0x08, 0x8E);
  add_idt_entry(5, (u32)isr5, 0x08, 0x8E);
  add_idt_entry(6, (u32)isr6, 0x08, 0x8E);
  add_idt_entry(7, (u32)isr7, 0x08, 0x8E);
  add_idt_entry(8, (u32)isr8, 0x08, 0x8E);
  add_idt_entry(9, (u32)isr9, 0x08, 0x8E);
  add_idt_entry(10, (u32)isr10, 0x08, 0x8E);
  add_idt_entry(11, (u32)isr11, 0x08, 0x8E);
  add_idt_entry(12, (u32)isr12, 0x08, 0x8E);
  add_idt_entry(13, (u32)isr13, 0x08, 0x8E);
  add_idt_entry(14, (u32)isr14, 0x08, 0x8E);
  add_idt_entry(15, (u32)isr15, 0x08, 0x8E);
  add_idt_entry(16, (u32)isr16, 0x08, 0x8E);
  add_idt_entry(17, (u32)isr17, 0x08, 0x8E);
  add_idt_entry(18, (u32)isr18, 0x08, 0x8E);
  add_idt_entry(19, (u32)isr19, 0x08, 0x8E);
  add_idt_entry(20, (u32)isr20, 0x08, 0x8E);
  add_idt_entry(21, (u32)isr21, 0x08, 0x8E);
  add_idt_entry(22, (u32)isr22, 0x08, 0x8E);
  add_idt_entry(23, (u32)isr23, 0x08, 0x8E);
  add_idt_entry(24, (u32)isr24, 0x08, 0x8E);
  add_idt_entry(25, (u32)isr25, 0x08, 0x8E);
  add_idt_entry(26, (u32)isr26, 0x08, 0x8E);
  add_idt_entry(27, (u32)isr27, 0x08, 0x8E);
  add_idt_entry(28, (u32)isr28, 0x08, 0x8E);
  add_idt_entry(29, (u32)isr29, 0x08, 0x8E);
  add_idt_entry(30, (u32)isr30, 0x08, 0x8E);
  add_idt_entry(31, (u32)isr31, 0x08, 0x8E);

  /* add irq interrupt routines for slave and master */
  /* for master PIC */
  add_idt_entry(32, (u32)irq0, 0x08, 0x8E);
  add_idt_entry(33, (u32)irq1, 0x08, 0x8E);
  add_idt_entry(34, (u32)irq2, 0x08, 0x8E);
  add_idt_entry(35, (u32)irq3, 0x08, 0x8E);
  add_idt_entry(36, (u32)irq4, 0x08, 0x8E);
  add_idt_entry(37, (u32)irq5, 0x08, 0x8E);
  add_idt_entry(38, (u32)irq6, 0x08, 0x8E);
  add_idt_entry(39, (u32)irq7, 0x08, 0x8E);
  /* for slave PIC */
  add_idt_entry(40, (u32)irq8, 0x08, 0x8E);
  add_idt_entry(41, (u32)irq9, 0x08, 0x8E);
  add_idt_entry(42, (u32)irq10, 0x08, 0x8E);
  add_idt_entry(43, (u32)irq11, 0x08, 0x8E);
  add_idt_entry(44, (u32)irq12, 0x08, 0x8E);
  add_idt_entry(45, (u32)irq13, 0x08, 0x8E);
  add_idt_entry(46, (u32)irq14, 0x08, 0x8E);
  add_idt_entry(47, (u32)irq15, 0x08, 0x8E);
    
  flush_idt((u32)&idt_ptr);
}
