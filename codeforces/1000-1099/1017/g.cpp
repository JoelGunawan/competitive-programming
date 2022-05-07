// header file
#include <bits/stdc++.h>
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
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim], lazy[2 * lim];
    int size = lim;
    segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    void propagate(int nd, int cl, int cr) {
        a[nd] += lazy[nd];
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(int l, int r, int val) {
        update(1, 0, size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = max(a[2 * nd], a[2 * nd + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl > r || cr < l)
            return -1e9;
        else if(cl >= l && cr <= r)
            return a[nd];
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};
int sz[lim], in[lim], out[lim], depth[lim], t, root[lim], par[lim];
vector<int> child[lim];
segment_tree segtree;
void dfs_sz(int nd) {
    sz[nd] = 1;
    for(auto &i : child[nd]) {
        depth[i] = depth[nd] + 1;
        dfs_sz(i);
        sz[nd] += sz[i];
        if(sz[i] > sz[child[nd][0]])
            swap(i, child[nd][0]);
    }
}
void dfs_hld(int nd) {
    in[nd] = ++t;
    //cout << "NODE " << nd << " " << in[nd] << endl;
    segtree.update(in[nd], in[nd], depth[nd]);
    for(auto i : child[nd]) {
        root[i] = i == child[nd][0] ? root[nd] : i;
        dfs_hld(i);
    }
    out[nd] = t;
}
int query(int u, int v) {
    int ans = -1e9;
    while(root[u] != root[v]) {
        if(depth[root[u]] > depth[root[v]])
            swap(u, v);
        ans = max(ans, segtree.query(in[root[v]], in[v]));
        v = par[root[v]];
    }
    if(depth[u] > depth[v])
        swap(u, v);
    ans = max(ans, segtree.query(in[u], in[v]));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        child[p].pb(i);
        par[i] = p;
    }
    depth[1] = 1;
    dfs_sz(1);
    dfs_hld(1);
    multiset<pair<pair<int, int>, int>> queries;
    for(int i = 0; i < q; ++i) {
        int t, v;
        cin >> t >> v;
        if(t == 1) {
            segtree.update(in[v], out[v], -1);
            queries.ins(mp(mp(in[v], out[v]), -1));
        }
        else if(t == 2) {
            auto tmp2 = queries.lb(mp(mp(in[v], 0), -1e9));
            while(tmp2 != queries.end() && tmp2->fi.fi <= out[v])
                segtree.update(tmp2->fi.fi, tmp2->fi.se, -tmp2->se), queries.erase(tmp2), tmp2 = queries.lb(mp(mp(in[v], 0), -1e9));
            int tmp = -segtree.query(in[v], in[v]) + query(0, par[v]) + 1;
            segtree.update(in[v], out[v], tmp);
            queries.ins(mp(mp(in[v], out[v]), tmp));
        }
        else {
            int tmp = -segtree.query(in[v], in[v]) + query(0, par[v]) + 1;
            if(tmp >= 1)
                cout << "black" << endl;
            else
                cout << "white" << endl;
        }
    }
    return 0;
}