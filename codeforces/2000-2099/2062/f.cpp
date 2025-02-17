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
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  return a.fi - a.se < b.fi - b.se;
}
void tc() {
  int n;
  cin >> n;
  pair<ll, ll> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi >> a[i].se;
  ll dp[2][n + 1][3];
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j <= n; ++j)
      for(int k = 0; k < 3; ++k)
        dp[i][j][k] = 1e18;
  for(int i = 1; i <= n; ++i)
    a[i].fi *= 2, a[i].se *= 2;
  sort(a + 1, a + n + 1, comp);
  // cerr << "OUT" << endl;
  // for(int i = 1; i <= n; ++i)
  //   cerr << a[i].fi << " " << a[i].se << endl;
  // cerr << "DONE" << endl;
  ll ans[n + 1];
  fill(ans, ans + n + 1, 1e18);
  // cerr << "DEBUG" << endl;
  for(int i = 1; i <= n; ++i) {
    int idx = i & 1;
    for(int j = 1; j <= n; ++j)
      for(int k = 0; k < 3; ++k)
          dp[idx][j][k] = 1e18;
    dp[idx][1][0] = min(dp[idx ^ 1][1][0], (a[i].fi + a[i].se) - (a[i].fi - a[i].se));
    dp[idx][1][1] = min(dp[idx ^ 1][1][1], (a[i].fi + a[i].se) / 2 - (a[i].fi - a[i].se) / 2);
    // cerr << dp[idx][1] << " ";
    for(int j = 2; j <= i; ++j) {
      dp[idx][j][0] = min(dp[idx ^ 1][j - 1][0] + a[i].fi + a[i].se, dp[idx ^ 1][j][0]);
      dp[idx][j][1] = min({dp[idx ^ 1][j - 1][1] + a[i].fi + a[i].se, 
        dp[idx ^ 1][j - 1][0] + (a[i].fi + a[i].se) / 2 + (a[i].fi - a[i].se) / 2,
        dp[idx ^ 1][j][1]});
      dp[idx][j][2] = min({dp[idx ^ 1][j - 1][1] + (a[i].fi + a[i].se) / 2 - (a[i].fi - a[i].se) / 2,
        dp[idx ^ 1][j - 1][2] + a[i].fi + a[i].se,
        dp[idx ^ 1][j][2]});
      // cerr << dp[idx][j] << " ";
      ans[j] = min({ans[j], dp[idx ^ 1][j - 1][1] + (a[i].fi + a[i].se) / 2 + (a[i].fi - a[i].se) / 2, 
        dp[idx ^ 1][j - 1][2] + (a[i].fi - a[i].se) + (a[i].fi + a[i].se)});
    }
    // cerr << endl;
  }
  // cerr << "DONE" << endl;
  for(int i = 2; i <= n; ++i)
    cout << ans[i] / 2 << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}