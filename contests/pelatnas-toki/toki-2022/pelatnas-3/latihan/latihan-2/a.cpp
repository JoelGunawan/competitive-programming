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
const int lim = 5e5 + 5;
struct segtree {
    
};
struct disjoint_set {
    segtree a[lim];
    int size[lim], head[lim];
    disjoint_set() {
        fill(size, size + lim, 1);
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
            // merge segment trees

        }
        return x != y;
    }
};
disjoint_set dsu;
vector<int> edges[lim];
int depth[lim], md[lim];
// md -> max depth of query ending in cur node
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            depth[i] = depth[nd] + 1, dfs(i);
    }
}
void solve(int nd) {
    int tmp = -1;
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            tmp = i;
    }
    if(tmp != -1) {
        dsu.head[nd] = dsu.find_head(tmp);
        dsu.size[dsu.find_head(tmp)] += 1;
    }
    else {
        // modify semua nilai segtree dimana 
        return;
    }
    vector<int> ans;
    for(auto i : edges[nd])
        if(!vis[i])
            solve(i), ans.pb(i);
    for(auto i : ans)
        dsu.merge(nd, i);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    int m;
    cin >> m;
    pair<int, int> queries[m];
    for(int i = 0; i < m; ++i)
        cin >> queries[i].fi >> queries[i].se, md[queries[i].se] = max(md[queries[i].se], depth[queries[i].fi]);
    // dp v -> subtree v
    // d -> edge hitam terdekat di depth d
    // c -> child
    // dp[v][d] = capital pi(dp[c][depth[v]] -> kita add black edge + (if d >= md) dp[c][d] -> kita add white edge)

    return 0;
}