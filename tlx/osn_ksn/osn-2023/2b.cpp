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
const int lim = 1e5 + 5;
vector<int> child[lim];
bool vis[lim]; 
pair<int, int> maxd[lim];
int d[lim];
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
    return x != y;
  }
} dsu;
ll dfs(int nd) {
  int cur = 0;
  vis[nd] = 1;
  maxd[nd] = mp(d[nd], nd);
  ll res = 0;
  for(auto i : child[nd]) {
    d[i] = d[nd] + 1;
    res += dfs(i);
    maxd[nd] = max(maxd[nd], mp(maxd[i].fi, i));
  }
  res += maxd[nd].fi - d[nd];
  dsu.merge(maxd[nd].se, nd);
  return res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  ll k;
  cin >> n >> k >> q;
  for(int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    child[x].pb(i);
  }
  if(q == 0) {
    cout << (dfs(1) >= k ? "YA" : "TIDAK") << endl;
    return 0;
  }
  if(dfs(1) < k)
    cout << "TIDAK" << endl;
  else {
    cout << "YA" << endl;
    // alrdy dsu merged into one dsu
    vector<vector<int>> chains;
    map<int, int> chain_idx;
    for(int i = 1; i <= n; ++i) {
      if(chain_idx[dsu.fh(i)] == 0)
        chains.pb({i}), chain_idx[dsu.fh(i)] = chains.size();
      else
        chains[chain_idx[dsu.fh(i)] - 1].pb(i);
    }
    // for every chain, find count of inversion required
    int last = 0;
    int ans[n + 1];
    memset(ans, -1, sizeof(ans));
    for(auto v : chains) {
      deque<int> cur = {};
      for(int i = last + 1; i <= last + v.size(); ++i)
        cur.pb(i);
      for(auto c : v) {
        // cerr << c << " " << maxd[c].fi - d[c] << endl;;
        if(maxd[c].fi - d[c] <= k)
          ans[c] = cur.back(), cur.pop_back(), k -= maxd[c].fi - d[c];
        else if(k == 0)
          ans[c] = cur.front(), cur.pop_front();
        else 
          ans[c] = cur[k], cur.erase(cur.begin() + k), k = 0;
      }
      // cerr << endl;
      // cerr << "DEB " << k << endl;
      last += v.size();
    }
    for(int i = 1; i <= n; ++i)
      cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}