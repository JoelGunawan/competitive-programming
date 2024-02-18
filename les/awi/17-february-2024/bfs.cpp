#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim]; // awalnya semua false
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // first -> node
    // second -> jarak
    queue<pair<int, int>> q;
    // awal (mulai dari node 1, jaraknya 0)
    q.push({1, 0});
    // queue
    // {1, 0}
    // {2, 1} {4, 1} {5, 1} {9, 1}
    while(q.size()) {
        // nd = 1, dist = 0
        // nd = 2, dist = 1
        int nd = q.front().fi, dist = q.front().se;
        // {1, 0} -> empty
        // {2, 1} {4, 1} {5, 1} {9, 1} -> {4, 1} {5, 1} {9, 1}
        q.pop();
        if(vis[nd]) {
            continue;
        }
        cout << "NODE " << nd << " " << dist << endl;
        // vis[1] = 1
        // vis[2] = 1
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                // {2, 1}
                // {2, 1} {4, 1}
                // {2, 1} {4, 1} {5, 1}
                // {2, 1} {4, 1} {5, 1} {9, 1}
                q.push({i, dist + 1});
            }
        }
    }

}