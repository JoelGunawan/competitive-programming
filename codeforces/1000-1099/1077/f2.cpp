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
  int n, k, x;
  cin >> n >> k >> x;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // dp[n][x] = dp[n - i][x - 1] + a[n], i <= k
  // how to maintain max in queue in O(1)?
  // make a deque
  // actually, we can just use a vector as a queue (duh)
  // fi -> index, se -> value
  vector<pair<int, ll>> v[x + 1];
  int idx[x + 1];
  memset(idx, 0, sizeof(idx));
  ll dp[x + 1];
  for(int i = 0; i <= x; ++i)
    v[i].pb(mp(0, 0));
  for(int i = 1; i <= n; ++i) {
    memset(dp, -1, sizeof(dp));
    for(int j = 1; j <= x; ++j) {
      if(idx[j - 1] >= v[j - 1].size())
        continue;
      dp[j] = v[j - 1][idx[j - 1]].se + a[i];
    }
    for(int j = 0; j <= x; ++j) {
      // cerr << dp[j] << " ";
      if(dp[j] != -1) {
        while(v[j].size() && dp[j] > v[j].back().se) 
          v[j].pop_back();
        v[j].pb(mp(i, dp[j]));
        idx[j] = min(idx[j], (int)v[j].size() - 1); 
      }
      if(idx[j] < v[j].size() && v[j][idx[j]].fi <= i - k)
        ++idx[j];
    }
    // cerr << endl;
  }
  if(idx[x] >= v[x].size())
    cout << -1 << endl;
  else
    cout << v[x][idx[x]].se << endl;
  return 0;
}