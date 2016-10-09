#pragma once

#include <types.h>
#include <arraylist.h>

namespace std {

    template<typename _TType>
    class arraylist {
    private:
        _llnode *m_node;
    public:
        arraylist() {
            //m_node = _llcreate();
        }

        ~arraylist() {
            //_lldestroy(m_node);
        }

        size_t len() {
            return m_node->dist_to_end + 1;
        }

        void push_back(_TType val) {
            _lladd(m_node, val);
        }

        _TType at(size_t i) {
            return (_TType) _llget(m_node, i);
        }
    };
}