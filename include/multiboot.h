#ifndef _MULTIBOOT_H
#define _MULTIBOOT_H

#include <types.h>

struct symbol_table {
  uint32 tabsize;
  uint32 strsize;
  uint32 addr;
  uint32 resered;
};

struct elf_section  {
  uint32 num;
  uint32 size;
  uint32 addr;
  uint32 shndx;
};

/* refer to Multiboot specification version 0.6.96 http://www.gnu.org  */
struct multiboot_info  {
  /* multiboot info version info */
  uint32 flags;
  /* available memory from bios */
  uint32 mem_lower;
  uint32 mem_upper;
  /* "root" partition */
  uint32 boot_device;
  /* kernel command line */
  uint32 cmdline;
  /* boot module list */
  uint32 mods_count;
  uint32 mods_addr;
  union {
    struct symbol_table aout_sym;
    struct elf_section elf_sec;
  }u;
  /* memory buffer mapping */
  uint32 mmap_length;
  uint32 mmap_addr;
  /* drive info buffer */
  uint32 drives_length;
  uint32 drives_addr;
  /* ROM config table */
  uint32 config_table;
  /* boot loader name */
  uint32 boot_loader_name;
  /* APM table */
  uint32 apm_table;
  /* video */
  uint32 vbe_control_info;
  uint32 vbe_mode_info;
  uint32 vbe_mode;
  uint32 vbe_interface_seg;
  uint32 vbe_interface_off;
  uint32 vbe_interface_len;
};

#endif
