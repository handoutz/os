#ifndef __HEADER_TTY_
#define __HEADER_TTY_

#include <system.h>
#include <types.h>

extern void tty_init();
extern void tty_show_prompt();
extern void tty_key_down(char c);
extern void tty_on_enter();
#endif
