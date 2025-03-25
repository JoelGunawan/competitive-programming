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
  int n, m;
  cin >> n >> m;
  vector<int> edges[n + 5][26];
  vector<int> vals[n + 5];
  vector<int> inv[n + 5][26];
  for(int i = 1; i <= m; ++i) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    edges[u][c - 'a'].pb(v);
    vals[u].pb(c - 'a');
    inv[v][c - 'a'].pb(u);
  }
  for(int i = 1; i <= n; ++i) {
    sort(vals[i].begin(), vals[i].end());
    vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
  }
  bool vis[n + 1][n + 1];
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int>> bfs;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 26; ++j) {
      for(auto x : edges[i][j]) {
        if(!vis[i][x]) {
          bfs.push(mp(i, x));
          vis[i][x] = 1;
        }
      }
    }
    bfs.push(mp(i, i));
    vis[i][i] = 1;
  }
  while(bfs.size()) {
    int x = bfs.front().fi, y = bfs.front().se;
    bfs.pop();
    for(auto i : vals[y]) {
      for(auto j : inv[x][i]) {
        for(auto k : edges[y][i]) {
          if(!vis[j][k]) {
            // cerr << x << " " << y << " " << j << " " << k << endl;
            vis[j][k] = 1;
            bfs.push(mp(j, k));
          }
        }
      }
    }
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(i != j && vis[i][j]) {
        // cerr << i << " " << j << endl;
        res += vis[i][j];
      }
    }
  }
  cout << res << endl;
  return 0;
}