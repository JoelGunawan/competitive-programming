// header file
#include <bits/stdc++.h>
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
ll sqr(ll a) {
    return a * a;
}
void tc() {
    int n;
    cin >> n;
    ll a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    ll dp[n + 1][n * 100 + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int cur_sum = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n * 100; ++j) {
            // di sekarang kita tuker
            dp[i][j] = LLONG_MAX;
            if(j >= b[i] && dp[i - 1][j - b[i]] != -1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + (j - b[i]) * b[i] + (cur_sum - (j - b[i])) * a[i]);
            // di sekarang kita gak tuker
            if(j >= a[i] && dp[i - 1][j - a[i]] != -1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + (j - a[i]) * a[i] + (cur_sum - (j - a[i])) * b[i]);
            if(dp[i][j] == LLONG_MAX)
                dp[i][j] = -1;
        }
        cur_sum += a[i] + b[i];
    }
    //for(int i = 1; i <= n; ++i) {
    //    for(int j = 0; j <= n * 10; ++j)
    //        cout << dp[i][j] << " ";
    //    cout << endl;
    //}
    ll res = LLONG_MAX;
    for(int i = 0; i <= n * 100; ++i)
        if(dp[n][i] != -1)
            res = min(res, dp[n][i]);
    res *= 2;
    for(int i = 1; i <= n; ++i)
        res += sqr(a[i]) * (n - 1) + sqr(b[i]) * (n - 1);
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}