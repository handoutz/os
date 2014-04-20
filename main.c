#include <system.h>
#include <test.h>
void irq_keyboard(struct regs *r){
	puts("keyboard interrupted");
}

void kmain(void)
{
	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
	__asm__ __volatile__("sti");
	//irq_install_handler(1, &irq_keyboard);
	timer_install();
	keyboard_install();

	init_video();
	memory_init();
	init_tests();

	for(;;);
}

