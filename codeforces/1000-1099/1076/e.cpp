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
struct fenwick {
    ll a[300005];
    ll query(int idx) {
        ll res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    ll q(int l, int r) {
        return query(r) - query(l - 1);
    }
    void upd(int idx, ll val) {
        while(idx < 300005) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
};
fenwick bit;
vector<int> edges[300005];
int depth[300005];
bool vis[300005];
vector<pair<ll, ll>> operations[300005];
void get_depth(int nd, int d) {
    depth[nd] = d;
    vis[nd] = 1;
    for(auto i : edges[nd])
        if(!vis[i])
            get_depth(i, d + 1);
}
ll res[300005];
void dfs(int nd) {
    for(auto i : operations[nd]) {
        bit.upd(min(1ll * 300000, i.fi + depth[nd]), i.se);
    }
    res[nd] = bit.q(depth[nd], 300000);
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
    }
    for(auto i : operations[nd]) {
        bit.upd(min(1ll * 300000, i.fi + depth[nd]), -i.se);
    }   
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
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        ll v, d, x;
        cin >> v >> d >> x;
        operations[v].pb(mp(d, x));
    }
    get_depth(1, 1);
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for(int i = 1; i <= n; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}