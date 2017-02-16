CC=i386-elf-gcc
CXX=i386-elf-g++
CFLAGS=-O1 -ffreestanding -fstrength-reduce -fomit-frame-pointer -finline-functions -std=gnu99 -nostdinc -Wall -m32 -I./include -g
CXXFLAGS=-O1 -fno-builtin -ffreestanding -fstrength-reduce -fpermissive -fomit-frame-pointer -finline-functions -std=c++11 -nostdinc -Wall -m32 -I./include -g
#CPP+= -fno-rtti -fno-exceptions
ASM=nasm -f elf

SAUCES=sys.c main.c scrn.c gdt.c idt.c isrs.c irq.c timer.c keyboard_handler.c strings.c test.c memory.c vfs.c linkedlist.c tty.c syslog.c arraylist.c mfs.c
CPPS=std/vector.cpp services.cpp
OBJECTS=kernel.asm.o spammy.asm.o
OBJECTS+=$(SAUCES:.c=.o)
OBJECTS+=$(CPPS:.cpp=.o)


all: kernel.run

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS)

kernel.asm.o: 
	$(ASM) -o $@ kernel.asm

spammy.asm.o:
	$(ASM) -o $@ spammy.asm

build-cpp: $(CPPS)
	$(CXX) -c new.cpp -o new.o
	$(CXX) -c std/vector.cpp -o std/vector.o
	$(CXX) -c services.cpp -o services.o

print-%  : ; @echo $* = $($*)

kernel.run: $(OBJECTS)
	i386-elf-ld -m elf_i386 -T link.ld -o kernel.run $(OBJECTS)

postbuild:
	rm -rf *.o
clean:
	rm -f $(OBJECTS)