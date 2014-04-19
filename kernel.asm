;;kernel.asm
bits 32
section .text
	align 4
	dd 0x1BADB002		;magic
	dd 0x00			;flags
	dd - (0x1BADB002 + 0x00);checksum
global start
extern kmain

global gdt_flush
extern gp
gdt_flush:
	lgdt [gp]   ;loads gdt with [gp]
	mov ax, 0x10 ; 0x10 is the offset in GDT to our segment
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush2
flush2:
	ret
start:
	cli
	call kmain
	hlt
