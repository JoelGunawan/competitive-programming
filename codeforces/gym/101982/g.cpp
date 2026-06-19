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
ll sqr(ll a) {
  return a * a;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  double gx, gy, x1, y1, x2, y2;
  cin >> gx >> gy >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(3);
  if (x1 > x2)
    swap(x1, x2);
  if (y1 > y2)
    swap(y1, y2);
  if (x1 <= gx && gx <= x2) {
    cout << min(abs(gy - y1), abs(gy - y2)) << endl;
  } else if (y1 <= gy && gy <= y2) {
    cout << min(abs(gx - x1), abs(gx - x2)) << endl;
  } else {
    // find closest corner
    cout << sqrt(sqr(min(abs(gy - y1), abs(gy - y2))) + sqr(min(abs(gx - x1), abs(gx - x2)))) << endl;
  }
  return 0;
}