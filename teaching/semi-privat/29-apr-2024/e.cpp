#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[405][405];
ll a[405];
ll f(int l, int r) {
  if(l == r) {
    return 0;
  }
  else if(dp[l][r] != -1) {
    return dp[l][r];
  }
  else {
    dp[l][r] = 5e18;
    for(int i = l; i < r; ++i) {
      dp[l][r] = min(dp[l][r], f(l, i) + f(i + 1, r));
    }
    ll cost = 0;
    for(int i = l; i <= r; ++i)
      cost += a[i];
    return dp[l][r] += cost;
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  cout << f(1, n) << endl;
  // dp yg harus bottom up:
  // dp data structures
  // dp ada prefix sum
  // dp ada stack
  // dp ada segment tree
}