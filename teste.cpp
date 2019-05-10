#include <iostream>
#include <cstdlib>
using namespace std;
#include <map>
#include <bits/stdc++.h>
//#include <QVector>


map<int, function<int(int, int)>> logic_map{
        {0, [](int a, int b) { return a && b; }},
        {1, [](int a, int b) { return a || b; }},
        {2, [](int a, int b) { return !a; }}
    };

int main(){
    cout<<logic_map[1](0,0);
    cout << rand()%2;
}