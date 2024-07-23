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
  int s, n;
  cin >> s >> n;
  // for each weight, get list of items that can actually be part of optimal
  vector<pair<int, int>> a[s + 1];
  for(int i = 1; i <= n; ++i) {
    int v, w, k;
    cin >> v >> w >> k;
    a[w].pb(mp(v, k));
  }
  // weight, value
  vector<pair<int, int>> items = {mp(0, 0)};
  for(int i = 1; i <= s; ++i) {
    sort(a[i].begin(), a[i].end());
    int cnt = 0, lim = s / i;
    while(a[i].size() && cnt < lim) {
      --a[i].back().se;
      items.pb(mp(i, a[i].back().fi));
      ++cnt;
      if(a[i].back().se == 0)
        a[i].pop_back();
    }
  }
  int dp[2][s + 1];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i < items.size(); ++i) {
    int cur = i & 1, pr = (i & 1) ^ 1;
    for(int j = 0; j <= s; ++j) {
      dp[cur][j] = dp[pr][j];
      if(j - items[i].fi >= 0)
        dp[cur][j] = max(dp[cur][j], dp[pr][j - items[i].fi] + items[i].se);
    }
  }
  cout << dp[(items.size() - 1) & 1][s] << endl;
  return 0;
}