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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, s, k, g;
  cin >> n >> m >> s >> k >> g;
  vector<int> edges[n + 5];
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  bool exit[n + 5];
  memset(exit, 0, sizeof(exit));
  for(int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    assert(!exit[x]);
    exit[x] = 1;
  }
  // k exits
  // g ghosts
  // s start
  // multisource bfs
  queue<pair<int, int>> bfs;
  for(int i = 1; i <= g; ++i) {
    int x;
    cin >> x;
    bfs.push(mp(0, x));
  }
  int dist[n + 5];
  memset(dist, -1, sizeof(dist));
  while(bfs.size()) {
    int nd = bfs.front().se, d = bfs.front().fi;
    bfs.pop();
    if(dist[nd] != -1)
      continue;
    dist[nd] = d;
    for(auto x : edges[nd]) {
      if(dist[x] == -1)
        bfs.push(mp(d + 1, x));
    }
  }
  bfs.push(mp(0, s));
  int dist2[n + 5];
  memset(dist2, -1, sizeof(dist2));
  while(bfs.size()) {
    int nd = bfs.front().se, d = bfs.front().fi;
    bfs.pop();
    if(dist2[nd] != -1)
      continue;
    dist2[nd] = d;
    for(auto x : edges[nd]) {
      if(dist2[x] == -1)
        bfs.push(mp(d + 1, x));
    }
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(exit[i] && ((dist2[i] < dist[i]) || (dist[i] == -1 && dist2[i] != -1)))
      ++res;
  }
  cout << res << endl;
  return 0;
}