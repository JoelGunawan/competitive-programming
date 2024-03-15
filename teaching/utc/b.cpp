#include <bits/stdc++.h>
using namespace std;
// top down
int memo[1005];
int f(int x) {
  // base case
  cout << "f(" << x << ")" << endl;
  if(x == 0 || x == 1)
    return 1;
  else if(memo[x] != -1)
    return memo[x];
  else {
    memo[x] = f(x - 1) + f(x - 2);
    return memo[x]; 
  }
}
int main() {
  // set ke memo ke -1
  memset(memo, -1, sizeof(memo));
  cout << f(10) << endl;
  int dp[1005];
  // set base case
  dp[0] = dp[1] = 1;
  for(int i = 2; i <= 1000; ++i)
    // transisi
    dp[i] = dp[i - 1] + dp[i - 2];
  cout << dp[10] << endl;
}