#ifdef __cplusplus
#pragma once

#include <system.h>

template<typename t>
t *mallocate() {
    return (t *) malloc(sizeof(t));
}

template<typename t>
t callocate(int ct) {
    return (t) malloc(sizeof(t) * ct);
}

#endif