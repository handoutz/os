#include <system.h>
#include <memory.h>
#include <types.h>
typedef struct alloc_major {
        struct lloc_major *prev;
        struct alloc_major *next;
        size_t pages;
        size_t size;
        size_t usage;
        struct alloc_minor *first;
} alloc_major;

typedef struct alloc_minor {
        struct alloc_minor *prev;
        struct alloc_minor *next;
        struct alloc_major *block;
        size_t magic;
        size_t size;
        size_t req_size;
} alloc_minor;

static struct alloc_major *memRoot = 0;
static struct alloc_minor *bestBet = 0;

static size_t page_size = 4096;
static size_t page_count = 16;
static unsigned long long allocated = 0;
static unsigned long long inuse = 0;

void *mem_start = (void*)0x00100000;
void *malloc(size_t size) {
	char *loc;
	loc = mem_start;
	mem_start += size;
	return (void*)loc;
}
void *realloc(void* ptr, size_t size) {
	//todo: this
	return 0;
}
void *calloc(size_t num, size_t size) {
	//todo: this
	return 0;
}
void free(void* ptr) {
	//todo: this
	return 0;
}

static void mm_dump() {
	printl("[MM] DEBUG DUMP");
}

static struct alloc_major *mm_alloc_page(size_t size) {
	size_t sz;
	struct alloc_major *maj;
	sz = size + sizeof(struct alloc_major);
	sz += sizeof(alloc_minor);
	if( (sz%page_size) == 0)
		sz = sz / page_size;
	else
		sz = sz / (page_size) + 1;
	
	if(sz < page_count) sz = page_count;
	//todo: this
	return NULL;
}

unsigned short *memcpyw(unsigned short *dest, const unsigned short *s, size_t count){
		short *dst = (short*)dest;
			short *src = (short*)s;
				--src;
					--dst;
						while(count--){
									*++dst=*++src;
										}
							return dest;
}
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, size_t ct){
		char *dst = (char*) dest;
			char *s = (char*)src;
				--s;
					--dest;
						while(ct--){
									*++dst = *++s;
										}
							return dest;
}
unsigned char *memset(unsigned char *dest, unsigned char val, size_t count){
		char *d=(char*)dest;
			do{
						*d++ = val;
							}while(count--);
				return dest;
}
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count){
		short *d=(short*)dest;
			do{
						*d++=val;
							} while(count--);
				return dest;
}

