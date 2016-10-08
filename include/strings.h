#ifndef __STRINGS_H
#define __STRINGS_H

#include <stdarg.h>

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL(__VA_ARGS__, 5,4,3,2,1)
#define VA_NUM_ARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N

#define CHARINRANGE(target, ...) char_in_range(target, VA_NUM_ARGS_IMPL(__VA_ARGS__,5,4,3,2,1), __VA_ARGS__)
#ifdef __cplusplus
extern "C" {
#endif

extern char *itoa(int val, int base);

extern char *i2s(int val);

int strcmp(char *a, char *b);

BOOL char_in_range(char target, int ct, ...);

//extern size_t strlen(STRING str);
extern STRING sprintf(char *fmt, ...);

extern STRING vsprintf(char *fmt, va_list lst);

extern STRING char2str(char c);

#ifdef __cplusplus
};
#endif
#endif
