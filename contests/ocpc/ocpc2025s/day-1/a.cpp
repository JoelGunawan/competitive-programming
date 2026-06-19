#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
using namespace std;
const int N = 2.5e5;
int n, m;
int tot;
vector<pair<int, int>> adj[N * 16];
vector<int> dist;
vector<vector<int>> g;
struct segtree {
  int n;
  vector<int> tree;
  segtree(int _n) {
    n = _n;
    tree.assign(n * 4, 0);
  }
  void build(int x, int st, int ed, int sx, int ex) {
    tree[x] = ++tot;
    if (st == ed) {
      if (sx == ex) {
        g[sx][st] = tree[x];
      }
      return;
    }
    int mid = (st + ed) / 2;
    build(x * 2 + 1, st, mid, sx, ex);
    build(x * 2 + 2, mid + 1, ed, sx, ex);
    adj[tree[x]].push_back({tree[x * 2 + 1], 0});
    adj[tree[x]].push_back({tree[x * 2 + 2], 0});
  }
  void addEdge(int x, int st, int ed, int l, int r, int u) {
    if (st > r || ed < l) {
      return;
    }
    if (l <= st && ed <= r) {
      adj[u].push_back({tree[x], 1});
      return;
    }
    int mid = (st + ed) / 2;
    addEdge(x * 2 + 1, st, mid, l, r, u);
    addEdge(x * 2 + 2, mid + 1, ed, l, r, u);
  }
};
struct segtree2d {
  int n, m;
  vector<segtree> tree;
  segtree2d(int _n, int _m) {
    n = _n;
    m = _m;
    tree.assign(n * 4, segtree(m));
    build(0, 0, n - 1);
  }
  int build(int x, int sx, int ex) {
    tree[x].build(0, 0, m - 1, sx, ex);
    int nrt = tree[x].tree[0];
    if (sx == ex) {
      return nrt;
    }
    int mid = (sx + ex) / 2;
    int ls = build(x * 2 + 1, sx, mid);
    int rs = build(x * 2 + 2, mid + 1, ex);
    adj[nrt].push_back({ls, 0});
    adj[nrt].push_back({rs, 0});
    return nrt;
  }
  void addEdge(int x, int lx, int rx, int ly, int ry, int sx, int ex, int u) {
    if (lx > ex || sx > rx) {
      return;
    }
    if (lx <= sx && ex <= rx) {
      tree[x].addEdge(0, 0, m - 1, ly, ry, u);
      return;
    }
    int mid = (sx + ex) / 2;
    addEdge(x * 2 + 1, lx, rx, ly, ry, sx, mid, u);
    addEdge(x * 2 + 2, lx, rx, ly, ry, mid + 1, ex, u);
  }
};
pair<int, int> cheby(int x, int y) {
  return {(x - y + m - 1), x + y};
}
void solve() {
  tot = 0;
  cin >> n >> m;
  g.assign(m + n, vector<int>(m + n));
  int sx, sy, tx, ty;
  cin >> sx >> tx >> sy >> ty;
  sx--, sy--, tx--, ty--;
  tie(sx, tx) = cheby(sx, tx);
  tie(sy, ty) = cheby(sy, ty);
  segtree2d seg(n + m, n + m);
  vector<vector<int>> p(n + m, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto [x, y] = cheby(i, j);
      // cout << x << ' ' << y << ' ';
      // cout << g[x][y] << ' ';
      int p;
      cin >> p;
      seg.addEdge(0, x - p, x + p, y - p, y + p, 0, m + n - 1, g[x][y]);
    }
    cout << '\n';
  }

  dist.assign(tot + 1, INT_MAX);
  deque<pair<int, int>> dq;
  dq.push_back({g[sx][tx], 0});
  dist[g[sx][tx]] = 0;
  while (dq.size()) {
    auto [cdist, u] = dq.front();
    if (dist[u] != cdist) {
      continue;
    }
    for (auto [v, d]: adj[u]) {
      if (dist[v] > dist[u] + d) {
        dist[v] = dist[u] + d;
        if (d == 0) {
          dq.push_front({v, dist[v]});
        } else {
          dq.push_back({v, dist[v]});
        }
      }
    }
  }
  cout << dist[g[sy][ty]];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
    cout << '\n';
  }
}
