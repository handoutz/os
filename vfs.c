#include <fs/vfs.h>
vfs_node* root = NULL;

void initvfs(){
	vfs_node r = {
		NODE_DIRECTORY, "/", malloc(NODE_SIZE),
		NULL, NULL
	};
	root = &r;
	puts("initialized VFS at ");
	puts(i2s(root));
	puts("\n");
}
vfs_node* vfs_map(char* path){
	
}
vfs_node* vfs_create(char* path){

}

