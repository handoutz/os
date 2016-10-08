#pragma once

#include <types.h>
#include <arraylist.h>

namespace std {
    template<typename _TType>
    class vector {
    private:
        _llnode *m_node;
    public:
        vector();

        ~vector();

        void push_back(_TType val);

        _TType *at(size_t i);
    };
}