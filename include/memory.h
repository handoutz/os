#ifndef __MEMORY_H
#define __MEMORY_H
#include <types.h>

struct allocation{
	size_t start;
	size_t end;
	size_t size;
	void* ptr;
};

extern void memory_init();
//initializes a memory location
extern void *malloc(size_t size);
//initializes an array
extern void *calloc(size_t num, size_t eleSize);

#endif
