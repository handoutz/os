#include <system.h>
#include <strings.h>
#include <memory.h>
#include <stdarg.h>
#include <syslog.h>
#include <arraylist.h>

char *itoa(int val, int base) {
    if (val == 0) {
        return "0";
    }
    static char buf[32] = {0};
    int i = 30;
    for (; val && i; --i, val /= base) {
        buf[i] = "0123456789abcdef"[val % base];
    }
    return &buf[i + 1];
}

char *i2s(int val) {
    return itoa(val, 10);
}

int strcmp(char *a, char *b) {
    int i = 0;
    while (1) {
        if (a[i] == '\0' && b[i] == '\0') {
            return 1;
        }
        if (a[i] == '\0' || b[i] == '\0') {
            return 0;
        }
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return 0;
}

BOOL char_in_range(char target, int ct, ...) {
    //DEBUG("targ: %c, %i", target, ct);
    va_list lst;
    va_start(lst, ct);
    for (int i = 0; i < ct; i++) {
        int arg = va_arg(lst, int);
        //DEBUG("arg=%c|%i", arg, arg);
        if (target == arg) {
            va_end(lst);
            return TRUE;
        }
    }
    va_end(lst);
    return FALSE;
}

inline void addlst(_llnode **n, char *val) {
    int *len = (int *) malloc(sizeof(int));
    *len = strlen(val);
    PAIR *p = create_pair(val, len);

    if (*n == NULL) {
        *n = _llcreate_val(p);
    } else {
        _lladd(*n, p);
    }
}

unsigned char *sprintf(char *fmt, ...) {
    va_list lst;
    STRING res;
    va_start(lst, fmt);
    res = vsprintf(fmt, lst);
    va_end(lst);
    return res;
}

unsigned char *char2str(char c) {
    STRING res = (STRING) malloc(sizeof(c) * 2);
    res[0] = (unsigned char) c;
    res[1] = '\0';
    return res;
}

unsigned char *vsprintf(char *fmt, va_list lst) {
    _llnode *node = NULL;
    BOOL expecting_fmt = FALSE;
    while (*fmt != '\0') {
        if (*fmt == '%') {
            expecting_fmt = TRUE;
        } else if (expecting_fmt == TRUE) {
            expecting_fmt = FALSE;
            switch (*fmt) {
                case 's': {
                    char *s = va_arg(lst, char*);
                    addlst(&node, s);
                    //puts(s);
                    break;
                }
                case 'i': {
                    int i = va_arg(lst, int);
                    addlst(&node, itoa(i, 10));
                    //puts(itoa(i, 10));
                    break;
                }
                case 'c': {
                    int i = va_arg(lst, int);
                    addlst(&node, (char *) char2str((char) i));
                    break;
                }
            }
        } else {
            addlst(&node, (char *) char2str(*fmt));
        }
        ++fmt;
    }
    if (node == NULL) {
        return NULL;
    }
    _llnode *cur = node;
    int totalLen = 0;
    while (cur != NULL) {
        PAIR *curp = cur->data;
        int *len = curp->second;
        totalLen += *len;
        cur = cur->next;
    }
    STRING resultStr = (STRING) malloc((sizeof(CHAR) * totalLen) + 1);
    cur = node;
    int resCt = 0;
    while (cur != NULL) {
        PAIR *curp = cur->data;
        int *len = curp->second;
        STRING val = curp->first;
        for (int j = 0; j < *len; j++) {
            if (val[j] == '\0')continue;
            //puts(i2s(resCt));
            resultStr[resCt++] = val[j];
        }
        cur = cur->next;
    }
    resultStr[resCt] = '\0';
    return resultStr;
}
