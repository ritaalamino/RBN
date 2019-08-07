// Copyright 2019 COPT

#ifndef NETWORK_RBN_H
#define NETWORK_RBN_H

#include <vector>
#include "bits/stdc++.h"
#include "util/node.h"

namespace rbn {
namespace network {
class RBN{
 protected:
    int steps; 
    int vertex_num; 
    std::vector<int> number_connections;
    std::vector<std::vector<int> > saved_logic_functions;
    std::vector<std::vector<int> > connections_graph;
    std::vector<util::Node> vertex_node;
    std::vector<std::vector<int> > f_Logica;
    std::vector<std::vector<util::Node> > h_States;

 public:
    /*Recieves node number and random seed (v_n,r)*/
    RBN(int v_n, int r);
    /**
      * It is the constructor that builds a Random
      * Boolean Network base. It is necessary to create
      * some of the other son classes.
      * Recieves the vertex number and the random seed.
      */
    void addHistory();
      /**
      * It adds the last vertex node at a historic matrix.
      */
    void setSteps(int p);
    /**
      * The functions recieves the number of steps
      * you are going to make, so you can use
      * to calculate distances with no problem.
      */
    int getSteps();
    /**                                                                                                                                                                                                                                                                                                                                     
      * It returns the steps number.
      */
    void setNumberConnections();
    /**                                                                                                                                                                                                                                                                                                                                     
      * It is necessary to use before define logic functions.
      * It updates the connections number.
      */
    void setConnections(std::vector<std::vector<int>> a);
    /**                                                                                                                                                                                                                                                                                                                                     
      * It recieves a matrix of int (vector), that updates connections.
      * It is necessary to respect the vertex number.
      */

    std::vector<int> getNumberConnections();
    /**                                                                                                                                                                                                                                                                                                                                     
      * It returns the connections number of each vertex vector format.
      */
    void setRandomLogicFunctions();

    void setLogicFunctions(std::vector<std::vector<int>> a);

    void saveLogicFunctions(std::vector<std::vector<int> > a);

    void setInitialState(std::vector<int> a);
    /**
      * Recieves a vector of initial states and sets it.
      */

    std::vector<std::vector<util::Node> > getTransitions();
    /**
      * It returns the vector history of states.
      */
    std::vector<std::vector<int> > getConnections();
    /**
      * It returns the vector of conections as adjacency matrix.
      */
    std::vector<std::vector<int> > getLogicFunctions();
    /**
      * It returns the vector of logic functions.
      */

    std::vector<std::vector<int> > getSavedLogicFunctions();

    void nextStep(); 
    /**
      * It returns nothing. But updates de history of states
      * and the nodes states.
      * It uses the conections and the logic functions.
      */
    double hDistance(RBN b);
    /**
      * It recieves an RBN and calculates the Hamming
      * Distance, dividing by the total steps.
      */
    int getSize();
    /**
      * Returns the vertex number.
      */
    int getNodeState(int i);
    /**
      * Returns the vertex node state.
      */
    util::Node getNode(int i);
    /**
      * Returns the vertex node.
      */
    void outConnect();
    /**
      * Prints connections.
      */
    void outStates();
    /**
      * Prints states.
      */
    void outLogic();
    /**
      * Prints logic.
      */
};

class homRBN: public RBN{
 private:
    int k;

 public:
    homRBN(int v_n, int r, int c);
    /**
      * Homogeneous class of RBN.
      * It recieves:
      * (vertex number, random seed, number of connections)
      * Creates:
      * A Random Boolean Network that has a specifc
      * number of connections in each vertex node.
      */
};

class hetRBN: public RBN{
 public:
    hetRBN(int v_n, int r);
    /**
      * Heterogeneous class of RBN.
      * It recieves:
      * (vertex number, random seed)
      * Creates:
      * A Random Boolean Network that has a random
      * number of connections in each vertex node.
      */
};

class blankRBN: public RBN{
 public:
    blankRBN(int v_n);
    /**
      * Blank RBN
      * Recieves the Number of Nodes
      * Connections Matrix all 1
      */
};

class classicRBN: public RBN{
 private:
    int k;

 public:
    classicRBN(int v_n, int r, std::vector<int> &c);
    /**
      * Classic class of RBN.
      * It recieves:
      * (vertex number, random seed, connections vector)
      * Creates:
      * A Random Boolean Network that has a specifc
      * number of connections in each vertex node defined
      * by the vector.
      */
};
class probRBN: public RBN{
 private:
    float probability;

 public:
    probRBN(int v_n, int r);
     /**
      * Heterogeneous class of RBN.
      * It recieves:
      * (vertex number, random seed)
      * Creates:
      * A Random Boolean Network that has a random
      * number of connections according to the random
      * probability in each vertex node.
      */
    probRBN(int v_n, int r, float p);
    /**
      * Heterogeneous class of RBN.
      * It recieves:
      * (vertex number, random seed, probability)
      * Creates:
      * A Random Boolean Network that has a random
      * number of connections according to the
      * probability in each vertex node.
      */
};
}  // namespace network
}  // namespace rbn

#endif
