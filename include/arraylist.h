#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H

typedef struct _llnode {
    void *data;
    struct _llnode *next;
} _llnode;

extern _llnode *_llcreate();
extern _llnode *_llcreate_val(void* val);

extern void *_llget(_llnode *node, int pos);

extern void _lladd(_llnode *node, void *val);

#endif