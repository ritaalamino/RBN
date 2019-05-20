class Graph{
    private:
        int vertex_num = 4;
    
    public:
        int **conex_Graph; //Grafo de conexão
        vector<vector<int>> f_Logica; //matriz de funções lógicas que pode ser substituida por vetor.
        Node *vertex_node; //Nó que guarda estado
        vector<vector<Node>> h_States; //Matriz historico de estados
        Graph(int v_n,int r){ //entra com o numero de nós
            srand(r);
            this->vertex_num = v_n;
            conex_Graph = new int *[vertex_num];
            vertex_node = new Node[vertex_num];
            for (int i = 0; i < vertex_num; i++){
                h_States.push_back(vector<Node>()); //suposta inicialização do historico de estados
                vertex_node[i] = Node();
                h_States[0].push_back(vertex_node[i].r_state());
                //cout << h_States[0][i].r_state() << "teste" << endl;
                f_Logica.push_back(vector<int>());
                //f_Logica[i] = new int[vertex_num];
                conex_Graph[i] = new int[vertex_num];
                for (int j = 0; j<vertex_num; j++){
                    //f_Logica[i][j] = rand()%3;
                    conex_Graph[i][j] = rand()%2;
                    if (conex_Graph[i][j]==1){
                        f_Logica[i].push_back(rand()%4);
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
                h_States[1].push_back(vertex_node[i].r_state());
                //cout << h_States[1][i].r_state() << "teste" << endl;
                aux.clear();
            }
        }

        double h_distance(vector<int> a, vector<int> b){
            double sum = 0;
            float h_dist;
            for(int i = 0;i < this->vertex_num ;i++){
               if (this->h_States[0][i].r_state() != this->h_States[1][i].r_state()){
                   sum+=1;
                   
               }
            }
            //cout << sum << "sum ";
            h_dist = (sum/this->vertex_num);
            //cout << " -- -- " << h_dist;
            this->h_States[0] = this->h_States[1];
            this->h_States[1].clear();
            return h_dist;
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
