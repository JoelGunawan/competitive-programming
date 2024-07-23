// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  // do iterative bfs, count of ways
  ll dp[n + 2][m + 2][8];
  memset(dp, 0, sizeof(dp));
  char a[n + 1][m + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  string s = "YOKOHAMA";
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'Y')
        ++dp[i][j][0];
    }
  }
  ll res = 0;
  for(int it = 1; it < 8; ++it) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        if(a[i][j] == s[it])
          dp[i][j][it] += dp[i + 1][j][it - 1] + dp[i][j + 1][it - 1] + dp[i][j - 1][it - 1] + dp[i - 1][j][it - 1];
        if(it == 7)
          res += dp[i][j][it];
      }
    }
  }
  cout << res << endl;
  return 0;
}