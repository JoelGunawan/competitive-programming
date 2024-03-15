#include <bits/stdc++.h>
using namespace std;
void tc() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    long long dp[n + 1][10001];
    for(int i = 0; i <= n; ++i)
        fill(dp[i], dp[i] + 10001, 1e9);
    int sumt = 0;
    long long kuadrat = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 10001; ++j) {
            if(j - a[i] >= 0 && sumt - j - b[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + a[i] * (j - a[i]) + b[i] * (sumt - j - b[i]));
            if(j - b[i] >= 0 && sumt - j - a[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + b[i] * (j - b[i]) + a[i] * (sumt - j - a[i]));
        }
        kuadrat += a[i] * a[i] + b[i] * b[i];
        sumt += a[i] + b[i];
    }
    long long res = 1e9;
    for(int i = 0; i < 10001; ++i) {
        res = min(res, dp[n][i]);
    }
    cout << 2 * res + kuadrat * (n - 1) << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
}