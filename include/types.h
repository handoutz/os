#ifndef __TYPES_H
#define __TYPES_H

#define CHAR unsigned char
#define STRING CHAR *
#define CSTRING const CHAR *

typedef unsigned int size_t;
#define NULL 0

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct POINT
{
    int x;
    int y;
} POINT;
typedef struct PAIR
{
    void *first;
    void *second;
} PAIR;
//1 byte
typedef signed char int8_t;
//1 byte
typedef unsigned char uint8_t;
typedef unsigned char BYTE;
//2 bytes
typedef signed int int16_t;
//2 bytes
typedef unsigned int uint16_t;
//4 bytes
typedef signed long int int32_t;
//4 bytes
typedef unsigned long int uint32_t;
//8 bytes
typedef signed long long int int64_t;
//8 bytes
typedef unsigned long long int uint64_t;

#endif
