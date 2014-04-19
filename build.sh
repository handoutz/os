rm kc.o kasm.o kernel scrn.o
#alias GCC='gcc -Wall -nostdinc -m32 -I./include'
nasm -f elf32 kernel.asm -o kasm.o
gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c system.c -o sys.o
gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c kernel.c -o kc.o
gcc -O -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-builtin -Wall -nostdinc -m32 -I./include -c scrn.c -o scrn.o
ld -m elf_i386 -T link.ld -o kernel kasm.o sys.o kc.o scrn.o
