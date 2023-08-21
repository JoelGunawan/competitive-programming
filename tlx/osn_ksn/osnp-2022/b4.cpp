#include <bits/stdc++.h>
#define ll long long
int mod = 1e9 + 7;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    // n = 1
    // state 1 -> tile ke brp
    // state 2 -> atas/bawah
    // 0 -> atas
    // 1 -> bawah
    ll dp[m + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 1; i < m; ++i) {
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i + 1][1] += 2 * dp[i][0];
        dp[i + 1][0] += dp[i][0];
        dp[i + 1][1] += dp[i][1];
        dp[i + 1][0] += 2 * dp[i][1];
    }
    cout << (dp[m][0] + dp[m][1]) % mod << endl;
}