#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <string>
using namespace std;



int main(){

    ifstream f("date.in");
    ofstream g("date.out");
    
    int noduri,arce,x,y;
    
    f >> noduri >> arce;
    
    vector<int> la[noduri + 1];
    vector<int> exterior[noduri + 1];
    int d[noduri + 1];
    
    for (int i = 1; i <= noduri; i++) {
        d[i] = 0;
    }
    
    for (int i = 1; i <= arce; i++) {
        f >> x >> y;
        la[x].push_back(y);
        la[y].push_back(x);
        d[x]++;
    }
    
    queue<int> C;
    
    for (int i = 1; i <= noduri; i++) {
        if(d[i] == 0)
            C.push(i);
    }
    
    while(C.size() > 0){
        int i = C.front();
        cout << i << " ";
        for(int j = la[i].front(); j <= la[i].size(); j++){
            d[j]--;
            cout << j;
            if(d[j] == 0){
                C.push(j);
            }
        }
        cout << endl;
        g << i;
        C.pop();
    }
    
    f.close();
    g.close();
    return 0;
}
    
    