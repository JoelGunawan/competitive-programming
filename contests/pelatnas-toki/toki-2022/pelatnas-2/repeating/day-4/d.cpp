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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll fact[n + 1], inv_fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    for(int i = 0; i <= n; ++i)
        inv_fact[i] = powmod(fact[i], mod - 2);
    int dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = fact[n];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
            for(int k = 0; k <= j; ++k) {
                if(j - k != i && dp[i - 1][k] != -1) {
                    dp[i][j] += (dp[i - 1][k] * inv_fact[j - k]) % mod;
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << ((powmod(n, n) - dp[n][n]) + mod) % mod << endl;
    return 0;
}