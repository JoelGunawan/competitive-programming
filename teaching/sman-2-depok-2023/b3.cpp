#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int h[n + 1], k[n + 1], d[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i] >> k[i] >> d[i];
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            // d[i] = 0 -> dosis rendah
            dp[i][j] = dp[i - 1][j];
            // hati" -> j - h[i] < 0 -> error
            // j = 2, h[i] = 5
            // dp[i - 1][j - h[i]]
            // dp[0][-3]
            if(j - h[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + k[i]);
            if(d[i] == 0 && j - h[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - h[i]] + k[i]);
            }
        }
    }   
    int res = 0; 
    for(int i = 0; i <= m; ++i) {
        res = max(res, dp[n][i]);
    }
    cout << res << endl;
}