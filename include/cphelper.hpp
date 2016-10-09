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
/*#ifndef __cxxbv1_done
#define __cxxbv1_done
namespace __cxxabiv1 {
    /* guard variables */

    /* The ABI requires a 64-bit type.
    __extension__ typedef int __guard __attribute__((mode(__DI__)));

    extern "C" int __cxa_guard_acquire(__guard *);
    extern "C" void __cxa_guard_release(__guard *);
    extern "C" void __cxa_guard_abort(__guard *);

    extern "C" int __cxa_guard_acquire(__guard *g) {
        return !*(char *) (g);
    }

    extern "C" void __cxa_guard_release(__guard *g) {
        *(char *) g = 1;
    }

    extern "C" void __cxa_guard_abort(__guard *) {

    }
}
#endif*/

#endif