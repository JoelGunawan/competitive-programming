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
const int lim = 405;
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
    return x != y;
  }
};
void tc() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, pair<int, int>>> adj;
  vector<int> edges[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj.pb(mp(w, mp(u, v)));
    edges[u].pb(v);
    edges[v].pb(u);
  }
  int a[q + 1], b[q + 1], k[q + 1], ans[q + 1];
  for(int i = 1; i <= q; ++i)
  cin >> a[i] >> b[i] >> k[i];
  fill(ans, ans + q + 1, 1e9);
  sort(adj.begin(), adj.end());
  disjoint_set dsu;
  int dist[n + 1][n + 1];
  memset(dist, -1, sizeof(dist));
  for (int i = 1; i <= n; ++i) {
    queue<pair<int, int>> bfs;
    bfs.push(mp(i, 0));
    while(bfs.size()) {
      int nd = bfs.front().fi, d = bfs.front().se;
      bfs.pop();
      if(dist[i][nd] != -1)
        continue;
      dist[i][nd] = d;
      for(auto j : edges[nd]) {
        if(dist[i][j] == -1)
          bfs.push(mp(j, d + 1));
      }
    }
  }
  for(auto p : adj) {
    int l = dsu.fh(p.se.fi), r = dsu.fh(p.se.se);
    if(dsu.merge(p.se.fi, p.se.se)) {
      if (dsu.fh(p.se.fi) == l) {
        for(int i = 1; i <= n; ++i) {
          int cur = dsu.fh(i);
          if(cur == i) {
            dist[cur][l] = min(dist[cur][l], dist[cur][r]);
            dist[l][cur] = dist[cur][l];
          }
        }
        for(int i = 1; i <= n; ++i) {
          for(int j = 1; j <= n; ++j) {
            int cl = dsu.fh(i), cr = dsu.fh(j);
            if(cl == i && cr == j) {
              dist[cl][cr] = min(dist[cl][cr], dist[cl][l] + dist[cr][l]);
              dist[cr][cl] = dist[cl][cr];
            }
          }
        }
      }
      else {
        for(int i = 1; i <= n; ++i) {
          int cur = dsu.fh(i);
          if(cur == i) {
            dist[cur][r] = min(dist[cur][l], dist[cur][r]);
            dist[r][cur] = dist[cur][r];
          }
        }
        for(int i = 1; i <= n; ++i) {
          for(int j = 1; j <= n; ++j) {
            int cl = dsu.fh(i), cr = dsu.fh(j);
            if(cl == i && cr == j) {
              dist[cl][cr] = min(dist[cl][cr], dist[cl][r] + dist[cr][r]);
              dist[cr][cl] = dist[cl][cr];
            }
          }
        }
      }
      int val[n + 1];
      for(int i = 1; i <= n; ++i)
        val[i] = dsu.fh(i);
      for (int i = 1; i <= q; ++i) {
        // cerr << "CHECK QUERY " << p.fi << " " << a[i] << " " << b[i] << " " << k[i] << " " << dist[val[a[i]]][val[b[i]]] << endl;
        if (dist[val[a[i]]][val[b[i]]] < k[i]) {
          ans[i] = min(ans[i], p.fi);
        }
      }
    }
  }
  for(int i = 1; i <= q; ++i)
    cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}