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
struct segtree {
  int a[lim << 1];
  segtree() {
    memset(a, 0, sizeof(a));
  }

  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while (idx > 0) {
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
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a[n + 5];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].fi >> a[i].se;
  }

  // let us consider a constructive construction from
  // left to right (in terms of tulips we pick)
  // let us consider if we want to pick tulip i, which previous tulip
  // can we pick?
  // - the j + r_j value can not be >= i
  // - the j value can not be >= i - l_i
  // based on these two constraints, we want to maximize the results
  // do sweep, we can simply do a "pending insert" to satisfy the first req
  // so we just need to query the max that satisfies requirement 2
  // just use segtree (technically we could use a set for this but i'm too lazy)
  
  // fi -> pos to insert
  // se -> idx to insert
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; ++i) {
    pq.emplace(i + a[i].se + 1, i);
  }

  int dp[n + 5];
  memset(dp, 0, sizeof(dp));
  segtree seg;

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    // insert to seg
    while (pq.size() && pq.top().fi == i) {
      auto [pos, idx] = pq.top();
      pq.pop();
      seg.update(idx, dp[idx]);
      // cerr << "updating " << i << " " << idx << endl;
    }

    // calculate dp
    // cerr << "query " << 1 << " " << i - a[i].fi - 1 << endl;
    dp[i] = max(1, seg.query(1, 0, lim - 1, 1, i - a[i].fi - 1) + 1);
    res = max(res, dp[i]);
    // cerr << "dp value " << i << " " << dp[i] << endl;
  }
  // cerr << endl;

  cout << res << endl;

  return 0;
}