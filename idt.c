#include <system.h>
struct idt_entry {
	unsigned short base_lo;
	unsigned short sel;
	unsigned char always0;
	unsigned char flags;
	unsigned short base_hi;
} STRUCT_PACKED;
struct idt_ptr{
	unsigned short limit;
	unsigned int base;
} STRUCT_PACKED;

struct idt_entry idt[256];
struct idt_ptr idtp;

extern void idt_load();
