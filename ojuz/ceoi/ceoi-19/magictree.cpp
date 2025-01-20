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
const int lim2 = 1 << 17;
struct node {
  int l = -1, r = -1;
  ll val = 0, lazy = 0;
};
struct segment_tree {
  vector<node> a = {node()};
  int new_node() {
    a.pb(node());
    return a.size() - 1;
  }
  void prop(int nd, int cl, int cr) {
    // assert(nd != -1);
    if(cl != cr) {
      if(a[nd].l != -1)
        a[a[nd].l].lazy += a[nd].lazy;
      if(a[nd].r != -1)
        a[a[nd].r].lazy += a[nd].lazy;
    }
    a[nd].val += a[nd].lazy;
    a[nd].lazy = 0;
  }
  void get_elems(vector<pair<int, ll>> &v, int nd = 0, int cl = 0, int cr = lim2 - 1) {
    if(nd == -1)
      return;
    prop(nd, cl, cr);
    if(cl == cr && a[nd].val != 0) {
      v.pb(mp(cl, a[nd].val));
      return; 
    }
    int mid = (cl + cr) >> 1;
    get_elems(v, a[nd].l, cl, mid);
    get_elems(v, a[nd].r, mid + 1, cr);
  }
  void update(int nd, int cl, int cr, int l, int r, ll val) {
    if(nd == -1)
      return;
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      a[nd].lazy += val;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(a[nd].l, cl, mid, l, r, val);
      update(a[nd].r, mid + 1, cr, l, r, val);
      if(a[nd].l != -1)
        a[nd].val = max(a[nd].val, a[a[nd].l].val);
      if(a[nd].r != -1)
        a[nd].val = max(a[nd].val, a[a[nd].r].val);
    }
  }
  void update_nn(int nd, int cl, int cr, int idx, ll val) {
    assert(nd >= 0);
    prop(nd, cl, cr);
    if(cl == cr) {
      a[nd].val = max(a[nd].val, val);
      prop(nd, cl, cr);
    }
    else {
      int mid = (cl + cr) >> 1;
      if(idx <= mid) {
        if(a[nd].l == -1) {
          a[nd].l = new_node();
        }
        update_nn(a[nd].l, cl, mid, idx, val);
        a[nd].val = max(a[nd].val, a[a[nd].l].val);
      }
      else {
        if(a[nd].r == -1) {
          a[nd].r = new_node();
        }
        update_nn(a[nd].r, mid + 1, cr, idx, val);
        a[nd].val = max(a[nd].val, a[a[nd].r].val);
      }
    }
  }
  ll query(int nd, int cl, int cr, int l, int r) {
    if(nd == -1)
      return 0;
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // cerr << nd << " " << cl << " " << cr << " " << a[nd].val << endl;
      return a[nd].val;
    }
    else if(cl > r || cr < l) {
      return 0;
    }
    else {
      int mid = (cl + cr) >> 1;
      return max(query(a[nd].l, cl, mid, l, r), query(a[nd].r, mid + 1, cr, l, r));  
    }
  }
};
const int lim = 1e5 + 5;
int cnt = 0;
vector<int> child[lim];
int d[lim], w[lim];
struct disjoint_set {
  int h[lim], sz[lim];
  segment_tree seg[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  void merge(int x, int y) {
    // cerr << "MERGING " << x << " " << y << endl;
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      vector<pair<int, ll>> v, v2;
      seg[y].get_elems(v);
      // if(cnt < 200 && (debug.size() == 1 || v.size() == 1)) {
      //  vector<pair<int, ll>> debug;
      //  seg[x].get_elems(debug);
      //   cerr << "OUTPUT" << endl;
      //   for(auto p : debug)
      //     cerr << p.fi << " " << p.se << endl;
      //   cerr << "-------" << endl;
      //   for(auto p : v) 
      //     cerr << p.fi << " " << p.se << endl;
      //   cerr << "-------" << endl;
      // }
      // sort(v.begin(), v.end());
      for(auto p : v) {
        // if(cnt < 200 && (debug.size() == 1 || v.size() == 1))
        //   cerr << p.fi << " " << p.se << " " << seg[x].query(0, 0, lim2 - 1, 0, p.fi) << endl; 
        v2.pb(mp(p.fi, p.se + seg[x].query(0, 0, lim2 - 1, 0, p.fi)));
      }
      // cerr << "DONE" << endl;
      ll pr = 0;
      for(auto p : v) {
        seg[x].update(0, 0, lim2 - 1, p.fi, lim2 - 1, max(0ll, p.se - pr));
        pr = max(pr, p.se);
      }
      for(auto p : v2) {
        // if(cnt < 200 && (debug.size() == 1 || v.size() == 1))
        //   cerr << p.fi << " " << p.se << endl; 
        seg[x].update_nn(0, 0, lim2 - 1, p.fi, p.se);
      }
      seg[y].a.clear();
      // if(cnt < 200 && (debug.size() == 1 || v.size() == 1)) {
      //   cerr << "---------" << endl;
      //   debug.clear();
      //   seg[x].get_elems(debug);
      //   for(auto p : debug)
      //       cerr << p.fi << " " << p.se << endl;
      //   cerr << "DONE" << endl;
      //   ++cnt;
      // }
    }
  }
} dsu;
void dfs(int nd) {
  ll val = 0;
  // if(nd <= 10) {
  //   cerr << "-------" << endl;
  //   cerr << "AT NODE " << nd << endl;
  // }
  for(auto x : child[nd]) {
    dfs(x);
    val += dsu.seg[dsu.fh(x)].query(0, 0, lim2 - 1, 0, d[nd]);
    dsu.merge(nd, x);
  }
  // cerr << nd << " " << d[nd] << " " << w[nd] << " " << val << " " << dsu.seg[dsu.fh(nd)].query(0, 0, lim2 - 1, 0, lim2 - 1) << endl;
  if(w[nd]) {
    dsu.seg[dsu.fh(nd)].update_nn(0, 0, lim2 - 1, d[nd], w[nd] + val);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    child[p].pb(i);
  }
  for(int i = 1; i <= m; ++i) {
    int v, a, b;
    cin >> v >> a >> b;
    d[v] = a, w[v] = b;
  }
  dfs(1);
  cout << dsu.seg[dsu.fh(1)].query(0, 0, lim2 - 1, 0, lim2 - 1) << endl;
  return 0;
}