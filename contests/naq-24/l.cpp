#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #define endl "\n"
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
vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
bool vis[15][15];
char a[15][15];
int x, y, d, len;
bool f() {
  // check up left right down
  vis[x][y] = 1;
  for(auto p : nxt) {
    if(a[x + p.fi][y + p.se] == 'Z')
      continue;
    if(a[x + p.fi][y + p.se] >= 'a' + len - d) {
      return true;
    }
    if(a[x + p.fi][y + p.se] == '.' && !vis[x + p.fi][y + p.se]) {
      // go there
      x += p.fi, y += p.se, ++d;
      if(f())
        return true;
      x -= p.fi, y -= p.se, --d;
    }
  }
  vis[x][y] = 0;
  return false;
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  // check 2 things:
  // - direct path
  // - can visit previous snake
  // anything other than that, not possible
  for(int i = 0; i <= n + 1; ++i)
    for(int j = 0; j <= m + 1; ++j)
      a[i][j] = 'Z';
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= m; ++j) {
      if(a[i][j] >= 'a' && a[i][j] <= 'f')
        a[i][j] += 10;
      else if(a[i][j] >= '0' && a[i][j] <= '9')
        a[i][j] = 'a' - '0' + a[i][j];
      if(a[i][j] >= 'a' && a[i][j] <= 'z')
        len = max(len, a[i][j] - 'a');
    }
  }
  // if find path directly to A, just do it
  bool vis[n + 1][m + 1];
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int>> bfs;
  pair<int, int> st;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'a')
        bfs.push(mp(i, j)), st = mp(i, j);
    }
  } 
  while(bfs.size()) {
    int x = bfs.front().fi, y = bfs.front().se;
    bfs.pop();
    if(vis[x][y])
      continue;
    vis[x][y] = 1;
    if(a[x][y] == 'A') {
      cout << 1 << endl;
      return 0;
    }
    for(auto p : nxt) {
      if(!vis[x + p.fi][y + p.se] && (a[x + p.fi][y + p.se] == '.' || a[x + p.fi][y + p.se] == 'A'))
        bfs.push(mp(x + p.fi, y + p.se));
    }
  }
  if(n == 1 || m == 1) {
    cout << 0 << endl;
    return 0;
  }
  // there is no case for len = 2
  // only larger lengths, find whether we can go back through previously passed point
  x = st.fi, y = st.se;
  cout << f() << endl;
  return 0;
}