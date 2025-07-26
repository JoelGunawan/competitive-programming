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
  int a, m, p, q, r, s;
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  a = rng() % 1000;
  m = rng() % 10;
  const int lim = 1e9;
  p = rng() % lim;
  q = rng() % lim;
  if(p > q)
    swap(p, q);
  
  r = rng() % lim;
  s = rng() % lim;
  if(r > s)
    swap(r, s);
  ++a, ++m, ++p, ++q, ++r, ++s;
  cout << a << " " << m << " " << p << " " << q << " " << r << " " << s << endl;
  cout << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
  return 0;
}