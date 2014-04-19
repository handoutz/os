#include <system.h>
#include <keyboard.h>
void keyboard_handler(struct regs *r){
	unsigned char scancode;
	putch('a');
	scancode = inportb(0x60);
	if(scancode & 0x80) {
		//user released shift/alt/ctl
	}else {
		//key was pressed
		putch(kbdus[scancode]);
	}
}
void keyboard_install() {
	irq_install_handler(1, keyboard_handler);
}
