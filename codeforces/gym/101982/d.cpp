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
int mod = 1e9 + 9;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int k, b;
  cin >> k >> b;
  // use digit dp
  // maintain the number of possibilities and the number of carry it contains?
  // maintain states for the last k binary digits?
  int mlim = 1 << 11;
  ll dp[2][mlim][b + 1];
  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = dp[0][k][k & 1] = 1;
  ll res = 0;
  for (int i = 0; i < b; ++i) {
    int cur = i & 1, nx = cur ^ 1;
    for (int mask = 0; mask < mlim; ++mask) {
      for (int j = 0; j <= b; ++j)
        dp[nx][mask][j] = 0;    
    }
    for (int mask = 0; mask < mlim; ++mask) {
      for (int j = 0; j <= b; ++j) {
        if (dp[cur][mask][j] == 0) continue;
        int nm = mask >> 1;
        if (mask > 0 && nm == 0) {
          res += dp[cur][mask][j] * j;
        } 
        dp[nx][nm][j + (nm & 1)] += dp[cur][mask][j];
        if (dp[nx][nm][j + (nm & 1)] >= mod) {
          dp[nx][nm][j + (nm & 1)] -= mod;
        }
        nm = (mask >> 1) + k;
        dp[nx][nm][j + (nm & 1)] += dp[cur][mask][j];
        if (dp[nx][nm][j + (nm & 1)] >= mod) {
          dp[nx][nm][j + (nm & 1)] -= mod;
        }
      }
    }
  } 
  cout << res % mod << endl;
  return 0;
}