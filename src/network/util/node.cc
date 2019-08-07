// Copyright 2019 COPT

#include <random>

#include "network/util/node.h"

namespace rbn {
namespace network {
namespace util {

int Node::cont = 0;
Node::Node() {
    id = ++cont;
    state = rand()%2;
}

Node::Node(int v) {
    id = ++cont;
    state = v;
}

void Node::setState(int value) {
    state = value;
}

int Node::getState() {
    return state;
}

int Node::getID() {
    return id;
}

int Node::getCount() {
    return cont;
}
}  // namespace util
}  // namespace network
}  // namespace rbn
