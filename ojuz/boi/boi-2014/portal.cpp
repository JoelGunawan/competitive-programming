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
  int r, c;
  cin >> r >> c;
  char a[r + 2][c + 2];
  for(int i = 0; i <= r + 1; ++i)
    for(int j = 0; j <= c + 1; ++j)
      a[i][j] = '#';
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      cin >> a[i][j];
    }
  }
  // for each grid cell, find closest 
  pair<int, int> s, t;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(a[i][j] == 'S')
        s = mp(i, j), a[i][j] = '.';
      else if(a[i][j] == 'C')
        t = mp(i, j), a[i][j] = '.';
    }
  }
  pair<int, int> cw[4][r + 2][c + 2];
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j <= r + 1; ++j)
      for(int k = 0; k <= c + 1; ++k)
        cw[i][j][k] = mp(-1, -1);
  int w[r + 2][c + 2];
  queue<pair<int, pair<int, int>>> bfs;
  vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(a[i][j] == '.') {
        bool h = 0;
        for(auto p : nxt) 
          h |= a[i + p.fi][j + p.se] == '#';
        if(h)
          bfs.push(mp(0, mp(i, j)));
      }
    }
  }
  memset(w, -1, sizeof(w));
  while(bfs.size()) {
    int d = bfs.front().fi, x = bfs.front().se.fi, y = bfs.front().se.se;
    bfs.pop();
    if(w[x][y] != -1)
      continue;
    w[x][y] = d;
    for(auto p : nxt) {
      if(a[x + p.fi][y + p.se] == '.' && w[x + p.fi][y + p.se] == -1)
        bfs.push(mp(d + 1, mp(x + p.fi, y + p.se)));
    }
  }
  for(int i = 0; i < 4; ++i) {
    for(int j = nxt[i].fi > 0 ? r : 1; (j <= r && nxt[i].fi <= 0) || (j >= 1 && nxt[i].fi > 0); j += nxt[i].fi > 0 ? -1 : 1)
      for(int k = nxt[i].se > 0 ? c : 1; (k <= c && nxt[i].se <= 0) || (k >= 1 && nxt[i].se > 0); k += nxt[i].se > 0 ? -1 : 1)  
        if(a[j][k] == '.') {
          if(a[j + nxt[i].fi][k + nxt[i].se] == '#')
            cw[i][j][k] = mp(j, k);
          else
            cw[i][j][k] = cw[i][j + nxt[i].fi][k + nxt[i].se];
        }
  }
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  pq.push(mp(0, s));
  int dist[r + 2][c + 2];
  memset(dist, -1, sizeof(dist));
  while(pq.size()) {
    int d = pq.top().fi, x = pq.top().se.fi, y = pq.top().se.se;
    pq.pop();
    if(dist[x][y] != -1)
      continue;
    dist[x][y] = d;
    for(auto p : nxt) {
      if(a[x + p.fi][y + p.se] == '.' && dist[x + p.fi][y + p.se] == -1)
        pq.push(mp(d + 1, mp(x + p.fi, y + p.se)));
    }
    for(int i = 0; i < 4; ++i) {
      // cout << x << " " << y << " " << cw[i][x][y].fi << " " << cw[i][x][y].se << " " << w[x][y] << endl;
      if(dist[cw[i][x][y].fi][cw[i][x][y].se] == -1)
        pq.push(mp(d + 1 + w[x][y], cw[i][x][y]));
    }
  }
  cout << dist[t.fi][t.se] << endl;
  return 0;
}