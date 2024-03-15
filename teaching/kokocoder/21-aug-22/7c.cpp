#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int memo[1005];
int solve(int n) {
    if(memo[n] != -1)
        return memo[n];
    else if(n <= 0)
        return 0;
    else {
        return memo[n] = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    }
}
int main() {
    int n;
    cin >> n;
    // n / 2 -> n >> 1
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof(memo));
    cout << solve(n) << endl;
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; ++i)
        dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
    cout << dp[n] << endl;
}