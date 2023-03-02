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
    // cost: i + j - x
    // 2 at once: i + j - x (but do both at once)
    // 2 at once: same height diff
    // make height diff into complex
    // for one off, can use
    // save max int res of height diff
    // special case: launch same time, land diff coords
    // cur: x + y + acc
    // for init, harus manual cari
    // cari semua possibility launch
    // 1 only
    // 2 only
    // 1 and 2 together
    // start -> 1 and 2 together
    // cari target: if 1 and 2 together acuan ke 1 aja
    // 2 ngikut
    // launch -> set target dp to max result
    int n, d;
    cin >> n >> d;
    int a[2][n + 1], p[2][n + 1];
    for(int j = 0; j < 2; ++j) {
        for(int i = 1; i <= n; ++i)
            cin >> a[j][i];
        for(int i = 1; i <= n; ++i)
            cin >> p[j][i];
    }
    ll dp[n + 1][n + 1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = -1e18;
    ll one[n + 1], two[n + 1];
    for(int i = 0; i <= n; ++i)
        one[i] = two[i] = -1e18;
    map<ll, ll> heightdiff;
    map<ll, bool> vis;
    heightdiff[0] = 0;
    vis[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // haru
            dp[i][j] = max(dp[i][j], max({one[i] + p[1][j], two[j] + p[0][i]}) - d);
            int cur1 = a[0][i] + i, cur2 = a[1][i] + j;
            if(vis[cur1 - cur2]) {
                dp[i][j] = max(dp[i][j], heightdiff[i - j + a[0][i] - a[1][j]] + p[0][i] + p[1][j] - d);
            }
            if(i == j) {
                // masukkan ke height diff as special case
                heightdiff[cur1 - cur2] = max(dp[i][j], heightdiff[cur1 - cur2]);
                vis[cur1 - cur2] = 1;
            }
            one[i] = max(one[i], dp[i][j]);
            two[j] = max(two[j], dp[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    if(dp[n][n] < -1e13)
        cout << "Mustahil" << endl, exit(0);
    cout << dp[n][n] << endl;
    return 0;
}