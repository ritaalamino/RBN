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
    //cin >> v_s2;
    classicRBN m(v_n,v_s);
    classicRBN n(v_n,v_s2);
    m.createRBN();
    m.outStates();
    return 0;
}