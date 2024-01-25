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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    char a[n + 1][n + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // trap
            if(a[i][j] == '*') {
                dp[i][j] = 0;
            }
            // base case
            else if(i == 1 && j == 1) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}