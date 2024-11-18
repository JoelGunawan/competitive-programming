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
  // m strongest heroes -> either picked/banned
  // then observe that only the m strongest heroes matter
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());
  int m;
  cin >> m;
  while(v.size() > m)
    v.pop_back();
  // actions: ...
  // only m largest matter, then choose pick/ban brute force
  reverse(v.begin(), v.end());
  int dp[2][1 << m];
  bool valid[m + 1][1 << m];
  fill(dp[0], dp[0] + (1 << m), 1e9);
  dp[0][0] = 0;
  memset(valid, 0, sizeof(valid));
  valid[0][0] = 1;
  vector<pair<char, int>> arr(m + 1);
  for(int i = 1; i <= m; ++i)
    cin >> arr[i].fi >> arr[i].se;
  reverse(arr.begin() + 1, arr.end());
  const int inf = 1e9, inf2 = 1e8 + 5;
  for(int i = 1; i <= m; ++i) {
    char c = arr[i].fi; int t = arr[i].se;
    // player 1: add score, maximize
    // player 2: subtract score, minimize
    for(int j = 0; j < 1 << m; ++j) {
      if(t == 1)
        dp[i & 1][j] = -inf;
      else
        dp[i & 1][j] = inf;
      // choose a submask of j and do the action (pick/ban)
      if(c == 'b') {
        for(int x = 0; x < m; ++x) {
          if(!((1 << x) & j))
            continue;
          if(abs(dp[(i - 1) & 1][j ^ (1 << x)]) > inf2)
            continue;
          if(t == 1)
            dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j ^ (1 << x)]);
          else
            dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j ^ (1 << x)]);
        }
      }
      else {
        for(int x = 0; x < m; ++x) {
          if(!((1 << x) & j))
            continue;
          if(abs(dp[(i - 1) & 1][j ^ (1 << x)]) > inf2)
            continue;
          if(t == 1)
            dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j ^ (1 << x)] + v[x]);
          else
            dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j ^ (1 << x)] - v[x]);
        }
      }
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }
  cout << dp[m & 1][(1 << m) - 1] << endl;
  return 0;
}