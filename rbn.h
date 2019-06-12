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
            this->id = ++cont;
            this->state = rand()%2; //inicializa o nó com um valor aleatório
        };
        /*Defines new state*/
        Node(int v){
            this->state = v;
            this->id = ++cont;
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
int Node::cont = 0;

class RBN{
    protected:
        int vertex_num;
        int **conex_Graph; //Grafo de conexão
        float **prob_Graph; //Grafo de probabilidade da conexão
        Node *vertex_node; //Nó que guarda estado
        vector<vector<int>> f_Logica; //matriz de funções lógicas que pode ser substituida por vetor
        vector<vector<Node>> h_States; //Matriz historico de estados

//definir matriz de probabilidade de conexão (sortear uma probabilidade de 0 a 1 e se estiver dentro de p conecta (1)) ou (homogenea define um k) / heterogenea (um k pra cada nodo) pelo usuario
//quantidade de conexões pré definidas
//sortear os nodos que serão conectados

    public:        
        /*Recieves node number and random seed (v_n,r)*/
        RBN(int v_n,int r){
            srand(r);
            this->vertex_num = v_n;
            this->conex_Graph = new int *[vertex_num];
            this->prob_Graph = new float *[vertex_num];
            this->vertex_node = new Node[vertex_num];
            for (int i = 0; i < vertex_num; i++){
                this->prob_Graph[i] = new float[vertex_num];
                this->h_States.push_back(vector<Node>()); //suposta inicialização do historico de estados
                this->vertex_node[i] = Node();
                this->h_States[0].push_back(vertex_node[i]); //it registers first line at hisotirc
                this->f_Logica.push_back(vector<int>());
                this->conex_Graph[i] = new int[vertex_num];
                for (int j = 0; j<vertex_num; j++){
                    this->prob_Graph[i][j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    this->conex_Graph[i][j] = rand()%2;
                    if (conex_Graph[i][j]==1){
                        this->f_Logica[i].push_back(rand()%7); //Number of logic functions
                    }
                }                
            }
        }

        void f_rand(){
            vector<int> aux;
            int aux2;
            for (int i = 0; i < this->vertex_num;i++){
                for (int j = 0; j < this->vertex_num; j++){
                    if (this->conex_Graph[i][j] == 1){
                        aux.push_back(getNodeState(j));
                    }
                }
                while (aux.size()>1){
                    aux2 = this->f_Logica[i].front();
                    this->f_Logica[i].push_back(aux2);
                    this->f_Logica[i].erase(f_Logica[i].begin());
                    aux.push_back(logic_map[aux2](aux[0],aux[1]));
                    aux.erase(aux.begin());
                    aux.erase(aux.begin());
                }
                this->vertex_node[i].setState(aux[0]);
                h_States[i+1].push_back(vertex_node[i]);
                aux.clear();
            }
        }
        /*Ham Distance*/
        double h_distance(RBN b){
            double sum = 0;
            float h_dist;
            for(int i = 0;i < this->vertex_num ;i++){
                for(int j = 0; j<this->vertex_num; j++){
                    if (this->h_States[i][j].getState() != b.h_States[i][j].getState()){
                        sum+=1;                   
                    }
                }
            }
            h_dist = (sum/steps);
            return h_dist;
        }
        
        float lExpoent(){

        }

        int getSize(){
            return vertex_num;
        }
        /*Returns state*/
        int getNodeState(int i){
            return this->vertex_node[i].getState();
        }

        Node getNode(int i){
            return this->vertex_node[i];
        }
        /*Print Probability*/
        void outProb(){
            for (int i = 0; i < vertex_num; i++)
            {
                cout << "\n";
                for (int j = 0; j < vertex_num; j++)
                {
                    cout << this->prob_Graph[i][j] << " ";
                }
            }
        cout << "\n";
        }
        /*Print Connections*/
        void outConect(){
            for (int i = 0; i < vertex_num; i++)
            {
                cout << "\n";
                for (int j = 0; j < vertex_num; j++)
                {
                    cout << this->conex_Graph[i][j] << " ";
                }
            }
        cout << "\n";
        }
        /*Print States*/
        void outStates(){
            cout<<"Estados: ";
            for (int i = 0; i < this->vertex_num; i++)
            {
                    cout << getNodeState(i) << " ";
            }
            cout << "\n";
        }

        /*Prints connections logic*/
        void outLogic(){
            for(vector<int> row: this->f_Logica){
                for(int cel: row){
                    cout<< cel << " ";
                }
                cout<<"\n";
            }
        }

};

class hetRBN: public RBN{
    
    hetRBN(int v_n, int r):RBN(v_n,r){

    }
}
