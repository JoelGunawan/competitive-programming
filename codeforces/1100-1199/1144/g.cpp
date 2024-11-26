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
const int inf = 1e9;
struct min_segtree {
  pair<int, int> a[2 * lim];
  min_segtree() {
    for(int i = 0; i < 2 * lim; ++i)
      a[i] = mp(inf, inf);
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = mp(val, idx - lim);
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[2 * idx], a[2 * idx + 1]);
    }
  }
  pair<int, int> query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return mp(inf, inf);
    else {
      int mid = (cl + cr) / 2;
      return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
    }
  }
};
struct max_segtree {
  pair<int, int> a[2 * lim];
  max_segtree() {
    for(int i = 0; i < 2 * lim; ++i)
      a[i] = mp(-inf, -inf);
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = mp(val, idx - lim);
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[2 * idx], a[2 * idx + 1]);
    }
  }
  pair<int, int> query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return mp(-inf, -inf);
    else {
      int mid = (cl + cr) / 2;
      return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // dp[i] = max(min(dp[i - x], (x > 1 ? a[i - 1] : inf))) where dp[i - x] > a[i - x + 1] ... a[i - 1] is DECREASING and a[i] > a[i - x]
  // dp[n] -> n is incr such that the decr is max
  int dp[n + 1][2], pr[n + 1][2];
  memset(pr, -1, sizeof(pr));
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 1e9;
  dp[0][1] = -1e9;
  min_segtree mn; max_segtree mx;
  mn.update(0, -1e9);
  mx.update(0, 1e9);
  int incr = 0, decr = 0;
  for(int i = 1; i <= n; ++i) {
    if(i > 1 && a[i] >= a[i - 1])
      decr = 0;
    if(i > 1 && a[i] <= a[i - 1])
      incr = 0;
    ++incr, ++decr;
    pair<int, int> tmp = mx.query(1, 0, lim - 1, i - incr, i - 1);
    dp[i][0] = tmp.fi, pr[i][0] = tmp.se;
    tmp = mn.query(1, 0, lim - 1, i - decr, i - 1);
    dp[i][1] = tmp.fi, pr[i][1] = tmp.se;
    // cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    if(i < n && dp[i][0] > a[i + 1]) {
      // cerr << "Update mn " << i << " " << a[i] << endl;
      mn.update(i, a[i]);
    }
    if(i < n && dp[i][1] < a[i + 1]) {
      // cerr << "Update mx " << i << " " << a[i] << endl;
      mx.update(i, a[i]); 
    }
  }
  if(dp[n][0] != -inf || dp[n][1] != inf) {
    cout << "YES" << endl;
    // backtrack
    pair<int, int> cur = mp(n, 0);
    int ans[n + 1];
    memset(ans, -1, sizeof(ans));
    if(dp[n][0] == -inf)
      cur.se = 1;
    while(cur.fi > 0) {
      int prev = pr[cur.fi][cur.se];
      for(int i = prev + 1; i <= cur.fi; ++i)
        ans[i] = cur.se;
      // cerr << cur.fi << " " << cur.se << endl;
      cur = mp(pr[cur.fi][cur.se], cur.se ^ 1);
    }
    for(int i = 1; i <= n; ++i)
      cout << ans[i] << " ";
    cout << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}