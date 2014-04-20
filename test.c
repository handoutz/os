#include <system.h>
#include <test.h>
#include <strings.h>

void init_tests() {
	int eqs = strcmp("a", "a");
	int neqs = strcmp("a","b");
	printl(i2s(eqs));
	printl(i2s(neqs));
//	putch(i2s(strcmp("a","a"))[0]);
}
