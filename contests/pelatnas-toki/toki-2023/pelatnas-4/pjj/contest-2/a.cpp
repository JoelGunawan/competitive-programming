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
const int lim = 1e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, ll val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    void update(int l, int r, ll val) {
        update(l, val);
        update(r + 1, -val);
    }
    ll query(int idx) {
        ll ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
};
vector<int> edges[lim];
int par[17][lim], in[lim], out[lim], ti, depth[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    in[nd] = ++ti;
    for(int i = 1; i < 17; ++i) {
        par[i][nd] = par[i - 1][par[i - 1][nd]];
    }
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            par[0][i] = nd;
            dfs(i);
        }
    }
    out[nd] = ti;
}
int lca(int u, int v) {
    if(depth[u] > depth[v])
        swap(u, v);
    for(int i = 16; i >= 0; --i) {
        if(depth[par[i][v]] >= depth[u])
            v = par[i][v];
    }
    if(u == v)
        return u;
    for(int i = 16; i >= 0; --i) {
        if(par[i][u] != par[i][v])
            u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}
struct query {
    ll l, r, m, num, s, t, x, y;
    bool operator<(const query& rhs) const {
        return m > rhs.m;
    };
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dsu on tree dr min weight, nanti bisa di paralel binser berapa max yg bs didapat
    // find count of "used" edges in a path
    // HLD + binser -> Nlog^3N
    // coba non HLD atau coba HLD tapi ga pake binsernya
    // find count of "used" in path, sum edgesnya berapa?
    // simpan dist i ke root dan j ke root
    // nanti di update lazy seg, terus simpen LCA
    // jadinya binser + mst + ett + seg/fen
    // greedy edge dr yg cost terkecil ke terbesar, nanti simpan count used edges berapa (bisa pakai teknik yg sama juga)
    // bisa pakai segtree biasa, difference array style
    int n, m, q;
    cin >> n >> m >> q;
    pair<int, int> adj[n];
    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
        adj[i] = mp(u, v);
    }
    depth[1] = 1;
    dfs(1);
    for(int i = 1; i <= n - 1; ++i) {
        if(depth[adj[i].fi] < depth[adj[i].se])
            swap(adj[i].fi, adj[i].se);
    }
    // fi -> price
    // se -> idx
    fenwick cost, count;
    pair<int, int> periksa[m];
    for(int i = 0; i < m; ++i) {
        cin >> periksa[i].se >> periksa[i].fi;
    }
    sort(periksa, periksa + m);
    ll ans[q];
    memset(ans, -1, sizeof(ans));
    vector<query> queries[2][m + 1];
    for(int i = 0; i < q; ++i) {
        ll s, t, x, y;
        cin >> s >> t >> x >> y;
        query a;
        a.x = x, a.y = y, a.l = 0, a.r = m, a.m = (a.l + a.r) >> 1, a.num = i;
        a.s = s, a.t = t;
        queries[1][a.m].pb(a);
    }
    for(int iter = 0; iter < 18; ++iter) {
        // coba jalanin paralel binser
        // count: jumlah emas yg digunakan
        int idx = iter & 1;
        for(int i = 0; i < m; ++i)
            queries[idx][i].clear();
        for(auto i : periksa) {
            count.update(in[adj[i.se].fi], out[adj[i.se].fi], 1);
        }
        for(int i = 0; i < m; ++i) {
            // before update di proses dulu
            for(auto j : queries[idx ^ 1][i]) {
                int r = lca(j.s, j.t);
                ll perak = cost.query(in[j.s]) + cost.query(in[j.t]) - 2 * cost.query(in[r]);
                ll emas = count.query(in[j.s]) + count.query(in[j.t]) - 2 * count.query(in[r]);       
                //cout << j.num << endl;
                //cout << "INDEX " << i << endl;
                //cout << "PERAK " << perak << " " << j.y << endl;
                //cout << "EMAS " << emas << " " << j.x << endl;
                if(perak <= j.y && emas <= j.x) {
                    ans[j.num] = max(ans[j.num], j.x - emas);
                }
                if(perak <= j.y) {
                    j.l = j.m + 1;
                }
                else {
                    j.r = j.m - 1;
                }
                j.m = (j.l + j.r) >> 1;
                queries[idx][j.m].pb(j);
            }
            // update cost/count
            // u higher depth
            int u = adj[periksa[i].se].fi;
            ll harga = periksa[i].fi;
            count.update(in[u], out[u], -1);
            cost.update(in[u], out[u], harga);
        }
        for(auto j : queries[idx ^ 1][m]) {
            int r = lca(j.s, j.t);
            ll perak = cost.query(in[j.s]) + cost.query(in[j.t]) - 2 * cost.query(in[r]);
            ll emas = count.query(in[j.s]) + count.query(in[j.t]) - 2 * count.query(in[r]);       
            //cout << j.num << endl;
            //cout << "INDEX " << i << endl;
            //cout << "PERAK " << perak << " " << j.y << endl;
            //cout << "EMAS " << emas << " " << j.x << endl;
            if(perak <= j.y && emas <= j.x) {
                ans[j.num] = max(ans[j.num], j.x - emas);
            }
            if(perak <= j.y) {
                j.l = j.m + 1;
            }
            else {
                j.r = j.m - 1;
            }
            j.m = (j.l + j.r) >> 1;
            queries[idx][j.m].pb(j);
        }
        memset(cost.a, 0, sizeof(cost.a));
        memset(count.a, 0, sizeof(count.a));
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << endl;
    return 0;
}