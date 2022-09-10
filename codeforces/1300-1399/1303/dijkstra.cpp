#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
// first -> node
// second -> weight
vector<pair<int, int>> edges[lim];
int main() {
    // pertama buat jarak
    // kedua node
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    priority_queue<pair<int, pair<int, int>>> dijkstra;
    dijkstra.push({0, {1, 0}});
    bool vis[lim];
    int dist[lim], pr[lim];
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    memset(pr, -1, sizeof(pr));
    while(dijkstra.size()) {
        int d = -dijkstra.top().first, node = dijkstra.top().second.first, prev_node = dijkstra.top().second.second;
        dijkstra.pop();
        if(vis[node])
            continue;
        vis[node] = 1;
        dist[node] = d;
        pr[node] = prev_node;
        for(auto i : edges[node]) {
            if(!vis[i.first]) {
                dijkstra.push({-(d + i.second), {i.first, node}});
            }
        }
    }
    if(dist[n] == -1)
        cout << dist[n] << endl;
    else {
        vector<int> res = {n};
        int x = n;
        while(x != 1) {
            x = pr[x];
            res.push_back(x);
        }
        reverse(res.begin(), res.end());
        for(auto i : res)
            cout << i << " ";
        cout << endl;
    }
}