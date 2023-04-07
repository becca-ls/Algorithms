// codigo para verificar se exite um caminho entre dois pontos de um grafo, usando bfs

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void printar(vector<bool> v){
    for( int i=0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void printar2(vector<vector<int>> v){
    for( int i=0; i < v.size(); i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>> edges, int source, int destination) {
        vector<vector<int>> grafo(n);
        for(int i=0; i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        //printar2(grafo);
        vector<bool> vis(n,false);
        queue<int> q;
        vis[source] = true;
        q.push(source);
        
        while(!q.empty()){
            int atual = q.front();
            if(atual==destination){
                return true;
            }
            q.pop();
            for(int i=0; i<grafo[atual].size(); i++){
                if(vis[grafo[atual][i]]==false){
                    q.push(grafo[atual][i]);
                    vis[grafo[atual][i]] = true;
                }
            }
        }
    return false;
    }
};

int main(){
    int n=3; 
    vector<vector<int>> v = {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
    vector<vector<int>> v2 = {{0,1},{1,2},{2,0}};
    vector<vector<int>> v3 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source=0;
    int destination=2;
    Solution s;
    bool resp = s.validPath(n,v2, source, destination);
    cout<< "resposta: "<<resp<<endl;
    return 0;
}
