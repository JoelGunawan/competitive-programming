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
int mod = 26101991;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    assert(n != 1);
    ll a[n + 1];
    for(int i = 0; i < n + 1; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    // cost of segment -> left * midpoint * right
    // left -> i, right -> j + 1
    if(q <= 2) {
        // fi -> val
        // se -> cnt
        pair<ll, ll> dp[n][n];
        for(int i = 0; i < n; ++i)
            dp[i][i] = mp(0, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n - i; ++j) {
                // j and i + j
                // find minimum
                dp[j][i + j] = mp(LLONG_MAX, 0);
                for(int k = 0; k < i; ++k) {
                    // j to j + k and j + k + 1 to i + j
                    if(dp[j][j + k].fi + dp[j + k + 1][i + j].fi + a[j] * a[j + k + 1] * a[i + j + 1] == dp[j][i + j].fi)
                        dp[j][i + j].se += (dp[j][j + k].se * dp[j + k + 1][i + j].se) % mod, dp[j][i + j].se %= mod;
                    else if(dp[j][j + k].fi + dp[j + k + 1][i + j].fi + a[j] * a[j + k + 1] * a[i + j + 1] < dp[j][i + j].fi)
                        dp[j][i + j] = mp(dp[j][j + k].fi + dp[j + k + 1][i + j].fi + a[j] * a[j + k + 1] * a[i + j + 1], dp[j][j + k].se * dp[j + k + 1][i + j].se), dp[j][i + j].se %= mod;
                }
            }
        }
        dp[0][n - 1].se %= mod;
        if(q == 1)
            cout << dp[0][n - 1].fi << endl;
        else
            cout << (dp[0][n - 1].se + mod) % mod << endl;
    }
    else {
        ll dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n - i; ++j) {
                for(int k = 0; k < i; ++k)
                    dp[j][i + j] += dp[j][j + k] * dp[j + k + 1][i + j], dp[j][i + j] %= mod;
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    return 0;
}