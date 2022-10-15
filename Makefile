
CC=gcc
CXX=g++
CFLAGS=-m32 -O1 -ffreestanding -fstrength-reduce -fomit-frame-pointer -finline-functions -std=gnu99 -nostdinc -Wall -m32 -I./include -g -Wno-unused-variable -fno-stack-protector
CXXFLAGS=-m32 -O1 -fno-builtin -ffreestanding -fstrength-reduce -fpermissive -fomit-frame-pointer -finline-functions -std=c++11 -nostdinc -Wall -m32 -I./include -g
#CPP+= -fno-rtti -fno-exceptions
ASM=nasm -f elf

SOURCES=sys.c main.c scrn.c gdt.c idt.c isrs.c irq.c timer.c keyboard_handler.c strings.c test.c memory.c vfs.c linkedlist.c tty.c syslog.c arraylist.c mfs.c
SAUCES=$(join $(addsuffix src/, $(dir $(SOURCES))), $(notdir $(SOURCES)))
CPPS=vector.cpp services.cpp
OBJ=loader.asm.o kernel.asm.o spammy.asm.o
OBJ+=$(SOURCES:.c=.o)
OBJ+=$(CPPS:.cpp=.o)
OBJECTS=$(join $(addsuffix output/, $(dir $(OBJ))), $(notdir $(OBJ)))

all: kernel.run boot.iso

output/%.o: src/%.c
	echo "Compiling $< to $@"
	$(CC) -c -o $@ $< $(CFLAGS)

output/kernel.asm.o:
	$(ASM) -o $@ kernel.asm

output/spammy.asm.o:
	$(ASM) -o $@ spammy.asm

output/loader.asm.o:
	$(ASM) -o $@ loader.asm
output/%.o: src/%.cpp
	echo "Compiling $< to $@"
	$(CXX) -c -o $@ $< $(CXXFLAGS)
build-cpp: $(CPPS)
	$(CXX) -c new.cpp -o new.o
	$(CXX) -c std/vector.cpp -o std/vector.o
	$(CXX) -c services.cpp -o services.o

print-%  : ; @echo $* = $($*)

kernel.run: $(OBJECTS)
	ld -m elf_i386 -T newlinker.ld -o kernel.run $(OBJECTS)

boot.iso: kernel.run
	rm iso/boot/kernel.run
	cp kernel.run ./iso/boot/kernel.run
	grub-mkrescue -o boot.iso iso

postbuild:
	rm -rf *.o

clean:
	rm -f $(OBJECTS)
	rm -f boot.iso

run: clean all
	qemu-system-i386 -cdrom boot.iso

debug: clean all
	qemu-system-i386 -s -S -cdrom boot.iso
