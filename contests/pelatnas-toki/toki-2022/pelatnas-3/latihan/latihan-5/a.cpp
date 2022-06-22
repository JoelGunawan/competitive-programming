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
int cost[305][305], opcost[305][305][305], dp[305][305];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int w, l, r;
        cin >> w >> l >> r;
        cost[l][r] = w;
    }
    for(int lewat = 1; lewat <= n; ++lewat) {
        for(int l = lewat; l >= 1; --l) {
            for(int r = lewat; r <= n; ++r) {
                opcost[l][r][lewat] = max({cost[l][r], opcost[l + 1][r][lewat], opcost[l][r - 1][lewat]});
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i)
        dp[i][i] = cost[i][i], res = max(res, dp[i][i]);
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= n - i + 1; ++j) {
            int l = j, r = j + i - 1;
            for(int k = 0; k < i; ++k) {
                //cout << l << " " << l + k - 1 << " " << l + k + 1 << " " << r << " " << opcost[l][r][k] << endl;
                dp[l][r] = max({dp[l][r], dp[l][l + k - 1] + dp[l + k + 1][r] + opcost[l][r][k + l]});
            } 
            //cout << l << " " << r << " " << dp[l][r] << endl;
            res = max(res, dp[l][r]);
        }
    }
    cout << res << endl;
    return 0;
}