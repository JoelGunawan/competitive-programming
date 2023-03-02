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
int mod = 1e9 + 7;
const int lim = 2e6 + 5;
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
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
    return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // cara valid - invalid
    // O(N + M + K^2)
    // sparse DP!!!!!
    fact[0] = inv[0] = 1;
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> a[9 * k];
    for(int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        for(int j = -1; j < 2; ++j) {
            for(int l = -1; l < 2; ++l) {
                a[9 * i + 3 * (j + 1) + (l + 1)] = mp(x + j, y + l);
            }
        }
    }
    for(int i = 1; i <= n + m; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    k = 9 * k;
    ll total = combinmod(n + m - 2, m - 1);
    // cara invalid
    sort(a, a + k);
    ll dp[k];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < k; ++i) {
        ll cur = 0;
        for(int j = 0; j < i; ++j) {
            if(a[j].fi <= a[i].fi && a[j].se <= a[i].se) {
                cur += mul(dp[j], combinmod(a[i].fi + a[i].se - a[j].fi - a[j].se, a[i].fi - a[j].fi));
            }
        }
        cur = combinmod(a[i].fi + a[i].se, a[i].fi) - cur;
        cur %= mod;
        if(cur < 0)
            cur += mod;
        dp[i] = cur;
        total -= mul(dp[i], combinmod(n + m - 2 - a[i].fi - a[i].se, n - 1 - a[i].fi));
        //cout << a[i].fi + 1 << " " << a[i].se + 1 << " " << dp[i] << " " << mul(dp[i], combinmod(n + m - 2 - a[i].fi - a[i].se, n - 1 - a[i].fi)) << endl;
    }
    total %= mod;
    if(total < 0)
        total += mod;
    cout << total << endl;
    return 0;
}