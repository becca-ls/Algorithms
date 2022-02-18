#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vll;

void printar(vll v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    x:
    ll n; cin>>n;
    while(n!=0){

        vll b(n,0);
        cin>>b[0];
        //cout<<b[0]<<endl;
        if(b[0]==0){
            cout<<endl;
            goto x;
            break;
        }
        for(int i=1;i<n;i++){
            cin>>b[i];
        }
        //printar(b);
        
        bool ok=1;
        ll fila=1;
        stack<int> pilha;
        ll id=0;
        while((fila<=n || !pilha.empty()) && ok){
            if(fila<=n){
                //ainda tem gente na fila
                if(fila==b[id]){
                    fila++;
                    id++;
                }else{
                    //olhar a pilha
                    if(pilha.empty()){
                        pilha.push(fila);
                        fila++;
                    }else{
                        if(pilha.top()==b[id]){
                            pilha.pop();
                            id++;
                        }else{
                            pilha.push(fila);
                            fila++;
                        }
                    }
                }
            }else{
                //fila vazia e pilha não vazia
                while(!pilha.empty()){
                    if(pilha.top()==b[id]){
                        id++;
                        pilha.pop();
                    }else{
                        ok=0;
                        break;
                    }
                }
            }
            
        }
        if(ok){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        
    }

    return 0;
}
//questao F do homework 1 da seletiva da maratona 2022
