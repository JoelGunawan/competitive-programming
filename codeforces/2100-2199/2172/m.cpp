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
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 5];
  vector<int> product[k + 5];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    product[a[i]].push_back(i);
  }
  vector<int> edges[n + 5];
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int dist[n + 5];
  memset(dist, -1, sizeof(dist));
  queue<pair<int, int>> bfs;
  bfs.emplace(1, 0);
  while (bfs.size()) {
    auto [nd, d] = bfs.front();
    bfs.pop();
    if (dist[nd] != -1) continue;
    dist[nd] = d;
    for (auto &nb : edges[nd]) if (dist[nb] == -1) bfs.emplace(nb, d + 1);
  }

  for (int i = 1; i <= k; ++i) {
    int res = 0;
    for (auto &d : product[i]) {
      res = max(res, dist[d]);
      // cerr << i << " " << d << " " << dist[d] << endl;
    }
    cout << res << " ";
  }
  cout << endl;
  
  return 0;
}