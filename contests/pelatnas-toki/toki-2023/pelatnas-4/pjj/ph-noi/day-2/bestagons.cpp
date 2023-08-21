#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> edges[n + 1];
    bool adj[n + 1][n + 1];
    memset(adj, 0, sizeof(adj));
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        adj[u][v] = adj[v][u] = 1;
    }
    int cnt = 0;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    for(int a = 1; a <= n; ++a) {
        vis[a] = 1;
        for(int b = 1; b <= n; ++b) {
            if(vis[b] || !adj[a][b])
                continue;
            vis[b] = 1;
            for(int c = 1; c <= n; ++c) {
                if(vis[c] || !adj[b][c])
                    continue;
                vis[c] = 1;
                for(int d = 1; d <= n; ++d) {
                    if(vis[d] || !adj[c][d])
                        continue;
                    vis[d] = 1;
                    for(int e = 1; e <= n; ++e) {
                        if(vis[e] || !adj[d][e])
                            continue;
                        vis[e] = 1;
                        for(int f = 1; f <= n; ++f) {
                            if(!vis[f] && adj[e][f] && adj[f][a]) {
                                ++cnt;
                                //cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
                            }
                        }
                        vis[e] = 0;
                    }
                    vis[d] = 0;
                }
                vis[c] = 0;
            }
            vis[b] = 0;
        }
        vis[a] = 0;
    }
    cout << cnt << endl;
}