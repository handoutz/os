#pragma once

#include <types.h>

namespace fs {

    class Path {
    public:

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