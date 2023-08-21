#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    int arr[q + 1];
    for(int i = 1; i <= q; ++i)
        cin >> arr[i];
    int res = 0;
    for(int i = 2; i <= q; ++i) {
        // dijkstra dr arr[i - 1]
        // trus cari dist ke i
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, arr[i - 1]));
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        while(pq.size()) {
            int dist = pq.top().first, nd = pq.top().second;
            pq.pop();
            if(vis[nd])
                continue;
            vis[nd] = 1;
            if(nd == arr[i]) {
                res += dist;
                break;
            }
            for(auto i : edges[nd]) {
                if(!vis[i.first]) {
                    pq.push(make_pair(dist + i.second, i.first));
                }
            }
        }
    }
    cout << res << endl;
}