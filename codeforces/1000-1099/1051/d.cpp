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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    // dp state:
    // dp[pos][k][mask]
    ll dp[2][k + 1][4];
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;
    dp[0][2][1] = 1;
    dp[0][2][2] = 1;
    dp[0][1][3] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= k; ++j) {
            dp[i % 2][j][0] = (dp[(i - 1) % 2][j][0] + dp[(i - 1) % 2][j][1] + dp[(i - 1) % 2][j][2] + dp[(i - 1) % 2][j - 1][3]) % mod;
            dp[i % 2][j][1] = (dp[(i - 1) % 2][j][1] + dp[(i - 1) % 2][j - 1][0] + dp[(i - 1) % 2][j - 1][3]) % mod; 
            dp[i % 2][j][2] = (dp[(i - 1) % 2][j][2] + dp[(i - 1) % 2][j - 1][0] + dp[(i - 1) % 2][j - 1][3]) % mod; 
            dp[i % 2][j][3] = (dp[(i - 1) % 2][j][0] + dp[(i - 1) % 2][j][1] + dp[(i - 1) % 2][j][2] + dp[(i - 1) % 2][j - 1][3]) % mod;
            if(j > 1) {
                dp[i % 2][j][1] += dp[(i - 1) % 2][j - 2][2];
                dp[i % 2][j][1] %= mod;
                dp[i % 2][j][2] += dp[(i - 1) % 2][j - 2][1];
                dp[i % 2][j][2] %= mod;
            }
        }
    }
    cout << (dp[(n - 1) % 2][k][0] + dp[(n - 1) % 2][k][1] + dp[(n - 1) % 2][k][2] + dp[(n - 1) % 2][k][3]) % mod << endl;
    return 0;
}