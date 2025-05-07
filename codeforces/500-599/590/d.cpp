#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k, s;
  cin >> n >> k >> s;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // if s > n^2 -> doesn't matter
  if (s > n * (n - 1) / 2) {
    s = n * (n - 1) / 2;
  }
  // dp[n][k][swaps] = min value
  int dp[2][k + 1][s + 1];
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j <= k; ++j) {
      for(int l = 0; l <= s; ++l) 
        dp[i][j][l] = 1e9;
    }
  }
  dp[0][0][0] = 0;
  int res = 1e9;
  for(int idx = 1; idx <= n; ++idx) {
    int pr = (idx & 1) ^ 1, cur = idx & 1;
    for(int j = 0; j <= k; ++j) {
      if(j > idx)
        continue;
      for(int l = 0; l <= s; ++l) {
        dp[cur][j][l] = dp[pr][j][l];
        if(j > 0 && l >= idx - j) {
          dp[cur][j][l] = min(dp[cur][j][l], dp[pr][j - 1][l - (idx - j)] + a[idx]);
          // cerr << "THIS CASE " << idx << " " << j << " " << l << " " << dp[cur][j][l] << endl;
          // cerr << j - 1 << " " << l - (idx - j - 1) << endl;
        }
        // cerr << idx << " " << j << " " << l << " " << dp[cur][j][l] << endl;
      }
    }
    for(int l = 0; l <= s; ++l)
      res = min(res, dp[cur][k][l]);
  }
  cout << res << endl;
  return 0;
}