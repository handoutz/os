#pragma once
#ifndef __SYSTEM_H
#define __SYSTEM_H
#ifdef __cplusplus
extern "C" {
#endif

#include <macro.h>
#include <tables.h>
#include <timer.h>
#include <types.h>
#include <memory.h>
#include <strings.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LGRAY 7
#define COLOR_DGRAY 8
#define COLOR_LBLUE 9
#define COLOR_LGREEN 10
#define COLOR_WHITE 15

extern void keyboard_install();

//extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
//extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count);

//extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
//extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

extern int strlen(unsigned char *str);
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned char _data);

//vidya
extern void cls();
extern void putch(unsigned char c);
extern void putus(unsigned char *str);
extern void puts(char *str);
extern void printl(char *str);
extern void printf(char *str, ...);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void setcursorloc(int x, int y);
extern void setcursorloc_pt(POINT p);
extern POINT getcursorloc();
extern void init_video();

extern void key_down(char k);
//void (*handler)(struct regs *rr);
extern void hook_keyboard(void (*handler)(char c));
#ifdef __cplusplus
};
/*void *operator new(size_t s) {
    void *ss = malloc(s);
    return ss;
}
void operator delete(void *p) {
    free(p);
}*/
#endif

#endif
