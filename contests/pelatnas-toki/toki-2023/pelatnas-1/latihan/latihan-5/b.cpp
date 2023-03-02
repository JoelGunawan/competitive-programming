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
vector<pair<int, int>> gcds;
const int lim = 1e5 + 5;
int a[lim];
vector<int> edges[lim];
bool vis[lim];
vector<int> factors[lim];
map<int, pair<int, int>> cnt[lim];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int mod = 998244353;
ll ans = 0;
void dfs(int nd) {
    vis[nd] = 1;
    cnt[nd][a[nd]] = mp(1, 1);
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            // fi -> factor, se -> {sum, cnt}
            vector<pair<int, pair<int, int>>> cur;
            for(auto j : cnt[i]) {
                cur.pb(mp(gcd(j.fi, a[nd]), j.se));
            }
            for(auto j : cur) {
                for(auto k : cnt[nd]) {
                    ans += 1ll * gcd(j.fi, k.fi) * (1ll * j.se.fi * k.se.se + 1ll * j.se.se * k.se.fi);
                    ans %= mod;
                }
            }
            for(auto j : cur) {
                cnt[nd][j.fi].fi += j.se.fi + j.se.se;
                cnt[nd][j.fi].se += j.se.se;
                cnt[nd][j.fi].fi %= mod;
                cnt[nd][j.fi].se %= mod;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    for(int i = 1; i <= 1e5; ++i) {
        for(int j = i; j <= 1e5; j += i)
            factors[j].pb(i);
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}