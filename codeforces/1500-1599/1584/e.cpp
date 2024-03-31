// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
// range min query
struct segment_tree {
  ll a[2 * lim];
  segment_tree() {
    fill(a, a + 2 * lim, 1e18);
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[2 * idx], a[2 * idx + 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if(cl > r || cr < l) {
      return 1e18;
    }
    else {
      int mid = (cl + cr) / 2;
      return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
    }
  }
  int query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
}
segment_tree seg[2][2];
void tc() {
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // find prefix with alternating, then find kind of min queries
  // create 2 min segment trees, find first index that is less than x
  // can use binary search in segment tree if we want to but not necessary
  // ~ 2e8
  // also find count equal to cur in a given range
  for(int i = 0; i <= n + 1; ++i) {
    segodd.update(i, 1e18);
    segeven.update(i, 1e18);
  }
  ll cur1 = 0, cur2 = 0;
  ll pre[2][n + 1];
  for(int i = 1; i <= n; ++i) {
    if(i & 1) {
      pre[0][i] = pre[0][i - 1] + a[i];
      pre[1][i] = pre[1][i - 1] - a[i];
    }
    else {
      pre[0][i] = pre[0][i - 1] - a[i];
      pre[1][i] = pre[1][i - 1] + a[i];
    }
    seg[0][i & 1].update(i, pre[0][i]);
    seg[1][i & 1].update(i, pre[1][i]);
  }
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    // try to extend right
    int l = i + 1, r = n, ans = mid - 1;
    int red[] = {pre[0][i - 1], pre[1][i - 1]};
    while(l <= r) {
      int mid = (l + r) / 2;
      // cek ke kanan bisa sejauh apa
      int que[] = {seg[0][i & 1].query(i + 1, mid), seg[1][i & 1].query(i + 1, mid)};
      if(que[1] - red[1] >= 0 && que[0] - red[0] >= 0) {
        l = mid + 1, ans = mid;
      }
      else {
        r = mid - 1;
      }
    }
    if(ans == -1) 
      continue;
    else {
      // occur of pre[] equals to cur pre in [i + 1, ans]
      int occur;
      res += occur;
    }
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) 
    tc();
  return 0;
}