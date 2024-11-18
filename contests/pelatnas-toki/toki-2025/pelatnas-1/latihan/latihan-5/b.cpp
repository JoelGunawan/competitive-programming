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
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool vis[lim];
// indicates shift of value when going to par
int shift[lim];
int cnt[lim];
int dfs(int nd) {
  vis[nd] = 1;
  cnt[nd] = shift[nd];
  for(auto i : edges[nd])
    if(!vis[i])
      cnt[nd] += dfs(i);
  return cnt[nd];
}
int par[18][lim], depth[lim];
void get_lca(int nd) {
  for(int i = 1; i < 18; ++i)
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      par[0][i] = nd, depth[i] = depth[nd] + 1, get_lca(i);
  }
}
int lca(int u, int v) {
  if(depth[u] < depth[v])
    swap(u, v);
  for(int i = 16; i >= 0; --i) {
    if(depth[par[i][u]] >= depth[v])
      u = par[i][u];
  }
  if(u == v)
    return u;
  for(int i = 16; i >= 0; --i) {
    if(par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  }
  return par[0][u];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, pair<int, int>>> v;
  for(int i = 1; i < n; ++i) {
    int u, x, w1, w2;
    cin >> u >> x >> w1 >> w2;
    edges[u].pb(x);
    edges[x].pb(u);
    v.pb(mp(mp(u, x), mp(w1, w2)));
  }
  depth[1] = 1;
  get_lca(1);
  for(int i = 2; i <= n; ++i) {
    ++shift[i - 1], ++shift[i], shift[lca(i - 1, i)] -= 2;
  }
  memset(vis, 0, sizeof(vis));
  dfs(1);
  ll res = 0;
  for(auto p : v) {
    if(depth[p.fi.fi] > depth[p.fi.se])
      swap(p.fi.fi, p.fi.se);
    // p.fi.fi is par
    res += min(1ll * cnt[p.fi.se] * p.se.fi, (ll)p.se.se);
  }
  cerr << endl;
  cout << res << endl;
  return 0;
}