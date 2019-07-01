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


int main(){
    int v_n,v_s,v_s2;
    //cout << "\n***********\nNumber of Vertex: ";   
    //cin >> v_n;
    v_n = 10;
    //cout << "\n***********\nRandom Seed 1: ";   
    //cin >> v_s;
    v_s = 1;
    //cout << "\n***********\nRandom Seed 2: ";   
    v_s2 = 2;
    vector<int> vector1;
    for(int i=0; i<v_n; i++){
        vector1.push_back(1);
    }
    //cin >> v_s2;
    classicRBN m(v_n,v_s,vector1);
    classicRBN n(v_n,v_s2,vector1);
    cout << "m ";
    m.outStates();
    cout << "n ";
    n.outStates();
    cout << "Ham. Dist. " << m.h_distance(n) <<endl;
    cout << "*-----------------------------\n";
    for(int i =0; i < steps; i++){
        m.fRand();
        n.fRand();
        cout << "m ";
        m.outStates();
        cout << "n ";
        n.outStates();
        cout << "Ham. Dist. " << m.h_distance(n) <<endl;
        cout << "------------------------------\n";
    } 
    //m.outConnect();
    //cout<<m.getNode(1).getCount();    
    
}