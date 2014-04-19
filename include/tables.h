#ifndef __TABLES_H
#define __TABLES_H

extern void gdt_flush();

extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();

#endif
