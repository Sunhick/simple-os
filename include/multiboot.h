#ifndef _MULTIBOOT_H
#define _MULTIBOOT_H

#include <types.h>

struct symbol_table {
  u32 tabsize;
  u32 strsize;
  u32 addr;
  u32 resered;
};

struct elf_section  {
  u32 num;
  u32 size;
  u32 addr;
  u32 shndx;
};

/* refer to Multiboot specification version 0.6.96 http://www.gnu.org  */
struct multiboot_info  {
  /* multiboot info version info */
  u32 flags;
  /* available memory from bios */
  u32 mem_lower;
  u32 mem_upper;
  /* "root" partition */
  u32 boot_device;
  /* kernel command line */
  u32 cmdline;
  /* boot module list */
  u32 mods_count;
  u32 mods_addr;
  union {
    struct symbol_table aout_sym;
    struct elf_section elf_sec;
  }u;
  /* memory buffer mapping */
  u32 mmap_length;
  u32 mmap_addr;
  /* drive info buffer */
  u32 drives_length;
  u32 drives_addr;
  /* ROM config table */
  u32 config_table;
  /* boot loader name */
  u32 boot_loader_name;
  /* APM table */
  u32 apm_table;
  /* video */
  u32 vbe_control_info;
  u32 vbe_mode_info;
  u32 vbe_mode;
  u32 vbe_interface_seg;
  u32 vbe_interface_off;
  u32 vbe_interface_len;
};

#endif
