#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
const int lim = 2505;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};
struct segtree {
  // 2d segtree -> range update point query -> query each point, what segments
  vector<int> l, r, nx;
  vector<pair<unsigned ll, unsigned ll>> v;
  segtree() {
    add_node();
    add_node();
  }
  int add_node() {
    int cur = l.size();
    l.pb(-1), r.pb(-1), v.pb(mp(0, 0)), nx.pb(-1);
    return cur;
  }
  void update(int x1, int y1, int x2, int y2, pair<unsigned ll, unsigned ll> val) {
    update_x(1, 0, lim - 1, x1, y1, x2, y2, val);
  }
  void update_x(int nd, int cl, int cr, int x1, int y1, int x2, int y2, pair<unsigned ll, unsigned ll> val) {
    // cerr << "UX " << cl << " " << cr << endl;
    if(cl >= x1 && cr <= x2) {
      if(nx[nd] == -1)
        nx[nd] = add_node();
      update_y(nx[nd], 0, lim - 1, y1, y2, val);
    }
    else if(cl > x2 || cr < x1)
      return;
    else {
      int mid = (cl + cr) >> 1;
      if(l[nd] == -1)
        l[nd] = add_node();
      if(r[nd] == -1)
        r[nd] = add_node();
      update_x(l[nd], cl, mid, x1, y1, x2, y2, val);
      update_x(r[nd], mid + 1, cr, x1, y1, x2, y2, val);
    }
  }
  void update_y(int nd, int cl, int cr, int y1, int y2, pair<unsigned ll, unsigned ll> val) {
    // cerr << "UY " << cl << " " << cr << endl;
    if(cl >= y1 && cr <= y2) {
      v[nd].fi ^= val.fi;
      v[nd].se ^= val.se;
    }
    else if(cl > y2 || cr < y1)
      return;
    else {
      int mid = (cl + cr) >> 1;
      if(l[nd] == -1)
        l[nd] = add_node();
      if(r[nd] == -1)
        r[nd] = add_node();
      update_y(l[nd], cl, mid, y1, y2, val);
      update_y(r[nd], mid + 1, cr, y1, y2, val);
    }
  }
  void remove(int x1, int y1, int x2, int y2, pair<unsigned ll, unsigned ll> val) {
    remove_x(1, 0, lim - 1, x1, y1, x2, y2, val);
  }
  void remove_x(int nd, int cl, int cr, int x1, int y1, int x2, int y2, pair<unsigned ll, unsigned ll> val) {
    if(cl >= x1 && cr <= x2) {
      remove_y(nx[nd], 0, lim - 1, y1, y2, val);
    }
    else if(cl > x2 || cr < x1)
      return;
    else {
      int mid = (cl + cr) >> 1;
      remove_x(l[nd], cl, mid, x1, y1, x2, y2, val);
      remove_x(r[nd], mid + 1, cr, x1, y1, x2, y2, val);
    }
  }
  void remove_y(int nd, int cl, int cr, int y1, int y2, pair<unsigned ll, unsigned ll> val) {
    if(cl >= y1 && cr <= y2) {
      v[nd].fi ^= val.fi;
      v[nd].se ^= val.se;
    }
    else if(cl > y2 || cr < y1)
      return;
    else {
      int mid = (cl + cr) >> 1;
      remove_y(l[nd], cl, mid, y1, y2, val);
      remove_y(r[nd], mid + 1, cr, y1, y2, val);
    }
  }
  pair<unsigned ll, unsigned ll> query(int x, int y) {
    int cl = 0, cr = lim - 1;
    int ndx = 1;
    pair<unsigned ll, unsigned ll> ret = mp(0, 0);
    while(ndx != -1 && cl <= cr) {
      int mid = (cl + cr) >> 1;
      int ccl = 0, ccr = lim - 1, ndy = nx[ndx];
      while(ndy != -1 && l <= r) {
        int mid = (ccl + ccr) >> 1;
        ret.fi ^= v[ndy].fi;
        ret.se ^= v[ndy].se;
        if(y <= mid)
          ndy = l[ndy], ccr = mid;
        else
          ndy = r[ndy], ccl = mid + 1;
        // cerr << cl << " " << cr << endl;
      }
      if(x <= mid)
        ndx = l[ndx], cr = mid;
      else
        ndx = r[ndx], cl = mid + 1;
      // cerr << cl << " " << cr << endl;
    }
    return ret;
  }
} seg;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  pair<unsigned ll, unsigned ll> key[q + 1];
  mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count()); 
  for(int i = 0; i <= q; ++i)
    key[i] = mp(rng(), rng());
  map<pair<pair<int, int>, pair<int, int>>, pair<unsigned ll, unsigned ll>> a;
  while(q--) {
    int t, r1, c1, r2, c2;
    cin >> t >> r1 >> c1 >> r2 >> c2;
    if(t == 1)
      seg.update(r1, c1, r2, c2, key[q]), a[mp(mp(r1, c1), mp(r2, c2))] = key[q];
    else if(t == 2) 
      seg.remove(r1, c1, r2, c2, a[mp(mp(r1, c1), mp(r2, c2))]);
    else {
      // cerr << seg.query(r1, c1) << " " << seg.query(r2, c2) << endl;
      cout << (seg.query(r1, c1) == seg.query(r2, c2) ? "Yes" : "No") << endl;
    }
    // cerr << "HERE" << endl;
  }
  return 0;
}