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
const int lim = 3e5 + 5;
struct disjoint_set {
  int h[2 * lim], sz[2 * lim];
  ll cost[2 * lim];
  int nx = lim;
  vector<int> child[2 * lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
    memset(cost, 0, sizeof(cost));
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  bool merge(int x, int y, int z) {
    x = fh(x), y = fh(y);
    if(x != y) {
      h[y] = nx;
      h[x] = nx;
      child[nx].pb(x), child[nx].pb(y);
      cost[y] = 1ll * sz[x] * z;
      cost[x] = 1ll * sz[y] * z;
      sz[nx] = sz[x] + sz[y];
      ++nx;
    }
    return x != y;
  }
  void dfs(int nd) {
    for(auto x : child[nd]) {
      cost[x] += cost[nd];
      dfs(x);
    }
  }
} dsu;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int d[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> d[i];
  vector<pair<int, pair<int, int>>> adj;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj.pb(mp(max(d[u], d[v]), mp(u, v)));
  }
  sort(adj.begin(), adj.end());
  lll res = 0;
  for(auto p : adj) {
    dsu.merge(p.se.fi, p.se.se, p.fi);
  }
  dsu.nx--;
  dsu.dfs(dsu.nx);
  for(int i = 1; i <= n; ++i) {
    cout << dsu.cost[i] + d[i] << " ";
  }
  cout << endl;
  return 0;
}