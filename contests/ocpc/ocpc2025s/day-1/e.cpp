#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
using namespace std;


struct Edge {
  int v, pos, flow, cap;
  
  Edge() {}

  Edge(int _v, int _pos, int _flow, int _cap) {
    v = _v;
    pos = _pos;
    flow = _flow;
    cap = _cap;
  }

  int rem() {
    return cap - flow;
  }
};

struct Dinic {
  int n;
  vector<vector<Edge>> adj;
  vector<int> ptr, lev;

  Dinic(int _n) {
    n = _n;
    adj.assign(n + 5, vector<Edge>(0));
  }

  void addEdge(int u, int v, int cap, int rcap = 0) {
    Edge a = Edge(v, adj[v].size(), 0, cap);
    Edge b = Edge(u, adj[u].size(), 0, rcap);
    adj[u].push_back(a);
    adj[v].push_back(b);
  }

  bool bfs(int s, int t) {
    ptr = lev = vector<int>(n + 5, 0);
    lev[s] = 1;
    queue<int> q({s});
    while (q.size()) {
      int u = q.front();
      q.pop();

      for (Edge e : adj[u]) if (e.rem() && lev[e.v] == 0) {
        lev[e.v] = lev[u] + 1;
        q.push(e.v);
      }
    }
    return lev[t] > 0;
  }

  int dfs(int u, int flow, int t) {
    if (u == t) {
      return flow;
    }

    for (int &i = ptr[u]; i < (int) adj[u].size(); i++) {
      Edge &e = adj[u][i];
      if (lev[u] + 1 != lev[e.v] || !e.rem()) {
        continue;
      }

      int new_flow = min(flow, e.rem());
      if (int val = dfs(e.v, new_flow, t)) {
        e.flow += val;
        adj[e.v][e.pos].flow -= val;
        return val;
      }
    }
    return 0;
  }

  int maxflow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
      while (int val = dfs(s, (int) 1e9, t)) {
        res += val;
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  auto solve = [&]() -> void {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0)), b = a;
    array<int, 2> suma = {0, 0}, sumb = {0, 0};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        suma[(i + j) & 1] += a[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        sumb[(i + j) & 1] += b[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int side = 4;
        side -= (i == 0);
        side -= (i == n - 1);
        side -= (j == 0);
        side -= (j == m - 1);
        if (side != a[i][j] + b[i][j]) {
          cout << "Nostad\n";
          return;
        }
      }
    }

    if (suma[0] != sumb[1] || suma[1] != sumb[0]) {
      cout << "Nostad\n";
      return;
    }

    int s = 2 * n * m + 1, t = 2 * n * m + 2;
    Dinic g(t);
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) & 1) {
          g.addEdge(s, i * m + j, a[i][j]);
          for (int dir = 0; dir < 4; dir++) {
            int u = i + dx[dir];
            int v = j + dy[dir];
            if (min(u, v) >= 0 && u < n && v < m) {
              int lef = i * m + j;
              int rig = u * m + v;
              g.addEdge(lef, rig + n * m, 1);
              count++;
            }
          }
        } else {
          g.addEdge(i * m + j + n * m, t, b[i][j]);
        }
      }
    }

    int res = g.maxflow(s, t);
    // cout << res << "\n";
    if (count == suma[0] + suma[1] && res == suma[1]) {
      cout << "Ostad\n";
    } else {
      cout << "Nostad\n";
    }
  };

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
}
