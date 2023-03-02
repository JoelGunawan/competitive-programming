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
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll lim = 1e5 + 5;
ll a[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // (x + y - z) / 2
    ll n, m;
    cin >> n >> m;
    ll tot = 0;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i], tot += a[i];
    pair<pair<ll, ll>, ll> adj[m + 1];
    ll cs[n + 1];
    memset(cs, 0, sizeof(cs));
    vector<ll> res;
    for(ll i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;    
        ll tmp = (2 * (a[x] + a[y]) - tot) / 2;
        res.pb(tmp);
        cs[x] += tmp;
        cs[y] += tmp;
    }
    bool ans = 1;
    for(ll i = 1; i <= n; ++i)
        ans &= (cs[i] == a[i]);
    if(ans) {
        for(auto i : res)
            cout << 2 * i << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}