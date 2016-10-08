#ifndef __FS_H
#define __FS_H

#define FS_PATH_MAX_LENGTH 32

#include <system.h>
#include <types.h>

#ifdef __cplusplus
#include "fstypes.hpp"
extern "C" {
#endif

extern STRING combinePath(char *a, char *b);

#ifdef __cplusplus
};
#endif

#endif