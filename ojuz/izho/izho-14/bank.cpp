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
  int a[n + 1], b[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 0; i < m; ++i) 
    cin >> b[i];
  pair<int, int> dp[1 << m];
  // dp[i] -> max progress
  dp[0] = mp(1, 0);
  for(int i = 1; i < 1 << m; ++i) {
    dp[i] = mp(0, 0);
    for(int j = 0; j < m; ++j) {
      if((1 << j) & i) {
        dp[i] = max(dp[i], mp(dp[i ^ (1 << j)].fi, dp[i ^ (1 << j)].se + b[j]));
        // cout << i << " " << dp[i].fi << " " << dp[i].se << endl;
        if(dp[i].fi <= n && dp[i].se == a[dp[i].fi])
          ++dp[i].fi, dp[i].se = 0;
      }
    }
  }
  if(dp[(1 << m) - 1].fi == n + 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}