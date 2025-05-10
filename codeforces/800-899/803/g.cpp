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
const int lim = 1 << 20;
const int inf = 1e9 + 5;
struct segment_tree {
  int a[lim << 1], lazy[lim << 1];
  segment_tree() {
    fill(a, a + (lim << 1), inf);
    memset(lazy, -1, sizeof(lazy));
  }
  void prop(int nd, int cl, int cr) {
    if(lazy[nd] == -1)
      return;
    if(cl != cr) {
      lazy[nd << 1] = lazy[nd];
      lazy[(nd << 1) | 1] = lazy[nd];
    }
    a[nd] = lazy[nd]; // update is a set
    lazy[nd] = -1;
  }
  void update(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // cerr << "UPD " << cl << " " << cr << " " << val << endl;
      lazy[nd] = val;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update((nd << 1), cl, mid, l, r, val);
      update((nd << 1) | 1, mid + 1, cr, l, r, val);
      a[nd] = min(a[nd << 1], a[(nd << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // cerr << "QUER " << cl << " " << cr << " " << a[nd] << endl;
      return a[nd];
    }
    else if (cl > r || cr < l) {
      return inf;
    }
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  segment_tree normal;
  for(int i = 0; i < n; ++i)
    cin >> a[i], normal.update(1, 0, lim - 1, i, i, a[i]);
  int q;
  cin >> q;
  vector<pair<pair<int, int>, pair<int, int>>> queries;
  vector<int> points;
  for(int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      queries.push_back(mp(mp(t, x), mp(l, r)));
      points.push_back(l);
      points.push_back(l - 1);
      points.push_back(l + 1);
      points.push_back(r);
      points.push_back(r - 1);
      points.push_back(r + 1);
    }
    else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      queries.push_back(mp(mp(t, 0), mp(l, r)));
      points.push_back(l);
      points.push_back(l - 1);
      points.push_back(l + 1);
      points.push_back(r);
      points.push_back(r - 1);
      points.push_back(r + 1);
    }
  }
  sort(points.begin(), points.end());
  points.resize(unique(points.begin(), points.end()) - points.begin());
  if(points[0] == -1)
    points.erase(points.begin());
  segment_tree seg;
  for(int i = 0; i + 1 < points.size(); ++i) {
    int cur = points[i], nxt = points[i + 1];
    if(nxt - cur >= n) {
      seg.update(1, 0, lim - 1, i, i, normal.query(1, 0, lim - 1, 0, n - 1));
      continue;
    }
    cur %= n, nxt %= n;
    if(cur < nxt) {
      seg.update(1, 0, lim - 1, i, i, normal.query(1, 0, lim - 1, cur, nxt - 1));
    }
    else {
      seg.update(1, 0, lim - 1, i, i, min(normal.query(1, 0, lim  - 1, cur, n - 1), normal.query(1, 0, lim - 1, 0, nxt - 1)));
    }
  }
  for (auto [p1, p2] : queries) {
    auto [t, x] = p1;
    auto [l, r] = p2;
    if(t == 1) {
      seg.update(1, 0, lim - 1, lb(points.begin(), points.end(), l) - points.begin(), lb(points.begin(), points.end(), r) - points.begin(), x);
    }
    else {
      cout << seg.query(1, 0, lim - 1, lb(points.begin(), points.end(), l) - points.begin(), lb(points.begin(), points.end(), r) - points.begin()) << endl;
    }
  }
  
  return 0;
}