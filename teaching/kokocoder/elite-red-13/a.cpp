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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j / 2] + dp[i - 1][j / 3] + ...
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    vector<int> factors[2005];
    for(int i = 1; i <= 2000; ++i)
        for(int j = i; j <= 2000; j += i)
            factors[j].pb(i);
    dp[0][1] = 1;
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k : factors[j])
                dp[i][j] += dp[i - 1][k], dp[i][j] %= mod;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i)
        res = (res + dp[k][i]) % mod;
    cout << res << endl;
    return 0;
}