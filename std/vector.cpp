#include <std/vector.hpp>

namespace std {
    template<typename _TType>
    vector<_TType>::vector() {
        m_node = _llcreate();
    }

    template<typename _TType>
    vector<_TType>::~vector() {
        _lldestroy(m_node);
    }

    template<typename _TType>
    _TType *vector<_TType>::at(size_t i) {
        return (_TType *) _llget(m_node, i);
    }

    template<typename _TType>
    void vector<_TType>::push_back(_TType val) {
        _lladd(m_node, val);
    }

}