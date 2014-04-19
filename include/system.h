#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <macro.h>
#include <tables.h>
#include <timer.h>
#include <types.h>


extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count);

extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

extern int strlen(unsigned char *str);
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned char _data);

//vidya
extern void cls();
extern void putch(unsigned char c);
extern void putus(unsigned char *str);
extern void puts(char* str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

//gdt

#endif
