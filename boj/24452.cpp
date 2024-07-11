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
const int lim = 4e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  vector<pair<int, int>> ops;
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    while(h[nd] != -1)
      nd = h[nd];
    return nd;
  }
  bool connected(int x, int y) {
    return fh(x) == fh(y);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      h[y] = x;
      sz[x] += sz[y];
      ops.pb(mp(x, y));
    }
    else
      ops.pb(mp(-1, -1));
    return x != y;
  }
  void rollback(int cnt) {
    while(cnt-- && ops.size()) {
      if(ops.back().fi == -1) {
        ops.pop_back();
        continue;
      }
      h[ops.back().se] = -1;
      sz[ops.back().fi] -= sz[ops.back().se];
      ops.pop_back();
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> adj;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj.pb(mp(u, v));
  }
  int state[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> state[i];
  int q;
  cin >> q;
  vector<pair<pair<pair<int, int>, pair<int, int>>, int>> queries;
  int ans[q];
  memset(ans, -1, sizeof(ans));
  for(int idx = 0; idx < q; ++idx) {
    int a, b;
    cin >> a >> b;
    if(state[a] > state[b])
      swap(a, b);
    // // cerr << "DEB INPUT " << a << " " << b << endl;
    queries.pb(mp(mp(mp(state[a], state[b]), mp(a, b)), idx));
  }
  sort(queries.begin(), queries.end());
  map<pair<int, int>, vector<pair<int, int>>> edges;
  disjoint_set dsu;
  for(auto p : adj) {
    if(state[p.fi] == state[p.se])
      dsu.merge(p.fi, p.se);
    else
      edges[mp(min(state[p.fi], state[p.se]), max(state[p.fi], state[p.se]))].pb(mp(p.fi, p.se));
  }
  pair<int, int> cur = mp(0, 0);
  for(auto x : queries) {
    // rollback
    // // cerr << x.fi.se.fi << " " << x.fi.se.se << endl;
    int statea = x.fi.fi.fi, stateb = x.fi.fi.se, a = x.fi.se.fi, b = x.fi.se.se, idx = x.se;
    if(cur != mp(statea, stateb)) {
      dsu.rollback(edges[cur].size());
      cur = mp(0, 0);
    }
    // cerr << idx << " " << cur.fi << " " << cur.se << endl;
    if(statea == stateb || cur == mp(statea, stateb)) {
      // don't do anything
      // cerr << "type 1: " << a << " " << b << endl;
      ans[idx] = dsu.connected(a, b);
    }
    else {
      cur = mp(statea, stateb);
      // cerr << "Change: " << idx << " " << cur.fi << " " << cur.se << endl;
      for(auto p : edges[cur])
        dsu.merge(p.fi, p.se);
      ans[idx] = dsu.connected(a, b);
    }
  }
  for(auto x : ans)
    cout << x << endl;
  return 0;
}