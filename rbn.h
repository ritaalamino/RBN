#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>
#include <ctime>

/*Dictionary for Conextions*/ 
map<int, function<int(int, int)>> logic_map{
/*AND*/ {0, [](int a, int b) { return a & b; }},
/*OR*/  {1, [](int a, int b) { return a | b; }},
/*XOR*/ {2, [](int a, int b) { return a ^ b;}},
/*NOT*/ {3, [](int a, int b) { return !a;}},
///*NOT*/ {2, [](int a, int b) { return !b}},
/*XNOR*/{4, [](int a, int b) { return !(a ^ b);}},
/*NAND*/{5, [](int a, int b) { return !(a & b);}},
/*NOR*/ {6, [](int a, int b) { return !(a | b);}}
};

//Criar vetor com edereços de nodos conectados
//Criar ID do nodo

class Node{
    private:
        int state; /*State RBN*/
        int static cont;
        int id;

    public:
        Node(){ 
            this->cont = this->cont + 1;
            this->id = cont;
            this->state = rand()%2; //inicializa o nó com um valor aleatório
        };
        /*Defines new state*/
        Node(int v){
            this->state = v;
            this->cont = this->cont + 1;
            this->id = cont;
        }
        //Returns actual node state
        int getState(){
            return this->state; 
        }
        //Writes node state to rewrite matrix
        int setState(int value){
            this->state = value;
        }

        int getID(){
            return this->id;
        }

        int getCount(){
            return this->cont;
        }
};