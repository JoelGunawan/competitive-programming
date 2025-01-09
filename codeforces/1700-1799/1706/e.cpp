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
struct disjoint_set {
  vector<int> h, sz, val;
  disjoint_set(int n) {
    h = vector<int>(n, -1);
    sz = vector<int>(n, 1);
    val = vector<int>(n, 0);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  bool merge(int x, int y, int num) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y]) {
        swap(x, y);
      }
      sz[x] += sz[y];
      h[y] = x;
      val[y] = num;
    }
    return x != y;
  }
  int lca(int x, int y) {
    // go to lca
    vector<int> v1;
    int tmp = x;
    do {
      v1.pb(tmp);
      tmp = h[tmp];
    } while(tmp != -1);
    tmp = y;
    vector<int> v2;
    do {
      v2.pb(tmp);
      tmp = h[tmp];
    } while(tmp != -1);
    // take max both ways
    set<int> s;
    int ret = 0;
    for(auto x : v1)
      s.ins(x);
    for(auto x : v2) {
      if(s.count(x))
        break;
      ret = max(ret, val[x]);
    }
    s.clear();
    for(auto x : v2)
      s.ins(x);
    for(auto x : v1) {
      if(s.count(x))
        break;
      ret = max(ret, val[x]);
    }
    return ret;
  }
};
const int lim = 1 << 17;
struct segment_tree {
  int a[lim << 1];
  segment_tree() {
    memset(a, 0, sizeof(a));
  };
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      // cerr << "ANS " << nd << " " << cl << " " << cr << " " << a[nd] << endl;
      return a[nd];
    }
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
} seg;
void tc() {
  // KRT -> the MST based on merging, we know that the eventual MST
  // DSU -> make par edge the number
  int n, m, q;
  cin >> n >> m >> q;
  disjoint_set dsu(n + 5);
  // cerr << "TEST" << endl;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    dsu.merge(u, v, i);
  }
  // cerr << "HERE" << endl;
  for(int i = 1; i <= n; ++i) {
    seg.update(i, 0);
  }
  for(int i = 1; i < n; ++i) {
    // cerr << "UPDATE " << dsu.lca(i, i + 1) << endl;
    seg.update(i, dsu.lca(i, i + 1));
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    // cerr << "QUE " << l << " " << r << endl;
    cout << seg.query(1, 0, lim - 1, l, r - 1) << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}