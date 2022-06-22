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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[n + 1][n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 3;
    vector<pair<int, int>> limits[n + 1];
    for(int i = 0; i < m; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        if(r - l + 1 < w) {
            cout << 0 << endl;
            exit(0);
        }
        limits[r].pb(mp(l, w));
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < i; ++j) {
            for(int k = 0; k < max(1, j); ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if(j == i - 1 && j != 0) {
                    for(int l = k; l < max(1, j); ++l)
                        dp[i][j][k] += dp[i - 1][l][k];
                    for(int l = 0; l <= k; ++l) 
                        dp[i][j][k] += dp[i - 1][k][l];
                    // dp[i - 1][k][k] -> k == 0
                    //if(k == 0 && j != k)
                    //    dp[i][j][k] += 2 * dp[i][k][k];
                }
                dp[i][j][k] %= mod;
            }
        }
        for(auto x : limits[i]) {
            if(x.se == 1) {
                for(int j = 0; j <= n; ++j) {
                    for(int k = 0; k <= n; ++k) {
                        if(j >= x.fi || k >= x.fi)
                            dp[i][j][k] = 0;
                    }
                }
            }
            else if(x.se == 2) {
                for(int j = 0; j <= n; ++j) {
                    for(int k = 0; k <= n; ++k) {
                        if(max(j, k) < x.fi || min(j, k) >= x.fi)
                            dp[i][j][k] = 0;
                    }
                }
            }
            else {
                for(int j = 0; j <= n; ++j) {
                    for(int k = 0; k <= n; ++k) {
                        if(j < x.fi || k < x.fi)
                            dp[i][j][k] = 0;
                    }
                }
            }
        }
    }
    /*
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            for(int k = 0; k <= n; ++k)
                cout << dp[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
    */
    ll res = 0;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            res += dp[n][i][j], res %= mod;
    cout << res << endl;
    return 0;
}