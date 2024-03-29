#ifndef __TIMER_H
#define __TIMER_H
typedef void (*TIMERCB)(int);
extern int time_ticks;
extern int seconds_from_boot();
extern void timer_install();
extern void register_to_timer(TIMERCB cb);
extern void timer_wait(int ticks);

#endif
