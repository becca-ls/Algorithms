#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<vector<int>> tab;

void printar(){
    for(int i=0;i<n*n;i++){
        cout << tab[i][0];
        for(int j=1;j<n*n;j++) cout << " " << tab[i][j];
        cout<< endl;
    }
}

bool checar(int num, int row, int col){
    for(int i=0;i<n*n;i++){
        if(tab[row][i]==num) return 0;
    }
    for(int i=0;i<n*n;i++){
        if(tab[i][col]==num) return 0;
    }
    int r0 = row-(row%n);
    int c0 = col-(col%n);
    for(int i=r0; i<(r0+n);i++){
        for(int j=c0; j<(c0+n);j++){
            if(tab[i][j]==num) return 0;
        }
    }
    return 1;
}

bool solver(int row, int col){
    if((row==(n*n)-1) && (col==(n*n))) return 1; 
    if(col==(n*n)){
        row++;
        col = 0;
    }
    if(tab[row][col]>0){
        col++;
        return solver(row,col);
    }
    for(int tente=1;tente<=(n*n);tente++){
        if(checar(tente,row,col)){
            tab[row][col]=tente;
            if(solver(row,col+1)) return 1;
            tab[row][col]=0;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio (0); cin.tie (0);
    cin>>n;
    while(1){
        tab.resize(0);
        tab.reserve(n*n);
        for(int i=0;i<n*n;i++){
            tab[i].resize(0);
            for(int j=0;j<n*n;j++){
                int a; cin>>a;
                tab[i].push_back(a);
            }
        }
        if(solver(0,0)) printar();
        else cout<<"NO SOLUTION"<< endl;
        string s;
        getline(cin,s);
        if(!(cin>>n)) break;
        cout<<endl;
    }
    return 0;
}
