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

    ll n; cin>>n;
    while(n){
        ll tam; cin>>tam;
        vll vec(tam);
        for(int i=0;i<tam;i++){
            cin >> vec[i];
        }
        //printar(vec);

        ll soma=1, moedas=1;
        if(tam==2) moedas=2;

        else{
            for(int i=1;i<tam-1;i++){
                if(soma+vec[i]<vec[i+1]){
                    moedas++;
                    soma+=vec[i];
                    //cout<<soma<<" soma"<<endl;
                }
            }
            soma+=vec[vec.size()-1];
            moedas++;
        }
        cout<<moedas<<endl;
        n--;
    }
    
    return 0;
}
