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
  char a[n + 1][m + 1];
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  queue<pair<int, pair<pair<int, int>, pair<int, int>>>> bfs;
  vector<pair<int, int>> candy_corn;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'S')
        bfs.push(mp(0, mp(mp(i, j), mp(0, 0))));
      else if(a[i][j] == 'C')
        candy_corn.pb(mp(i, j));
    }
  }
  int cc[n + 1][m + 1];
  memset(cc, -1, sizeof(cc));
  for(int i = 0; i < candy_corn.size(); ++i) {
    cc[candy_corn[i].fi][candy_corn[i].se] = i;
  }
  vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
  int dist[n + 1][m + 1][1 << candy_corn.size()][candy_corn.size() + 1];
  bool vis[n + 1][m + 1][1 << candy_corn.size()][candy_corn.size() + 1];
  while(bfs.size()) {
    int d = bfs.front().fi, x = bfs.front().se.fi, y = bfs.front().se.se;
    bfs.pop();
    if(dist[])
  }
  return 0;
}