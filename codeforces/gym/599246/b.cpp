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
  int n, m;
  cin >> n >> m;
  char a[n + 5][m + 5];
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  // when can 1 and 4 be in the same place?
  // all row
  // all col
  // otherwise -> count duplicate is easy
  ll dp[4][n + 5][m + 5];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      dp[0][i][j] = 1;
  ll res = 0;
  int nr[n + 1], nc[m + 1];
  memset(nr, 0, sizeof(nr));
  memset(nc, 0, sizeof(nc));
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(a[i][j] == '.') {
        ++nr[i], ++nc[j];
      }
  for(int i = 0; i < 3; ++i) {
    ll row[n + 1];
    ll col[m + 1];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int j = 1; j <= n; ++j) {
      for(int k = 1; k <= m; ++k) {
        if(a[j][k] == '#')
          continue;
        row[j] += dp[i][j][k];
        col[k] += dp[i][j][k];
        dp[i + 1][j][k] -= 2 * dp[i][j][k]; // prevent a -> a
        if(i == 0) // prevent a -> b -> a for rows and cols
          dp[i + 2][j][k] -= 1ll * (nr[j] - 1 + nc[k] - 1) * dp[i][j][k];
        if(i == 1) // prevent a -> b -> a for rows and cols. Problem: some return edges are already handled, the return is dp[i][j][k] - 1 (always)
        dp[i + 2][j][k] -= 1ll * (nr[j] - 1 + nc[k] - 1) * (dp[i][j][k] - 1);
      }
    }
    for(int j = 1; j <= n; ++j) {
      for(int k = 1; k <= m; ++k) {
        if(a[j][k] == '.') { 
          dp[i + 1][j][k] += row[j] + col[k];
          // cerr << i << " " << j << " " << k << " " << row[j] << " " << col[k] << " " << dp[i + 1][j][k] << endl;
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j)
      res += dp[3][i][j]; 
  }
  // cerr << res << endl;
  for(int i = 1; i <= n; ++i) {
    // cerr << i << " " << nr[i] << endl;
    res -= 1ll * nr[i] * (nr[i] - 1) * (nr[i] - 2);
  }
  for(int i = 1; i <= m; ++i) {
    // cerr << i << " " << nc[i] << endl;
    res -= 1ll * nc[i] * (nc[i] - 1) * (nc[i] - 2);
  }
  // cerr << res << endl;
  cout << res << endl;
  return 0;
}