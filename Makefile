#rm kc.o kasm.o kernel scrn.o
#alias GCC='gcc -Wall -nostdinc -m32 -I./include'
#nasm -f elf32 kernel.asm -o kasm.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c system.c -o sys.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c kernel.c -o kc.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c scrn.c -o scrn.o
#ld -m elf_i386 -T link.ld -o kernel kasm.o sys.o kc.o scrn.o
CC=gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include
ASM=nasm -f elf32

SAUCES=sys.c kernel.c scrn.c gdt.c idt.c isrs.c
OBJECTS=$(SAUCES:.c=.o)

all: build

build: clean build-asm build-c link

build-asm: kernel.asm
	$(ASM) kernel.asm -o kasm.o

#build-c: system.c kernel.c scrn.c gdt.c idt.c
build-c: $(SAUCES)
	$(CC) -c sys.c -o sys.o
	$(CC) -c gdt.c -o gdt.o
	$(CC) -c kernel.c -o kernel.o
	$(CC) -c scrn.c -o scrn.o
	$(CC) -c idt.c -o idt.o

link: $(OBJECTS)
	#ld -m elf_i386 -T link.ld -o kernel kasm.o sys.o gdt.o kc.o scrn.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o $(OBJECTS)


clean:
	rm -rf $(OBJECTS) kernel
