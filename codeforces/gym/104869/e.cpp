#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main() {
  // wrong approach, correct approach using BFS
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x, y, p, q;
  cin >> x >> y >> p >> q;
  // find first state such that dist[x][w][1] is minimal
  int dist[x + 1][y + 1][2];
  memset(dist, -1, sizeof(dist));
  queue<pair<int, pair<int, pair<int, int>>>> bfs;
  bfs.push(mp(0, mp(0, mp(0, 0))));
  while(bfs.size()) {
    int d = bfs.front().fi, s = bfs.front().se.fi, w = bfs.front().se.se.fi, side = bfs.front().se.se.se;
    bfs.pop();
    // cerr << s << " " << w << " " << side << endl;
    if(dist[s][w][side] != -1)
      continue;
    dist[s][w][side] = d;
    // for every single movement possible: try it using bfs
    if(side == 0) {
      // move ms and mw such that if moved is x, y then ms - x + q >= mw - y OR ms - i = 0
      int ms = x - s, mw = y - w;
      // cerr << x << " " << s << " " << ms << " " << mw << endl;
      for(int i = 0; i <= ms; ++i) {
        for(int j = 0; j <= mw; ++j) {
          // cerr << i << " " << j << " " << ms - i + q << " " << mw -j << endl;
          if(dist[s + i][w + j][!side] == -1 && i + j <= p && (ms - i + q >= mw - j || ms - i == 0))
            bfs.push(mp(d + 1, mp(s + i, mp(w + j, !side))));
        }
      }
    }
    else {
      // move s and w such that if moved is i, j then s - i + q >= w - j OR s = 0
      for(int i = 0; i <= s; ++i) {
        for(int j = 0; j <= w; ++j) {
          if(dist[s - i][w - j][!side] == -1 && i + j <= p && (s - i + q >= w - j || s == 0))
            bfs.push(mp(d + 1, mp(s - i, mp(w - j, !side))));
        }
      }
    }
  }
  const int inf = 1e9;
  int res = inf;
  for(int i = 0; i <= y; ++i) {
    if(dist[x][i][1] != -1)
      res = min(res, dist[x][i][1]);
  }
  cout << (res == inf ? -1 : res) << endl;
}