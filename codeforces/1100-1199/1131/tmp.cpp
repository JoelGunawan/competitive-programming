#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
vector<pair<int, int>> edges[lim];
int main() {
    // input
    // first bisa long long
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    priority_queue<pair<int, int>> pq;
    int ans[lim];
    while(pq.size()) {
        int dist = -pq.top().first, nd = pq.top().second;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans[nd] = dist;
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                pq.push(make_pair(-(dist + i.second), i.first));
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}