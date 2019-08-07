// Copyright 2019 COPT

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "bits/stdc++.h"
#include "network/rbn.h"
#include "network/util/logicmap.hpp"
#include "network/util/node.h"

namespace rbn {
namespace network {
RBN::RBN(int v_n, int r) {
    srand(r);
    vertex_num = v_n;
    for (int i = 0; i < vertex_num; i++) {
        connections_graph.push_back(std::vector<int>());
        vertex_node.push_back(util::Node());
        for (int j = 0; j < vertex_num; j++) {
            connections_graph[i].push_back(-1);
        }
    }
}

void RBN::addHistory(){
    h_States.push_back(vertex_node);
}

void RBN::setSteps(int p) {
    steps = p;
}
int RBN::getSteps() {
    return steps;
}

void RBN::setNumberConnections(){
    for ( int i = 0 ; i < vertex_num ; i++ ){
        number_connections.push_back(0);
        for ( int j = 0 ; j < vertex_num ; j++){
            if( RBN::connections_graph[i][j] == 1 ){
                number_connections[i]++;
            }
        }
    }
}

void RBN::setConnections(std::vector<std::vector<int> > a){
    connections_graph = a;
}

std::vector<int> RBN::getNumberConnections(){
    return number_connections;
}

void RBN::setInitialState(std::vector<int> a){
    for ( int i = 0 ; i < vertex_num ; i ++ ) {
        vertex_node[i].setState(a[i]);
    }
    RBN::addHistory();
}

std::vector<std::vector<util::Node> > RBN::getTransitions() {
    return RBN::h_States;
}

std::vector<std::vector<int> > RBN::getConnections() {
    return RBN::connections_graph;
}

std::vector<std::vector<int> > RBN::getLogicFunctions() {
    return RBN::f_Logica;
}

std::vector<std::vector<int> > RBN::getSavedLogicFunctions() {
    return RBN::saved_logic_functions;
}

void RBN::nextStep() {
    std::vector<int> aux;
    int aux2;
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            if (connections_graph[i][j] == 1) {
                aux.push_back(h_States[h_States.size()-1][j].getState());
            }
        }
        while (aux.size() > 1) {
            aux2 = f_Logica[i].front();
            f_Logica[i].push_back(aux2);
            f_Logica[i].erase(f_Logica[i].begin());
            aux.push_back(util::logic_map[aux2](aux[0], aux[1]));
            aux.erase(aux.begin());
            aux.erase(aux.begin());
        }
        if (aux.size() != 0){
            vertex_node[i].setState(aux.front());
        }
        aux.clear();
    }
    RBN::addHistory();
}

/*Ham Distance FIX*/
double RBN::hDistance(RBN b) {
    double sum = 0;
    float h_dist;
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            if (h_States[i][j].getState() != b.h_States[i][j].getState()) {
                sum+=1;
            }
        }
    }
    h_dist = (sum/steps);
    return h_dist;
}
/* 
float RBN::lExpoent() {
}*/

int RBN::getSize() {
    return vertex_num;
}
        /*Returns state*/
int RBN::getNodeState(int i) {
    return vertex_node[i].getState();
}

util::Node RBN::getNode(int i) {
    return vertex_node[i];
}

/*Print Connections*/

void RBN::outConnect() {
    for (int i = 0; i < vertex_num; i++) {
        std::cout << "\n";
        for (int j = 0; j < vertex_num; j++) {
            std::cout << connections_graph[i][j] << " ";
        }
    }
    std::cout << "\n";
}

/*Print States*/

void RBN::outStates() {
    std::cout << "Estados: ";
    for (int i = 0; i < vertex_num; i++) {
            std::cout << getNodeState(i) << " ";
    }
    std::cout << "\n";
}

        /*Prints connections logic*/
void RBN::outLogic() {
    for (std::vector<int> row : f_Logica) {
        for (int cel : row) {
            std::cout<< cel << " ";
        }
        std::cout << "\n";
    }
}

void RBN::setRandomLogicFunctions(){
    RBN::setNumberConnections();
    for (int i = 0; i < vertex_num; i++){
        f_Logica.push_back(std::vector<int>());
        for (int j = 0; j < number_connections[i]-1; j++)
        {
            f_Logica[i].push_back(rand()%7);
        }
        
    }
}

void RBN::setLogicFunctions(std::vector<std::vector<int> > a){
    RBN::setNumberConnections();
    RBN::saveLogicFunctions(a);
    for (int i = 0; i < vertex_num; i++){
        f_Logica.push_back(std::vector<int>());
        for (int j = 0; j < number_connections[i]-1; j++)
        {
            f_Logica[i].push_back(a[i][j]);
        }
        
    }
}

void RBN::saveLogicFunctions(std::vector<std::vector<int> > a){
    saved_logic_functions = a;
}

homRBN::homRBN(int v_n, int r, int c): RBN(v_n, r) {
    for (int i = 0; i < vertex_num; i++) {
        k = c;
        for (int j = 0; j < vertex_num; j++) {
            if (k != 0) {
                if (connections_graph[i][j] != 1) {
                    connections_graph[i][j] = rand()%2;
                }
                if (j == vertex_num-1) {
                    int l = 0;
                    while (k != 0) {
                        if (connections_graph[i][l] != 1) {
                            connections_graph[i][l] = rand()%2;
                            if (connections_graph[i][l] == 1) k--;
                        }
                        l++;
                        if (l == vertex_num) l = 0;
                    }
                }
            }
            else {
                connections_graph[i][j] = 0;
            }
            if (connections_graph[i][j] == 1) {
                k = k - 1;
                  // Number of logic function
            }
        }
    }
}

hetRBN::hetRBN(int v_n, int r):RBN(v_n, r) {
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            connections_graph[i][j] = rand()%2;
        }
    }
}

blankRBN::blankRBN(int v_n):RBN(v_n, 1) {
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            connections_graph[i][j] = 1;
        }
    }
}

classicRBN::classicRBN(int v_n, int r, std::vector<int> &c): RBN(v_n, r) {
    for (int i = 0; i < vertex_num; i++) {
        k = c[i];  
        for (int j = 0; j < vertex_num; j++) {
            if (k != 0) {
                if (connections_graph[i][j] != 1) {
                    connections_graph[i][j] = rand()%2;
                }
                if (j == vertex_num-1) {
                    int l = 0;
                    while (k != 0) {
                        if (connections_graph[i][l] != 1) {
                            connections_graph[i][l] = rand()%2;
                            if (connections_graph[i][l] == 1) { k--;}
                        }
                        l++;
                        if (l == vertex_num) l = 0;
                    }
                }
            }
            else connections_graph[i][j] = 0;
            if (connections_graph[i][j] == 1) k = k - 1;
        }
    }
}


probRBN::probRBN(int v_n, int r): RBN(v_n, r) {
    probability = static_cast <float> (rand())/
        static_cast <float> (RAND_MAX);
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            if ((static_cast <float> (rand())/
              static_cast <float> (RAND_MAX)) <= probability) {
                connections_graph[i][j] = 1;
            }
            else {
                connections_graph[i][j] = 0;
            }
        }
    }
}
probRBN::probRBN(int v_n, int r, float p): RBN(v_n, r) {
    probability = p;
    for (int i = 0; i < vertex_num; i++) {
        
        for (int j = 0; j < vertex_num; j++) {
            if ((static_cast <float> (rand())/
              static_cast <float> (RAND_MAX)) <= probability) {
                connections_graph[i][j] = 1;
            }
            else {
                connections_graph[i][j] = 0;
            }
        }
    }
}
}  // namespace network
}  // namespace rbn
