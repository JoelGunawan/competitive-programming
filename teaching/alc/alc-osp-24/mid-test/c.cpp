#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool correct[n];
  for(int i = 0; i < n; ++i) {
    if(s[i] == s[n - i - 1])
      correct[i] = true;
    else
      correct[i] = false;
  }
  if(s.size() <= 3) {
    if(correct[0])
      cout << 0 << endl;
    else
      cout << 1 << endl;
    return 0;
  }
  int dp[n][2];
  // utk posisi 0
  if(correct[0]) {
    dp[0][1] = 0;
    dp[0][0] = 1e9;
  }
  else {
    dp[0][1] = 1e9;
    dp[0][0] = 0;
  }
  for(int i = 1; i < n / 2; ++i) {
    if(correct[i]) {
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 2);
      // BB -> SS -> BS
      // SB -> BS
      dp[i][0] = min(dp[i - 1][1] + 2, dp[i - 1][0] + 1);
    }
    else {
      if(i == n / 2 - 1) {
        dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
        break;
      }
      dp[i][1] = min(dp[i - 1][1] + 2, dp[i - 1][0] + 1);
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + 1);
    }
    //cout << dp[i][0] << " " << dp[i][1] << endl;
  }
  cout << dp[n / 2 - 1][1] << endl;
}