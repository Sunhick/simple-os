all: boot.o kmain.o screen.o
	ld -m elf_i386 -T boot.ld -o kernel.bin kmain.o screen.o boot.o
boot.o: boot.asm
	nasm -f aout -o boot.o boot.asm
kmain.o: kmain.c include/system.h
	gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kmain.o kmain.c
screen.o: screen.c include/system.h
	gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o screen.o screen.c

.PHONY: clean
clean:
	rm -f *~ *.o kernel.bin
