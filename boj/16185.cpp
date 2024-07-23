// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const ll inf = 1e18;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int cost[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> cost[i];
  ll dp[n + 1][k + 1][k + 1][3];
  for(int i = 0; i <= n; ++i) {
    for(int in = 0; in <= k; ++in) {
      for(int out = 0; out <= k; ++out) {
        for(int j = 0; j < 3; ++j) {
          dp[i][in][out][j] = 1e18;
        }
      }
    }
  }
  dp[0][0][0][1] = 0;
  for(int i = 1; i <= n; ++i) {
    for(int in = 0; in <= k; ++in) {
      for(int out = 0; out <= k; ++out) {
        dp[i][in][out][0] = min(min({dp[i - 1][in][out][0], dp[i - 1][in][out][1], dp[i - 1][in][out][2]}) + cost[i], out > 0 ? min({dp[i - 1][in][out - 1][0], dp[i - 1][in][out - 1][1], dp[i - 1][in][out - 1][2]}) : inf);
        dp[i][in][out][1] = min(dp[i - 1][in][out][0], in > 0 ? (dp[i - 1][in - 1][out][0] + cost[i]) : inf);
        dp[i][in][out][2] = min(dp[i - 1][in][out][1], in > 0 ? (dp[i - 1][in - 1][out][1] + cost[i]) : inf);
      }
    }
    // cerr << dp[i][0][0][0] << " ";
  }
  // cerr << endl;
  ll res = 1e18;
  for(int i = 0; i <= k; ++i) {
    // cout << min(dp[n][i][i][0], dp[n][i][i][1]) << endl;
    res = min({res, dp[n][i][i][0], dp[n][i][i][1]});
  }
  cout << res << endl;
  return 0;
}