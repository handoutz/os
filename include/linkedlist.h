#include <system.h>
#include <types.h>
typedef struct linked_list_node {
	void *val;
	struct linked_list_node *next;
} linked_list_node;

typedef struct linked_list {
	struct linked_list_node *root;
	struct linked_list_node *last;
	int size;
} linked_list;

extern linked_list* ll_create();
extern void ll_destroy(linked_list* ll);
extern void* ll_get(linked_list* ll, int n);
extern void ll_add(linked_list* ll, void* val);
