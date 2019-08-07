// Copyright 2019 COPT

#include "network/rbn.h"
#include "io/rbnexport.h"
#include <iostream>

int main() {
 int v_n, v_s;
 // cout << "\n***********\nNumber of Vertex: ";
 v_n = 3;
 // cout << "\n***********\nRandom Seed 1: "
 v_s = 1;
 rbn::network::hetRBN m(v_n, 2);
 std::vector<int> a{1,1,1};
 m.setInitialState(a); 
 //m.setConnections() - recebe matriz de conexões
 m.setRandomLogicFunctions();
 m.outStates();
  m.outConnect();
 m.outLogic();
 m.nextStep();
 m.outStates(); 


}
