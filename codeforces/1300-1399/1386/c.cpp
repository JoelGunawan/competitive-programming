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
const int lim = 2e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  bool par[lim], cycle[lim];
  int cnt = 0;
  // x, y
  vector<pair<int, int>> rb;
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
    memset(par, 0, sizeof(par));
    memset(cycle, 0, sizeof(cycle));
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  bool get_par(int nd) {
    return h[nd] == -1 ? par[nd] : par[nd] ^ get_par(h[nd]);
  }
  void merge(int x, int y) {
    int xh = fh(x), yh = fh(y);
    // cerr << "MERGE " << x << " " << y << endl;
    if(xh != yh) {
      if(sz[xh] < sz[yh])
        swap(xh, yh);
      if(get_par(x) == get_par(y))
        par[yh] = 1;
      h[yh] = xh;
      sz[xh] += sz[yh];
      rb.pb(mp(xh, yh));
    }
    else {
      if(get_par(x) == get_par(y)) {
        // cerr << "THIS HAPPENED" << endl;
        // cerr << x << " " << y << endl;
        cycle[xh] = 1;
        rb.pb(mp(xh, xh));
        ++cnt;
      }
      else {
        rb.pb(mp(-1, -1));
      }
    }
  }
  void merge(pair<int, int> a) {
    merge(a.fi, a.se);
  }
  void rollback() {
    if(rb.size()) {
      if(rb.back() != mp(-1, -1)) {
        pair<int, int> cur = rb.back();
        if(cur.fi == cur.se) {
          --cnt;
          cycle[cur.fi] = 0;
        }
        else {
          h[cur.se] = -1;
          sz[cur.fi] -= sz[cur.se];
          par[cur.se] = 0;
        }
      }
      rb.pop_back();
    }
  }
  void clear() {
    while(rb.size())
      rollback();
  }
} dsu;
const int lim2 = 1 << 18;
int ans[lim];
pair<int, int> adj[lim2];
struct segtree {
  int cur_right;
  segtree() {

  }
  void query(int nd, int cl, int cr, int l, int r) {
    if(cl > r || cr < l)
      return;
    // cerr << "QUERY" << endl;
    int init_size = dsu.rb.size();
    if(cl == cr) {
      // one point only
      dsu.merge(adj[cl]);
      // cerr << "ADD " << cl << endl;
      int ocr = cur_right;
      while(cur_right > 0) {
        --cur_right;
        dsu.merge(adj[cur_right]);
        // cerr << cl << " " << dsu.rb.size() << endl;
        // if(cl == 0) {
        //   for(auto p : dsu.rb)
        //     cerr << p.fi << " " << p.se << endl;
        // }
        // cerr << "TRY MERGE " << cur_right << " " << dsu.cnt << endl;
        if(dsu.cnt > 0) {
          ++cur_right;
          dsu.rollback();
          break;
        }
      }
      // cerr << "DEB " << cl << " " << cur_right << endl;
      ans[cl] = cur_right;
      while(cur_right < ocr)
        ++cur_right, dsu.rollback();
      dsu.rollback(); // for current
    }
    else {
      // check right and check left
      int csz = dsu.rb.size();
      for(int i = cl; i <= cr; ++i)
        dsu.merge(adj[i]);
      int ocr = cur_right;
      while(cur_right > 0) {
        --cur_right;
        dsu.merge(adj[cur_right]);
        if(dsu.cnt > 0) {
          ++cur_right;
          dsu.rollback();
          break;
        }
      }
      for(int i = 0; i < ocr - cur_right; ++i)
        dsu.rollback();
      for(int i = cl; i <= cr; ++i)
        dsu.rollback();
      int ncr = cur_right; 
      cur_right = ocr;
      assert(csz == dsu.rb.size());
      while(cur_right > ncr) {
        --cur_right;
        dsu.merge(adj[cur_right]);
      }
      // insert all lc
      int mid = (cl + cr) >> 1;
      for(int i = cl; i <= mid; ++i)
        dsu.merge(adj[i]);
      query((nd << 1) | 1, mid + 1, cr, l, r);
      for(int i = cl; i <= mid; ++i) 
        dsu.rollback();
      query((nd << 1), cl, mid, l, r);
      while(cur_right < ocr)
        dsu.rollback(), ++cur_right;
    }
    // cerr << "DONE" << endl;
    int end_size = dsu.rb.size();
    assert(init_size == end_size);
  }
} seg;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  adj[0] = mp(0, lim - 1);
  for(int i = 1; i <= m; ++i) {
    cin >> adj[i].fi >> adj[i].se;
  }
  for(int i = m + 1; i < lim2; ++i)
    adj[i] = mp(0, lim - 1);
  seg.cur_right = m + 2;
  seg.query(1, 0, lim2 - 1, 0, m - 1);
  // for(int i = 0; i < m; ++i)
  //   cerr << ans[i] << " ";
  // cerr << endl;
  for(int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    if(y + 1 >= ans[x - 1])
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}