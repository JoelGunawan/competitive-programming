#include <bits/stdc++.h>
#define endl "\n" 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(2 * (n + 1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[a].emplace_back(b + n, c / 2);
        adj[a + n].emplace_back(b + n, c);
    }

    vector<int> dist(2 * (n + 1), -1);
    vector<bool> vis(2 * (n + 1), 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, 1});
    while(pq.size()) {
        auto [d, nd] = pq.top();
        // cerr << a << " " << b << " " << c << endl;
        pq.pop();
        if(vis[nd]) {
            continue;
        }
        vis[nd] = 1;
        dist[nd] = d;
        for (auto [dst, cost] : adj[nd]) {
            if(!vis[dst]) {
                pq.push({d + cost, dst});
            }
        }
    }
    cout << min(dist[n], dist[2 * n]) << '\n';
}