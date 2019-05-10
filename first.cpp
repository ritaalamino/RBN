#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>

map<int, function<bool(bool, bool)>> logic_map{
    {0, [](bool a, bool b) { return a && b; }},
    {1, [](bool a, bool b) { return a || b; }},
    {2, [](bool a, bool b) { return !a; }}};

class Node
{
  private:
    int state = 0;

  public:
    Node *left;
    Node *right;
    
    Node()
    {
        left = right = NULL;
        this->state = rand() % 2;;
    };

    int r_state(){
        return this->state;
    }

    int w_state(int value){
        this->state = value;
    }
};

class Matrix
{
  private:
    int vertex_num;
    

  public:
    int **adjMatrix;
    int **F_logica;
    Node *vertex_node;
    Matrix(int vertex_num)
    {
        srand(5);
        this->vertex_num = vertex_num;
        adjMatrix = new int *[vertex_num];
        vector<vector<int>> F_logica;
        vertex_node = new Node[vertex_num];
        /*QVector<QVector<int>> testMatrix;*/
        for (int i = 0; i < vertex_num; i++)
        {
            vertex_node[i] = Node();
            vector<int> linha;
            adjMatrix[i] = new int[vertex_num]; //Cria matriz de funções lógicas
            for (int j = 0; j < vertex_num; j++)
            {
                linha.push_back(rand() % 3);
                adjMatrix[i][j] = rand() % 2;
                /*if (adjMatrix[i][j] == 1)
                {
                    this->vertex_node[i].r_state();
                }
            }*/
            F_logica.push_back(linha);
        }
    }
    int v_size()
    {
        return vertex_num;
    }
    void output()
    {
        for (int i = 0; i < vertex_num; i++)
        {
            cout << "\n";
            for (int j = 0; j < vertex_num; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
        }
        cout << "\n";
    }

};


class Stack{
    private:
        vector <int> aux_res;
    public:
        Stack(){

        }
        void initialize(Matrix *m){
            for (int i = 0; i < m->v_size(); i++)
            {
                for (int j = 0; j < m->v_size(); j++)
                {
                    if (m->adjMatrix[i][j] == 1)
                    {
                        this->aux_res.push_back(m->vertex_node[i]->r_state());
                    }
                }
            
                int j = 0;
                while (sizeof(this->aux_res) > 1){
                    //define a função aleatória
                    cout << m->vertex_node[0].r_state();
                    cout << m->vertex_node[1].r_state();
                    this->aux_res->push_back(logic_map[m->F_logica[i][j]](this->aux_res[0],this->aux_res[1]));
                    //m->F_logica[i][j].push_back(m->F_logica[i][j].push_back)
                    this->aux_res.erase(this->aux_res.begin());   
                    this->aux_res.erase(this->aux_res.begin());   
                    j += 1;         
                }
            
                m->vertex_node[i].w_state(this->aux_res[0]);
                this->aux_res.erase(this->aux_res.begin());
        }
    };
};
class BinaryTree{
    private:
        Node *root, aux;
    public:
        BinaryTree(){
            root = NULL;
        }
        Node *add(vector<int> v){
            while(sizeof(v) >= 1){
                aux = root;
                if(sizeof(v)>=1){
                    if (root == NULL){
                        root = new Node();
                        root.w_state(logic_map[rand() % 3](v[0],v[1]));
                    }
                    if(root->left == NULL){
                        root.left = new Node();
                        root.left.w_state(v[0]);
                        v.erase(v.begin());
                    }
                    if(root->right == NULL){
                        root.left = new Node();
                        root.right.w_state(v[0]);
                        v.erase(v.begin());
                    }
                    else{
                        root = aux;
                        root.left = 
                    }
                }
            }   
            
            
        }
}
/*
class BinaryTree
{
  private:
    Node *root;

  public:
    BinaryTree()
    {
        root = NULL;
    };
    
        ~BinaryTree(){
            destroy_tree();
        };
        void destroy_tree(Node *leaf){
            if leaf != NULL:{
                destroy_tree(leaf->right);
                destroy_tree(leaf->left);
                delete leaf;
            }
        };
    Node *add(Matrix *matriz)
    {
        root = insert(matriz);
    };
    
    Node *new_state(Matrix *m)
    {
        
        Percorrer lista de conexões
        adicionar a cada duas conexões left e right
        fechar raiz com operação lógica
        enquanto não percorre tudo
        se achar mais conexões
        adicionar outra raiz
        definir raiz anterior como esquerda
        definir nova entrada como direita
        
        //root = new Node();
        vector <int> v;
        for (int i = 0; i < m->v_size(); i++)
        {
            for (int j = 0; j < m->v_size(); j++)
            {
                if (m->adjMatrix[i][j] == 1)
                {
                    v.push_back(m->vertex_node[i].r_state());
                }
            }
            int j = 0;
            while (sizeof(v) > 1){
                //define a função aleatória
                cout << m->vertex_node[0].r_state();
                cout << m->vertex_node[1].r_state();
                v.push_back(logic_map[m->F_logica[i][j]](v[0],v[1]));
                //m->F_logica[i][j].push_back(m->F_logica[i][j].push_back)
                v.erase(v.begin());   
                v.erase(v.begin());   
                j += 1;         
            }
            m->vertex_node[i].w_state(v[0]);
            v.erase(v.begin());
        }
        
        
            /*
            if (node==NULL){
                return new Node(value, NULL, NULL);
            } else if (root->left == NULL)
            {
                node.left = insert(value, node.left);
            }
            else
            {
                node.right = insert(value, node.right);
            }
                
            return node;
            
    };
    
        bool verify(Node *node){
            verify(node->left);
            verify(node->right);
        };
};

int logicf(){
    n = rand()%3;
    if (n == 0):
        return 'not';;
    else if (n == 1):
        return 'and';
    else if (n==2):
        return 'or';
}

map<int,..>func = {
    {1 = !},
    {2 = &&},
    {3 = ||}
};*/

int main()
{
    Matrix m(3);
    m.output();
    //cout << logic_map[1](true, true);
    Stack l(m);
    m.output();

}
