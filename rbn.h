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

class Node{
    private:
        int state; /*State RBN*/
        int static cont;
        int id;

    public:
        Node(){
            id = ++cont;
            state = rand()%2;
        };
        
        Node(int v){
            state = v;
            id = ++cont;
        }
        //Returns actual node state
        int getState(){
            return state; 
        }
        //Writes node state to rewrite matrix
        int setState(int value){
            state = value;
        }

        int getID(){
            return id;
        }

        int getCount(){
            return cont;
        }
};
int Node::cont = 0;

class RBN{
    protected:
        int vertex_num;
        vector<vector<int>> conex_Graph;
        vector<Node> vertex_node;
        vector<vector<int>> f_Logica;
        vector<vector<Node>> h_States;

    public:        
        /*Recieves node number and random seed (v_n,r)*/
        RBN(int v_n,int r){
            srand(r);
            vertex_num = v_n;
            for(int i = 0; i < vertex_num; i++){
                conex_Graph.push_back(vector<int>());
                vertex_node.push_back(Node());
                for(int j = 0; j < vertex_num; j++){
                    conex_Graph[i].push_back(-1);
                }
            }   
        }

        void fRand(){
            vector<int> aux;
            int aux2;
            for (int i = 0; i < vertex_num;i++){
                for (int j = 0; j < vertex_num; j++){
                    if (conex_Graph[i][j] == 1){
                        aux.push_back(getNodeState(j));
                    }
                }
                while (aux.size()>1){
                    aux2 = f_Logica[i].front();
                    f_Logica[i].push_back(aux2);
                    f_Logica[i].erase(f_Logica[i].begin());
                    aux.push_back(logic_map[aux2](aux[0],aux[1]));
                    aux.erase(aux.begin());
                    aux.erase(aux.begin());
                }
                vertex_node[i].setState(aux[0]);
                h_States[i+1].push_back(vertex_node[i]);
                aux.clear();
            }
        }
        /*Ham Distance FIX*/
        double h_distance(RBN b){
            double sum = 0;
            float h_dist = 0;
            for(int j = 0; j<vertex_num; j++){
                if (vertex_node[j].getState() != b.vertex_node[j].getState()){
                    sum+=1;                   
                }
            }
            h_dist = (sum/vertex_num);
            return h_dist;
        }
        
        float lExpoent(){

        }

        int getSize(){
            return vertex_num;
        }
        /*Returns state*/
        int getNodeState(int i){
            return vertex_node[i].getState();
        }

        Node getNode(int i){
            return vertex_node[i];
        }
        /*Print Connections*/
        void outConnect(){
            for (int i = 0; i < vertex_num; i++)
            {
                cout << "\n";
                for (int j = 0; j < vertex_num; j++)
                {
                    cout << conex_Graph[i][j] << " ";
                }
            }
        cout << "\n";
        }
        /*Print States*/
        void outStates(){
            cout<<"Estados: ";
            for (int i = 0; i < vertex_num; i++)
            {
                    cout << getNodeState(i) << " ";
            }
            cout << "\n";
        }

        /*Prints connections logic*/
        void outLogic(){
            for(vector<int> row: f_Logica){
                for(int cel: row){
                    cout<< cel << " ";
                }
                cout<<"\n";
            }
        }

};

class homRBN: public RBN{
    private:
        int k;

    public:
    homRBN(int v_n, int r,int c): RBN(v_n, r){
        for (int i = 0; i < vertex_num; i++){
            k = c;
            h_States.push_back(vector<Node>());
            h_States[0].push_back(vertex_node[i]);
            f_Logica.push_back(vector<int>());
            for (int j = 0; j<vertex_num; j++){
                if (k!=0){
                    if(conex_Graph[i][j]!=1){
                        conex_Graph[i][j] = rand()%2;
                    }
                    if (j == vertex_num-1){
                        int l = 0;
                        while(k!=0){
                            if(conex_Graph[i][l]!=1){
                               conex_Graph[i][l] = rand()%2;
                               if(conex_Graph[i][l] == 1) k--; 
                            }
                            l++;
                        }
                    }
                }
                else{
                    conex_Graph[i][j] = 0;
                }
                if (conex_Graph[i][j]==1){
                    k = k - 1;
                    f_Logica[i].push_back(rand()%7); //Number of logic function
                }
            }                
        }
    }
};

class hetRBN: public RBN{
    
    public:
    hetRBN(int v_n, int r):RBN(v_n,r){    
        for (int i = 0; i < vertex_num; i++){
            h_States.push_back(vector<Node>());
            h_States[0].push_back(vertex_node[i]);
            f_Logica.push_back(vector<int>());
            for (int j = 0; j<vertex_num; j++){
                conex_Graph[i][j] = rand()%2;
                if (conex_Graph[i][j]==1){
                    f_Logica[i].push_back(rand()%7);
                }
            }                
        }
    }
};

//TEST
class classicRBN: public RBN{
    
    public:
        classicRBN(int v_n, int r, vector<int> c): RBN(v_n,r){
        for (int i = 0; i < vertex_num; i++){
            h_States.push_back(vector<Node>());
            h_States[0].push_back(vertex_node[i]);
            f_Logica.push_back(vector<int>());
            conex_Graph[i] = c;
            for (int j = 0; j<vertex_num; j++){
                if (conex_Graph[i][j]==1){
                    f_Logica[i].push_back(rand()%7);
                }
            }                
        }
    }  
};

class probRBN: public RBN{
    private:
    float probability;

    public:
    probRBN(int v_n,int r): RBN(v_n, r){
        probability = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        for (int i = 0; i < vertex_num; i++){
            h_States.push_back(vector<Node>());
            h_States[0].push_back(vertex_node[i]);
            f_Logica.push_back(vector<int>());
            for (int j = 0; j<vertex_num; j++){ 
                if((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) <= probability){
                    conex_Graph[i][j] = 1;
                    if (conex_Graph[i][j]==1){
                        f_Logica[i].push_back(rand()%7);
                    }
                }
                else{
                    conex_Graph[i][j] = 0;
                }
            }                
        }
    }
    probRBN(int v_n,int r,float p): RBN(v_n, r){
        probability = p;
        for (int i = 0; i < vertex_num; i++){
            h_States.push_back(vector<Node>());
            h_States[0].push_back(vertex_node[i]);
            f_Logica.push_back(vector<int>());
            cout<<p<<endl;
            for (int j = 0; j<vertex_num; j++){ 
                if((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) <= probability){
                    conex_Graph[i][j] = 1;
                    if (conex_Graph[i][j]==1){
                        f_Logica[i].push_back(rand()%7);
                    }
                }
                else{
                    conex_Graph[i][j] = 0;
                }
            }                
        }
    }
};
