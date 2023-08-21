#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 5e4 + 5;
bool special[lim];
vector<int> edges[lim];
bool vis[lim];
int dfs(int nd) {
    vis[nd] = 1;
    int ret = special[nd];
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}
void tc() {
    int n, e, q, r;
    cin >> n >> e >> q >> r;
    for(int i = 1; i <= n; ++i) {
        special[i] = 0;
        edges[i].clear();
    }
    vector<pair<int, int>> adj;
    adj.push_back(make_pair(0, 0));
    for(int i = 1; i <= e; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        adj.push_back(make_pair(u, v));
    }    
    for(int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        special[x] = 1;
    }
    // gmn cara cari pair yg hilang?
    // pair yg hilang = jumlah pair awal - jumlah pair akhir
    // cari jumlah pair -> buat tiap connected component, mis 1, 7, 5, 3
    // 1 -> 7, 7 -> 1, 1 -> 5, 5 -> 1, 1 -> 3, 3 -> 1, ...
    // 1, 7 | 1, 5 | 1, 3 | 3, 5 | 3, 7 | 5, 7
    // 4 * 3 / 2 -> n * (n - 1) / 2 dimana n banyak special node yg terhubung
    long long awal = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            int tmp = dfs(i);
            awal += 1ll * tmp * (tmp - 1) / 2;            
        }
    }
    for(int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    bool skip[e + 1];
    memset(skip, 0, sizeof(skip));
    for(int i = 1; i <= r; ++i) {
        int x;
        cin >> x;
        skip[x] = 1;
    }
    for(int i = 1; i <= e; ++i) {
        if(!skip[i]) {
            edges[adj[i].first].push_back(adj[i].second);
            edges[adj[i].second].push_back(adj[i].first);
        }
    }
    memset(vis, 0, sizeof(vis));
    long long akhir = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            int tmp = dfs(i);
            akhir += 1ll * tmp * (tmp - 1) / 2;
        }
    }
    cout << awal - akhir << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
}