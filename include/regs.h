#ifndef _REGS_H
#define _REGS_H

typedef struct regs {
  unsigned int eax, ebx, ecx, edx, ebi, esi, edi, esp;
  unsigned int int_no, err_code;
  unsigned int cs, ds, es, ss, gs, fs, eip, eflags;
}regs_t;

#endif
