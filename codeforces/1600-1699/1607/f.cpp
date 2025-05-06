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
void tc() {
  int n, m;
  cin >> n >> m;
  char a[n + 2][m + 2];
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  unsigned char in[n + 2][m + 2];
  memset(in, 0, sizeof(in));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'L')
        ++in[i][j - 1];
      else if(a[i][j] == 'R')
        ++in[i][j + 1];
      else if(a[i][j] == 'U')
        ++in[i - 1][j];
      else
        ++in[i + 1][j];
    }
  }
  int dist[n + 2][m + 2];
  memset(dist, 0, sizeof(dist));
  queue<pair<int, int>> bfs;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(in[i][j] == 0)
        bfs.push({i, j});
    }
  }
  bool vis[n + 2][m + 2];
  memset(vis, 0, sizeof(vis));
  pair<short, short> start[n + 2][m + 2];
  for(int i = 0; i <= n + 1; ++i)
    for(int j = 1; j <= m + 1; ++j)
      start[i][j] = {i, j};
  while(bfs.size()) {
    auto [x, y] = bfs.front();
    bfs.pop();
    if(x < 1 || y < 1 || x > n || y > m)
      continue;
    if(vis[x][y])
      continue;
    vis[x][y] = 1;
    if(a[x][y] == 'U') {
      if(dist[x][y] + 1 > dist[x - 1][y]) {
        dist[x - 1][y] = dist[x][y] + 1;
        start[x - 1][y] = start[x][y];
      }
      --in[x - 1][y];
      if(in[x - 1][y] == 0) 
        bfs.push({x - 1, y});
    }
    else if(a[x][y] == 'D') {
      if(dist[x][y] + 1 > dist[x + 1][y]) {
        dist[x + 1][y] = dist[x][y] + 1;
        start[x + 1][y] = start[x][y];
      }
      --in[x + 1][y];
      if(in[x + 1][y] == 0) 
        bfs.push({x + 1, y});
    }
    else if(a[x][y] == 'R') {
      if(dist[x][y] + 1 > dist[x][y + 1]) {
        dist[x][y + 1] = dist[x][y] + 1;
        start[x][y + 1] = start[x][y];
      }
      --in[x][y + 1];
      if(in[x][y + 1] == 0) 
        bfs.push({x, y + 1});
    }
    else {
      if(dist[x][y] + 1 > dist[x][y - 1]) {
        dist[x][y - 1] = dist[x][y] + 1;
        start[x][y - 1] = start[x][y];
      }
      --in[x][y - 1];
      if(in[x][y - 1] == 0) 
        bfs.push({x, y - 1});
    }
  }
  pair<int, pair<short, short>> res;
  for(int i = 0; i <= n + 1; ++i) {
    for(int j = 0; j <= m + 1; ++j) {
      res = max(res, {dist[i][j], start[i][j]});
      if(!vis[i][j] && i > 0 && j > 0 && i < n + 1 && j < m + 1) {
        // find cycle length
        int cx = i, cy = j;
        // cerr << "INIT " << cx << " " << cy << endl;
        vector<pair<short, short>> v;
        while(true) {
          if(vis[cx][cy])
            break;
          vis[cx][cy] = 1;
          v.pb({cx, cy});
          if(a[cx][cy] == 'U')
            --cx;
          else if(a[cx][cy] == 'D')
            ++cx;
          else if(a[cx][cy] == 'R')
            ++cy;
          else
            --cy;
          // cerr << cx << " " << cy << endl;
          if(cx > n || cy > m || cx < 1 || cy < 1)
            break;
        }
        for(auto [x, y] : v) {
          res = max(res, {dist[x][y] + (int)v.size(), start[x][y]});
        }
      }
    }
  }
  cout << res.se.fi << " " << res.se.se << " " << res.fi << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}