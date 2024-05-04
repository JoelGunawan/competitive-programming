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
bool vis[105][105];
bool valid[105][105];
int a[105][105];
// D, U, R, L
vector<pair<int, int>> nxt = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
int dfs(int x, int y, vector<int> &v) {
  v.pb(a[x][y]);
  vis[x][y] = 1;
  int mn = 1e9;
  for(auto p : nxt) {
    if(!vis[x + p.fi][y + p.se] && valid[x + p.fi][y + p.se])
      mn = min(mn, dfs(x + p.fi, y + p.se, v));
    else if(!valid[x + p.fi][y + p.se]) {
      mn = min(mn, a[x + p.fi][y + p.se]);
    }
  }
  return mn;
}
void tc() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  // Idea: BFS/DFS, cek node yang terurut tidak menurun dari ujung
  // Use BFS
  queue<pair<int, int>> bfs;
  for(int i = 1; i <= n; ++i) {
    bfs.push(make_pair(i, 1));
    bfs.push(make_pair(i, m));
  }
  for(int i = 1; i <= m; ++i) {
    bfs.push(make_pair(1, i));
    bfs.push(make_pair(n, i));
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      vis[i][j] = 0;
      valid[i][j] = 1;
    }
  }
  while(bfs.size()) {
    int x = bfs.front().fi, y = bfs.front().se;
    bfs.pop();
    if(vis[x][y])
      continue;
    vis[x][y] = 1;
    valid[x][y] = 0;
    for(auto p : nxt) {
      if(x + p.fi > 0 && x + p.fi <= n && y + p.se > 0 && y + p.se <= m && a[x][y] <= a[x + p.fi][y + p.se] && !vis[x + p.fi][y + p.se])
        bfs.push(mp(x + p.fi, y + p.se));
    }
  }
  // dfs yg valid
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      vis[i][j] = 0;
    }
  }
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(valid[i][j] && !vis[i][j]) {
        vector<int> v = {};
        int mn_wall = dfs(i, j, v);
        for(auto x : v) {
          res += mn_wall - x;
        }
      }
    }
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  memset(vis, 0, sizeof(vis));
  memset(valid, 0, sizeof(valid));
  while(t--) {
    tc();
    if(t != 0)
      cout << endl;
  }
  return 0;
}