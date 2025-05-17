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
const int lim = 1 << 18;
int mod = 998244353;
struct segtree {
  int a[lim << 1];
  segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
  int queryr(int nd, int cl, int cr, int l, int val) {
    if(cr < l || a[nd] <= val)
      return lim;
    if(cl == cr)
      return cl;
    int mid = (cl + cr) >> 1;
    int r1 = queryr(nd << 1, cl, mid, l, val);
    if(r1 != lim)
      return r1;
    else
      return queryr((nd << 1) | 1, mid + 1, cr, l, val);
  }
  int queryl(int nd, int cl, int cr, int r, int val) {
    if(cl > r || a[nd] <= val)
      return 0;
    if(cl == cr)
      return cl;
    int mid = (cl + cr) >> 1;
    int r1 = queryl((nd << 1) | 1, mid + 1, cr, r, val);
    if(r1 != 0)
      return r1;
    else
      return queryl(nd << 1, cl, mid, r, val);
  }
};
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int res = 0;
    while(idx) {
      res += a[idx];
      idx -= idx&-idx;
    }
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
segtree seg;
fenwick sum;
void tc() {
  int n;
  cin >> n;
  int p[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> p[i];
  int c[n + 1];
  vector<int> colors[n + 1]; 
  for(int i = 1; i <= n; ++i)
    cin >> c[i], colors[c[i]].push_back(i);
  segtree seg;
  fenwick sum;
  for(int i = 1; i <= n; ++i) 
    seg.update(i, p[i]);
  ll res = 1;
  for(int i = 1; i <= n; ++i) {
    if(colors[i].empty())
      continue;
    for(auto idx : colors[i])
      seg.update(idx, 0), sum.update(idx, 1);
    vector<pair<pair<int, int>, int>> v;
    for(auto idx : colors[i]) {
      int maxl = seg.queryl(1, 0, lim - 1, idx - 1, p[idx]);
      int maxr = seg.queryr(1, 0, lim - 1, idx + 1, p[idx]);
      maxl = *lb(colors[i].begin(), colors[i].end(), maxl);
      maxr = min(n, maxr);
      v.pb({{maxl, maxr}, idx});
      // cerr << idx << " " << maxl << " " << maxr << endl;
    }
    sort(v.begin(), v.end(), [] (const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) -> bool { return a.fi.se - a.fi.fi < b.fi.se - b.fi.fi; } );
    for(auto [pii, idx] : v) {
      auto [maxl, maxr] = pii;
      res = (res * sum.query(maxl, maxr)) % mod;
      sum.update(idx, -1);
      seg.update(idx, p[idx]);
    }
  }
  for(int i = 1; i <= n; ++i)
    seg.update(i, 0);
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}