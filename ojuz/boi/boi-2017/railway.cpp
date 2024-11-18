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
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
int ord[lim], num[lim], par[17][lim], dp[lim], depth[lim];
int t;
void dfs(int nd) {
  vis[nd] = 1;
  ord[nd] = ++t;
  num[ord[nd]] = nd;
  for(int i = 1; i < 17; ++i)
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  depth[nd] = max(depth[nd], 1);
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      depth[i] = depth[nd] + 1;
      par[0][i] = nd;
      dfs(i);
    }
  }
}
void dfs2(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd])
    if(!vis[i]) {
      dfs2(i);
      dp[nd] += dp[i];
    }
}
int lca(int u, int v) {
  if(depth[u] < depth[v])
    swap(u, v);
  for(int i = 16; i >= 0; --i) {
    if(depth[par[i][u]] >= depth[v])
      u = par[i][u];
  }
  // cerr << u << " " << v << endl;
  if(u == v)
    return u;
  // cerr << "ERROR " << u << " " << v << endl;
  for(int i = 16; i >= 0; --i) {
    if(par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  }
  return par[0][u];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> arr;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
    arr[mp(u, v)] = i;
    arr[mp(v, u)] = i;
  }
  dfs(1);
  // sort node by ett, then just -1 at lca of both nodes
  // -1 at total lca at the end
  for(int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    vector<int> nodes;
    while(x--) {
      int y;
      cin >> y;
      nodes.pb(y);
    }
    for(auto &x : nodes)
      x = ord[x];
    sort(nodes.begin(), nodes.end());
    for(auto &x: nodes)
      x = num[x];
    // for(auto x : nodes)
    //   cerr << x << " ";
    // cerr << endl;
    int total_lca = nodes[0];
    for(auto x : nodes)
      total_lca = lca(total_lca, x), ++dp[x];
    --dp[total_lca];
    for(int i = 1; i < nodes.size(); ++i) {
      // cerr << nodes[i - 1] << " " << nodes[i] << " " << lca(nodes[i - 1], nodes[i]) << endl;
      --dp[lca(nodes[i - 1], nodes[i])];
    }
  }
  memset(vis, 0, sizeof(vis));
  dfs2(1);
  vector<int> ans;
  for(int i = 1; i <= n; ++i) {
    // cerr << i << " " << dp[i] << endl;
    if(dp[i] >= k) {
      ans.pb(arr[mp(i, par[0][i])]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}