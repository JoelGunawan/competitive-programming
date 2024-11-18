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
double sqr(double x) {
  return x * x;
}
double dist(double x1, double x2, double y1, double y2) {
  return sqrtl(sqr(x1 - y1) + sqr(x2 - y2));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  pair<double, double> a, b;
  int d;
  cin >> a.fi >> a.se >> b.fi >> b.se >> d;
  if(a.fi > b.fi)
    swap(a, b);
  // find longest right and find longest left
  cout << fixed << setprecision(10);
  // else two focus points, binary search right most point
  double l = b.fi, r = b.fi + 1e3;
  while(r - l > 1e-9) {
    double mid = (l + r) / 2;
    // check at mid, whether there is a point c such that dist(a, c) + dist(b, c) <= a
    double cl = -1e3 - 100, cr = 1e3 + 100;
    while(cr - cl > 1e-9) {
      double m1 = cl + (cr - cl) / 3, m2 = cl + (cr - cl) * 2 / 3; 
      if(dist(a.fi, a.se, mid, m1) + dist(b.fi, b.se, mid, m1) < dist(a.fi, a.se, mid, m2) + dist(b.fi, b.se, mid, m2))
        cr = m2;
      else
        cl = m1;
    }
    if(dist(a.fi, a.se, mid, cl) + dist(b.fi, b.se, mid, cl) > d)
      r = mid;
    else
      l = mid; 
  }
  double xh = l;
  l = a.fi - 1e3, r = a.fi;
  while(r - l > 1e-9) {
    double mid = (l + r) / 2;
    // check at mid, whether there is a point c such that dist(a, c) + dist(b, c) <= a
    double cl = -1e3 - 100, cr = 1e3 + 100;
    while(cr - cl > 1e-9) {
      double m1 = cl + (cr - cl) / 3, m2 = cl + (cr - cl) * 2 / 3; 
      if(dist(a.fi, a.se, mid, m1) + dist(b.fi, b.se, mid, m1) < dist(a.fi, a.se, mid, m2) + dist(b.fi, b.se, mid, m2))
        cr = m2;
      else
        cl = m1;
    }
    if(dist(a.fi, a.se, mid, cl) + dist(b.fi, b.se, mid, cl) > d)
      l = mid;
    else
      r = mid; 
  }
  double xl = l;
  l = min(a.se, b.se) - 1e3, r = min(a.se, b.se);
  while(r - l > 1e-9) {
    double mid = (l + r) / 2;
    // check at mid, whether there is a point c such that dist(a, c) + dist(b, c) <= a
    double cl = -1e3 - 100, cr = 1e3 + 100;
    while(cr - cl > 1e-9) {
      double m1 = cl + (cr - cl) / 3, m2 = cl + (cr - cl) * 2 / 3; 
      if(dist(a.fi, a.se, m1, mid) + dist(b.fi, b.se, m1, mid) < dist(a.fi, a.se, m2, mid) + dist(b.fi, b.se, m2, mid))
        cr = m2;
      else
        cl = m1;
    }
    if(dist(a.fi, a.se, cl, mid) + dist(b.fi, b.se, cl, mid) > d)
      l = mid;
    else
      r = mid; 
  }
  double yl = l;
  l = max(a.se, b.se), r = max(a.se, b.se) + 1e3;
  while(r - l > 1e-9) {
    double mid = (l + r) / 2;
    // check at mid, whether there is a point c such that dist(a, c) + dist(b, c) <= a
    double cl = -1e3 - 100, cr = 1e3 + 100;
    while(cr - cl > 1e-9) {
      double m1 = cl + (cr - cl) / 3, m2 = cl + (cr - cl) * 2 / 3; 
      if(dist(a.fi, a.se, m1, mid) + dist(b.fi, b.se, m1, mid) < dist(a.fi, a.se, m2, mid) + dist(b.fi, b.se, m2, mid))
        cr = m2;
      else
        cl = m1;
    }
    if(dist(a.fi, a.se, cl, mid) + dist(b.fi, b.se, cl, mid) > d)
      r = mid;
    else
      l = mid; 
  }
  double yh = l;
  cout << xl << " " << yl << " " << xh << " " << yh << endl;
  return 0;
}