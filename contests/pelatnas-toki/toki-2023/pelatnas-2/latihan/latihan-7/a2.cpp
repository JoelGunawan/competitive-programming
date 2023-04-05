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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, m;
    cin >> n >> m >> mod;
    // partition cnt = n - 1 -> m^(n/2)
    // partition cnt = n - 2 ->     
    ll dp[n + 1];
    n /= 2;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        ll tmp = 1;
        for(int j = 1; j <= i; ++j) {
            ll pr = tmp;
            tmp *= m;
            tmp %= mod;
            // semua m kecuali terakhir m - 1
            if(j == 1)
                dp[i] += tmp * dp[i - j];
            else 
                dp[i] += (tmp - pr) * dp[i - j];
            dp[i] %= mod;
        }
    }
    dp[n] %= mod;
    dp[n] += mod;
    dp[n] %= mod;
    cout << dp[n] << endl;
    return 0;
}