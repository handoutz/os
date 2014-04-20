#include <system.h>
//#include <keyboard.h>
int time_ticks = 0;

void timer_wait(int ticks) {
	unsigned long eticks;
	eticks = time_ticks + ticks;
	while(time_ticks < eticks);
}

void timer_phase(int hz) {
	int divide = 1193180/hz;
	outportb(0x43,0x36);
	outportb(0x40, divide & 0xFF);
	outportb(0x40, divide >> 8);
}

unsigned char lastKey = '\0';
void timer_handle(struct regs *r) {
	time_ticks++;
	if(time_ticks % 18 == 0) {
		//puts("one second!\n");
	}
	char kbStat = inportb(0x64);
	if(kbStat & 0x01) {
		char c = inportb(0x60);
		key_press(c);
	}
}
void timer_install(){
	irq_install_handler(0, &timer_handle);
}
