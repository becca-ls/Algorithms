#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;

    for(int i=0;i<t;i++){
        int n; cin>>n;
        
        int a = log2(n);
        a = pow(2,a)-1;
        cout<<a<<endl;
        
    }
    

    return 0;
}

//log2 e operação AND bit a bit
