#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // state
    int dp[n + 1];
    // base case
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    // transisi
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 6; ++j) {
            if(i - j >= 0)
                dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
}