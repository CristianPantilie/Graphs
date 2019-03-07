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

    int n, m, s, x, y;

    f >> n >> m;
    stack <int> S;

    int vizitat[n + 1];
    for (int i = 1; i <= n; i++) {
        vizitat[i] = 0;
    }

    vector <int> la[n + 1];
    for (int i = 1; i <= m; i++) {
        f >> x >> y;

        la[x].push_back(y);
        la[y].push_back(x);
    }
    
    f >> s; //sursa
    S.push(s);
    vizitat[s] = 1;
    g << s << " ";
    
    while(S.size() > 0){
        s = S.top();
        int cate = la[s].size();
        int gasit = 0;
        for (int i = 0; i < cate; i++) {
            if(vizitat[la[s][i]] == 0){  //ii cauta vecin nevizitat
                vizitat[la[s][i]] = 1;
                g << la[s][i] << " ";
                S.push(la[s][i]);
                gasit = 1;
                break;   //daca a gasit vecin nevizitat se opreste si cauta mai departe in stiva
            }
        }
        if(gasit == 0){  //daca nu a gasit vecin nevizitat scoate elementul din stiva
                S.pop();
            }
    }

    f.close();
    g.close();

    return 0;
}
