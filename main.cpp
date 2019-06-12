/*Library Random Boolean Network*/
#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>
#include <ctime>
#define steps 10 /*Steps Tests*/
#include </home/ritaalamino/RBN/rbn.h>

/*Node class that keeps state
Could be used for a tree
*/



/*Class adjacency Matrix
conex_Graph it's a connection matrix
vector it's the logic vector matrix for connections
h_States it's a historic matrix
*/
//Usar QVector

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
    m.outStates();
    cout << "n ";
    n.outStates();
    cout << "*-----------------------------\n";
    /*for(int i =0; i < steps; i++){
        m.f_rand();
        n.f_rand();
        cout << "m ";
        m.outStates();
        cout << "n ";
        n.outStates();
        cout << "------------------------------\n";
    } */
    m.getNode(1).getCount();    
    cout << "Ham. Dist. " << m.h_distance(n) <<endl;
}