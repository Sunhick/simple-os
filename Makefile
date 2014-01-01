IDIR=./include
CC=gcc
CFLAGS=-m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fno-stack-protector -I$(IDIR)

LIBS= -lssp
ODIR=obj
LDIR=

_DEPS=string.h system.h io.h screen.h vmemory.h stdarg.h
DEPS= $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ=string.o io.o kmain.o screen.o boot.o vmemory.o stdarg.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(OBJ)
	ld -m elf_i386 -T boot.ld -o kernel.bin $(OBJ)
$(ODIR)/boot.o: boot.asm
	nasm -f aout -o $@ $^
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ kernel.bin $(IDIR)/*~
