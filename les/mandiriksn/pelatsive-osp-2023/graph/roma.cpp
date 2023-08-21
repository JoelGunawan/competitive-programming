#include <bits/stdc++.h>
using namespace std;
const int lim = 505;
vector<int> edges[lim];
vector<int> tol[lim];
int main() {
    int n, l, t, start, end;
    cin >> n >> l >> t >> start >> end;
    for(int i = 0; i < l; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 0; i < t; ++i) {
        int u, v;
        cin >> u >> v;
        tol[u].push_back(v);
        tol[v].push_back(u);
    }
    // dijkstra 2 state (visited 2 state)
    // state 1 -> node
    // state 2 -> udh pake jalan tol atau belum?
    // state 2 = 0 -> belum ada ruas tol yg dipakai
    // state 2 = 1 -> ada ruas tol yg sudah dipakai
    // fi -> dist
    // se.fi -> node
    // se.se -> state jalan tol
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dijkstra;
    bool vis[n + 1][2];
    memset(vis, 0, sizeof(vis));
    dijkstra.push(make_pair(0, make_pair(start, 0)));
    int ans = 1e9;
    while(dijkstra.size()) {
        int dist = dijkstra.top().first, nd = dijkstra.top().second.first, state_tol = dijkstra.top().second.second;
        dijkstra.pop();
        if(vis[nd][state_tol])
            continue;
        // transisi dijkstra ada 2 macam
        // state_tol = 0 -> blh jalan tol, boleh jalan biasa
        // pakai jalan biasa -> ttp state 0
        // state_tol = 1 -> blh jalan biasa saja
        vis[nd][state_tol] = 1;
        if(nd == end) 
            ans = min(ans, dist);
        if(state_tol == 0) {
            for(auto i : edges[nd]) {
                if(!vis[i][0])
                    dijkstra.push(make_pair(dist + 1, make_pair(i, 0)));
            }
            for(auto i : tol[nd]) {
                if(!vis[i][1])
                    dijkstra.push(make_pair(dist + 1, make_pair(i, 1)));
            }
        }
        else {
            for(auto i : edges[nd]) {
                if(!vis[i][1]) {
                    dijkstra.push(make_pair(dist + 1, make_pair(i, 1)));
                }
            }
        }
    }
    cout << ans << endl;
}