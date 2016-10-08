#ifndef __HASHMAP_H
#define __HASHMAP_H

typedef int (*hm_cmp)(void *a, void *b);
typedef unsigned int (*hm_hash)(void *key);

typedef struct Hashmap {
	void *buckets;
	hm_cmp compare;
	hm_hash hash;
} Hashmap;
typedef struct HashmapNode{
	void *key;
	void *value;
	unsigned int hash;
} HashmapNode;

typedef int (*hm_traverse_cb)(HashmapNode *node);

Hashmap *hm_create(hm_cmp compare, hm_hash hash, size_t size);
void hm_destroy(Hashmap *hm);

int hm_set(Hashmap *hm, void *key, void *data);
void *hm_get(Hashmap *hm, void *key);

int hm_traverse(Hashmap *map, hm_traverse_cb cb);
void *hm_delete(Hashmap *map, void *key);

#endif
