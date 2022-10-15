#include <fs/vfs.h>
vfs_node* root = NULL;
vfs_node* vfs_dev = NULL;
vfs_node* tty0 = NULL;

void initvfs(){
	vfs_dev = malloc(sizeof(struct vfs_node));
	tty0 = malloc(sizeof(struct vfs_node));
	root = malloc(sizeof(struct vfs_node));
	vfs_node _tty0 = {
		NODE_FILE, "tty0", malloc(NODE_SIZE), NULL,
		NULL, NULL
	};
	vfs_node dev = {
		NODE_DIRECTORY, "dev", malloc(NODE_SIZE), tty0,
		tty0, root
	};
	vfs_node r = {
		NODE_DIRECTORY, "/", malloc(NODE_SIZE), vfs_dev,
		vfs_dev, NULL
	};
	*root = r;
	*vfs_dev = dev;
	*tty0 = _tty0;
	puts("initialized VFS at ");
	puts(i2s(root));
	puts("\n");
}
vfs_node* vfs_subnode(vfs_node* super, char* name) {
	vfs_node* cur = super->first_child;
	while(cur != NULL) {
		if(strcmp(cur->name, name)) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
vfs_node* vfs_map(char* path){
	if(strcmp(path, "/")){
		return root;
	}
	int i=0,j=0;
	char cur = path[0];
	char *curname = malloc(64);
	vfs_node *curnode;
	while(cur != '\0') {
		if(cur == '/' && curnode == NULL) {
			curnode = root;
		} else if(cur == '/') {
			curname[j] = '\0';
			curnode = vfs_subnode(curnode, curname);
			*curname = "";
			j=0;
		} else {
			curname[j++] = cur;
		}
		cur = path[i++];
	}
	return curnode;
}
vfs_node* vfs_create(char* path){

}

