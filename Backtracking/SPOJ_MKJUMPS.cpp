//Problema dos cavalos no tabuleiro de xadrez modificado
//DFS - busca em profundidade

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, p, pa;
vector<vector<int>> tab; 

bool posso_ir(int r, int c){
    if(r<n && r>-1 && c>-1 && c<10){
        if(tab[r][c]==0) return true;
        return false;
    }
    return false;
}

void dfs(int r, int c){
    pa++;
    tab[r][c]=1;
    if(posso_ir(r-2,c-1)) dfs(r-2,c-1);
    if(posso_ir(r-2,c+1)) dfs(r-2,c+1);
    if(posso_ir(r+2,c-1)) dfs(r+2,c-1);
    if(posso_ir(r+2,c+1)) dfs(r+2,c+1);
    if(posso_ir(r-1,c-2)) dfs(r-1,c-2);
    if(posso_ir(r-1,c+2)) dfs(r-1,c+2);
    if(posso_ir(r+1,c-2)) dfs(r+1,c-2);
    if(posso_ir(r+1,c+2)) dfs(r+1,c+2);
    p = max(p,pa);
    pa--;
    tab[r][c]=0;
}

int main(){
    int caso=0;
    cin >> n;
    while(n){
        tab.reserve(0);
        tab.reserve(n);
        caso++;
        int tt=0;
        for(int i=0;i<n;i++){
            vector<int> v(10);
            int a,b;
            cin >> a >> b;
            tt+=b;
            for(int j=0;j<a;j++) v[j]=1;
            for(int j=9;j>=(a+b);j--) v[j]=1;
            tab[i]=v;
        }
        int id=0;
        while(tab[0][id]==1) id++;
        p=0;
        pa=0;
        dfs(0,id);
        int resp = tt - p;
        cout << "Case " << caso << ", " << resp << " square";
        if(resp!=1) cout << "s";
        cout << " can not be reached." << endl;
        cin >> n;
    }
    return 0;
}
