#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct muchie{
    int nod1;
    int nod2;
    int cost;
};

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
    
    muchie muchii[m + 1];
    int culori[n + 1];
    for (int i = 1; i <= n; i++) {
        culori[i] = i; //initial fiecare nod are propria culoare (este in propriul arbore)
    }
    
    for(int i = 1; i <= m; i++){
        f >> muchii[i].nod1 >> muchii[i].nod2 >> muchii[i].cost;
    }
    
    qsort(muchii + 1, m, sizeof(muchie), cmp);
    
    int muchii_alese = 0;
    for (int i = 1; i <= m; i++) {
        
        if(culori[muchii[i].nod1] != culori[muchii[i].nod2]){
            g << muchii[i].nod1 << " " << muchii[i].nod2 << " " << muchii[i].cost << '\n';  
        }
        
        cul_inlocuita = culori[muchii[i].nod2];
        
        for(int j = 1; j <= n; j++){  //ca sa coloreze la fel doi arbori care au fost uniti 
            if(culori[j] == cul_inlocuita){
                culori[j] = culori[muchii[i].nod1];
            }
            muchii_alese++;
            if(muchii_alese == n - 1)
                break;
        }
    }
        
    f.close();
    g.close();
    return 0;
}