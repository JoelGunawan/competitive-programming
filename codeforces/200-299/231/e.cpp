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
        h[y] = x;
        sz[x] += sz[y];
    }
    return x != y;
  }
};
int low[lim], disc[lim], t;
vector<int> edges[lim];
vector<pair<int, int>> bridges;
void tarjan(int nd, int par = -1) {
  disc[nd] = low[nd] = t++;
  //cout << "tarjan: " << nd << " " << disc[nd] << endl;
  for(auto x : edges[nd]) {
    //cout << "tarjan edges: " << x << " " << disc[x] << endl;
    if(x == par)
      continue;
    if(disc[x] == -1) {
      tarjan(x, nd);
      low[nd] = min(low[nd], low[x]);
      //cout << "check low: " << x << " " << nd << " " << low[x] << " " << disc[nd] << endl;
      if(low[x] > disc[nd]) {
        //cout << "add to bridges" << endl;
        bridges.pb(mp(x, nd));
      }
    }
    else {
      low[nd] = min(low[nd], disc[x]);
    }
  }
}
int par[17][lim], weight[17][lim], depth[lim], mod = 1e9 + 7;
bool vis[lim], type[lim];
void dfs(int nd) {
  //cout << "DFS: " << nd << " " << depth[nd] << endl;
  vis[nd] = 1;
  depth[nd] = max(depth[nd], 1);
  weight[0][nd] = type[nd] + 1;
  for(int i = 1; i < 17; ++i) {
    par[i][nd] = par[i - 1][par[i - 1][nd]];
    weight[i][nd] = (1ll * weight[i - 1][nd] * weight[i - 1][par[i - 1][nd]]) % mod;
  }
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      depth[x] = depth[nd] + 1;
      par[0][x] = nd;
      dfs(x);
    }
  }
}
pair<int, int> lca(int u, int v) {
  if(depth[v] > depth[u]) 
    swap(u, v);
  int res = 1;
  //cout << u << " " << v << endl;
  for(int i = 16; i >= 0; --i) {
    if(depth[par[i][u]] >= depth[v]) {
      res = (1ll * res * weight[i][u]) % mod;
      u = par[i][u];
    }
  }
  //cout << u << " " << v << " " << res << endl;
  if(u == v)
    return mp(res, u);
  for(int i = 16; i >= 0; --i) {
    if(par[i][u] != par[i][v]) {
      res = (1ll * res * weight[i][u]) % mod;
      res = (1ll * res * weight[i][v]) % mod;
      u = par[i][u], v = par[i][v];
    }
  }
  return mp((1ll * res * weight[0][u] * weight[0][v]) % mod, par[0][u]);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // make bridge tree, if node contains > 1 node -> times 2
  // if node contains only 1 node -> times 1
  disjoint_set dsu;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
    adj.pb(mp(min(u, v), max(u, v)));
  }
  memset(disc, -1, sizeof(disc));
  tarjan(1);
  for(auto &p : bridges) {
    if(p.fi > p.se)
      swap(p.fi, p.se);
  }
  sort(bridges.begin(), bridges.end());
  for(auto p : adj) {
    if(!binary_search(bridges.begin(), bridges.end(), p)) {
      dsu.merge(p.fi, p.se);
    }
  }
  for(int i = 1; i <= n; ++i) {
    edges[i].clear();
    type[dsu.fh(i)] = dsu.sz[dsu.fh(i)] > 1;
  }
  for(auto p : bridges) {
    //cout << "bridges: " << p.fi << " " << p.se << endl;
    edges[dsu.fh(p.fi)].pb(dsu.fh(p.se));
    edges[dsu.fh(p.se)].pb(dsu.fh(p.fi));
  }
  dfs(dsu.fh(1));
  int k;
  cin >> k;
  while(k--) {
    int x, y;
    cin >> x >> y;
    pair<int, int> ret = lca(dsu.fh(x), dsu.fh(y));
    if(type[ret.se])
      ret.fi = (ret.fi * 2) % mod;
    //cout << dsu.fh(x) << " " << dsu.fh(y) << " " << ret.fi << " " << ret.se << " " << type[ret.se] << endl;
    cout << ret.fi << endl;
  }
}