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
ll mod;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll f(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, m;
    cin >> n >> m >> mod;
    n /= 2;
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    ll mul[n + 10];
    mul[0] = 1;
    mul[1] = m, mul[2] = (m * (m - 1)) % mod;
    mul[3] = (((m * m) % mod) * (m - 1)) % mod;
    for(int i = 4; i <= n; ++i) {
        if(i & 1) {
            mul[i] = f(powmod(m, i - 1), m - 1) - mul[i - 2];
        }
        else
            mul[i] = f(powmod(m, i - 1), m - 1) - mul[i - 2];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j)
            dp[i] = (dp[i] + dp[i - j] * mul[j]) % mod;
    }
    dp[n] %= mod;
    if(dp[n] < 0)
        dp[n] += mod;
    cout << dp[n] << endl;
    return 0;
}