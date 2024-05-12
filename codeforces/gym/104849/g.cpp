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
const int lim = 505 * 505;
vector<int> edges[lim], pot[lim];
bool vis[lim];
// bfs from 1 and bfs from n
int dist1[lim], dist2[lim], cont1[lim], n;
void dfs(int nd, int cont = -1) {
  // cout << nd << " " << dist1[nd] << " " << dist2[nd] << endl;
  if(dist1[n - 1] == dist1[nd] + dist2[nd]) {
    cont = dist1[nd];
  }
  cont1[nd] = cont;
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      dist2[i] = dist2[nd] + 1, dfs(i, cont);
  }
}
void dfs_dist(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      dist1[i] = dist1[nd] + 1, dfs_dist(i);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  int res;
  n = h * w;
  char a[2 * h + 1][2 * w + 1];
  for(int i = 0; i <= 2 * h; ++i) {
    for(int j = 0; j <= 2 * w; ++j) {
      cin >> a[i][j];
    }
  }
  // find the longest branch
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      if(a[2 * i + 1][2 * j] == '.' && j != 0)
        edges[i * w + j].pb(i * w + j - 1);
      else if(j != 0)
        pot[i * w + j].pb(i * w + j - 1);
      if(a[2 * i][2 * j + 1] == '.' && i != 0)
        edges[i * w + j].pb((i - 1) * w + j);
      else if(i != 0)
        pot[i * w + j].pb((i - 1) * w + j);
      if(a[2 * i + 1][2 * j + 2] == '.' && j != w - 1)
        edges[i * w + j].pb(i * w + j + 1);
      else if(j != w - 1)
        pot[i * w + j].pb(i * w + j + 1);
      if(a[2 * i + 2][2 * j + 1] == '.' && i != h - 1) 
        edges[i * w + j].pb((i + 1) * w + j);
      else if(i != h - 1)
        pot[i * w + j].pb((i + 1) * w + j);
    }
  }
  // can not be previous node
  dfs_dist(0);
  memset(vis, 0, sizeof(vis));
  dfs(n - 1);
  res = dist1[n - 1];
  for(int i = 0; i < n; ++i) {
    // cout << cont1[i] << " ";
    for(auto x : pot[i]) {
      if(cont1[x] < cont1[i]) {
        res = max(res, dist1[x] + dist2[i] + 1);
      }
    }
  }
  // cout << endl;
  cout << res + 1 << endl;
  return 0;
}