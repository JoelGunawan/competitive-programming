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
    int n, u;
    cin >> n >> u;
    int a[n + 1], b[n + 1], x[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i] >> x[i];
    int dp[u + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= u; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i + b[j] <= u && i - a[j] + b[j] >= 0)
                dp[i] = max(dp[i], dp[i - a[j] + b[j]] + x[j]);
        }
    }
    int res = 0, idx = 0;
    for(int i = 0; i <= u; ++i) {
        if(dp[i] > res)
            res = dp[i], idx = i;
    }
    cout << res << " " << u - idx << endl;
    return 0;
}