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
  int x, y;
  cin >> x >> y;
  // s1 = x / 2 or s1 = y - x
  // s2 = y - x, (y - x / 2) / 2 or s2 = x - (y - x) = 2x - y
  // min between 2 * (x / 2 + y - x) or 2 * (y - x + 2 * x - y)
  double ans = 1e30;
  cout << fixed << setprecision(10);
  if(y - x > 0) {
    ans = min(ans, x + 2.0 * (y - x));
  }
  if(y - x > 0 && 2 * x - y > 0) {
    ans = min(ans, 2 * (2.0 * x - y) + 2 * (y - x));
  }
  if(y - x / 2.0 > 0)
    ans = min(ans, x + (y - x / 2.0));
  if(ans > 1e20)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}