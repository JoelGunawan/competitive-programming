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
  int n, m, w;
  cin >> n >> m >> w;
  // observe that we go through at most one portal
  // solution: find shortest path from src to portal, dest to portal, and direct path, considering the cost of the portals too
  int a[n + 1][m + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  // bfs through all non -1 cells and find min cost from src and dest
  // min cost direct -> use bfs as well
  queue<pair<ll, pair<int, int>>> q;
  // from src
  q.push(mp(0, mp(1, 1)));
  vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
  ll dist[n + 1][m + 1];
  memset(dist, -1, sizeof(dist));
  for(ll d = q.front().fi, x = q.front().se.fi, y = q.front().se.se; q.size() > 0; q.pop(), d = q.front().fi, x = q.front().se.fi, y = q.front().se.se) {
    if(dist[x][y] != -1 || a[x][y] == -1)
      continue;
    dist[x][y] = d;
    for(auto p : nxt) {
      if(p.fi + x <= n && p.se + y <= m && p.fi + x >= 1 && p.se + y >= 1 && dist[p.fi + x][p.se + y] == -1) {
        q.push(mp(d + w, mp(p.fi + x, p.se + y)));
      }
    }
  }
  q.push(mp(0, mp(n, m)));
  ll dist2[n + 1][m + 1];
  memset(dist2, -1, sizeof(dist2));
  for(ll d = q.front().fi, x = q.front().se.fi, y = q.front().se.se; q.size() > 0; q.pop(), d = q.front().fi, x = q.front().se.fi, y = q.front().se.se) {
    if(dist2[x][y] != -1 || a[x][y] == -1)
      continue;
    dist2[x][y] = d;
    for(auto p : nxt) {
      if(p.fi + x <= n && p.se + y <= m && p.fi + x >= 1 && p.se + y >= 1 && dist2[p.fi + x][p.se + y] == -1) {
        q.push(mp(d + w, mp(p.fi + x, p.se + y)));
      }
    }
  }
  ll const inf = 1e18;
  ll min_src = inf, min_dest = inf;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] > 0) {
        if(dist[i][j] != -1)
          min_src = min(min_src, dist[i][j] + a[i][j]);
        if(dist2[i][j] != -1)
          min_dest = min(min_dest, dist2[i][j] + a[i][j]);
      }
    }
  }
  // cout << min_src << " " << min_dest << endl;
  if(min_src == inf || min_dest == inf) {
    cout << dist[n][m] << endl;
  }
  else if (dist[n][m] == -1) {
    cout << min_src + min_dest << endl;
  }
  else {
    cout << min(dist[n][m], min_src + min_dest) << endl;
  }
  return 0;
}