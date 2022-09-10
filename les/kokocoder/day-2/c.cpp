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
    int n;
    cin >> n;
    int h[2][n];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < n; ++j)
            cin >> h[i][j];
    }
    ll dp[2][n];
    dp[0][0] = h[0][0];
    dp[1][0] = h[1][0];
    for(int i = 1; i < n; ++i) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + h[0][i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + h[1][i]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    return 0;
}