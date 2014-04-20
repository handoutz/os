#include <system.h>
#include <strings.h>
#include <memory.h>
char *itoa(int val, int base) {
	if(val == 0){
		return "0";
	}
	static char buf[32] = {0};
	int i = 30;
	for(;val&&i; --i, val /= base){
        	buf[i]="0123456789abcdef"[val%base];
        }
        return &buf[i+1];
}
char *i2s(int val) {
	return itoa(val, 10);
}

int strcmp(char *a, char *b) {
	int i=0;
	while(1) {
		if(a[i]=='\0' && b[i]=='\0'){
			return 1;
		}
		if(a[i]=='\0' ||  b[i]=='\0') {
			return 0;
		}
		if(a[i] != b[i]){
			return 0;
		}
		i++;
	}
	return 0;
}
