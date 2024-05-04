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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> railway[n + 1], road[n + 1];
  set<pair<int, int>> s;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    s.insert(mp(min(u, v), max(u, v)));
    railway[u].pb(v);
    railway[v].pb(u);
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      if(!s.count(mp(i, j))) {
        road[i].pb(j);
        road[j].pb(i);
      }
    }
  }
  // first -> node
  // second -> distance
  queue<pair<int, int>> bfs;
  bfs.push(mp(1, 0));
  int rail_dist, road_dist;
  bool vis[n + 5];
  memset(vis, 0, sizeof(vis));
  bool found = 0;
  while(bfs.size()) {
    int nd = bfs.front().fi, dist = bfs.front().se;
    bfs.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    if(nd == n) {
      rail_dist = dist;
      found = 1;
      break;
    }
    for(auto e : railway[nd]) {
      if(!vis[e])
        bfs.push(mp(e, dist + 1));
    }
  }
  while(bfs.size())
    bfs.pop();
  if(!found) {
    cout << -1 << endl;
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  bfs.push(mp(1, 0));
  found = 0;
  while(bfs.size()) {
    int nd = bfs.front().fi, dist = bfs.front().se;
    bfs.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    if(nd == n) {
      road_dist = dist;
      found = 1;
      break;
    }
    for(auto e : road[nd]) {
      if(!vis[e])
        bfs.push(mp(e, dist + 1));
    }
  }
  if(!found) {
    cout << -1 << endl;
    return 0;
  }
  cout << max(road_dist, rail_dist) << endl;
  return 0;
}