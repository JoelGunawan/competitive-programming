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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1][m + 1];
    // max log k states only
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    map<int, int> dp[2][m + 1];
    dp[0][1][1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i & 1][j].clear();
            for(auto l : dp[(i - 1) & 1][j]) {
                if(1ll * a[i][j] * l.fi >= k)
                    dp[i & 1][j][0] += l.se, dp[i & 1][j][0] %= mod;
                else
                    dp[i & 1][j][a[i][j] * l.fi] += l.se, dp[i & 1][j][a[i][j] * l.fi] %= mod;
            }
            for(auto l : dp[i & 1][j - 1]) {
                if(1ll * a[i][j] * l.fi >= k)
                    dp[i & 1][j][0] += l.se, dp[i & 1][j][0] %= mod;
                else
                    dp[i & 1][j][a[i][j] * l.fi] += l.se, dp[i & 1][j][a[i][j] * l.fi] %= mod;
            }
            //for(auto l : dp[i][j])
            //    cout << i << " " << j << " " << l.fi << " " << l.se << endl;
        }
    }
    cout << dp[n & 1][m][0] << endl;
    return 0;
}