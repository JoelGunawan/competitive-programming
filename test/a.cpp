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

// is power of 2
const int lim = 1 << 10;
struct segment_tree {
  int a[lim << 1];
  segment_tree() {
    memset(a, 0, sizeof(a));
  }

  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while (idx > 0) {
      idx >>= 1;
      // 2 * idx, 2 * idx + 1
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }

  int query(int nd, int cl, int cr, int l, int r){
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
    return query(1, 0, lim - 1, l, r);
  }
};

// sum lazy segment tree
// +=
struct lazy_segment_tree {
  ll a[lim << 1];
  ll lazy[lim << 1];
  segment_tree() {
    memset(a, 0, sizeof(a));
    memset(lazy, 0, sizeof(lazy));
  }

  // [cl, cr]
  void propagate(int nd, int cl, int cr) {
    if (cl != cr) {
      lazy[nd << 1] += lazy[nd];
      lazy[(nd << 1) | 1] += lazy[nd];
    }
    a[nd] += (cr - cl + 1) * lazy[nd];
    lazy[nd] = 0;
  }

  void update(int nd, int cl, int cr, int l, int r, int val) {
    propagate(nd, cl, cr);
    if (cl >= l && cr <= r) {
      // update code
      lazy[nd] += val;
      propagate(nd, cl, cr);
    } else if (cl > r || cr < l) {
      return;
    } else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      update((nd << 1) | 1, mid + 1, cr, l, r, val);
    }
  }

  // cl, cr, cd, cu, d, u
  int query(int nd, int cl, int cr, int l, int r){
    propagate(nd, cl, cr);
    if (cl >= l && cr <= r) {
      return a[nd];
    } else if (cl > r || cr < l) {
      return 0;
    } else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }

  int query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
};

struct fenwick {
  ll a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    while (idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }

  ll query(int idx) {
    ll ret = 0;
    while (idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  return 0;
}