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
int mod = 998244353;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
int sz[lim], par[lim];
int dfs(int nd) {
    vis[nd] = 1;
    sz[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            sz[nd] += dfs(i), par[i] = nd;
    }
    return sz[nd];
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll fact[lim], inv[lim];
ll c(ll a, ll b) {
    if(a < b)
        return 0;
    else {
        //cout << a << " " << b << " " << mul(fact[a], mul(inv[a - b], inv[b])) << endl;
        return mul(fact[a], mul(inv[a - b], inv[b]));
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fact[0] = inv[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (1ll * fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    int n, k;
    cin >> n >> k;
    if(k % 2 == 1) {
        cout << 0 << endl, exit(0);
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    ll ans = 0;
    for(int i = 2; i <= n; ++i) {
        // dia harus tuker antara parent dan cur
        // divide by k / 2 cycles
        // C(sz[nd], k / 2) * (k / 2)! * C(sz[par] - sz[nd], k / 2) * (k / 2)!;
        int par_sz = sz[1] - sz[i];
        //cout << sz[i] << " " << par_sz << " " << k / 2 << " " << mul(c(par_sz, k / 2), fact[k / 2 - 1]) << " " << mul(c(sz[i], k / 2), fact[k / 2]) << endl;
        ans += mul(2, mul(mul(c(par_sz, k / 2), fact[k / 2]), mul(c(sz[i], k / 2), fact[k / 2])));
    }
    cout << ans % mod << endl;
    return 0;
}