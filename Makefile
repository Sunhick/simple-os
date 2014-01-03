# Make file for Simple OS
# make all : builds all the components of simple OS
# make iso : creates a bootable disk image
# make clean : gets rid of all unwanted files from the system

IDIR=./include
CC=gcc
CFLAGS=-m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fno-stack-protector -I$(IDIR) #-DDEBUG

LIBS= -lssp
ODIR=obj
LDIR=

_DEPS=string.h system.h io.h screen.h vmemory.h stdarg.h time.h
DEPS= $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ=string.o io.o kmain.o screen.o boot.o vmemory.o stdarg.o time.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(OBJ)
	ld -m elf_i386 -T boot.ld -o kernel.bin $(OBJ)
$(ODIR)/boot.o: boot.asm
	nasm -f aout -o $@ $^
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

iso: kernel.bin
	cp kernel.bin iso/
	cd iso && sh makeiso.sh && cd ..

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ kernel.bin $(IDIR)/*~ iso/kernel.*
	rm -r iso/isodir 
