#include <system.h>
#include <memory.h>
#include <types.h>
//#include <liballoc.h>

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

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
void mem_init(void){
// And this inside a function
    unsigned int i;
    for(i=0;i<1024;i++){
           // This sets the following flags to the pages:
        //   Supervisor: Only kernel-mode can access them
        //   Write Enabled: It can be both read from and written to
        //   Not Present: The page table is not present
        page_directory[i] = 0x00000002;
    }
    for(i=0;i<1024;i++){
            // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }
    page_directory[0] = ((unsigned int)first_page_table) | 3;
    //loadPageDirectory(page_directory);
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
