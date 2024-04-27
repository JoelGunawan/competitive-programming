#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  // pair<T1, T2> p;
  // p.first -> T1
  // p.second -> T2
  // pair<T1, pair<T2, T3>>
  // p.first -> T1
  // p.second -> pair<T2, T3>
  // p.second.first -> T2
  // p.second.second -> T3
  pair<int, pair<int, int>> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].second.first >> a[i].first >> a[i].second.second;
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  // sortir berdasarkan b terkecil
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(j >= (a[i].second.first - a[i].first) && j + a[i].first <= m) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - (a[i].second.first - a[i].first)] + a[i].second.second);
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
      // cout << dp[i][j] << " ";
    }
    // cout << endl;
  }
  int mx = 0;
  for(int i = 0; i <= m; ++i) {
    mx = max(mx, dp[n][i]);
  }
  for(int i = 0; i <= m; ++i) {
    if(dp[n][i] == mx) {
      cout << mx << " " << m - i << endl;
      break;
    }
  }
}