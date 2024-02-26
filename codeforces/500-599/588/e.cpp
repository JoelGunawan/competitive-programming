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
vector<int> edges[lim], mn[17][lim];
int par[17][lim];
bool vis[lim];
vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> res;
  int idxa = 0, idxb = 0;
  while(idxa < a.size() || idxb < b.size()) {
    if(idxa >= a.size()) {
      res.pb(b[idxb]);
      ++idxb;
    }
    else if(idxb >= b.size()) {
      res.pb(a[idxa]);
      ++idxa;
    }
    else {
      if(a[idxa] < b[idxb])
        res.pb(a[idxa]), ++idxa;
      else
        res.pb(b[idxb]), ++idxb;
    }
  }
  while(res.size() > 10)
    res.pop_back();
  return res;
}
void build_lca(int nd) {
  vis[nd] = 1;
  for(int i = 1; i < 17; ++i) {
    par[i][nd] = par[i - 1][par[i - 1][nd]];
    mn[i][nd] = merge(mn[i - 1][nd], mn[i - 1][par[i - 1][nd]]);
  }
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      par[0][i] = nd;
      dfs(i);
    }
  }
}
vector<int> lca(int u, int v) {

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    // find first 10 mins for each path
    // can represent as vector
    for(int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      edges[u].pb(v);
      edges[v].pb(u);
    }
    int c[m + 1];
    for(int i = 1; i <= m; ++i)
      cin >> c[i];
    for(int i = 1; i <= m; ++i) {
      mn[0][c[i]].pb(i);
    }
    for(int i = 1; i <= n; ++i) {
      sort(mn[0][i].begin(), mn[0][i].end());
      while(mn[0][i].size() > 10)
        mn[0][i].pop_back();
    }
    build_lca(1);
    int q;
    cin >> q;
    while(q--) {

    }
    return 0;
}