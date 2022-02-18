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
int mod = 998244353;
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
ll memo[1000][1000];
ll powmod(ll a, ll b) {
    if(a < 1000 && b < 1000 && memo[a][b] != -1)
        return memo[a][b];
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        if(a < 1000 && b < 1000)
            memo[a][b] = b & 1 ? (tmp * a) % mod : tmp;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll fact[501], inv_fact[501];
ll combinmod(ll a, ll b) {
    return mulmod(fact[a], mulmod(inv_fact[b], inv_fact[a - b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(memo, -1, sizeof(memo));
    int n, x;
    fact[0] = 1;
    inv_fact[0] = powmod(fact[0], mod - 2);
    for(int i = 1; i <= 500; ++i)
        fact[i] = mulmod(fact[i - 1], i), inv_fact[i] = powmod(fact[i], mod - 2);
    cin >> n >> x;
    // lower bound
    // find how many ways we can select lower bound and upper bound
    // upper bound
    // case n >= max(x) -> all valid
    // else -> reduce all by n and remove invalid x
    // do bottom up dp
    // semua n >= max(x) use combin
    // the way you can do such that n >= max(x)
    // reserve one number as max(x)
    // the rest can be from 1 to x
    // simple :D
    // dp O(nx^2)
    ll dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    // this is base case
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= min(i - 1, x); ++j) {
            // reserve 1 as x max
            // the rest is in the form
            // x_1+x_2+x_3+...+x_xmax=i - 1
            dp[i][j] = (powmod(j, i) - powmod(j - 1, i) + mod) % mod;
        }
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= x; ++j) {
            // lakuin semua dp[n][j + n - 1], dp[n + 1][j + n], dp[n + 2][n + j + 2]
            for(int k = i; k <= n && j + k - 1 <= x; ++k) {
                // number of ways to insert x new elements
                //cout << k << " " << j + k - 1 << endl;
                if(k <= j + k - 1)
                    dp[k][j + k - 1] = (dp[k][j + k - 1] + mulmod(dp[i][j], mulmod(combinmod(k, k - i), powmod(k - 1, k - i)))) % mod;
            }
        }
    }
    ll res = 0;
    //for(int i = 0; i <= n; ++i) {
    //    for(int j = 0; j <= x; ++j)
    //        cout << dp[i][j] << " ";
    //    cout << endl;
    //}
    for(int i = 0; i <= x; ++i)
        res = (res + dp[n][i]) % mod;
    cout << res << endl;
    return 0;
}