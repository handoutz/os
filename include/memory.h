#ifndef __MEMORY__H
#define __MEMORY__H
#include <system.h>
#include <types.h>
//#include <liballoc.h>

#define MEMORY_START_LOC 0xC0100000;


extern unsigned char *memcpy(unsigned char*, const unsigned char*, size_t);
extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *s, size_t count);
extern unsigned char *memset(unsigned char*, unsigned char, size_t);
extern unsigned short *memsetw(unsigned short*, unsigned short, size_t);
void mem_init(void);
/*extern void *sbrk(size_t size);
extern void *malloc(size_t);
extern void *realloc(void*, size_t);
extern void *calloc(size_t, size_t);
extern int free(void*);*/
void     *malloc(size_t);				//< The standard function.
void     *realloc(void *, size_t);		//< The standard function.
void     *calloc(size_t, size_t);		//< The standard function.
int      free(void *);					//< The standard function.

#endif
