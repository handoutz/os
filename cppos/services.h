#ifndef __SERVICES_H
#define __SERVICES_H

#ifdef __cplusplus

inline void *operator new(size_t size) throw() {
    void *ptr = malloc(size);
    return ptr;
}
inline void *operator new(size_t size, void *p) throw() {
    return p;
}
inline void *operator new[](size_t size, void *p) throw() {
    return p;
}

inline void operator delete(void *ptr) {}
inline void operator delete[](void *ptr) {}

extern "C" {
#endif

extern void initialize_svcs();

#ifdef __cplusplus
};
#endif

#endif