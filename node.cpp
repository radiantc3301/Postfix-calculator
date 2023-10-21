#include "node.h"
#include <stdexcept>
#include <iostream>

Node::Node(bool sentinel) {
    is_sentinel = sentinel;
    value = 0;  // Or any appropriate default value for sentinel nodes
    next = nullptr;
    prev = nullptr;
}

Node::Node(int v, Node* nxt, Node* prv) {
    is_sentinel = false;  // Regular nodes are not sentinel nodes
    value = v;
    next = nxt;
    prev = prv;
}

bool Node::is_sentinel_node() {
    return is_sentinel;
}

int Node::get_value() {
    return value;
}
