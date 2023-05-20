//Prim Algorithms, MST
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxN = 1e5;
 
struct Edge { 
    int v; 
    ll w; 
};
 
struct Node {
    int id; ll dist;
    friend bool operator<(const Node &a, const Node &b){
        return a.dist > b.dist;
    }
};
 
int n, m, a, b;
ll dist[maxN+1], c;
vector<Edge> G[maxN+1];
priority_queue<Node> Q;
 
int main(){
    cin >> n >> m; ll res = 0; 
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    Q.push({1, 0});
    while(!Q.empty()){
        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
        res += d;
        for(Edge e : G[u]){
          if(!vis[e.v])
                Q.push({e.v, e.w});
        }
    }
    ll count = 0;
    for(ll i = 1; i <= n; i++){
        if(vis[i] == true) count++;
    }
    if(count != n) cout << "IMPOSSIBLE\n";
    else{
        cout << res << endl;
    }
}