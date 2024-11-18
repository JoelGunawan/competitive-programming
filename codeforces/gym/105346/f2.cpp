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
vector<int> edges[200005];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, s, k, g;
  cin >> n >> m >> s >> k >> g;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  int exits[k + 1];
  for(int i = 1; i <= k; ++i)
    cin >> exits[i];
  int ghosts[g + 1];
  for(int i = 1; i <= g; ++i) {
    cin >> ghosts[i];
  }
  queue<pair<int, int>> bfs;
  for(int i = 1; i <= g; ++i) 
    bfs.push(mp(0, ghosts[i]));
  int dist_ghost[n + 5];
  fill(dist_ghost, dist_ghost + n + 5, 1e9);
  while(bfs.size()) {
    int dist = bfs.front().fi, nd = bfs.front().se;
    bfs.pop();
    if(dist >= dist_ghost[nd])
      continue;
    dist_ghost[nd] = dist;
    for(auto x : edges[nd]) {
      if(dist + 1 < dist_ghost[x])
        bfs.push(mp(dist + 1, x));
    }
  }
  int dist_harry[n + 5];
  fill(dist_harry, dist_harry + n + 5, 1e9);
  bfs.push(mp(0, s));
  while(bfs.size()) {
    int dist = bfs.front().fi, nd = bfs.front().se;
    bfs.pop();
    if(dist >= dist_harry[nd])
      continue;
    dist_harry[nd] = dist;
    for(auto x : edges[nd]) {
      if(dist + 1 < dist_harry[x])
        bfs.push(mp(dist + 1, x));
    }
  }
  int res = 0;
  for(int i = 1; i <= k; ++i) {
    if(dist_harry[exits[i]] < dist_ghost[exits[i]])
      ++res;
  }
  cout << res << endl;
  return 0;
}