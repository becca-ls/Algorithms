#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k;cin>>k;
    while(k){

        ll n; cin>>n;
        vll A(n),B(n),C(n),D(n);
        for(int i=0;i<n;i++){
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        }
        vll ab, cd;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ab.push_back(A[i]+B[j]);
                cd.push_back(C[i]+D[j]);
            }
        }
        ll ans = 0;
        sort(cd.begin(),cd.end());
        for(int i=0;i<ab.size();i++){
            auto l = lower_bound(cd.begin(),cd.end(),-ab[i]);
            auto r = upper_bound(cd.begin(),cd.end(),-ab[i]);
            ans += (r-l);
        }
        cout<<ans<<endl;
        k--;
        if(k) cout<<endl;
    }


    return 0;
}
