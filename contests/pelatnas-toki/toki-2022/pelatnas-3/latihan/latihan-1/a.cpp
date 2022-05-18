// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("O3")
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
const int lim = 505;
int mod = 1e9 + 7;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll sub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
const int lim2 = 7e4;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ll res = 0;
    ll memo[lim2];
    memo[0] = 1;
    for(int i = 1; i < lim2; ++i) {
        memo[i] = (memo[i - 1] * 2) % mod;
    }
    ll tmp;
    int prevr, curr, x;
    for(int i = 1; i <= n; ++i) {
        x = min(k, i);
        for(int j = 1; j <= x; ++j) {
            for(int l = 0; l < i; ++l) {
                prevr = l, curr = i;
                //cout << i << " " << j << " " << l << " " << prevr << " " << curr << endl;
                //cout << powmod(2, curr - prevr) << " ";
                tmp = ((((memo[curr - prevr] - 1 + mod) * dp[l][j - 1]) % mod) * memo[prevr * (curr - prevr)]) % mod;
                //cout << tmp << endl;
                if(j == k)
                    tmp = (tmp * memo[curr * (n - curr)]) % mod;
                dp[i][j] += tmp;
            }
            //cout << dp[i][j] << " ";
            dp[i][j] %= mod;
        }
        //cout << endl;
    }
    for(int i = 0; i <= n; ++i)
        res += dp[i][k];
    //cout << endl;
    cout << res % mod << endl;
    return 0;
}