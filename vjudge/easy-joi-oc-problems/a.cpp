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
    // given certain n, p, and w
    // find min q
    // if there is a valid answer, use that answer
    int n, p, q;
    cin >> n >> p >> q;
    int a[n + 1];
    if(p + q >= n) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e9, ans = 1e9;
    while(l <= r) {
        int mid = (l + r) >> 1;
        // calculate minimum p and minimum q
        int dp[n + 1][p + 1];
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= p; ++j)
                dp[i][j] = 1e9;
        dp[0][0] = 0;
        int lastp = 1, lastq = 1;
        for(int i = 1; i <= n; ++i) {
            while(a[i] - a[lastp] >= mid)
                ++lastp;
            while(a[i] - a[lastq] >= 2 * mid)
                ++lastq;
            for(int j = 0; j <= p; ++j) {
                // ambil q
                dp[i][j] = min(dp[i][j], dp[lastq - 1][j] + 1);
                // ambil p
                if(j != 0)
                    dp[i][j] = min(dp[i][j], dp[lastp - 1][j - 1]);
            }
        }
        int mn = 1e9;
        for(int i = 0; i <= p; ++i) {
            mn = min(mn, dp[n][i]);
        }
        if(mn <= q)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}