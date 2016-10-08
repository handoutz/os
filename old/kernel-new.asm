[BITS 32]
global start
start:
	mov esp, _sys_stack
	jmp stublet
        dd 0x1BADB002           ;magic
        dd 0x00                 ;flags
        dd - (0x1BADB002 + 0x00);checksum


stublet:
	extern kmain
	call kmain
	jmp $

SECTION .bss
	resb 8192
_sys_stack:
