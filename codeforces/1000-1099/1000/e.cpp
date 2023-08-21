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
const int lim = 3e5 + 5;
vector<int> edges[lim];
int disc[lim], low[lim], ti = 1;
vector<pair<int, int>> bridges;
void dfs(int nd, int par) {
    disc[nd] = low[nd] = ti++;
    for(auto i : edges[nd]) {
        if(i == par) {
            continue;
        }
        else if(disc[i] == -1) {
            dfs(i, nd);
            // not a back edge, can take from low
            low[nd] = min(low[nd], low[i]);
        }
        else {
            // udah visited sebelumnya, ini merupakan back edge
            low[nd] = min(low[nd], disc[i]);
        }
    }
    //cout << nd << " " << disc[nd] << " " << low[nd] << endl;
    for(auto i : edges[nd]) {
        if(i != par && low[i] > disc[nd])
            bridges.push_back(mp(min(i, nd), max(i, nd)));
    }
}
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
int dist[lim];
bool vis[lim];
void dfs2(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dist[i] = dist[nd] + 1, dfs2(i);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // get bridge tree
    // nanti dfs ke target node, cek lewat bridge mana aja
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    dfs(1, 0);
    // diameter on bridge tree
    disjoint_set dsu;
    sort(bridges.begin(), bridges.end());
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            if(!binary_search(bridges.begin(), bridges.end(), mp(min(i, j), max(i, j))))
                dsu.merge(i, j);
        }
        edges[i].clear();
    }
    for(auto i : bridges)
        edges[dsu.fh(i.fi)].pb(dsu.fh(i.se)), edges[dsu.fh(i.se)].pb(dsu.fh(i.fi));
    dist[dsu.fh(1)] = 1;
    dfs2(dsu.fh(1));
    memset(vis, 0, sizeof(vis));
    pair<int, int> mx = mp(0, 0);
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, mp(dist[i], i));
    }
    memset(dist, 0, sizeof(dist));
    dist[mx.se] = 1;
    dfs2(mx.se);
    int out = 0;
    for(int i = 1; i <= n; ++i)
        out = max(out, dist[i]);
    cout << out - 1 << endl;
    return 0;
}