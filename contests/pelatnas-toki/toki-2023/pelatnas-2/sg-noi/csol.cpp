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
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    vector<int> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // do dijkstra from 1 and n
    // maintain pair
    // fi.fi -> dist
    // fi.se -> max_h
    // se -> node
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pair<int, int> res[2][n + 1];
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    pq.push(mp(mp(0, 0), 1));
    while(pq.size()) {
        int dist = pq.top().fi.fi, cur_h = pq.top().fi.se, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        res[0][nd] = mp(dist, cur_h);
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                pq.push(mp(mp(dist + max(1, h[i] - dist), max(cur_h, h[i])), i));
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    pq.push(mp(mp(0, 0), n));
    while(pq.size()) {
        int dist = pq.top().fi.fi, cur_h = pq.top().fi.se, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        res[1][nd] = mp(dist, cur_h);
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                pq.push(mp(mp(dist + max(1, h[i] - dist), max(cur_h, h[i])), i));
            }
        }
    }
    int ans = 2e9;
    for(int i = 1; i <= n; ++i) {
        if(res[0][i].se == res[1][i].se && res[0][i].se == h[i])
            ans = min(ans, res[0][i].fi + res[1][i].fi);
    }
    cout << ans << endl;
    return 0;
}