#ifndef __MEMORY__H
#define __MEMORY__H
#include <system.h>
#include <types.h>

#define MEMORY_START_LOC 0x00100000;

typedef struct boundary_tag {
	unsigned int magic;
	unsigned int size;
	unsigned int real_size;
	int index;

	struct boundary_tag *split_left;
	struct boundary_tag *split_right;

	struct boundary_tag *prev;
	struct boundary_tag *next;
} boundary_tag;

extern unsigned char *memcpy(unsigned char*, const unsigned char*, size_t);
extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *s, size_t count);
extern unsigned char *memset(unsigned char*, unsigned char, size_t);
extern unsigned short *memsetw(unsigned short*, unsigned short, size_t);

extern void *malloc(size_t);
extern void *realloc(void*, size_t);
extern void *calloc(size_t, size_t);
extern void free(void*);

#endif
