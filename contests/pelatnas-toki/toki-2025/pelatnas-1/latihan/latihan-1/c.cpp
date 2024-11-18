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
  int n, h;
  cin >> n >> h;
  int r[n + 1], l[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> r[i] >> l[i];
  int dp[n + 1][n * 1000 + 1];
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= n * 1000; ++j)
      dp[i][j] = 1e9 + 5;
  }
  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= n * 1000; ++j) {
      dp[i][j] = dp[i - 1][j];
      if(j >= l[i])
        dp[i][j] = min(dp[i][j], dp[i - 1][j - l[i]] + r[i]);
    }
  }
  int res;
  for(int i = 0; i <= n * 1000; ++i)
    if(dp[n][i] <= h)
      res = i;
  cout << res << endl;
  int x = n, y = res;
  vector<int> v;
  while(x != 0) {
    if(dp[x][y] == dp[x - 1][y])
      --x;
    else {
      v.pb(x);
      y -= l[x], --x;
    }
  }
  cout << v.size() << endl;
  for(auto x : v)
    cout << x << " ";
  cout << endl;
  return 0;
}