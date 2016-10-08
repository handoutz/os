#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _llnode {
    void *data;
    struct _llnode *next;
    int dist_to_end;
} _llnode;

extern _llnode *_llcreate();

extern _llnode *_llcreate_val(void *val);

extern int _llsize(_llnode *node);

extern void *_llget(_llnode *node, int pos);

extern void _lladd(_llnode *node, void *val);

extern void _lldestroy(_llnode *node);
#ifdef __cplusplus
};
#endif

#endif