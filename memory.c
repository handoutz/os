#include <system.h>
#include <memory.h>

void *memory_start = (void*)0x01000000;

struct allocation allocs[1024];
int alloc_ct = 0;

void memory_init(){
	printl("memory started");
}
void free(void *loc){

}
void *malloc(size_t size){
	char *loc;
	loc = memory_start;
	memory_start += size;

	allocs[alloc_ct].start = (size_t)(memory_start - size);
	allocs[alloc_ct].end = (size_t)(memory_start);
	allocs[alloc_ct].size = size;
	allocs[alloc_ct].ptr = (void*)loc;

	alloc_ct++;
	return (void*)loc;
}
void *calloc(size_t num, size_t eleSize){
	return 0;
}
unsigned short *memcpyw(unsigned short *dest, const unsigned short *s, int count){
	short *dst = (short*)dest;
	short *src = (short*)s;
	--src;
	--dst;
	while(count--){
		*++dst=*++src;
	}
	return dest;
}
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int ct){
	char *dst = (char*) dest;
	char *s = (char*)src;
	--s;
	--dest;
	while(ct--){
		*++dst = *++s;
	}
	return dest;
}
unsigned char *memset(unsigned char *dest, unsigned char val, int count){
	char *d=(char*)dest;
	do{
		*d++ = val;
	}while(count--);
	return dest;
}
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count){
	short *d=(short*)dest;
	do{
		*d++=val;
	} while(count--);
	return dest;
}
