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
  int n = 1000;
  char a[] = {'.', '^', '<', 'v', '>'};
  char grid[2 * n + 5][2 * n + 5];
  bool vis[2 * n + 5][2 * n + 5];
  memset(grid, 0, sizeof(grid));
  memset(vis, 0, sizeof(vis));
  int posx = n, posy = n + 1;
  grid[n + 1][n + 1] = a[1];
  vis[n + 1][n + 1] = 1;
  vis[posx][posy] = 1;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for(int i = 0; i <= 2 * n + 2; ++i) {
    vis[0][i] = 1;
    vis[2 * n + 2][i] = 1;
    vis[i][0] = 1;
    vis[i][2 * n + 2] = 1;
  }
  while(true) {
    // make random path
    int dir = rng() % 4;
    ++dir;
    if(vis[posx + 1][posy] && vis[posx - 1][posy] && vis[posx][posy - 1] && vis[posx][posy + 1]) {
      grid[posx][posy] = 'G';
      break;
    }
    grid[posx][posy] = a[dir];
    if(dir == 1) {
      --posx;
      if(vis[posx][posy]) {
        ++posx;
        continue;
      }
    }
    else if(dir == 2) {
      --posy;
      if(vis[posx][posy]) {
        ++posy;
        continue;
      }
    }
    else if(dir == 3) {
      ++posx;
      if(vis[posx][posy]) {
        --posx;
        continue;
      }
    }
    else {
      ++posy;
      if(vis[posx][posy]) {
        --posy;
        continue;
      }
    }
    vis[posx][posy] = 1;
  }
  cout << n << endl;
  for(int i = 1; i <= 2 * n + 1; ++i) {
    for(int j = 1; j <= 2 * n + 1; ++j) {
      if(grid[i][j] == 0)
        grid[i][j] = a[0];
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}