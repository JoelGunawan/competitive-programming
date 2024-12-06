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
// merge sort tree, update using li chao tree style
// for all -> sum_r * t_used
// subtract over limit -> limit reached at time 5, (t - 5) * r - pad
// pad -> not exact whole
// merge sort tree for query
// segtree beats -> last time has to be the same
const int lim = 1 << 17;
const ll inf = 1e18;
int s[lim], m[lim], reg[lim];
struct segtree {
  bool same[lim << 1];
  // assert all time is same -> used
  ll sum_r[lim << 1];
  int t[lim << 1], lazy[lim << 1];
  // t -> last time
  // lazy -> lazy time
  // sum_r -> sum of r
  // reduce -> sort pairs, reduce
  vector<pair<int, pair<ll, ll>>> reduce[lim << 1]; // merge sort tree
  segtree() {
    memset(same, 1, sizeof(same));
    memset(t, 0, sizeof(t));
    memset(sum_r, 0, sizeof(sum_r));
    memset(lazy, -1, sizeof(lazy));
  }
  void build(vector<pair<ll, ll>> &v) {
    // build sum_r
    for(int i = 0; i < v.size(); ++i)
      sum_r[i + lim] = v[i].fi;
    for(int i = lim - 1; i >= 1; --i)
      sum_r[i] = sum_r[i << 1] + sum_r[(i << 1) | 1];
    // build reduce
    for(int i = 0; i < v.size(); ++i) {
      reduce[lim + i].pb(mp(0, mp(0, 0)));
      if(v[i].fi == 0)
        continue;
      int tx = v[i].se / v[i].fi + (v[i].se % v[i].fi ? 1 : 0);
      // cerr << "BUILD " << i << " " << -v[i].fi << " " << v[i].fi * tx - (v[i].se % v[i].fi ? v[i].fi - (v[i].se % v[i].fi) : 0) << endl;
      reduce[lim + i].pb(mp(tx, mp(-v[i].fi, v[i].fi * tx - (v[i].se % v[i].fi ? v[i].fi - (v[i].se % v[i].fi) : 0))));
    }
    for(int i = lim - 1; i >= 1; --i) {
      reduce[i].pb(mp(0, mp(0, 0)));
      int idx1 = 1, idx2 = 1, l = i << 1, r = (i << 1) | 1;
      while(idx1 < reduce[l].size() || idx2 < reduce[r].size()) {
        if(idx1 == reduce[l].size() || (idx2 < reduce[r].size() && reduce[r][idx2].fi < reduce[l][idx1].fi)) {
          // use idx2
          reduce[i].pb(reduce[r][idx2++]);
        }
        else
          reduce[i].pb(reduce[l][idx1++]);
      }
    }
    for(int i = 1; i <= lim - 1; ++i) {
      // make prefix sum
      vector<pair<int, pair<ll, ll>>> cons;
      for(auto x : reduce[i]) {
        if(cons.empty() || cons.back().fi != x.fi) {
          if(cons.empty())
            cons.pb(x);
          else
            cons.pb(mp(x.fi, mp(x.se.fi + cons.back().se.fi, x.se.se + cons.back().se.se)));
        }
        else
          cons.back().se.fi += x.se.fi, cons.back().se.se += x.se.se;
      }
      reduce[i] = cons;
    }
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      if(lazy[nd] != -1)
        lazy[nd << 1] = lazy[(nd << 1) | 1] = lazy[nd];
      same[nd << 1] |= same[nd];
      same[(nd << 1) | 1] |= same[nd];
    }
    if(lazy[nd] != -1)
      t[nd] = lazy[nd], same[nd] = 1;
    lazy[nd] = -1;
  }
  ll query(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl > r || cr < l)
      return 0;
    if(cl >= l && cr <= r && same[nd]) {
      ll ret = 0;
      if(t[nd] == 0) {
        // cerr << "TEST " << cl << " " << cr << endl;
        // first case
        // do manually, traverse all
        for(int i = cl; i <= cr; ++i) {
          // calculate cost manually
          // cerr << val << " " << s[i] << " " << reg[i] << " " << m[i] << endl;
          ret += min(s[i] + 1ll * reg[i] * val, (ll)m[i]);
        }
        // cerr << ret << endl;
      }
      else {
        // binser first in vector that is lower
        int cur_t = t[nd];
        ret = (val - cur_t) * sum_r[nd];
        // apply that penalty
        // find first that has lower time
        pair<int, pair<ll, ll>> cur = *--ub(reduce[nd].begin(), reduce[nd].end(), mp(val - cur_t + 1, mp(-inf, -inf)));
        // for(auto x : reduce[nd])
        //   cerr << x.fi << " " << x.se.fi << " " << x.se.se << endl;
        // cerr << "OUTPUT CUR " << cur.fi << " " << cur.se.fi << " " << cur.se.se << endl;
        // cerr << "DEB " << cl << " " << cr  << " " << ret << " " << cur.se.fi << " " << cur.se.se << endl;
        ret += cur.se.fi * (val - cur_t) + cur.se.se;
      }
      lazy[nd] = val;
      prop(nd, cl, cr);
      return ret;
    }
    int mid = (cl + cr) >> 1;
    ll ret = query((nd << 1) | 1, mid + 1, cr, l, r, val) + query(nd << 1, cl, mid, l, r, val);
    same[nd] = same[nd << 1] && same[(nd << 1) | 1] && t[nd << 1] == t[(nd << 1) | 1];
    t[nd] = t[nd << 1];
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> s[i] >> m[i] >> reg[i];
  vector<pair<ll, ll>> v(n);
  for(int i = 0; i < n; ++i)
    v[i] = mp(reg[i], m[i]);
  segtree seg;
  seg.build(v);
  int m;
  cin >> m;
  while(m--) {
    int t, l, r;
    cin >> t >> l >> r;
    cout << seg.query(1, 0, lim - 1, --l, --r, t) << endl;
  }
  return 0;
}