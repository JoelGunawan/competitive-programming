#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  a[n + 1] = 2e9 + 5;

  int dp[n + 5];
  memset(dp, -1, sizeof(dp));
  dp[n + 1] = 0;
  int l = n + 1, r = n + 1;
  // l -> always i + m
  // r -> move until...
  multiset<int> s;
  for(int i = n - 1; i >= 1; --i) {
    l = i + m;
    while(a[r - 1] > a[i] + k) {
      if(r > l && dp[r] != -1) {
        s.erase(s.find(dp[r]));
      }
      --r;
    }

    if(l <= r) {
      if(dp[l] != -1) {
        s.insert(dp[l]);
      }
    }

    if(s.size()) {
      dp[i] = *--s.end() + 1;
    }
  }

  cout << dp[1] << endl;
  return 0;
}