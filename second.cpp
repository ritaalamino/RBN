#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>
#include <ctime>


map<int, function<int(int, int)>> logic_map{
        {0, [](int a, int b) { return a && b; }},
        {1, [](int a, int b) { return a || b; }},
        {2, [](int a, int b) { return !a; }}
    };

class Node{
    private:
        int state = 0;
    public:
        Node *left;
        Node *right;

        Node(){
           left = right = NULL;
           this->state = rand()%2; //inicializa o nó com um valor aleatório
        };
        Node(int v){
            left = right = NULL;
            this->state = v;
        }
        int r_state(){
            return this->state; //retorna o estado atual
        }
        int w_state(int value){ //só escreve o status na hora de reescrever a matriz
            this->state = value;
        }
};

class Graph{
    private:
        int vertex_num = 4;
    
    public:
        int **conex_Graph; //Grafo de conexão
        vector<vector<int>> f_Logica; //matriz de funções lógicas que pode ser substituida por vetor.
        Node *vertex_node; //Nó que guarda estado

        Graph(int v_n){ //entra com o numero de nós
            srand(1);
            this->vertex_num = v_n;
            conex_Graph = new int *[vertex_num];
            vertex_node = new Node[vertex_num];
            for (int i = 0; i < vertex_num; i++){
                vertex_node[i] = Node();
                //cout<< "estado adicionado: " <<v_node(i);
                f_Logica.push_back(vector<int>());
                //f_Logica[i] = new int[vertex_num];
                conex_Graph[i] = new int[vertex_num];
                for (int j = 0; j<vertex_num; j++){
                    //f_Logica[i][j] = rand()%3;
                    conex_Graph[i][j] = rand()%2;
                    if (conex_Graph[i][j]==1){
                        f_Logica[i].push_back(rand()%3);
                    }
                }
            }
        }

        void f_rand(){
            vector<int> aux;
            int aux2;
            for (int i = 0; i < this->vertex_num;i++){
                for (int j = 0; j < this->vertex_num; j++){
                    //cout << "vetor de estados";
                    if (this->conex_Graph[i][j] == 1){
                        aux.push_back(v_node(j));
                        //cout<< aux[j];
                        
                    }
                    //cout << "\n";
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
                aux.clear();
            }
        }

        int v_size(){
            return vertex_num;
        }

        int v_node(int i){
            return this->vertex_node[i].r_state();
        }

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
        void states(){
        cout<<"Estados: ";
        for (int i = 0; i < vertex_num; i++)
        {
                cout << v_node(i) << " ";

        }
        cout << "\n";
        }

        void logica(){
            for(vector<int> row: this->f_Logica){
                for(int cel: row){
                    cout<< cel << " ";
                }
                cout<<"\n";
            }
        }

};
/*
class Ltree{
    private:
        Node* root = new Node;
    public:
        Ltree(Graph m){
            Node* temp = new Node;
            for(int i = 0; i < m.v_size(); i++){
                for(int j = 0; j < m.v_size(); j++){
                    if(m.conex_Graph[i][j] == 1){
                        if (root->left == NULL){
                            root->left->w_state(m.v_node(j));
                        }
                        else if(root->right == NULL){
                            root->right->w_state(m.v_node(j));
                        }
                        else{
                            root->w_state(rand()%3);
                            temp = root;
                            root = new Node;
                            root->left = temp;
                            root->right = new Node(m.v_node(j));
                        }
                    }
                }
            }
        }
};
*/
int main(){
    Graph m(20);
    m.states();
    for(int i =0; i < 100;i++){
        m.f_rand();
        m.states();
    }      
}