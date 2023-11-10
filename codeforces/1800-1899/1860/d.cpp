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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    // cnt0 * cnt1 / 2
    int cnt0 = 0, cnt1 = 0;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '0')
            ++cnt0;
        else
            ++cnt1;
    }
    int dp[2][n + 1][cnt0 * cnt1 + 1];
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= cnt0 * cnt1; ++j)
            dp[0][i][j] = dp[1][i][j] = 1e9;
    }
    int res = 0;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= cnt1; ++j) {
            for(int k = 0; k <= cnt0 * cnt1 / 2; ++k) {
                // dp[i][j][k]
                // j is count of 1
                // k is count of 10
                // transition: dp[i][j][k] = dp[i][j - 1][k], dp[i][j][k - j]
                int o = (i & 1) ^ 1;
                dp[i & 1][j][k] = min((j == 0) ? 1e9 : (dp[o][j - 1][k] + (s[i] == '0')), (k - j < 0) ? 1e9 : (dp[o][j][k - j] + (s[i] == '1')));
                //cout << i << " " << j << " " << k << " " << dp[i & 1][j][k] << endl;
                if(i == n && j == cnt1 && k == cnt0 * cnt1 / 2) {
                    res = dp[i & 1][j][k];
                }
            }
        }
    }
    cout << res / 2 << endl;
    return 0;
}