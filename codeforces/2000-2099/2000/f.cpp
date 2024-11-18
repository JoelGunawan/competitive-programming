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
const ll inf = 1e18;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i] >> b[i];
    ll dp[n + 1][k + 1];
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j <= k; ++j)
        dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
      vector<int> cost;
      int cur = 0;
      for(;a[i] >= 0 && b[i] >= 0;) {
        cost.pb(cur);
        if(a[i] <= b[i]) {
          cur += a[i];
          --b[i];
        }
        else {
          cur += b[i];
          --a[i];
        }
      }
      // cout << "COST " << i << endl;
      // for(auto x : cost)
      //   cout << x << " ";
      // cout << endl;
      for(int j = 0; j <= k; ++j) {
        // consider for every coloring
        // 3 cases:
        // - color columns
        // - color rows
        // - color rows and columns
        // - color all
        // whichever is lower must be colored first
        // 1000 * 100 * 100 -> good
        for(int idx = 0; j - idx >= 0 && idx < cost.size(); ++idx)
          dp[i][j] = min(dp[i][j], dp[i - 1][j - idx] + cost[idx]);
      }
    }
    cout << (dp[n][k] == inf ? -1 : dp[n][k]) << endl;
  }
  return 0;
}