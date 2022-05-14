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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // intinya dp antara pilih cur atau prev
    ll dp[n][2];
    for(int i = 0; i < n; ++i)
        dp[i][0] = 1e15, dp[i][1] = 1e15;
    dp[0][1] = a[0];
    for(int i = 1; i < n; ++i) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][0] = dp[i - 1][1];
    }
    ll res = min(dp[n - 1][0], dp[n - 1][1]);
    for(int i = 0; i < n; ++i)
        dp[i][0] = 1e15, dp[i][1] = 1e15;
    dp[0][0] = a[n - 1];
    for(int i = 1; i < n - 1; ++i) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][0] = dp[i - 1][1];
    }
    res = min(res, min(dp[n - 2][0], dp[n - 2][1]));
    cout << res << endl;
    return 0;
}