#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int n, m, max = 0;

    f >> n;
    f >> m;
    int a[n + 1][n + 1];
    int grade[n + 1];
    
    vector <int> nod_max;

    for(int i = 0; i <= n; i++){
        grade[i] = 0;
    }

    for(int lin = 1; lin <= n; lin++){
        for(int col = 1; col <= n; col++){
            a[lin][col] = 0;
        }
    }

    int x,y;
    for(int i = 1; i <= m; i++){
        f >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
        grade[x]++;
        grade[y]++;
        if(grade[x] == max){
            max = grade[x];
            cout << grade[x];
        }
        
        if(grade[y] == max){
            max = grade[y];
        }
    }

    for(int lin = 1; lin <= n; lin++){
        for(int col = 1; col <= n; col++){
            g << a[lin][col] << " ";
        }
        g << endl;
    }

    for(int i = 1; i <= n; i++){
        if(grade[i] == max){
            nod_max.push_back(i);
        }
    }
    
    int cate = nod_max.size();
    
    cout << max;
    
    for (int i = 0; i < cate; i++) {
        //cout << nod_max[i];
        
    }

    return 0;
}