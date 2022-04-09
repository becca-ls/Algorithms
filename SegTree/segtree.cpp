#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define endl "\n"

struct Node{
    ll v;
    Node(){v=0;}
    Node(ll _v): v(_v){}
    Node operator+ (const Node &o){ 
        Node result;
        result.v = v+o.v;
        return result;
    }
    ll getValue(){ return v;}
};


struct Segtree {
    vector<Node> tree;
    ll sz;

    Segtree(vector<Node> &vec){
        sz = vec.size()-1;
        this->tree.resize(4*sz);
        build(vec,1,1,sz);
    }

    void build(vector<Node> &vec, ll n, ll l, ll r){
        if(l==r){
            tree[n] = vec[l];
            return;
        }
        ll m = (l+r)/2;
        build(vec,2*n,l,m);
        build(vec,2*n+1,m+1,r);
        tree[n] = tree[2*n]+tree[2*n+1];
    }

    void update(ll p, ll val){
        Node node(val);
        update(1,1,sz,p,node);
    }

    void update(ll n, ll l,ll r, ll p, Node &node){
        if(l==r){
            tree[n] = tree[n]+node;
            return;
        }
        ll m = (l+r)/2;
        if(p<=m) update(2*n,l,m,p,node);
        else update(2*n+1,m+1,r,p,node);
        tree[n] = tree[2*n]+tree[2*n+1];
    }

    Node query(ll l, ll r){
        return query(1,1,sz,l,r);
    }

    Node query(ll n, ll l, ll r, ll a, ll b){
        if(a<=l && r<=b) return tree[n]; 
        if(r<a || b<l){
            return Node();
        }
        ll m = (l+r)/2;
        Node left = query(2*n,l,m,a,b);
        Node right = query(2*n+1,m+1,r,a,b);
        return left+right;
    }
};

int main(){
    ll N,Q; cin>>N>>Q;
    vector<Node> v(N);
    Segtree segtree (v);
    while(Q){
        string s; cin>>s;
        if(s=="add"){
            ll p, f; cin>>p>>f;
            segtree.update(p,f);
        }else{
            ll a,b; cin>>a>>b;
            Node ans = segtree.query(a,b);
            cout<< ans.getValue()<<endl;
        }
        Q--;
    }


    return 0;
}
