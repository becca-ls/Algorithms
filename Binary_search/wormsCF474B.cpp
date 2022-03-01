#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vll;

void printar(vll v){
    cout<<"veja: ";
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    vll v(n,0);
    ll s=0;
    for(int i=0;i<n;i++){
        int novo; cin>>novo;
        v[i] = s+novo;
        s+=novo;
    }
    //printar(v);
    
    ll m; cin>>m;
    for(int i=0;i<m;i++){
        ll x; cin>>x;
        //cout<<"x "<<x<<endl;
        /// agora vamo procurar x
        ll l=0;
        ll r=n-1;
        while(l<=r){
            //cout<<"l r "<<l<<" "<<r<<endl;
            ll id_atual = (r+l)/2;
            //cout<<"id "<<id_atual<<" v[id] "<<v[id_atual]<<endl;
            if(v[id_atual]==x){
                cout<<id_atual+1;
                //cout<<"ue\n";
                break;
            }else if(v[id_atual]<x){
                //cout<<"dir\n";
                //procurar p direita
                l=id_atual+1;
            }else{
                //pode ta nesse msm id ou pra esquerda
                if(id_atual-1<0){
                    cout<<id_atual+1;
                    //cout<<"ueeee\n";
                    break;
                }else if(v[id_atual-1]>x){
                    //cout<<"v[id-1] "<<v[id_atual-1]<<endl;
                    //procurar p tras
                    r=id_atual-1;
                }else{
                    if(v[id_atual-1]<x){
                        cout<<id_atual+1;
                        break;
                    }else if(v[id_atual-1]==x){
                        cout<<id_atual;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
