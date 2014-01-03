;This is a kernel entry point of the boot loader.
;We can either choose to do a useful stuff or setup stack
;load gdt or other stuff.

;Written by sunil <sunilbn@live.com>
	
[BITS 32]

	global start
start:
	mov esp, system_stack 	;setup a new stack
	jmp post_header		;jump post the multi-boot header

;Multi boot header
;Define multiboot header macros for readability
	MULTIBOOT_PAGE_ALIGN   equ 1<<0
	MULTIBOOT_MEMORY_INFO  equ 1<<1
	MULTIBOOT_AOUT_KLUDGE  equ 1<<16
	MULTIBOOT_HEADER_MAGIC equ 0x1BADB002
	MUTLIBOOT_HEADER_FLAGS equ  MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
	MUTLIBOOT_CHECKSUM     equ -(MULTIBOOT_HEADER_MAGIC + MUTLIBOOT_HEADER_FLAGS)
	extern code, bss, end
	
;Align the header on a word boundary. In some machines, accesses to objects larger than a byte must be aligned.
;An access to an object of size s bytes at byte address A is aligned if A mod s = 0. Misalignment causes hardware complications and require
;CPU cycles to access
	ALIGN 4
mboot:
	dd MULTIBOOT_HEADER_MAGIC ;GRUB multiboot header magic
	dd MUTLIBOOT_HEADER_FLAGS
	dd MUTLIBOOT_CHECKSUM

	dd mboot
	dd code
	dd bss
	dd end
	dd start

	extern kmain

;jump to kmain	
post_header:
	push ebx		;pointer to multiboot info structure
	call kmain		;call kernel main
	
hangup:				;kmain should never return;
	jmp hangup

	SECTION .bss
	resb 8192 		;reserve 8K bytes. Note: stack grows downwards
system_stack:	
