#pragma once

#include <types.h>
#include <cphelper.hpp>
#include <std/cstring.hpp>

namespace fs {

    class Path {
    private:
        STRING m_location, m_basename;
    public:
        //Path(STRING loc, STRING name) : m_location(loc), m_basename(name) {}
        Path(const Path &parent) : m_location(parent.m_location), m_basename(parent.m_basename) {}

        template<typename ... _tname>
        Path(Path parent, _tname ... parts) {

        }

        template<typename ... _tname>
        static STRING combine(_tname ... parts) {

        }
    };

    class Node {
    public:
        Node();

        Node(STRING name);
    };

    class Filesystem {
    public:
        virtual void initialize() {}

        virtual Node *create_node(Path p) {}

    };
}