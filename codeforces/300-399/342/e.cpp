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
const int lim = 1e5 + 1;
vector<int> edges[lim];
int subtree[lim];
bool vis[lim];
// p.fi -> node, p.se -> dist
vector<pair<int, int>> anc[lim];
int ans[lim];
int get_subtree(int nd, int pr = -1) {
  subtree[nd] = 1;
  // cerr << "GET SUBTREE " << nd << " " << root << " " << dist << endl;
  for(auto i : edges[nd]) {
    if(i != pr && !vis[i])
      subtree[nd] += get_subtree(i, nd);
  }
  return subtree[nd];
}
int get_centroid(int nd, int sz, int pr) {
  for(auto i : edges[nd])
    if(i != pr && !vis[i]) 
      if(2 * subtree[i] > sz)
        return get_centroid(i, sz, nd);
  return nd;
}
void generate_dist(int nd, int root, int dist = 0, int pr = -1) {
  anc[nd].pb(mp(root, dist));
  for(auto i : edges[nd])
    if(i != pr && !vis[i])
      generate_dist(i, root, dist + 1, nd);
}
// "dfs" from centroid to 
void construct(int nd) {
  int centroid = get_centroid(nd, get_subtree(nd), nd);
  generate_dist(centroid, centroid);
  // cerr << "CONS " << centroid << endl;
  vis[centroid] = 1;
  for(auto i : edges[centroid]) {
    // cerr << "edge " << centroid << " " << i << endl;
    if(!vis[i]) {
      construct(i);
    }
  }
}
// we need all pars
int main() {
  // maintain distances to all centroids
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  // maintain distance to all parent centroids
  construct(1);
  // technically can use lca, but construct manually is way easier?
  for(int i = 1; i <= n; ++i)
    ans[i] = 1e9;
  for(auto p : anc[1])
    ans[p.fi] = min(ans[p.fi], p.se);
  while(m--) {
    int t, nd;
    cin >> t >> nd;
    // cerr << "DEB " << 
    if(t == 2) {
      // query
      int res = 1e9;
      for(auto p : anc[nd]) {
        res = min(res, ans[p.fi] + p.se);
      }
      cout << res << endl;
    }
    else {
      // update
      // cerr << "DEB " << nd << endl;
      for(auto p : anc[nd]) {
        // cerr << "UP " << p.fi << " " << p.se << endl;
        ans[p.fi] = min(ans[p.fi], p.se);
      }
    }
  }
  return 0;
}