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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    // base case -> dp[0] = 1, dp[1] = 0, dp[2] = 1
    // recursive -> dp[n] = dp[0] * dp[n - 2] + dp[1] * dp[n - 3] ...
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 2; i <= n; i += 2) {
        for(int j = 0; j <= i - 2; j += 2)
            dp[i] += dp[j] * dp[i - j - 2];
    }
    cout << dp[n] << endl;
    return 0;
}