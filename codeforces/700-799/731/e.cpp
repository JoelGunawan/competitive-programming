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
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int pref[n + 1];
  pref[0] = 0;
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }
  // use dp[i], the dp cost of doing from i ... n
  ll dp[n + 1][2];
  memset(dp, 0, sizeof(dp));
  ll cur_mn = dp[n][0] - pref[n], cur_mx = dp[n][1] + pref[n];
  for(int i = n - 1; i >= 1; --i) {
    // cost of dp[i][0] = dp[i + k][1] + pref[i + k]; maximize dp[i][0]
    // cost of dp[i][1] = dp[i + k][0] - pref[i + k]; minimize dp[i][1]
    dp[i][0] = cur_mx;
    dp[i][1] = cur_mn;
    cur_mx = max(cur_mx, dp[i][1] + pref[i]);
    cur_mn = min(cur_mn, dp[i][0] - pref[i]);
  }
  cout << dp[1][0] << endl;
  return 0;
}