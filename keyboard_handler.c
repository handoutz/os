#include <system.h>
#include <keyboard.h>

void key_press(char c) {
	unsigned char scan;
	scan = c;
	if(scan > 0x80) {
		//released shift/whatever
	} else {
		//putch(kbdus[scan]);
	}
}
void keyboard_handler(struct regs *r){
	unsigned char scancode;
	//putch('a');
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
	int data = inportb(0x61);
	outportb(0x61, data|0x80);
	outportb(0x61, data & 0x7F);
}
