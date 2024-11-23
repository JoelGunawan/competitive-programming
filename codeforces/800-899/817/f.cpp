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
const int lim = 1 << 19;
// boolean segtree -> make true, make false, invert
// find first position of false
struct segment_tree {
  int a[2 * lim], lazy[2 * lim];
  segment_tree() {
    memset(a, 0, sizeof(a));
    memset(lazy, 0, sizeof(lazy));
  }
  // a -> count of 1 in segment
  // lazy:
  // - 0 -> no lazy
  // - 1 -> lazy set all to true
  // - 2 -> lazy set all to false
  // - 3 -> lazy invert
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      if(lazy[nd] == 1 || lazy[nd] == 2) {
        lazy[nd << 1] = lazy[(nd << 1) | 1] = lazy[nd];
      }
      else if(lazy[nd] == 3) {
        // depends on child
        // child 0 -> set to 3
        // child 1 -> set to 2
        // child 2 -> set to 1
        // child 3 -> set to 0
        lazy[nd << 1] = 3 - lazy[nd << 1];
        lazy[(nd << 1) | 1] = 3 - lazy[(nd << 1) | 1];
      }
    }
    if(lazy[nd] == 1)
      a[nd] = cr - cl + 1;
    else if(lazy[nd] == 2)
      a[nd] = 0;
    else if(lazy[nd] == 3)
      a[nd] = cr - cl + 1 - a[nd];
    lazy[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // cerr << "UPDATE " << cl << " " << cr << endl;
      lazy[nd] = val;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      update((nd << 1) | 1, mid + 1, cr, l, r, val);
      a[nd] = a[nd << 1] + a[(nd << 1) | 1];
      // cerr << (nd << 1) << " " << ((nd << 1) | 1) << " " << a[nd << 1] << " " << a[(nd << 1) | 1] << endl;
    }
    // cerr << cl << " " << cr << " " << a[nd] << endl;
  }
  int query(int nd, int cl, int cr) {
    prop(nd, cl, cr);
    if(cl == cr)
      return cl;
    int mid = (cl + cr) >> 1;
    // left full
    prop(nd << 1, cl, mid);
    if(mid - cl + 1 == a[nd << 1])
      return query((nd << 1) | 1, mid + 1, cr);
    else
      return query(nd << 1, cl, mid);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int q;
  cin >> q;
  vector<ll> coords;
  pair<int, pair<ll, ll>> que[q];
  for(int i = 0; i < q; ++i) {
    ll t, l, r;
    cin >> t >> l >> r;
    --l, --r; // make 0 based
    for(int j = -1; j <= 1; ++j)
      coords.pb(l + j), coords.pb(r + j);
    que[i] = mp(t, mp(l, r));
  }
  coords.pb(0);
  sort(coords.begin(), coords.end());
  reverse(coords.begin(), coords.end());
  while(coords.size() && coords.back() < 0)
    coords.pop_back();
  reverse(coords.begin(), coords.end());
  coords.resize(unique(coords.begin(), coords.end()) - coords.begin());
  segment_tree seg;
  for(auto p : que) {
    ll t = p.fi, l = p.se.fi, r = p.se.se;
    l = lb(coords.begin(), coords.end(), l) - coords.begin();
    r = lb(coords.begin(), coords.end(), r) - coords.begin();
    seg.update(1, 0, lim - 1, l, r, t);
    cout << coords[seg.query(1, 0, lim - 1)] + 1 << endl;
  }
  return 0;
}