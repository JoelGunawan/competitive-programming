#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  pair<int, int> start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'P') {
        start = {i, j};
      }
    }
  }

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  auto dfs = [&](auto &&self, int i, int j, int par) -> ll {
    // cerr << i << " " << j << " " << par << "\n";
    vector<ll> adj;
    for (int dir = 0; dir < 4; dir++) if (dir != par) {
      int u = i + dx[dir];
      int v = j + dy[dir];
      if (min(u, v) < 0 || u >= n || v >= m || a[u][v] == '.') {
        continue;
      }
      adj.push_back(self(self, u, v, dir ^ 2));
    }

    if (adj.size() == 0) {
      return a[i][j] - '0';
    }

    if (a[i][j] == '+') {
      return adj[0] + adj[1];
    }

    if (a[i][j] == '-') {
      return abs(adj[0] - adj[1]);
    }

    if (a[i][j] == '/') {
      return max(adj[0], adj[1]) / min(adj[0], adj[1]);
    }

    if (a[i][j] == '*') {
      return adj[0] * adj[1];
    }

    return adj[0];
  };

  cout << dfs(dfs, start.fi, start.se, 4) << "\n";
}