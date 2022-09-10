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
    // dp top of rock
    // start from rock with lowest height
    int v, h, n;
    cin >> v >> h >> n;
    ll dp[v + 2][h + 2];
    bool rock[v + 2][h + 2];
    memset(dp, 0, sizeof(dp));
    memset(rock, 0, sizeof(rock));
    pair<pair<int, int>, pair<int, int>> a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
        for(int j = a[i].fi.fi; j <= a[i].se.fi; ++j)
            for(int k = a[i].fi.se; k <= a[i].se.se; ++k)
                rock[j][k] = 1;
    }
    sort(a, a + n);
    reverse(a, a + n);
    // mulai dari v1 paling besar
    for(int i = 0; i < n; ++i) {
        ll cur = dp[a[i].fi.fi - 1][a[i].fi.se - 1] + dp[a[i].fi.fi - 1][a[i].se.se + 1] + 1;
        for(int j = a[i].fi.se; j <= a[i].se.se; ++j) {
            for(int k = a[i].fi.fi - 1; k >= 0; --k) {
                if(rock[k][j])
                    break;
                else
                    dp[k][j] += cur;
            }
        }
    }
    /*
    for(int i = 0; i <= v; ++i) {
        for(int j= 1; j <= h; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    ll maxi = 0;
    for(int i = 1; i <= h; ++i) {
        maxi = max(maxi, dp[0][i]);
    }
    cout << maxi << endl;
    return 0;
}