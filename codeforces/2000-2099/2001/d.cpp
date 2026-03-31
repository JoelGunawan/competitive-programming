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
struct segtree_mx {
  vector<int> a;
  int sz;
  segtree_mx(int n) {
    sz = 1;
    while (sz <= n) sz *= 2;
    a = vector<int>(2 * sz, 0);
  }

  void update(int idx, int val) {
    idx += sz;
    a[idx] = val;
    while (idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  
  int query(int nd, int cl, int cr, int l, int r) {
    if (cl >= l && cr <= r) {
      return a[nd];
    } else if (cl > r || cr < l) {
      return 0;
    } else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }

  int query(int l, int r) {
    return query(1, 0, sz - 1, l, r);
  }
};

struct segtree_mn {
  vector<int> a;
  int sz;
  segtree_mn(int n) {
    sz = 1;
    while (sz <= n) sz *= 2;
    a = vector<int>(2 * sz, 0);
  }

  void update(int idx, int val) {
    idx += sz;
    a[idx] = val;
    while (idx) {
      idx >>= 1;
      a[idx] = min(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  
  int query(int nd, int cl, int cr, int l, int r) {
    if (cl >= l && cr <= r) {
      return a[nd];
    } else if (cl > r || cr < l) {
      return 1e9;
    } else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }

  int query(int l, int r) {
    return query(1, 0, sz - 1, l, r);
  }
}; 

void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> order;
  set<int> s;
  for (int i = n; i >= 1; --i) {
    if (!s.count(a[i])) {
      order.push_back(i);
      s.insert(a[i]);
    }
  }

  vector<int> res;
  set<int> deleted;
  segtree_mx mx(n + 5);
  segtree_mn mn(n + 5);
  vector<int> vals[n + 5];
  for (int i = 1; i <= n; ++i) vals[a[i]].push_back(i);

  for (int i = 1; i <= n; ++i) {
    mn.update(i, a[i]);
    mx.update(i, a[i]);
  }
  
  int pr = 0;
  for (int i = 1; i <= n; ++i) {
    while (order.size() > 0 && deleted.count(a[order.back()])) {
      order.pop_back();
    }
    if (order.empty()) break;

    // choose maximum/minimum between current and order (depends on parity)
    if (i & 1) {
      // choose max
      int nx = mx.query(pr + 1, order.back());
      res.emplace_back(nx);
      deleted.insert(nx);
      int next_pr = 1e9;
      for (auto x : vals[nx]) {
        if (x > pr) next_pr = min(next_pr, x);
        mn.update(x, 1e9);
        mx.update(x, 0);
      }
      pr = next_pr;
    } else {
      // choose min
      int nx = mn.query(pr + 1, order.back());
      res.emplace_back(nx);
      deleted.insert(nx);
      int next_pr = 1e9;
      for (auto x : vals[nx]) {
        if (x > pr) next_pr = min(next_pr, x);
        mn.update(x, 1e9);
        mx.update(x, 0);
      }
      pr = next_pr;
    }
  }
  
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}