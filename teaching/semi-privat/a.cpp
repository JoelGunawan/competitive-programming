#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim];
vector<int> edges[lim];
void dfs(int nd) {
    vis[nd] = 1;
    cout << nd << endl;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
    }
}
int main() {
    // n node m edge
    // n m
    // u_1 v_1
    // u_2 v_2
    // ...
    // u_m v_m
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> bfs;
    bfs.push({0, 1});
    while(bfs.size()) {
        int nd = bfs.front().second, dist = bfs.front().first;
        bfs.pop();
        if(vis[nd])
            continue;
        cout << "DISTANCE " << nd << " " << dist << endl;
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            if(!vis[i])
                bfs.push({dist + 1, i});
        }
    }
}