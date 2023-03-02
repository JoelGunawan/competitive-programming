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
const int lim = 405;
ll fact[lim], inv[lim];
int mod;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n >> mod;
    // mul by 2^(k - 1)/k!
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            for(int k = 1; k <= j && i - k - 1 > 0; ++k) {
                dp[i][j] += (((dp[i - k - 1][j - k] * inv[k]) % mod) * powmod(2, k - 1)) % mod;
            }
            if(i == j)
                dp[i][j] = (powmod(2, i - 1) * inv[i]) % mod;
            dp[i][j] %= mod;
        }
    }
    ll res = 0;
    for(int i = n / 2; i <= n; ++i) {
        res += (dp[n][i] * fact[i]) % mod;
    }
    res %= mod;
    cout << res << endl;
    return 0;
}