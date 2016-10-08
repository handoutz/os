#include <arraylist.h>
#include <syslog.h>
#include <system.h>

_llnode *_llcreate_val(void *initialValue) {
    _llnode *n;
    n = (_llnode *) malloc(sizeof(_llnode));
    n->data = initialValue;
    return n;
}

_llnode *_llcreate() {
    return _llcreate(NULL);
}

inline void *__getval(_llnode *node) {
    if (node == NULL)return NULL;
    return node->data;
}

void *_llget(_llnode *node, int pos) {
    _llnode *cur = node;
    int i = 0;
    while (i != pos) {
        //TRACE("_llget | i=%i, pos=%i, data=%s", i, pos, cur->data == NULL ? "NULL" : (char *) cur->data);
        cur = cur->next;
        if (cur == NULL)
            break;
        i++;
    };
    if (cur != NULL)return cur->data;
    return NULL;
}

void _lladd(_llnode *node, void *val) {
    _llnode *cur = node;
    int ii = 0;
    while (cur->next != NULL) {
        cur = cur->next;
        ii++;
    }
    cur->next = _llcreate_val(val);
    cur->next->data = val;
    //TRACE("_lladd | ii=%i, curval=%s, nextval=%s, setval=%s", ii, cur->data, cur->next->data, val);
    //TRACE("inserted [%s] at %i", (char *) val, ii);
}