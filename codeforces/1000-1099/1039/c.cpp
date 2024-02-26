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
const int lim = 5e5 + 5;
vector<int> edges[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
    }
}
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll sub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    ll c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    pair<int, int> adj[m];
    vector<ll> vals;
    for(int i = 0; i < m; ++i) {
        cin >> adj[i].fi >> adj[i].se;
        vals.pb(c[adj[i].fi] ^ c[adj[i].se]);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    vector<pair<int, int>> list[vals.size()];
    for(auto p : adj) {
        int idx = lb(vals.begin(), vals.end(), c[p.fi] ^ c[p.se]) - vals.begin();
        list[idx].pb(p);
    }
    ll ans = mul(powmod(2, n), (1ll << k) % mod);
    for(auto v : list) {
        vector<int> nodes;
        for(auto p : v) {
            edges[p.fi].pb(p.se);
            edges[p.se].pb(p.fi);
            nodes.pb(p.fi);
            nodes.pb(p.se);
        }
        sort(nodes.begin(), nodes.end());
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        // for each cc, only two possibilities, all on or all off
        ans = sub(ans, powmod(2, n));
        ll cur = powmod(2, n - nodes.size());
        for(auto nd : nodes) {
            if(!vis[nd])    
                dfs(nd), cur = mul(cur, 2);
        }
        for(auto nd : nodes) {
            while(edges[nd].size())
                edges[nd].pop_back();
            vis[nd] = 0;
        }
        ans = add(ans, cur);
    }
    cout << ans << endl;
    return 0;
}