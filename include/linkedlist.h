#include <system.h>
#include <types.h>
typedef struct linked_list_node {
	void *val;
	linked_list_node *next;
} linked_list_node;

typedef struct linked_list {
	linked_list_node *nodes;
} linked_list;
