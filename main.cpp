/*Library Random Boolean Network*/
#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>
#include <ctime>
#define steps 10 /*Steps Tests*/

/*Dictionary for Conextions*/ 
map<int, function<int(int, int)>> logic_map{
/*AND*/ {0, [](int a, int b) { return a & b; }},
/*OR*/  {1, [](int a, int b) { return a | b; }},
/*XOR*/ {2, [](int a, int b) { return a ^ b;}},
/*NOT*/ {3, [](int a, int b) { return !a}},
///*NOT*/ {2, [](int a, int b) { return !b}},
/*XNOR*/{4, [](int a, int b) { return !(a ^ b);}},
/*NAND*/{5, [](int a, int b) { return !(a & b);}},
/*NOR*/ {6, [](int a, int b) { return !(a | b);}}
    };

/*Node class that keeps state
Could be used for a tree
*/
class Node{
    private:
        int state; /*State RBN*/
    public:
        //Node *left;
        //Node *right;

        /*Intialize with random value 0 or 1*/
        Node(){ 
           //left = right = NULL;
           this->state = rand()%2; //inicializa o nó com um valor aleatório
        };
        /*Defines new state*/
        Node(int v){
            //left = right = NULL;
            this->state = v;
        }
        //Returns actual node state
        int r_state(){
            return this->state; 
        }
        //Writes node state to rewrite matrix
        int w_state(int value){
            this->state = value;
        }
};
/*Class adjacency Matrix
conex_Graph it's a connection matrix
vector it's the logic vector matrix for connections
h_States it's a historic matrix
*/
class RBN{
    private:
        int vertex_num;
        int **conex_Graph; //Grafo de conexão
        float **prob_Graph; //Grafo de probabilidade da conexão
        Node *vertex_node; //Nó que guarda estado
        vector<vector<int>> f_Logica; //matriz de funções lógicas que pode ser substituida por vetor
        vector<vector<Node>> h_States; //Matriz historico de estados

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
                        aux.push_back(get_node(j));
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
                this->vertex_node[i].w_state(aux[0]);
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
                    if (this->h_States[i][j].r_state() != b.h_States[i][j].r_state()){
                        sum+=1;                   
                    }
                }
            }
            h_dist = (sum/steps);
            return h_dist;
        }

        int get_size(){
            return vertex_num;
        }
        /*Returns state*/
        int get_node(int i){
            return this->vertex_node[i].r_state();
        }
        /*Print Probability*/
        void prob(){
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
        void conexions(){
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
        void states(){
            cout<<"Estados: ";
            for (int i = 0; i < this->vertex_num; i++)
            {
                    cout << get_node(i) << " ";
            }
            cout << "\n";
        }

        /*Prints connections logic*/
        void logica(){
            for(vector<int> row: this->f_Logica){
                for(int cel: row){
                    cout<< cel << " ";
                }
                cout<<"\n";
            }
        }

};

int main(){
    int v_n,v_s,v_s2;
    cout << "\n***********\nNumber of Vertex: ";   
    //cin >> v_n;
    v_n = 10;
    cout << "\n***********\nRandom Seed 1: ";   
    //cin >> v_s;
    v_s = 1;
    cout << "\n***********\nRandom Seed 2: ";   
    v_s2 = 2;
    //cin >> v_s2;
    RBN m(v_n,v_s);
    RBN n(v_n,v_s2);
    cout << "m ";
    m.states();
    cout << "n ";
    n.states();
    cout << "*-----------------------------\n";
    for(int i =0; i < steps; i++){
        m.f_rand();
        n.f_rand();
        cout << "m ";
        m.states();
        cout << "n ";
        n.states();
        cout << "------------------------------\n";
    }      
    cout << "Ham. Dist. " << m.h_distance(n) <<endl;
}