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
const int lim = 4e5 + 5;
vector<int> edges[lim];
int low[lim], disc[lim], t;
vector<pair<int, int>> bridges;
void tarjan(int nd, int pr = -1) {
  low[nd] = disc[nd] = t++;
  for(auto x : edges[nd]) {
    if(disc[x] == -1) {
      tarjan(x, nd);
      if(low[x] > disc[nd]) {
        bridges.pb(mp(min(nd, x), max(nd, x)));
      }
      low[nd] = min(low[nd], low[x]);
    }
    else if(x != pr) {
      low[nd] = min(low[nd], disc[x]);
    }
  }
}
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
};
bool vis[lim];
void dfs(int nd, set<pair<int, int>> &s) {
  vis[nd] = 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      s.ins(mp(nd, x));
      dfs(x, s);
    }
    else if(!s.count(mp(nd, x)) && !s.count(mp(x, nd))) {
      s.ins(mp(nd, x));
    }
  }
}
map<pair<int, int>, pair<int, int>> a;
void dfs_bridge(int nd, set<pair<int, int>> &s) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      // cerr << "DEB " << nd << " " << i << endl;
      s.ins(a[mp(i, nd)]);
      dfs_bridge(i, s);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  memset(disc, -1, sizeof(disc));
  memset(low, -1, sizeof(low));
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
  tarjan(1);
  disjoint_set dsu;
  sort(bridges.begin(), bridges.end());
  for(auto x : adj) {
    if(!binary_search(bridges.begin(), bridges.end(), x))
      dsu.merge(x.fi, x.se);
  }
  int mx = 0;
  for(int i = 1; i <= n; ++i)
    mx = max(mx, dsu.sz[i]);
  cout << mx << endl;
  // construction -> for "internal edges" make a cycle, rest can be any
  // bridge -> point to largest all of it
  for(int i = 1; i <= n; ++i)
    edges[i].clear();
  for(auto p : adj)
    if(!binary_search(bridges.begin(), bridges.end(), p))
      edges[p.fi].pb(p.se), edges[p.se].pb(p.fi);
  set<pair<int, int>> s;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      dfs(i, s);
      // push the cycle into s
    }
  }
  for(int i = 1; i <= n; ++i)
    edges[i].clear();
  for(auto p : bridges)
    edges[dsu.fh(p.fi)].pb(dsu.fh(p.se)), edges[dsu.fh(p.se)].pb(dsu.fh(p.fi));
  for(auto p : bridges)
    a[mp(dsu.fh(p.fi), dsu.fh(p.se))] = p, a[mp(dsu.fh(p.se), dsu.fh(p.fi))] = mp(p.se, p.fi);
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; ++i) {
    if(dsu.fh(i) == i && dsu.sz[dsu.fh(i)] == mx) {
      dfs_bridge(dsu.fh(i), s);
      break;
    }
  }
  for(auto p : adj) {
    if(!s.count(mp(p.fi, p.se)) && !s.count(mp(p.se, p.fi)))
      s.ins(p);
  }
  for(auto p : adj) {
    if(s.count(p))
      cout << p.fi << " " << p.se << endl;
    else
      cout << p.se << " " << p.fi << endl;
  }
  return 0;
}