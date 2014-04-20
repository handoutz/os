#ifndef __HEADER_VFS
#define __HEADER_VFS

#include <system.h>
#include <types.h>
#include <memory.h>

#define NODE_DIRECTORY 0
#define NODE_FILE 1
#define NODE_SIZE 8192

typedef unsigned short node_type;

typedef struct vfs_node {
	node_type type;
	char* name;
	void* location;
	
	struct vfs_node* next;

	struct vfs_node* parent;
} vfs_node;
extern void initvfs();
extern vfs_node* vfs_map(char* path);
extern vfs_node* vfs_create(char* path);
#endif
