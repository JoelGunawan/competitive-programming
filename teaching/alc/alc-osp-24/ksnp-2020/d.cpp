#include <bits/stdc++.h>
using namespace std;
long long k(long long a) {
    return a * a;
}
int main() {
    int n;
    cin >> n;
    long long dp[n + 1], a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp[i] = 1e18;
        if(i >= 3) {
            dp[i] = min(dp[i], 3 * k(a[i - 2] - a[i]) + dp[i - 2]);
            dp[i] = min(dp[i], k(a[i - 1] - a[i - 2]) + 3 * k(a[i] - a[i - 2]) + dp[i - 1]);
        }
        dp[i] = min(dp[i], k(a[i] - a[i - 1]) + dp[i - 1]);
    }
    cout << dp[n] << endl;
}