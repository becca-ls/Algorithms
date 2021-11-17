#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tab(8), resp;
int rainhas = 0;

void salvar(){
    vector<int>v(8);
    for(int j=0;j<8;j++){
        for(int i=0;i<8;i++){
            if(tab[i][j]) v[j]=i;
        }
    }
    resp.push_back(v);
}

bool posso(int r, int c){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(tab[i][j]==1){
                if(i==r || j==c || ((r+c)==(i+j)) || ((r-c)==(i-j))){
                    return false;
                }
            }
        }
    }
    return true;
}

void printar(){
    cout << "SOLN       COLUMN" <<endl;
    cout << " #      1 2 3 4 5 6 7 8\n";
    cout<<endl;
    sort(resp.begin(),resp.end());
    for(int i=0;i<resp.size();i++){
        if(i<9) cout << " ";
        cout<<i+1<<"      ";
        for(int j=0;j<7;j++) cout << resp[i][j]+1 << " ";
        cout << resp[i][7]+1 << endl;
    }
}

void dfs(int r){
    if(r==8){
        if(rainhas<8) r=0;
    }//temos um r valido
    for(int i=0;i<8;i++){////vamos procurar na linha r
        if(tab[r][i]==0){//posição livre
            if(posso(r,i)){
                tab[r][i]=1;
                rainhas++;
                if(rainhas==8) salvar();
                else dfs(r+1);
                rainhas--;
            } 
            tab[r][i]=0;
        }   
    }
    return;
}

int main(){
    int n; cin>>n;
    string s;
    getline(cin,s);
    while(n){
        tab.clear();
        rainhas = 1;
        resp.resize(0);
        for(int i=0; i<8;i++){
            vector<int> v(8);
            tab[i]=v;
        }
        int r0,c0;
        cin >> r0 >> c0;
        r0--;
        c0--;
        tab[r0][c0]=1;
        dfs(r0+1);
        printar();
        n--;
        if(n) cout<<endl;
    }
    return 0;
}
