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
const int lim = 1e4 + 1e3;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll fact[lim], invfact[lim];
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
ll inv(ll a) {
    return powmod(a, mod - 2);
}
ll combinmod(ll a, ll b) {
    if(b > a)
        return 0;
    else
        return mulmod(fact[a], mulmod(invfact[b], invfact[a - b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1, invfact[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (fact[i - 1] * i) % mod, invfact[i] = inv(fact[i]);
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // remaining whitespace itu 
    int blackspace = (n - 1) * a[0] + 1;
    cout << mulmod(fact[n], combinmod(n + m - blackspace, n));
    /*
    if(n == 1)
        cout << m << endl, exit(0);
    sort(a, a + n);
    ll dp[2][m + 1][3];
    memset(dp, 0, sizeof(dp));
    dp[1][m][0] = 1;
    int div1 = inv(n - 1), div2 = inv(combinmod(n - 1, 2));
    for(int i = 0; i < n; ++i) {
        int cur = i & 1, prev = !cur, lx = i, gx = n - i - 1;
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k < 3; ++k) {
                // mid dominant 0
                if(j + 1 <= m)
                    dp[cur][j][k] += mulmod(dp[prev][j + 1][k], mulmod(combinmod(gx, 2), div2)); 
                // mid dominant 1
                if(j + a[i] <= m)
                    dp[cur][j][k] += mulmod(dp[prev][j + a[i]][k], mulmod(mulmod(gx, lx), div2));
                // mid dominant 2
                if(j + 2 * a[i] - 1 <= m)
                    dp[cur][j][k] += mulmod(dp[prev][j + 2 * a[i] - 1][k], mulmod(combinmod(lx, 2), div2));
                dp[cur][j][k] %= mod;
            }

            for(int k = 1; k < 3; ++k) {
                // dominant 0
                if(j + 1 <= m)
                    dp[cur][j][k] += mulmod(dp[prev][j + 1][k - 1], mulmod(gx, div1));
                // dominant 1
                if(j + a[i] <= m)
                    dp[cur][j][k] += mulmod(dp[prev][j + a[i]][k - 1], mulmod(lx, div1));
                dp[cur][j][k] %= mod;
            }
        }
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k < 3; ++k)
                cout << dp[cur][j][k] << " ";
            cout << endl;
        }
        cout << endl;
        for(int j = 0; j <= m; ++j)
            for(int k = 0; k < 3; ++k)
                dp[prev][j][k] = 0;
    }
    ll res = 0;
    for(int i = 0; i <= m; ++i)
        res += mulmod(mulmod(dp[(n - 1) & 1][i][2], combinmod(n + i, n)), mulmod(2, fact[n - 2]));
    cout << res << endl;
    */
    return 0;
}