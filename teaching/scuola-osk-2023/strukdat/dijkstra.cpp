#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    // dijkstra node 1
    // first -> dist, second -> node
    // top() -> elemen paling besar
    // dijkstra -> elemen paling kecil?
    // simpan dist jadi negatif
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    int memo[n + 1];
    while(pq.size()) {
        int dist = -pq.top().first, node = pq.top().second;
        pq.pop();
        if(vis[node])
            continue;
        vis[node] = 1;
        memo[node] = dist;
        for(auto i : edges[node]) {
            if(!vis[i.first]) {
                pq.push({-(dist + i.second), i.first});
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << memo[i] << " ";
    cout << endl;
}