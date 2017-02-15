#ifndef __MFS_H
#define __MFS_H

typedef struct inode
{
    uint32_t ino;
    uint32_t size;
    uint32_t mode;
    uint32_t mtime;
    uint32_t dtime;
    uint32_t blocks;
    uint32_t flags;
    UCHAR* block;
} _inode;

extern void mfs_init();

#endif