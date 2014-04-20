#include <system.h>
#include <test.h>
#include <strings.h>
#include <linkedlist.h>
void kp_test(char c) {
	putch(c);
}
void init_tests() {
	int eqs = strcmp("a", "a");
	int neqs = strcmp("a","b");
	printl(i2s(eqs));
	printl(i2s(neqs));
	
	int i;
	linked_list *lst = ll_create((void*)&("lol"));
	ll_add(lst, (void*)&("asdf"));
	printl((char*)ll_get(lst, 0));
	printl((char*)ll_get(lst, 1));
	printl((char*)ll_get(lst,0));
	
	for(i=0;i<lst->size;i++) {
		printl((char*)ll_get(lst, i));
	}
//	putch(i2s(strcmp("a","a"))[0]);
}
void test_kp() {
	hook_keyboard(&kp_test);
}
