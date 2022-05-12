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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<int> tmp;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        tmp.ins(i);
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i])
            tmp.erase(tmp.find(a[i]));
    }
    // pos, used_even, last
    // 0 -> even, 1 -> odd
    int dp[n + 1][n + 1][2];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            for(int k = 0; k < 2; ++k)
                dp[i][j][k] = 1e9;
    for(int j = 0; j < 2; ++j)
        dp[0][0][j] = 0;
    // last odd or last even
    for(int i = 1; i <= n; ++i) {
        if(a[i]) {
            if(a[i] & 1) {
                for(int j = 0; j <= n; ++j)
                    dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
            }
            else {
                for(int j = 0; j <= n; ++j)
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
            }
        }
        else {
            // determine even or odd
            // choose even
            for(int j = 0; j <= n; ++j) {
                dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);

            }
            // choose odd
            for(int j = 0; j <= n; ++j) {
                dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);

            }
        }
    }
    //for(int i = 1; i <= n; ++i)
    //    for(int j = 0; j <= n; ++j)
    //        cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
    int cnt = 0;
    for(auto i : tmp)
        if(i % 2 == 0)
            ++cnt;
    int res = min(dp[n][cnt][0], dp[n][cnt][1]);
    cout << res << endl;
    return 0;
}