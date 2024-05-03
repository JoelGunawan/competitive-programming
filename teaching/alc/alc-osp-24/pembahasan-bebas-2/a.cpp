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
    else {
        long long dp[m + 1][4];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][1] = 2;
        dp[1][2] = 1;
        dp[1][3] = 1;
        for(int i = 2; i <= m; ++i) {
          dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1] + 3 * dp[i - 1][2] + 4 * dp[i - 1][3];
          dp[i][1] = 3 * dp[i - 1][0] + 2 * dp[i - 1][1] + 7 * dp[i - 1][2] + 3 * dp[i - 1][3];
          dp[i][2] = 2 * dp[i - 1][0] + 4 * dp[i - 1][1] + 2 * dp[i - 1][2] + 2 * dp[i - 1][3];
          dp[i][3] = 4 * dp[i - 1][0] + 2 * dp[i - 1][1] + 3 * dp[i - 1][2] + dp[i - 1][3];
          dp[i][0] %= mod;
          dp[i][1] %= mod;
          dp[i][2] %= mod;
          dp[i][3] %= mod;
        }
        cout << (dp[m][0] + dp[m][1] + 2 * dp[m][2] + dp[m][3]) % mod << endl;
    }
}