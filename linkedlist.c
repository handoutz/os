#include <system.h>
#include <types.h>
#include <linkedlist.h>
#include <memory.h>

linked_list* ll_create() {
	linked_list_node* rootNode = (linked_list_node*)malloc(sizeof(struct linked_list_node));
	linked_list* lst = (linked_list*)malloc(sizeof(struct linked_list));
	struct linked_list_node root = {
		0, 0
	};
	*rootNode = root;
	struct linked_list lster = {
		rootNode, rootNode, 1
	};
	*lst = lster;
	return lst;
}
void ll_destroy(linked_list* ll) {
}
void *ll_get(linked_list* ll, int pos) {
	int i;
	//printl(i2s(pos));
	linked_list_node *lst = ll->root;
	for(i=0;i<pos;i++) {
		lst = lst->next;
	}
	//printl((char*)lst->val);
	return lst->val;
}
void ll_add(linked_list* ll, void* val) {
	if(ll->root->val == 0) {
		ll->root->val = val;
		return;
	}
	linked_list_node *n = (linked_list_node*)malloc(sizeof(struct linked_list_node));
	struct linked_list_node node = {
		val, 0
	};
	*n = node;
	ll->size++;
	ll->last->next = n;
	ll->last = n;
}
