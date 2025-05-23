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
const int lim2 = 2e5 + 5;
struct disjoint_set {
  int h[lim2], sz[lim2], val[lim2];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim2, 1);
    memset(val, 0, sizeof(val));
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  void merge(int x, int y, int v) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      val[y] = v;
    }
  }
};
const int lim = 1 << 18;
struct segment_tree {
  int a[lim << 1];
  segment_tree() {
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
};  
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  int p[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> p[i];
  return 0;
}