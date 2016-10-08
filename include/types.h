#ifndef __TYPES_H
#define __TYPES_H

#define CHAR unsigned char
#define STRING CHAR*
#define CSTRING const CHAR*

typedef unsigned int size_t;
#define NULL 0

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct POINT {
    int x;
    int y;
} POINT;
typedef struct PAIR {
    void *first;
    void *second;
} PAIR;

#endif
