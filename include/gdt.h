#ifndef _GDT_H
#define _GDT_H

#include <types.h>

struct idt_entry {
  u16 base_lo;
  u16 sel;
  u8 always0;
  u8 flags;
  u16 base_hi;
}__attribute__((packed));

struct gdt_entry {
  u16 limit_low;
  u16 base_low;
  u8 base_middle;
  u8 access;
  u8 granularity;
  u8 base_high;
}__attribute__((packed));

struct gdt_ptr {
  u16 limit;
  u32 base;
}__attribute__((packed));

struct idt_ptr {
  u16 limit;
  u32 base;
}__attribute__((packed));

void gdt_init();
void idt_init();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

#endif
