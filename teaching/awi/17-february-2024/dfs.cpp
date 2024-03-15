#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim]; // awalnya semua false
void dfs(int nd) {
    vis[nd] = 1;
    cout << nd << endl;
    for(int i = 0; i < edges[nd].size(); ++i) {
        if(!vis[edges[nd][i]]) {
            dfs(edges[nd][i]);
        }
    }
    /*
    for(int i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    */
}
int main() {
    // n node dan m edge
    // n m
    // u1 v1 edge ke-1
    // u2 v2 edge ke-2
    // ... 
    // um vm edge ke-m
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
}