#include <bits/stdc++.h>
using namespace std;
const int lim = 1005;
vector<int> edges[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    cout << nd << endl;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    queue<int> bfs;
    bfs.push(1);
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(bfs.size()) {
        int nd = bfs.front();
        bfs.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        cout << nd << endl;
        for(auto i : edges[nd]) {
            if(!vis[i])
                bfs.push(i);
        }
    }
}