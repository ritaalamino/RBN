// Copyright 2019 COPT

#ifndef NODE_H
#define NODE_H

namespace rbn {
namespace network {
namespace util {
class Node{
 private:
    static int cont;
    int state; //State RBN
    int id;

 public:
    Node();
    /**
      * It creates a Node with a random initial state.
      */
    Node(int v);
    /**
      * It creates a Node with a specific initial state.
      */
    int getState();
     /**
      * Returns Node State
      */
    void setState(int value);
    /**
      * Sets Node State
      */
    int getID();
    /**
      * Returns Node ID
      */
    int getCount();
    /**
      * Returns Node couting
      */
};
}  // namespace util
}  // namespace network
}  // namespace rbn

#endif  // NODE_h
