// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int tlim[2];
    int node[2][2];
    for(int i = 0; i < 2; ++i) {
        cin >> node[i][0] >> node[i][1] >> tlim[i];
    }
    // buat completely disjoint atau joint middle section
    // try every pair of nodes
    // cari shortest path 
    int dist[n + 1][n + 1];
    memset(dist, -1, sizeof(dist));
    for(int i = 1; i <= n; ++i) {
        queue<pair<int, int>> bfs;
        bfs.push(mp(0, i));
        while(bfs.size()) {
            int d = bfs.front().fi, nd = bfs.front().se;
            bfs.pop();
            if(dist[i][nd] != -1)
                continue;
            dist[i][nd] = d;
            for(auto i : edges[nd])
                bfs.push(mp(d + 1, i));
        }
    }
    if(dist[node[0][0]][node[0][1]] > tlim[0] || dist[node[1][0]][node[1][1]] > tlim[1]) {
        cout << -1 << endl;
        return 0;
    }
    int res = m - (dist[node[0][0]][node[0][1]] + dist[node[1][0]][node[1][1]]);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // i to j
            // dr 0, 0 -> i, 0, 1 -> i
            // dr 0, 0 -> j, 0, 1 -> i
            if(dist[node[0][0]][i] + dist[node[0][1]][j] + dist[i][j] <= tlim[0] && dist[node[1][0]][i] + dist[node[1][1]][j] + dist[i][j] <= tlim[1])
                res = max(res, m - (dist[node[0][0]][i] + dist[node[0][1]][j] + dist[node[1][0]][i] + dist[node[1][1]][j] + dist[i][j]));
            if(dist[node[0][0]][j] + dist[node[0][1]][i] + dist[i][j] <= tlim[0] && dist[node[1][0]][i] + dist[node[1][1]][j] + dist[i][j] <= tlim[1])
                res = max(res, m - (dist[node[0][0]][j] + dist[node[0][1]][i] + dist[node[1][0]][i] + dist[node[1][1]][j] + dist[i][j]));
        }
    }
    cout << res << endl;
    return 0;
}