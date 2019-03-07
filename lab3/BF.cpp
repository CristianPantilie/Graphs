#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;


int main(){

    ifstream f("date.in");
    ofstream g("date.out");
    int n, m, s, x, y;

    f >>n >>m;
    queue <int> c;
    //int prin = c.front();
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
    c.push(s);
    vizitat[s] = 1;
    g << s << " ";
    int cate = la[s].size();

   while(c.size() > 0){
        s = c.front();
        int cate = la[s].size();

        for (int i = 0; i < cate; i++) {
            if(vizitat[la[s][i]] == 0){
                vizitat[la[s][i]] = 1;
                g << la[s][i] << " ";
                c.push(la[s][i]);
            }
        }
        c.pop();
    }


    f.close();
    g.close();
    return 0;
}
