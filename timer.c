#include <system.h>
#include <arraylist.h>

//#include <keyboard.h>
int time_ticks = 0;
_llnode *root_node;

void timer_wait(int ticks) {
    unsigned long eticks;
    eticks = time_ticks + ticks;
    while (time_ticks < eticks);
}

void timer_phase(int hz) {
    int divide = 1193180 / hz;
    outportb(0x43, 0x36);
    outportb(0x40, divide & 0xFF);
    outportb(0x40, divide >> 8);
}

int seconds_from_boot() {
    return time_ticks / 18;
}

unsigned char lastKey = '\0';

void timer_handle(struct regs *r) {
    time_ticks++;
    if (time_ticks % 18 == 0) {
        if (root_node != NULL) {
            for (int iter = 0; iter <= _llsize(root_node); iter++) {
                TIMERCB cb = (TIMERCB) _llget(root_node, iter);
                cb(time_ticks);
            }
        }
    }
    char kbStat = inportb(0x64);
    if (kbStat & 0x01) {
        char c = inportb(0x60);
        key_press(c);
    }
}

void timer_install() {
    irq_install_handler(0, &timer_handle);
}

void register_to_timer(TIMERCB cb) {
    if (root_node == NULL) {
        root_node = _llcreate_val(cb);
    } else {
        _lladd(root_node, cb);
    }
}
