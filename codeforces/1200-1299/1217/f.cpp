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
int n, m;
const int lim = 2e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  vector<pair<int, int>> ops;
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  bool merge(int x, int y) {
    // cerr << "MERGE " << x << " " << y << endl;
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      h[y] = x;
      sz[x] += sz[y];
      ops.pb(mp(x, y));
    }
    else
      ops.pb(mp(-1, -1));
    return x != y;
  }
  bool rollback() {
    if(ops.size()) {
      if(ops.back() != mp(-1, -1)) {
        // cerr << "ROLLBACK " << ops.back().fi << " " << ops.back().se << endl;
        sz[ops.back().fi] -= sz[ops.back().se];
        h[ops.back().se] = -1;
      }
      else {
        // cerr << "ROLLBACK NOTHING" << endl;
      }
      ops.pop_back();
      return true;
    }
    else
      return false;
  }
} dsu;
const int lim2 = 1 << 18;
struct segtree {
  vector<pair<int, int>> updates[lim2 << 1];
  void update(int nd, int cl, int cr, int l, int r, pair<int, int> val) {
    // // cerr << nd << " " << cl << " " << cr << endl;
    if(cl >= l && cr <= r) {
      // // cerr << "STOP" << endl;
      // cerr << "UPDATED " << cl << " " << cr << " " << val.fi << " " << val.se << endl;
      updates[nd].pb(val);
    }
    else if(cl > r || cr < l) {
      // // cerr << "STOP" << endl;
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      update((nd << 1) | 1, mid + 1, cr, l, r, val);
    }
  }
  int nd = 1, cl = 0, cr = lim2 - 1;
  void query(int idx) {
    while(idx < cl || idx > cr) {
      // go to parent
      // // cerr << nd << " " << cl << " " << cr << " " << idx << endl;
      for(auto x : updates[nd])
        dsu.rollback();
      if(nd == (nd >> 1) << 1) {
        cr += cr - cl + 1;
      }
      else
        cl -= cr - cl + 1;
      nd >>= 1;
    }
    while(cl != cr) {
      int mid = (cl + cr) >> 1;
      if(idx <= mid) {
        // go left
        cr = mid, nd <<= 1;
      }
      else {
        cl = mid + 1, nd <<= 1, nd |= 1;
      }
      // cerr << "INSERTING " << nd << " " << cl << " " << cr << endl;
      for(auto x : updates[nd])
        dsu.merge(x.fi, x.se);
      // // cerr << "SE " << nd << " " << cl << " " << cr << " " << idx << endl;
    }
  }
} seg;
int mod(int x) {
  if(x <= 0)
    x += n;
  if(x == n + 1)
    return 1;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> m;
  pair<int, pair<int, int>> a[m];
  map<pair<int, int>, vector<int>> occur;
  for(int i = 0; i < m; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    if(x > y)
      swap(x, y);
    a[i] = mp(t, mp(x, y));
  }
  // // cerr << "HERE" << endl;
  for(int i = m - 1; i >= 0; --i) {
    if(a[i].fi == 2)
      continue;
    occur[a[i].se].pb(i);
    if(a[i].se.se == n)
      occur[mp(mod(a[i].se.se + 1), mod(a[i].se.fi + 1))].pb(i);  
    else
      occur[mp(mod(a[i].se.fi + 1), mod(a[i].se.se + 1))].pb(i);
  }
  // // cerr << "HERE2" << endl;
  for(auto &p : occur) {
    reverse(p.se.begin(), p.se.end());
    p.se.pb(m + 5);
  }
  // we know when the next occur of it exists, update to next occur
  // check -> update if need be
  vector<pair<int, int>> check[m + 10];
  set<pair<int, int>> s; // edges in set
  // // cerr << "HERE" << endl;
  int last = 0;
  for(int i = 0; i < m; ++i) {
    a[i].se.fi += last, a[i].se.se += last;
    a[i].se.fi = mod(a[i].se.fi), a[i].se.se = mod(a[i].se.se);
    if(a[i].se.fi > a[i].se.se)
      swap(a[i].se.fi, a[i].se.se);
    // // cerr << "DEBUG " << i << endl;
    // // cerr << a[i].se.fi << " " << a[i].se.se << endl;
    if(a[i].fi == 1) {
      // a[i].se.fi += last, a[i].se.se += last;
      for(auto x : check[i]) {
        if(x != a[i].se) {
          // extend
          // // cerr << "HERE " << " " << a[i].se.fi << " " << a[i].se.se << " " << x.fi << " " << x.se << endl;
          int nx = *ub(occur[x].begin(), occur[x].end(), i);
          seg.update(1, 0, lim2 - 1, i + 1, nx, x);
          check[nx].pb(x);
          // // cerr << "DONE" << endl;
        }
      }
      if(s.count(a[i].se)) {
        // erase
        // cerr << "ERASE " << a[i].se.fi << " " << a[i].se.se << endl;
        s.erase(a[i].se);
      }
      else {
        // insert
        // cerr << "INSERT " << a[i].se.fi << " " << a[i].se.se << endl;
        s.ins(a[i].se);
        // // cerr << "FINDING NX" << endl;
        // // cerr << occur[a[i].se].size() << " " << occur[a[i].se].back() << endl;
        int nx = *ub(occur[a[i].se].begin(), occur[a[i].se].end(), i);
        // // cerr << "BEFORE UPDATE " << endl;
        seg.update(1, 0, lim2 - 1, i + 1, nx, a[i].se);
        // // cerr << "POST " << nx << endl;
        check[nx].pb(a[i].se);
      }
    }
    else {
      seg.query(i);
      // cerr << a[i].se.fi << " " << a[i].se.se << " " << dsu.fh(a[i].se.fi) << " " << dsu.fh(a[i].se.se) << endl;
      last = dsu.fh(a[i].se.fi) == dsu.fh(a[i].se.se);
      cout << last;
    }
  }
  cout << endl;
  return 0;
}