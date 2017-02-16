;;kernel.asm
bits 32
section .text
global start
global gettime
gettime:
    ret
extern kmain

global idt_load
extern idtp
idt_load:
	lidt [idtp]
	ret

global gdt_flush
extern protect_main
extern gp
gdt_flush:
	cli
	lgdt [gp]   ;loads gdt with [gp]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	mov ax, 0x10 ; 0x10 is the offset in GDT to our segment
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	sti
	jmp 0x08:protect_main
flush2:
	ret
global enablesse
enablesse:
	mov eax, cr0
	and ax, 0xFFFB
	or ax, 0x2
	mov cr0, eax
	mov eax, cr4
	or ax, 3 << 9
	mov cr4, eax
	ret
start:
	call enablesse
	cli
	call kmain
	hlt
