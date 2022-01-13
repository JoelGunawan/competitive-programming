// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    int d[n + 1], a[n];
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    d[n] = l;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int dp[n + 1][k + 1];
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            dp[i][j] = 2e9;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            for(int it = 0; it <= j && it < i; ++it) {
                if(dp[i - it - 1][j - it] != 2e9)
                    dp[i][j] = min(dp[i][j], dp[i - it - 1][j - it] + a[i - it - 1] * (d[i] - d[i - it - 1]));
            }
        }
    }
    int res = 1e9;
    for(int i = 0; i <= k; ++i)
        res = min(res, dp[n][i]);
    /*
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    */
    cout << res << endl;
    return 0;
}