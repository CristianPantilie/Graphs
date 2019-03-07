#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <string>
using namespace std;

/*
    graf orientat, neponderat, fara circuite
    afisare noduri dupa sortare topologica
*/

int main(){

    ifstream f("date.in");
    ofstream g("date.out");
    
    int noduri,arce;
    
    f >> noduri >> arce;
    
    vector <int> interior[noduri + 1];
    vector <int> exterior[noduri + 1];
    int d[noduri + 1];
    
    for (int i = 1; i <= noduri; i++) {
        d[i] = 0;
    }
    
    for (int i = 1; i <= arce; i++) {
        f >> x >> y;
        interior[x].push_back(y);
        exterior[y].push_back(x);
        d[x]++;
    }
    
    queue <int> C;
    
    for (int i = 1; i <= noduri; i++) {
        if(d[i] == 0)
            C.push(i);
    }
    while(C.size() > 0){
        int i = C.front();
        for (int j = exterior[i].front(); j <= exterior[i].size(); j++) {
            d[j]--;
            if(d[j] == 0){
                C.push(j);
            }
        }
        
        g << i;
        C.pop(i);
    }

    f.close();
    g.close();
    return 0;
}