#include <system.h>
#include <test.h>
#include <fs/vfs.h>
#include <io/tty.h>

void irq_keyboard(struct regs *r) {
    puts("keyboard interrupted");
}
int in_prot_mode = 0;
void protect_main(void) {
    in_prot_mode = 1;
    //puts("asdfasdfadsfadsfdasfasdfwat");
    //protected_aftersetup();
}
void kmain(void) {
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    __asm__ __volatile__("sti");
    //init_video();
    //irq_install_handler(1, &irq_keyboard);
    timer_install();
    keyboard_install();
    //__asm__ __volatile__("mov eax, 0x0");
    protected_aftersetup();

    for (;;);
}
void protected_aftersetup() {
    init_video();
    initvfs();
    init_tests();
    keyboard_install();
    puts("in protected mode: ");
    puts(i2s(in_prot_mode));
    putch('\n');
    //test_kp();
    tty_init();
    for (;;);
}

