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
bool vis[lim];
vector<int> edges[lim];
vector<vector<int>> components;
void dfs(int nd, vector<int> &v) {
  vis[nd] = 1;
  v.pb(nd);
  for(auto x : edges[nd]) {
    if(!vis[x])
      dfs(x, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    // connected components have to be the same
    int c[n + 5];
    vector<pair<int, int>> adj;
    for(int i = 1; i <= m1; ++i) {
      int u, v;
      cin >> u >> v;
      adj.pb(mp(u, v));
    }   
    for(int i = 1; i <= m2; ++i) {
      int u, v;
      cin >> u >> v;
      edges[u].pb(v);
      edges[v].pb(u);
    }
    vector<vector<int>> components;
    for(int i = 1; i <= n; ++i) {
      if(!vis[i]) {
        vector<int> v;
        dfs(i, v);
        components.pb(v);
      }
    }
    for(int i = 0; i < components.size(); ++i) {
      for(auto x : components[i])
        c[x] = i;
    }
    int ops = 0;
    int cc = 0;
    for(int i = 1; i <= n; ++i) {
      vis[i] = 0;
      edges[i].clear();
      // cerr << c[i] << " ";
    }
    // cerr << endl;
    for(auto p : adj) {
      if(c[p.fi] != c[p.se])
        ++ops;
      else
        edges[p.fi].pb(p.se), edges[p.se].pb(p.fi);
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
      if(!vis[i])
        ++cc, dfs(i, v);
    }
    for(int i = 1; i <= n; ++i) {
      vis[i] = 0;
      edges[i].clear();
    }
    // cerr << "CC SIZES " << components.size() << " " << cc << endl;
    cout << ops + cc - components.size() << endl;
  }
  return 0;
}