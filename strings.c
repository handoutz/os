#include <system.h>
#include <strings.h>
#include <memory.h>

char* i2s(int i) {
	if(i < 10) {
		char *res = malloc(sizeof(int));
		res[0] = (char)(((int)'0')+i);
		return res;
	}
	return (char*)i;
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
