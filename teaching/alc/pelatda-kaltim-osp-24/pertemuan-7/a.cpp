#include <bits/stdc++.h>
using namespace std;
int h[1005], v[1005];
int memo[1005][100005];
/*
int dp(int i, int j) {
  if(j < 0) {
    return -1e9; // -10^9
  }
  if(i == 0) {
    return 0;
  }
  else {
    if(memo[i][j] != -1)
      return memo[i][j];
    else {
      //cout << dp(i - 1, j) << " " << dp(i - 1, j - h[i]) + v[i] << endl;
      memo[i][j] = max(dp(i - 1, j), dp(i - 1, j - h[i]) + v[i]);
      return memo[i][j];
    }
  }
}
*/
int main() {
  // n barang, uangnya ada m
  // memset(memo, -1, sizeof(memo));
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for(int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  // cout << dp(n, m) << endl;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      memo[i][j] = memo[i - 1][j];
      if(j >= h[i])  {
        memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - h[i]] + v[i]);
      }
    }
  }
  cout << memo[n][m] << endl;
}