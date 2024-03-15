#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    // sort(c + index_awal, c + index_akhir + 1);
    // reverse(c + index_awal, c + index_akhir + 1);
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    int dp[x + 1];
    for(int i = 1; i <= x; ++i)
        dp[i] = 1e9;
    dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    for(int i = 0; i <= x; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i + c[j] <= x) {
                dp[i + c[j]] = min(dp[i] + 1, dp[i + c[j]]);
            }
        }
    }
    if(dp[x] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}