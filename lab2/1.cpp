#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct nod{
    int grad;
    int eticheta;
};

struct muchie{
    int et1, et2;
};

int compare (const void * a, const void * b)
{
    nod *nod1 = (nod*) a;
    nod *nod2 = (nod*) b;
  return ( nod2 -> grad - nod1 -> grad);
}

int main()
{
    
    ifstream f("date.in");
    ofstream g("date.out");
    int n, suma, maxim = 0;
    vector <muchie> E;
    muchie m;
    f >> n;
    
    struct nod d[n];
    
    for (int i = 0; i < n; i++) {
        f >> d[i].grad;
        suma += d[i].grad;
        maxim = max(maxim, d[i].grad);
    }
    
    qsort(d, n + 1, sizeof(nod), compare);
    
    if((suma % 2) == 1 || maxim > n - 1){
        cout << "Nu se poate construi graful";
        return 0;
    }
    else{
        for(int k = 0; k < n ; k++){
            if(d[k].grad == 0)
                break;
            else if(d[k + d[k].grad].grad == 0){
                cout << "nu se poate construi graful";
                return 0;
            }
            if(d[k].grad == 1){
                while(d[k].grad == 1){
                    d[k].grad = 0;
                    d[k + 1].grad = 0;
                    m.et1 = d[k].eticheta;
                    m.et2 = d[k + 1].eticheta;
                    E.push_back(m);
                    k += 2;
                }
                break;
            }
            else{
                for (int j = 0; j < d[k]; j++) {
                    /* code */
                }
            }
        }
    }
    
}