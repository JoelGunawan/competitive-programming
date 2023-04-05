#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 1];

    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    // memset seperti fill tp hanya bs 0/-1
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // cuma perlu tau bfs buat cek visited/lain"
    // queue<int> bfs;
    // queue bentuk pair 
    // first -> node
    // second -> jarak dari tempat awal bfs
    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    while(!bfs.empty()) {
        int nd = bfs.front().first, dist = bfs.front().second;
        bfs.pop();
        // ini sudah visited belum?
        if(vis[nd])
            continue;
        vis[nd] = 1;
        cout << "NODE " << nd << " " << dist << endl;
        for(auto i : edges[nd]) {
            if(!vis[i]) 
                bfs.push({i, dist + 1});
        }
    }
}