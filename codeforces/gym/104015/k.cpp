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
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool vis[lim];
void dfs(int nd) {
  vis[nd] = 1;
  // for a node with degree k, we need queries in the direction of k - 1 of those edges or that node 
  // is chosen? -> no?
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
    }
  }
}
void tc() {
  int n, m, q;
  cin >> n >> m >> q;
  // have all matrix configurations?
  for(int i = 1; i <= n; ++i)
    edges[i].clear(), vis[i] = 0;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  dfs(1);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}