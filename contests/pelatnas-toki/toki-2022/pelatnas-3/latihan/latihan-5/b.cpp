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
const int lim = 1e5 + 5;
vector<int> edges[lim];
struct fenwick {
    int a[lim];
    vector<int> used;
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void reset() {
        for(auto i : used)
            a[i] = 0;
        used.clear();
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            used.pb(idx);
            idx += (idx&-idx);
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
};
fenwick bit;
int sz[lim], depth[lim], par[lim], in[lim], out[lim], root[lim], t, c[lim];
deque<pair<int, int>> a[lim];
ll res = 0;
void dfs_sz(int nd = 1) {
    sz[nd] = 1;
    for(auto &u : edges[nd]) {
        par[u] = nd;
        depth[u] = depth[nd] + 1;
        dfs_sz(u);
        sz[nd] += sz[u];
        if(sz[u] > sz[edges[nd][0]])
            swap(edges[nd][0], u);
    }
}

void dfs_hld(int nd = 1) {
    in[nd] = t++;
    for(auto u : edges[nd]) {
        root[u] = u == edges[nd][0] ? root[nd] : u;
        dfs_hld(u);
    }
    a[root[nd]].pb(mp(c[nd], 1));
    out[nd] = t;
}

void query(int nd, int update) {;
    while(nd > 0) {
        int to_remove = depth[nd] - depth[root[nd]] + 1;
        vector<pair<int, int>> add;
        while(to_remove && a[root[nd]].size()) {
            if(a[root[nd]].back().se > to_remove) {
                add.pb(mp(a[root[nd]].back().fi, to_remove));
                a[root[nd]].back().se -= to_remove;
                to_remove = 0;
                //cout << "REDUCE" << endl;
            }
            else {
                to_remove -= a[root[nd]].back().se;
                add.pb(a[root[nd]].back());
                a[root[nd]].pop_back();
                //cout << "POP" << endl;
            }
        }
        reverse(add.begin(), add.end());
        //cout << "NODE " << nd << " " << depth[nd] - depth[root[nd]] + 1 << endl;
        for(auto i : add) {
            //cout << "ADD " << i.fi << " " << i.se << endl;
            res += 1ll * bit.query(i.fi - 1) * i.se;
            bit.update(i.fi, i.se);
        }
        a[root[nd]].pb(mp(update, depth[nd] - depth[root[nd]] + 1));
        nd = par[root[nd]];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    map<int, int> x, b;
    for(int i = 1; i <= n; ++i)
        ++x[c[i]];
    int tmp = 0;
    for(auto i : x)
        b[i.fi] = ++tmp;
    for(int i = 1; i <= n; ++i)
        c[i] = b[c[i]];
    depth[1] = 1;
    pair<int, int> adj[n - 1];
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        edges[x].pb(y);
        adj[i] = mp(x, y);
    }
    root[1] = 1;
    dfs_sz(), dfs_hld();
    for(int i = 0; i < n - 1; ++i) {
        query(adj[i].fi, c[adj[i].se]);
        bit.reset();
        cout << res << endl;
        res = 0;
    }
    return 0;
}