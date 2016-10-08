#ifndef __MACRO_H
#define __MACRO_H

#include "types.h"
#include "memory.h"

#define STRUCT_PACKED __attribute__((packed))

inline PAIR *create_pair(void *a, void *b) {
    PAIR *p = (PAIR *) malloc(sizeof(PAIR));
    p->first = a;
    p->second = b;
    return p;
}
#ifdef __cplusplus

#define MALLOCATECLASS(classname) new ((classname*)malloc(sizeof(classname))) classname();
#endif
#endif
