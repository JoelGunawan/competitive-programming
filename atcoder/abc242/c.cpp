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
int mod = 998244353;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    ll dp[2][10];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < 10; ++i)
        dp[0][i] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= 9; ++j) {
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if(j != 1)
                dp[i & 1][j] += dp[(i - 1) & 1][j - 1];
            if(j != 9)
                dp[i & 1][j] += dp[(i - 1) & 1][j + 1];
            dp[i & 1][j] %= mod;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= 9; ++i)
        sum += dp[(n - 1) & 1][i];
    cout << sum % mod << endl;
    return 0;
}