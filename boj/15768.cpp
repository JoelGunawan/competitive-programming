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
// 1-based converting graph to bcc
struct bct {
  vector<vector<int>> edges;
  vector<pair<vector<int>, bool>> bcc;
  vector<int> disc, low, st;
  vector<bool> ap;
  int t;
  void tarjan(int nd, int par = -1) {
    disc[nd] = low[nd] = t++;
    int cld = 0;
    st.pb(nd);
    for(auto x : edges[nd]) {
      if(x == par)
        continue;
      if(disc[x] == -1) {
        ++cld;
        tarjan(x, nd);
        low[nd] = min(low[nd], low[x]);
        if(par != -1 && low[x] >= disc[nd])
          ap[nd] = 1;
      }
      else {
        low[nd] = min(low[nd], disc[x]);
      }
    }
    if(par == -1 && cld > 1)
      ap[nd] = 1;
  }
  void get_bct(int n, vector<pair<int, int>> adj) {
    disc = low = vector<int>(n + 5, -1);
    ap = vector<bool>(n + 5, 0);
    edges = vector<vector<int>>(n + 5, vector<int>());
    st.clear();
    bcc.clear();
    t = 0;
    for(auto x : adj) {
      edges[x.fi].pb(x.se);
      edges[x.se].pb(x.fi);
    }
    tarjan(1);
    for(auto x : bcc) {
      // cout << "type: " << x.se << endl;
      // cout << "nodes: ";
      // for(auto y : x.fi)
      //   cout << y << " ";
      // cout << endl;
    }
  }
  
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj(m);
  for(int i = 0; i < m; ++i) {
    cin >> adj[i].fi >> adj[i].se;
  } 
  bct a;
  a.get_bct(n, adj);
  return 0;
}