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
    // dp n * 512
    int dp[2][512];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 512; ++j)
            dp[i & 1][j] = (dp[(i + 1) & 1][j] + dp[(i + 1) & 1][j ^ a[i]]) % mod;
    }
    cout << dp[n & 1][0] - 1 << endl;
    return 0;
}