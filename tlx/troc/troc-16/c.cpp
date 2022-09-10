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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, x = 1;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        x = (1ll * x * (m - 1)) % mod;
    }
    int dp[2][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[i & 1][0] = (1ll * (m - 1) * (dp[(i - 1) & 1][0] + dp[(i - 1) & 1][1])) % mod;
        dp[i & 1][1] = dp[(i - 1) & 1][0];
    }
    cout << (((dp[n & 1][0] + dp[n & 1][1] - x) % mod) + mod) % mod << endl;
    return 0;
}