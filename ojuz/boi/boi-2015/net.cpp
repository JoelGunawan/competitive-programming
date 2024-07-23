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
const int lim = 5e5 + 5;
vector<int> edges[lim];
int leafs;
bool vis[lim];
int cnt[lim];
vector<int> v;
void dfs(int nd) {
  vis[nd] = 1;
  cnt[nd] = 0;
  if(edges[nd].size() == 1)
    ++cnt[nd], v.pb(nd);
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
      cnt[nd] += cnt[i];
    }
  }
}
void find_leafs(int nd) {
  vis[nd] = 1;
  if(edges[nd].size() ==1)
    ++cnt[nd];
  for(auto i : edges[nd]) {
    if(!vis[i])
      find_leafs(i), cnt[nd] += cnt[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v), edges[v].pb(u);
  }
  for(int i = 1; i <= n; ++i) {
    if(edges[i].size() > 1) {
      find_leafs(i);
      break;
    }
  }
  pair<int, int> x = mp(1e9, 1e9);
  for(int i = 1; i <= n; ++i)
    if(cnt[i] >= leafs / 2)
      x = min(x, mp(cnt[i], i));
  // dfs from x, find left and right
  memset(vis, 0, sizeof(vis));
  dfs(x.se);
  if((int)v.size() & 1)
    v.pb(v.back());
  cout << v.size() / 2 << endl;
  for(int i = 0; i < v.size() / 2; ++i)
    cout << v[i] << " " << v[i + v.size() / 2] << endl;
  return 0;
}