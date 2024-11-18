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
  int n;
  cin >> n;
  pair<pair<int, int>, pair<int, int>> a[n + 1];
  for(int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[i] = mp(mp(x1, y1), mp(x2, y2));
    if(a[i].fi > a[i].se)
      swap(a[i].fi, a[i].se);
  }
  bool ans = 0;
  double res = 1e18;
  for(int i = 1; i <= n; ++i) {
    if(a[i].fi.fi < 0 && a[i].se.fi > 0) {
      // go through y axis
      int xdist = a[i].se.fi - a[i].fi.fi, ydist = a[i].se.se - a[i].fi.se;
      double md = (-a[i].fi.fi) * (double)ydist / xdist + a[i].fi.se;
      if(md > 0)
        ans = 1, res = min(res, md);
    }
  }
  if(!ans)
    cout << -1.0 << endl;
  else {
    cout << fixed << setprecision(5);
    cout << res << endl;
  }
  return 0;
}