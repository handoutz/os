#ifndef __MFS_H
#define __MFS_H
#include <system.h>

#define MFS_UNUSED 0
#define MFS_DIRECTORY 1
#define MFS_FILE 2


typedef struct mfs_block
{
    uint64_t id;
    uint32_t size;
    BYTE* data;
} _mfs_block;

typedef struct mfs_index_entry
{
    BYTE flags;
    _mfs_block* block;
} _mfs_index_entry;

extern void mfs_init();

#endif