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
int mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // form 1
        // MEX = 0 -> choose any amount of 1
        // form 2
        // MEX = X -> choose any amount of numbers Y such that Y < X
        // form 3
        // MEX = X -> choose any amount of numbers Y such that Y < X, then we can do decreasing
        // misal 000111122111 -> illegal
        // allowed move -> skip the current and done
        // misal 00002222 -> any sequence of 0 and 2 is allowed
        // 00002222000111 -> allowed
        ll dp[3][n + 5];
        // 3 state berbeda
        // state 0 -> mex = i + 1
        // state 1 -> mex = i - 1
        // state 2 -> mex = i + 1 BUT there is already i + 2 in the sequence
        /*
        4 
        0 2 1 0
        0
        0
        0 0
        0 2
        0 2 0
        0 1
        1
        */
        memset(dp, 0, sizeof(dp));
        ll res = 0;
        for(int i = 0; i < n; ++i) {
            // use case if a[i] = 0 and a[i] = 1
            if(a[i] == 0)
                dp[0][a[i]] = 2 * dp[0][a[i]] + 1; 
            else if(a[i] == 1) {
                dp[0][a[i]] = 2 * dp[0][a[i]] + dp[0][a[i] - 1];
                dp[1][a[i]] = 2 * dp[1][a[i]] + 1;
            }
            else {
                dp[0][a[i]] = 2 * dp[0][a[i]] + dp[0][a[i] - 1];
                dp[1][a[i]] = dp[1][a[i]] * 2 + dp[2][a[i] - 2] + dp[0][a[i] - 2];
            }
            dp[2][a[i]] = 2 * dp[2][a[i]] + dp[1][a[i] + 2];
            dp[0][a[i]] %= mod;
            dp[1][a[i]] %= mod;
            dp[2][a[i]] %= mod;
        }
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j <= n; ++j) {
                res = (res + dp[i][j]) % mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}