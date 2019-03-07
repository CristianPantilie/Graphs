#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

typedef struct muchie{
    int nod1;
    int nod2;
    int cost;
}muchie;

int cmp(const void *a, const void *b){
    muchie *muchieA = (muchie *) a;
    muchie *muchieB = (muchie *) b;
    return (muchieA->cost - muchieB->cost);
}   

int main(){   
    ifstream f("date.in");
    ofstream g("date.out");
    int n, m, cul_inlocuita;
   
    f >> n >> m;
    
    int culori[n + 1];
    for (int i = 1; i <= n; i++) {
       culori[i] = 0;
    }
    
    muchie muchii[m + 1];
    
    for(int i = 1; i <= m; i++){
        f >> muchii[i].nod1 >> muchii[i].nod2 >> muchii[i].cost;
    }
    
    qsort(muchii + 1, m, sizeof(muchie), cmp);
    
    int muchii_alese = 1;
    g << muchii[1].nod1 << " " << muchii[1].nod2 << " " << muchii[1].cost << '\n';
    culori[muchii[1].nod1] = 1;
    culori[muchii[1].nod2] = 1;
    
    while(muchii_alese < n -1){
        for (int i = 2; i <= m; i++) {
            if(culori[muchii[i].nod1] != culori[muchii[i].nod2]){
                g << muchii[i].nod1 << " " << muchii[i].nod2 << " " << muchii[i].cost << '\n';
                muchii_alese++;
                culori[muchii[i].nod1] = culori[muchii[i].nod2] = 1;
                break;
            }
        }
    }
    
    f.close();
    g.close();
    return 0;
}