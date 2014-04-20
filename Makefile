#rm kc.o kasm.o kernel scrn.o
#alias GCC='gcc -Wall -nostdinc -m32 -I./include'
#nasm -f elf32 kernel.asm -o kasm.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c system.c -o sys.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c kernel.c -o kc.o
#gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c scrn.c -o scrn.o
#ld -m elf_i386 -T link.ld -o kernel kasm.o sys.o kc.o scrn.o
#CC=gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include
CC=gcc -O -ffreestanding -fstrength-reduce -fomit-frame-pointer -finline-functions -std=gnu99 -nostdinc -Wall -m32 -I./include
ASM=nasm -f elf32

SAUCES=sys.c main.c scrn.c gdt.c idt.c isrs.c irq.c timer.c keyboard_handler.c strings.c test.c memory.c
OBJECTS=$(SAUCES:.c=.o)

all: build

build: clean build-asm build-c link postbuild

build-asm: kernel.asm
	$(ASM) kernel.asm -o kasm.o

#build-c: system.c kernel.c scrn.c gdt.c idt.c
build-c: $(SAUCES)
	$(CC) -c sys.c -o sys.o
	$(CC) -c gdt.c -o gdt.o
	$(CC) -c main.c -o main.o
	$(CC) -c scrn.c -o scrn.o
	$(CC) -c idt.c -o idt.o
	$(CC) -c isrs.c -o isrs.o
	$(CC) -c irq.c -o irq.o
	$(CC) -c timer.c -o timer.o
	$(CC) -c keyboard_handler.c -o keyboard_handler.o
	$(CC) -c strings.c -o strings.o
	#$(CC) -c memory.c -o memory.o

link: $(OBJECTS)
	#ld -m elf_i386 -T link.ld -o kernel kasm.o sys.o gdt.o kc.o scrn.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o $(OBJECTS)

postbuild:
	rm -rf *.o
clean:
	rm -rf $(OBJECTS) kernel
