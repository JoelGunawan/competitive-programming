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
long double posx, posy, movx, movy;
int t1, t2, t3, t4;
long double l, r, u, d;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  // given boundaries, binary search time of arrival and departure.
  // how to binary search?
  long double earliest = 0, latest = 1e100;
  cin >> l >> d >> r >> u;
  long double eps = 1e-12;
  cout << setprecision(15);
  for(int i = 1; i <= n; ++i) {
    // binary search the time when they will intersect
    cin >> t1 >> t2 >> t3 >> t4;
    posx = t1, posy = t2, movx = t3, movy = t4;
    // cin >> posx >> posy >> movx >> movy;
    if(abs(movx) < eps && abs(movy) < eps) {
      if(posx - eps > l && posx + eps < r && posy - eps > d && posy + eps < u) {

      }
      else {
        cout << -1 << endl;
        return 0;
      }
    }
    else {
      // just do normal stuff
      // need to check whether to move forwards/backwards
      bool dne = 0;
      long double cl = 0, cr = 1e5 / max({(long double)1.0, movx, movy}), e = 1e18, la = 0;
      while(cr - cl > eps) {
        long double mid = (cl + cr) / 2;
        long double curx = posx + movx * mid, cury = posy + movy * mid;
        // cerr << i << " " << mid << " " << curx << " " << cury << endl;
        if(curx - eps < l || curx + eps > r) {
          if(movx == 0)
            dne = 1;
          else if(curx - eps < l == movx > 0)
            cl = mid;
          else
            cr = mid;
        }
        else if(cury - eps < d || cury + eps > u) {
          if(movy == 0)
            dne = 1;
          else if(cury - eps < d == movy > 0)
            cl = mid;
          else
            cr = mid;
        }
        else {
          // inside
          e = min(e, mid);
          cr = mid;
        }
        if(dne)
          break;
      }
      if(dne) {
        cout << -1 << endl;
        return 0;
      }
      cl = 0, cr = 1e5 / max({(long double)1.0, movx, movy});
      while(cr - cl > eps) {
        long double mid = (cl + cr) / 2;
        long double curx = posx + movx * mid, cury = posy + movy * mid;
        if(curx - eps < l || curx + eps > r) {
          if(movx == 0)
            dne = 1;
          else if(curx - eps < l == movx > 0)
            cl = mid;
          else
            cr = mid;
        }
        else if(cury - eps < d || cury + eps > u) {
          if(movy == 0)
            dne = 1;
          else if(cury - eps < d == movy > 0)
            cl = mid;
          else
            cr = mid;
        }
        else {
          // inside
          la = max(la, mid);
          cl = mid;
        }
        if(dne)
          break;
      }
      earliest = max(earliest, e);
      latest = min(latest, la);
      // cerr << e << " " << la << endl;
    }
  }
  if(earliest < latest) {
    cout << earliest << endl;
  }
  else {
    cout << -1 << endl;
  }
  return 0;
}