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
void tc() {
  int n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;

  pair<int, int> a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i].fi;
  for (int i = 1; i <= n; ++i) cin >> a[i].se;
  
  // only the top and bottom matters
  // top -> bottom or bottom -> top
  map<int, int> mn, mx;
  for (int i = 1; i <= n; ++i) {
    auto [x, y] = a[i];
    if (mn.find(x) == mn.end()) mn[x] = y;
    mn[x] = min(mn[x], y);
    mx[x] = max(mx[x], y);
  }  

  vector<pair<int, pair<int, int>>> vals;
  vals.emplace_back(ax, mp(ay, ay));
  for (auto [x, val] : mn) {
    vals.emplace_back(x, mp(val, mx[x]));
  }
  vals.emplace_back(bx, mp(by, by));
  sort(vals.begin(), vals.end());

  ll dp[vals.size()][2];
  dp[0][0] = dp[0][1] = 0;

  // cerr << vals[0].fi << " " << vals[0].se.fi << " " << vals[0].se.se << endl;
  for (int i = 1; i < vals.size(); ++i) {
    // cerr << vals[i].fi << " " << vals[i].se.fi << " " << vals[i].se.se << endl;
    // 0 -> bottom
    // 1 -> top
    dp[i][0] = dp[i][1] = 1e18;
    auto [bottom, top] = vals[i].se;
    
    // consider dp[i - 1][0]
    ll nxt = dp[i - 1][0] + vals[i].fi - vals[i - 1].fi;
    ll y = vals[i - 1].se.fi;
    // cerr << "deb " << nxt << " " << y << endl;
    dp[i][0] = min(dp[i][0], nxt + abs(y - top) + top - bottom);
    dp[i][1] = min(dp[i][1], nxt + abs(y - bottom) + top - bottom);

    nxt = dp[i - 1][1] + vals[i].fi - vals[i - 1].fi;
    y = vals[i - 1].se.se;
    // cerr << "deb " << nxt << " " << y << endl;
    dp[i][0] = min(dp[i][0], nxt + abs(y - top) + top - bottom);
    dp[i][1] = min(dp[i][1], nxt + abs(y - bottom) + top - bottom);
    // cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    // cerr << bottom << " " << top << endl;
  }

  cout << min(dp[vals.size() - 1][0], dp[vals.size() - 1][1]) << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    tc();
  }

  return 0;
}