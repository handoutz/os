#include <system.h>
#include <memory.h>
#include <types.h>
#include <liballoc.h>

static size_t page_size = 4096;
static size_t page_count = 16;
void *mem_start = (void *)MEMORY_START_LOC;

void *malloc(size_t size) {
	char *loc;
	loc = mem_start;
	mem_start += size+1;
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
int free(void* ptr) {
	//todo: this
	return 0;
}


unsigned short *memcpyw(unsigned short *dest, const unsigned short *s, size_t count)
{
    short *dst = (short *)dest;
    short *src = (short *)s;
    --src;
    --dst;
    while (count--)
    {
	*++dst = *++src;
    }
    return dest;
}
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, size_t ct)
{
    char *dst = (char *)dest;
    char *s = (char *)src;
    --s;
    --dest;
    while (ct--)
    {
	*++dst = *++s;
    }
    return dest;
}
unsigned char *memset(unsigned char *dest, unsigned char val, size_t count)
{
    char *d = (char *)dest;
    do
    {
	*d++ = val;
    } while (count--);
    return dest;
}
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    short *d = (short *)dest;
    do
    {
	*d++ = val;
    } while (count--);
    return dest;
}
