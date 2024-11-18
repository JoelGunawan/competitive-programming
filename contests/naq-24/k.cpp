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
int score(int expect, int actual) {
  int diff = abs(expect - actual);
  if(diff <= 15)
    return 7;
  else if(diff <= 23)
    return 6;
  else if(diff <= 43)
    return 4;
  else if(diff <= 102)
    return 2;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int e[n + 1], a[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> e[i];
  for(int i = 1; i <= m; ++i)
    cin >> a[i];
  ll dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  // e -> expected
  // a -> actual
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      // skip expected
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      // skip actual
      dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      // take
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + score(e[i], a[j]));
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}