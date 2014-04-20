#include <system.h>
#include <keyboard.h>
#include <linkedlist.h>

linked_list* kb_hooks;

void hook_keyboard(void (*handler)(char)) {
	ll_add(kb_hooks, handler);
}
void key_press(char c) {
	unsigned char scan;
	scan = c;
	if(scan > 0x80) {
		//released shift/whatever
	} else {
		int i;
		void (*handler)(char c) = 0;
		for(i=0; i< kb_hooks->size;i++) {
			handler = ll_get(kb_hooks, i);
			if(handler) {
				handler(kbdus[scan]);
			}
		}
		//putch(kbdus[scan]);
	}
}
void key_press_stub(char c){
	//putch(c);
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
	kb_hooks = ll_create();
}
