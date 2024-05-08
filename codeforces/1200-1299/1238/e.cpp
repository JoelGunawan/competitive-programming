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
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  s = " " + s;
  // obs: important is number of pairs from a -> b that is in the string
  // m is 20 -> 2^20?
  // dp[m][mask] -> fill n first positions, 
  // find min value with precompute the negative
  int dp[m + 1][1 << m];
  int cnt[20][20];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 2; i <= n; ++i) {
    ++cnt[s[i] - 'a'][s[i - 1] - 'a'];
    ++cnt[s[i - 1] - 'a'][s[i] - 'a'];
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  vector<int> masks[m + 1];
  for(int i = 0; i < 1 << m; ++i) {
    int cnt = 0;
    for(int j = 0; j < m; ++j) {
      if((1 << j) & i)
        ++cnt;
    }
    masks[cnt].pb(i);
  }
  for(int i = 1; i <= m; ++i) {
    for(auto x : masks[i]) {
      vector<int> idx;
      for(int j = 0; j < m; ++j) {
        if((1 << j) & x)
          idx.pb(j);
      }
      // for all possible indices, check if that is what we insert last
      dp[i][x] = 1e9;
      for(auto y : idx) {
        // set y as inserted in the last position
        int change = 0;
        for(int j = 0; j < m; ++j) {
          if(j == y)
            continue;
          // alrdy in mask, add
          if((1 << j) & x) {
            change += cnt[j][y] * i; 
          }
          else {
            change -= cnt[j][y] * i;
          }
        }
        dp[i][x] = min(dp[i][x], dp[i - 1][x ^ (1 << y)] + change);
      }
    }
  }
  cout << dp[m][(1 << m) - 1] << endl;
}