#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    if(n == 1) {
        long long dp[m + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i = 2; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1];
            dp[i][1] = dp[i - 1][1] + 2 * dp[i - 1][0];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        cout << (dp[m][0] + dp[m][1]) % mod << endl;
    }
}