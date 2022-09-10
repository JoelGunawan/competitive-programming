#include <bits/stdc++.h>
using namespace std;
vector<int> edges[3005];
int main() {
    map<vector<int>, bool> forbidden;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> d = {a, b, c};
        forbidden[d] = 1;
    }
    int dist[n + 1][n + 1];
    bool vis[n + 1][n + 1];
    pair<int, int> pr[n + 1][n + 1];
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    queue<pair<int, pair<pair<int, int>, pair<int, int>>>> bfs;
    bfs.push({0, {{1, 0}, {0, 0}}});
    while(bfs.size()) {
        int node = bfs.front().second.first.first, prev_node = bfs.front().second.first.second, d = bfs.front().first;
        pair<int, int> previous = bfs.front().second.second;
        bfs.pop();
        if(vis[prev_node][node])
            continue;
        vis[prev_node][node] = 1;
        dist[prev_node][node] = d;
        pr[prev_node][node] = previous;
        for(auto i : edges[node]) {
            if(!vis[node][i]) {
                vector<int> tmp = {prev_node, node, i};
                if(!forbidden[tmp])
                    bfs.push({d + 1, {{i, node}, {prev_node, node}}});
            }
        }
    }
    int min_val = 1e9, min_idx = -1;
    for(int i = 1; i <= n; ++i) {
        if(dist[i][n] != -1 && dist[i][n] < min_val)
            min_val = dist[i][n], min_idx = i;
    }
    if(min_idx == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> res = {n};
    pair<int, int> cur = {min_idx, n};
    while(cur.first != 0) {
        cur = pr[cur.first][cur.second];
        res.push_back(cur.second);
    }
    reverse(res.begin(), res.end());
    cout << res.size() - 1 << endl;
    for(auto i : res)
        cout << i << " ";
    cout << endl;
}