// header file
#include <bits/stdc++.h>
// macros
#define ll unsigned long long
#define endl "\n"
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[2 * n + 10];
  memset(a, 0, sizeof(a));
  for(long long i = 1; i <= n; ++i)
    cin >> a[i];
  // either choose to "buy" or choose to "not buy"
  // should be some form of dp
  // if we choose a number x to unlock then we find the cost of dp[x] 
  // where x is the right most unlocked position
  // choose buy -> right most unlocked position add by a[i]
  // choose not buy -> add a[i] to result
  // find out whether you can make sum exactly x and find the result
  // how to find if we can make sum exactly x?
  // we can find the sums we can make through adding every possible previous sum
  // with the new sum we insert
  // problem: O(N^2)
  // find whether we can make a sum of x
  // use bitset opt
  ll dp[5][(2 * n) / 64 + 10];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 2;
  long long pref[2 * n + 10];
  memset(pref, 0, sizeof(pref));
  for(long long i = 1; i <= n; ++i)
    pref[i] = pref[i - 1] + a[i];
  for(long long i = n + 1; i <= 2 * n; ++i)
    pref[i] = pref[i - 1];
  long long res = 0;
  for(long long i = 1; i <= 2 * n; ++i) {
    long long c1 = a[i] / 64, c2 = a[i] % 64;
    for(long long j = 0; j <= (2 * n) / 64; ++j) {
      dp[i & 1][j] = dp[(i - 1) & 1][j];
      if(a[i] == 0)
        continue;
      if(i <= n && j - c1 >= 0) {
        dp[i & 1][j] |= (ll)(dp[(i - 1) & 1][j - c1] << (ll)c2);
      }
      if(i <= n && j - c1 - 1 >= 0 && c2 != 0) {
        dp[i & 1][j] |= (ll)(dp[(i - 1) & 1][j - c1 - 1] >> (ll)(64 - c2));
      }
      // cout << "deb " << i << " " << j << " " << dp[i & 1][j] << endl;
    }
    if((ll)dp[i & 1][i / 64] & (ll)((ll)1 << (ll)(i % 64))) {
      // cout << "trigger res " << i << endl;
      if(pref[i] + 1 - i < 0) {
        cout << "ERROR: " << i << " " << pref[i] << endl;
      }
      res = max(res, pref[i] - i + 1);
      dp[i & 1][i / 64] ^= (ll)((ll)1 << (ll)(i % 64));
    }
    // observe thate must set the previous ones to 0
    // cout << "reset " << i << " " << i / 64 << " " << dp[i & 1][i / 64] << endl;
  }
  cout << res << endl;
  return 0;
}