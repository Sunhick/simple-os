# Make file for Simple OS
# make all : builds all the components of simple OS
# make iso : creates a bootable disk image
# make clean : gets rid of all unwanted files from the system
# make tags : generate the etag file for code navigation

IDIR=./include
CC=gcc
#CFLAGS=-m32 -O -w -fno-builtin -nostdlib  -ffreestanding -I $(IDIR) #-DDEBUG
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I $(IDIR)

LIBS= -lssp
ODIR=obj
LDIR=

_DEPS=string.h system.h io.h screen.h vmemory.h stdarg.h time.h gdt.h isr.h
DEPS= $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ=string.o io.o kmain.o screen.o boot.o vmemory.o stdarg.o time.o gdt.o isr.o gdt_asm.o timer.o keyboard.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(OBJ)
	ld -m elf_i386 -T boot.ld -o kernel.bin $(OBJ)
$(ODIR)/boot.o: boot.asm
	nasm -f aout -o $@ $^
$(ODIR)/gdt_asm.o: gdt.asm
	nasm -f aout -o $@ $^
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

iso: kernel.bin
	cp kernel.bin iso/
	cd iso && sh makeiso.sh && cd ..

#update/generate the etags file for easier code navigation
tags:
	find . \( -name "*.[ch]" -o -name "*.[ch]pp" -o -name "*.asm" \) -type f -print | etags -

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ kernel.bin $(IDIR)/*~ iso/kernel.*
	rm -r iso/isodir 
