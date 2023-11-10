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
    int n, m, k;
    cin >> n >> m >> k;
    ll a[m + 1][n + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[j][i];
    ll pre[m + 1][n + 1];
    memset(pre, 0, sizeof(pre));
    // sebanyak km?
    ll ans[m + 1][n + 1];
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= m - k + 1; ++i) {
        for(int j = 0; j < k; ++j)
            for(int l = 1; l <= n; ++l) {
                pre[i + j][l] = max(pre[i + j][l], l == 1 ? max(ans[i + j - 1][n], pre[i + j - 1][n]) 
                : max(ans[i + j][l - 1], pre[i + j][l - 1]));
            }
        for(int j = 0; j < k; ++j) {
            for(int l = 1; l <= n; ++l) {
                //cout << "DEB " << pre[i + j][l] << " " << a[i + j][l] << endl;
                ans[i + j][l] = max(ans[i + j][l], pre[i + j][l] + a[i + j][l]);
                //cout << ans[i + j][l] << " ";
            }
            //cout << endl;
        }
        for(int j = 0; j < k; ++j)
            for(int l = 1; l <= n; ++l) {
                pre[i + j][l] = max(pre[i + j][l], l == 1 ? max(ans[i + j - 1][n], pre[i + j - 1][n]) 
                : max(ans[i + j][l - 1], pre[i + j][l - 1]));
            }
    }
    cout << max(pre[m][n], ans[m][n]) << endl;
    return 0;
}