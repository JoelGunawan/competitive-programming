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
struct node {
  ll a = 0, b = 0, c = 0, d = 0, ab = 0, bc = 0, cd = 0, abc = 0, bcd = 0, abcd = 0, sum = 0;
};
node merge(node l, node r) {
  node x;
  x.a = max(r.sum + l.a, r.a);
  x.b = max(l.sum + r.b, l.b);
  x.c = max(r.sum + l.c, r.c);
  x.d = max(l.sum + r.d, l.d);
  x.ab = max({l.ab, r.ab, l.a + r.b});
  x.bc = max({l.bc + r.sum, r.bc + l.sum, l.b + r.c});
  x.cd = max({l.cd, r.cd, l.c + r.d});
  x.abc = max({l.abc + r.sum, l.ab + r.c, l.a + r.bc, r.abc});
  x.bcd = max({r.bcd + l.sum, r.cd + l.b, r.d + l.bc, l.bcd});
  x.abcd = max({l.abcd, l.abc + r.d, l.ab + r.cd, l.a + r.bcd, r.abcd});
  x.sum = l.sum + r.sum;
  return x;
}
const int lim = 1 << 18;
int x[lim], y[lim];
struct segtree {
  node a[lim << 1];
  segtree() {
    for(int i = 0; i < lim << 1; ++i)
      a[i] = node();
  }
  void update(int idx) {
    ll aval = x[idx], bval = y[idx];
    idx += lim;
    a[idx] = node();
    a[idx].a = a[idx].c = aval + bval;
    a[idx].b = a[idx].d = aval + bval;
    a[idx].ab = a[idx].cd = aval + 2 * bval;
    a[idx].abc = a[idx].bcd = a[idx].bc = a[idx].abcd = -1e18;
    a[idx].sum = aval;
    while(idx > 0) {
      idx >>= 1;
      a[idx] = merge(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  void query(int nd, int cl, int cr, int l, int r, vector<node> &v) {
    if(cl >= l && cr <= r) {
      v.pb(a[nd]);
    }
    else if(cl > r || cr < l)
      return;
    else {
      int mid = (cl + cr) >> 1;
      query(nd << 1, cl, mid, l, r, v);
      query((nd << 1) | 1, mid + 1, cr, l, r, v);
    }
  }
} seg;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> x[i];
  for(int i = 1; i <= n; ++i) 
    cin >> y[i];
  for(int i = 1; i <= n; ++i)
    seg.update(i);
  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      x[a] = b;
      seg.update(a);
    }
    else if(t == 2) {
      int a, b;
      cin >> a >> b;
      y[a] = b;
      seg.update(a);
    }
    else {
      int l, r;
      cin >> l >> r;
      vector<node> v;
      seg.query(1, 0, lim - 1, l, r, v);
      // cerr << "OUTPUT NODES" << endl;
      // for(auto nd : v) {
      //   cerr << nd.a << " " << nd.b << " " << nd.ab << " " << nd.c << " " << nd.d << " " << nd.cd << endl;
      // }
      while(v.size() > 1) {
        v[v.size() - 2] = merge(v[v.size() - 2], v.back()), v.pop_back();
      }
      cout << v[0].abcd << endl;
    }
  }
  return 0;
}