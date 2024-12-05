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
const int lim = 1 << 17;
ll bad[12];
bool flag;
struct segtree {
  // min_value -> represents distance to closest power of 42 (upwards)
  ll min_value[lim << 1], a[lim << 1], lazy_set[lim << 1], lazy_sum[lim << 1];
  bool avs[lim << 1];
  segtree() {
    memset(a, 0, sizeof(a));
    memset(avs, 0, sizeof(avs));
    memset(min_value, 0, sizeof(min_value));
    memset(lazy_set, 0, sizeof(lazy_set));
    memset(lazy_sum, 0, sizeof(lazy_sum));
  }
  // lazy_set -> actual value
  // lazy_sum -> just change
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      // lazy_set overpowers lazy_sum
      if(lazy_set[nd])
        lazy_sum[nd << 1] = lazy_sum[(nd << 1) | 1] =0, lazy_set[nd << 1] = lazy_set[(nd << 1) | 1] = lazy_set[nd], avs[nd << 1] = avs[(nd << 1) | 1] = 1;
      lazy_sum[nd << 1] += lazy_sum[nd];
      lazy_sum[(nd << 1) | 1] += lazy_sum[nd];
    }
    if(lazy_set[nd]) {
      min_value[nd] = lazy_set[nd];
      a[nd] = lazy_set[nd];
      min_value[nd] += lazy_sum[nd];
      a[nd] += lazy_sum[nd];
      min_value[nd] = *lb(bad, bad + 12, min_value[nd]) - min_value[nd];
    }
    else {
      min_value[nd] -= lazy_sum[nd];
      a[nd] += lazy_sum[nd];
    }
    lazy_set[nd] = 0, lazy_sum[nd] = 0;
  }
  void update_sum(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl > r || cr < l) {
      return;
    }
    else if(cl >= l && cr <= r && min_value[nd] > val) {
      lazy_sum[nd] += val;
      // cerr << "US " << cl << " " << cr << " " << val << endl;
      prop(nd, cl, cr);
      return;
    }
    else if(cl >= l && cr <= r && avs[nd]) {
      lazy_sum[nd] += val;
      // cerr << "US " << cl << " " << cr << " " << val << endl;
      prop(nd, cl, cr);
      // cerr << "US " << cl << " " << cr << " " << a[nd] << endl;
      if(min_value[nd] == 0)
        flag = 1;
      else if(min_value[nd] < 0) {
        lazy_set[nd] = a[nd];
        prop(nd, cl, cr);
        if(min_value[nd] == 0)
          flag = 1;
      }
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update_sum(nd << 1, cl, mid, l, r, val);
      update_sum((nd << 1) | 1, mid + 1, cr, l, r, val);
      min_value[nd] = min(min_value[nd << 1], min_value[(nd << 1) | 1]);
      avs[nd] = avs[nd << 1] && avs[(nd << 1) | 1] && a[nd << 1] == a[(nd << 1) | 1];
      // take any is fine
      a[nd] = a[nd << 1];
    }
  }
  void update_set(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl > r || cr < l) {
      return;
    }
    else if(cl >= l && cr <= r) {
      lazy_set[nd] = val;
      lazy_sum[nd] = 0;
      avs[nd] = 1;
      prop(nd, cl, cr);
      // cerr << cl << " " << cr << " " << a[nd] << endl;
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update_set(nd << 1, cl, mid, l, r, val);
      update_set((nd << 1) | 1, mid + 1, cr, l, r, val);
      min_value[nd] = min(min_value[nd << 1], min_value[(nd << 1) | 1]);
      avs[nd] = avs[nd << 1] && avs[(nd << 1) | 1] && a[nd << 1] == a[(nd << 1) | 1];
      // take any is fine
      a[nd] = a[nd << 1];
    }
  }
  ll query(int idx) {
    int nd = 1, cl = 0, cr = lim - 1;
    while(cl <= cr) {
      // cerr << "Q " << nd << " " << cl << " " << cr << " " << a[nd] << endl;
      prop(nd, cl, cr);
      if(avs[nd])
        return a[nd];
      int mid = (cl + cr) >> 1;
      if(idx <= mid)
        cr = mid, nd <<= 1;
      else
        cl = mid + 1, nd = (nd << 1) | 1;
    }
    return a[nd];
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // segtree beats -> only at most logn unique values? OR per update it affects at most only logn nodes
  // the update will only happen x times (just check increase to closest value x times, check when it will happen again)
  bad[0] = 1;
  for(int i = 1; i < 12; ++i)
    bad[i] = bad[i - 1] * 42;
  int n, q;
  cin >> n >> q;
  segtree seg;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    seg.update_set(1, 0, lim - 1, i, i, x);
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int idx;
      cin >> idx;
      cout << seg.query(idx) << endl;
    }
    else if(t == 2) {
      int a, b, x;
      cin >> a >> b >> x;
      flag = 1;
      while(flag) {
        flag = 0;
        seg.update_set(1, 0, lim - 1, a, b, x);
      }
    } 
    else {
      int a, b, x;
      cin >> a >> b >> x;
      flag = 1;
      while(flag) {
        flag = 0;
        seg.update_sum(1, 0, lim - 1, a, b, x);
      }
    }
  }
  return 0;
}