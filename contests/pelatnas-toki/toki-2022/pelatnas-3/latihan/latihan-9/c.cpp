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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const ll lim = 1 << 18;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], inf = 1e18;
    lazy_segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    ll arr_size = lim;
    void propagate(ll nd, ll cl, ll cr) {
        a[nd] += lazy[nd] * (cr - cl + 1);
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(ll l, ll r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(ll nd, ll cl, ll cr, ll l, ll r, long long val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            ll mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = a[2 * nd] + a[2 * nd + 1];
        }
    }
    long long query(ll nd, ll cl, ll cr, ll l, ll r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return 0;
        else {
            ll mid = (cl + cr) / 2;
            return query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r);
        }
    }
};
vector<ll> edges[lim];
set<ll> a[lim];
ll ett[lim], sz[lim], revett[lim], t;
bool vis[lim];
ll dfs(ll nd) {
    ett[nd] = ++t;
    revett[ett[nd]] = nd;
    vis[nd] = 1;
    sz[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            sz[nd] += dfs(i);
    }
    return sz[nd];
}
lazy_segment_tree res;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    for(ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            // update warna
            // update ke res
            // kalo misal ada yang in range
            // simpen set yang isinya indeks di ett
            ll x, c;
            cin >> x >> c;
            assert(c < lim);
            bool add = 1;
            if(a[c].size() && a[c].upper_bound(ett[x]) != a[c].begin()) {
                // cek apakah ada di parent
                ll tmp = revett[*--a[c].upper_bound(ett[x])];
                //cout << ett[tmp] + sz[tmp] - 1 << " " << ett[x] << endl;
                if(ett[tmp] + sz[tmp] - 1 >= ett[x]) {
                    //cout << "CANCEL ADD" << endl;
                    add = 0;
                }
            }
            while(add && a[c].size() && a[c].lower_bound(ett[x]) != a[c].end() && *a[c].lower_bound(ett[x]) <= ett[x] + sz[x] - 1) {
                ll tmp = revett[*a[c].lower_bound(ett[x])];
                //cout << "DEL " << endl;
                res.update(ett[tmp], ett[tmp] + sz[tmp] - 1, -1);
                a[c].erase(a[c].lower_bound(ett[x]));
            }
            if(add) {
                res.update(ett[x], ett[x] + sz[x] - 1, 1);
                a[c].ins(ett[x]);
            }
        }
        else {
            ll x;
            cin >> x;
            assert(res.query(1, 0, lim - 1, ett[x], ett[x] + sz[x] - 1) >= 0);
            cout << res.query(1, 0, lim - 1, ett[x], ett[x] + sz[x] - 1) << endl;
        }
    }
    return 0;
}