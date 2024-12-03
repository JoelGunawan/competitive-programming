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
const int lim = 1 << 19;
struct segment_tree {
  int a[2 * lim];
  segment_tree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] += val;
    while(idx) {
      idx >>= 1;
      a[idx] = a[idx << 1] + a[(idx << 1) | 1];
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  segment_tree seg;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  seg.update(0, m);
  int last[m + 1];
  memset(last, 0, sizeof(last));
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    seg.update(last[a[i]], -1);
    res += seg.query(1, 0, lim - 1, last[a[i]], i - 1);
    // cerr << "add " << i << " " << seg.query(1, 0, lim - 1, last[a[i]], i - 1) << endl;
    // cerr << "l r " << last[a[i]] << " " << i - 1 << endl;
    seg.update(i, 1);
    last[a[i]] = i;
  }
  cout << res << endl;
  return 0;
}