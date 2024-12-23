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
const int lim = 6e5 + 5;
ll cost = 0;
struct disjoint_set {
  int sz[lim], h[lim], szx[lim], szy[lim];
  vector<pair<int, int>> v;
  disjoint_set() {
    fill(sz, sz + lim, 1);
    memset(h, -1, sizeof(h));
    memset(szx, 0, sizeof(szx));
    memset(szy, 0, sizeof(szy));
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      v.pb(mp(x, y));
      h[y] = x;
      sz[x] += sz[y];
      cost -= 1ll * szx[x] * szy[x] + 1ll * szx[y] * szy[y];
      szx[x] += szx[y];
      szy[x] += szy[y];
      cost += 1ll * szx[x] * szy[x];
      // cerr << "MERGE " << x << " " << y << " " << cost << " " << szx[x] << " " << szy[x] << endl;
    }
    else
      v.pb(mp(-1, -1));
    return x != y;
  }
  bool rollback() {
    if(v.size()) {
      if(v.back() == mp(-1, -1))
        v.pop_back();
      else {
        int x = v.back().fi, y = v.back().se;
        h[y] = -1;
        cost -= 1ll * szx[x] * szy[x];
        szx[x] -= szx[y];
        szy[x] -= szy[y];
        cost += 1ll * szx[x] * szy[x] + 1ll * szx[y] * szy[y];
        sz[x] -= sz[y];
        // cerr << "ROLLBACK " << szx[x] << " " << szy[x] << endl;
        v.pop_back();
      }
      return true;
    }
    else
      return false;
  }
} dsu;
const int lim2 = 1 << 20;
struct segtree {
  vector<pair<int, int>> updates[lim2 << 1];
  void update(int nd, int cl, int cr, int l, int r, pair<int, int> val) {
    if(cl >= l && cr <= r) {
      updates[nd].pb(val);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      update((nd << 1) | 1, mid + 1, cr, l, r, val);
    }
  }
  void traverse(int nd, int cl, int cr, int last) {
    if(cl > last)
      return;
    else {
      for(auto x : updates[nd])
        dsu.merge(x.fi, x.se);
      int mid = (cl + cr) >> 1;
      if(cl == cr)
        cout << cost << " ";
      else {
        traverse(nd << 1, cl, mid, last);
        traverse((nd << 1) | 1, mid + 1, cr, last);
      }
      for(auto x : updates[nd])
        dsu.rollback();
    }
  }
} seg;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int q;
  cin >> q;
  pair<int, int> a[q];
  for(int i = 0; i < q; ++i) {
    cin >> a[i].fi >> a[i].se;
  }
  const int pad = 300000;
  for(int i = 0; i < q; ++i)
    a[i].fi += pad;
  set<pair<int, int>> s;
  map<pair<int, int>, int> pr, cnt;
  set<int> x[lim], y[lim];
  vector<pair<pair<int, int>, pair<int, int>>> updates;
  for(int i = 1; i <= pad; ++i)
    dsu.szx[i] = 1;
  for(int i = pad + 1; i <= 2 * pad; ++i)
    dsu.szy[i] = 1;
  // cerr << "HERE" << endl;
  for(int i = 0; i < q; ++i) {
    // cerr << i << endl;
    // cerr << i << endl;
    if(s.count(a[i])) {
      // erase
      s.erase(a[i]);
      vector<pair<int, int>> add, del;
      // if(x[a[i].fi].ub(a[i].se) != x[a[i].fi].end()) {
      //   del.pb(mp(a[i].se, (*x[a[i].fi].ub(a[i].se))));
      // }
      // if(x[a[i].fi].lb(a[i].se) != x[a[i].fi].begin()) {
      //   del.pb(mp(*--x[a[i].fi].lb(a[i].se), a[i].se));
      // }
      // if(x[a[i].fi].ub(a[i].se) != x[a[i].fi].end() && x[a[i].fi].lb(a[i].se) != x[a[i].fi].begin()) {
      //   add.pb(mp(*--x[a[i].fi].lb(a[i].se), *x[a[i].fi].ub(a[i].se)));
      // }
      // x[a[i].fi].erase(a[i].se);
      // if(y[a[i].se].ub(a[i].fi) != y[a[i].se].end()) {
      //   del.pb(mp(a[i].fi, *y[a[i].se].ub(a[i].fi)));
      // }
      // if(y[a[i].se].lb(a[i].fi) != y[a[i].se].begin()) {
      //   del.pb(mp(*--y[a[i].se].lb(a[i].fi), a[i].fi));
      // }
      // if(y[a[i].se].ub(a[i].fi) != y[a[i].se].end() && y[a[i].se].lb(a[i].fi) != y[a[i].se].begin()) {
      //   add.pb(mp(*--y[a[i].se].lb(a[i].fi), *y[a[i].se].ub(a[i].fi)));
      // }
      // y[a[i].se].erase(a[i].fi);
      del.pb(a[i]);
      for(auto x : add) {
        if(cnt[x] == 0) {
          pr[x] = i;
        }
        ++cnt[x];
        // cerr << "ADD " << x.fi << " " << x.se << " " << cnt[x] << endl;
      }
      for(auto x : del) {
        --cnt[x];
        if(cnt[x] == 0) {
          updates.pb(mp(mp(pr[x], i - 1), x));
        }
        // cerr << "DEL " << x.fi << " " << x.se << " " << cnt[x] << endl;
      }
    }
    else {
      pr[a[i]] = i;
      // insert edges and erase edges
      vector<pair<int, int>> add, del;
      // if(x[a[i].fi].ub(a[i].se) != x[a[i].fi].end()) {
      //   add.pb(mp(a[i].se, (*x[a[i].fi].ub(a[i].se))));
      // }
      // if(x[a[i].fi].lb(a[i].se) != x[a[i].fi].begin()) {
      //   add.pb(mp(*--x[a[i].fi].lb(a[i].se), a[i].se));
      // }
      // if(x[a[i].fi].ub(a[i].se) != x[a[i].fi].end() && x[a[i].fi].lb(a[i].se) != x[a[i].fi].begin()) {
      //   del.pb(mp(*--x[a[i].fi].lb(a[i].se), *x[a[i].fi].ub(a[i].se)));
      // }
      // x[a[i].fi].ins(a[i].se);
      // if(y[a[i].se].ub(a[i].fi) != y[a[i].se].end()) {
      //   add.pb(mp(a[i].fi, *y[a[i].se].ub(a[i].fi)));
      // }
      // if(y[a[i].se].lb(a[i].fi) != y[a[i].se].begin()) {
      //   add.pb(mp(*--y[a[i].se].lb(a[i].fi), a[i].fi));
      // }
      // if(y[a[i].se].ub(a[i].fi) != y[a[i].se].end() && y[a[i].se].lb(a[i].fi) != y[a[i].se].begin()) {
      //   del.pb(mp(*--y[a[i].se].lb(a[i].fi), *y[a[i].se].ub(a[i].fi)));
      // }
      // y[a[i].se].ins(a[i].fi);
      add.pb(a[i]);
      for(auto x : add) {
        if(cnt[x] == 0) {
          pr[x] = i;
        }
        ++cnt[x];
        // cerr << "ADD " << x.fi << " " << x.se << " " << cnt[x] << endl;
      }
      for(auto x : del) {
        --cnt[x];
        if(cnt[x] == 0) {
          updates.pb(mp(mp(pr[x], i - 1), x));
        }
        // cerr << "DEL " << x.fi << " " << x.se << " " << cnt[x] << endl;
      }
      s.ins(a[i]);
    }
  }
  for(auto x : cnt) {
    if(x.se)
      updates.pb(mp(mp(pr[x.fi], q - 1), x.fi));
  }
  for(auto p : updates) {
    // cerr << p.fi.fi << " " << p.fi.se << " " << p.se.fi << " " << p.se.se << endl;
    seg.update(1, 0, lim - 1, p.fi.fi, p.fi.se, p.se);
  }
  seg.traverse(1, 0, lim - 1, q - 1);
  cout << endl;
  return 0;
}