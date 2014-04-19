#include <system.h>
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
int strlen(unsigned char *str){
	int i=0;
	while(str[i++] != '\0');
		return i;
}
unsigned char inportb (unsigned short _port){
	unsigned char rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}
void outportb (unsigned short _port, unsigned char _data){
	__asm__ __volatile__("outb %1, %0" : : "dN" (_port), "a" (_data));
}
