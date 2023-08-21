// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,avx2,mmx,tune=native")
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
const int lim = 1 << 17;
vector<int> edges[lim], child[lim];
int depth[lim], val[lim], subtree[lim], par[17][lim];
bool vis[lim];
struct segment_tree {
    // replace zero with LLONG_MIN for max query
    // replace zero with LLONG_MAX for min query
    long long a[2 * lim], arr_size = lim, zero = 0;
    segment_tree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return max(a, b);
    }
    void update(int idx, long long val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
segment_tree seg;
void dfs(int nd) {
    vis[nd] = 1;
    subtree[nd] = 1;
    for(int i = 1; i < 17; ++i) {
        par[i][nd] = par[i - 1][par[i - 1][nd]];
    }
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            par[0][i] = nd;
            dfs(i);
            child[nd].push_back(i);
            subtree[nd] += subtree[i];
        }
    }
    for(auto &i : child[nd])
        if(subtree[i] > subtree[child[nd][0]])
            swap(i, child[nd][0]);
}
int in[lim], ti, root[lim];
void dfs2(int nd) {
    in[nd] = ti++;
    for(auto i : child[nd]) {
        root[i] = (i == child[nd][0] ? root[nd] : i);
        dfs2(i);
    }
}
int lca(int u, int v) {
    if(depth[u] > depth[v]) {
        swap(u, v);
    }
    // depth v lebih besar
    for(int i = 16; i >= 0; --i) {
        if(depth[par[i][v]] >= depth[u])
            v = par[i][v];
    }
    if(u == v)
        return u;
    for(int i = 16; i >= 0; --i) {
        if(par[i][v] != par[i][u])
            u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}
int query(int u, int v) {
    // u itu yg root
    if(depth[u] > depth[v])
        swap(u, v);
    int res = 0;
    while(root[v] != root[u]) {
        res = max(res, (int)seg.query(in[root[v]], in[v]));
        v = par[0][root[v]];
        if(depth[u] > depth[v])
            swap(u, v);
    }
    res = max(res, (int)seg.query(in[u], in[v]));
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // always set lca as pos keamanan
    // nanti cek sebelum set lca as pos keamanan, apa ada child lca yg udh di set sebagai pos keamanan
    // cara cek? -> hld
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    depth[1] = 1;
    dfs(1);
    dfs2(1);
    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> p;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        p.pb(mp(depth[lca(u, v)], mp(u, v)));
    }
    sort(p.begin(), p.end(), greater<pair<int, pair<int, int>>>());
    vector<int> v;
    for(auto i : p) {
        if(query(i.se.fi, i.se.se)) {
            continue;
        }
        else {
            // add di lca
            seg.update(in[lca(i.se.fi, i.se.se)], 1);
            v.pb(lca(i.se.fi, i.se.se));
        }
    }
    cout << v.size() << endl;
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}