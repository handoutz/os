#ifndef __TIMER_H
#define __TIMER_H
extern int time_ticks;
extern int seconds_from_boot();
extern void timer_install();
extern void register_to_timer(void(*funk)(int));
extern void timer_wait(int ticks);

#endif
