#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int h[n + 1], k[n + 1], d[n + 1];
  for(int i = 1; i <=  n; ++i)
    cin >> h[i] >> k[i] >> d[i];
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      // dosis rendah 
      if(d[i] == 0) {
        // max(dp[n - 1][m], dp[n][m - h[i]] + k[i])
        dp[i][j] = dp[i - 1][j];
        if(j >= h[i])
          dp[i][j] = max(dp[i][j], dp[i][j - h[i]] + k[i]);
      }
      // dosis tinggi
      else {
        // max(dp[n - 1][m], dp[n - 1][m - h[i]] + k[i])
        dp[i][j] = dp[i - 1][j];
        if(j >= h[i])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + k[i]);
      }
    }
  }
  cout << dp[n][m] << endl;
}