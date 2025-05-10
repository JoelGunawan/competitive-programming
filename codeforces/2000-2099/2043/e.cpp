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
const int lim = 4e3 + 5;
vector<int> edges[lim];
bool active[lim], vis[lim];
bool dfs(int nd) {
  vis[nd] = 1;
  active[nd] = 1;
  for(auto x : edges[nd]) {
    if(vis[x] && active[x]) {
      return 0;
    }
    if(!vis[x]) {
      bool ret = dfs(x);
      if(!ret)
        return 0;
    }
  }
  active[nd] = 0;
  return 1;
}
void tc() {
  int n, m;
  cin >> n >> m;
  int a[n + 2][m + 2], b[n + 2][m + 2];
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> b[i][j];
  int col_shift = 1000;
  int supermask = 1 << 30;
  --supermask;
  for(int bit = 0; bit < 30; ++bit) {
    set<int> unchanged;
    for(int i = 1; i <= n; ++i) {
      unchanged.ins(i);
      edges[i].clear();
      vis[i] = active[i] = 0;
    }
    for(int i = 1; i <= m; ++i) {
      unchanged.ins(i + col_shift);
      edges[i + col_shift].clear();
      vis[i + col_shift] = active[i + col_shift] = 0;
    }
    int mask = 1 << bit;
    queue<pair<int, int>> check;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        check.push({i, j});
      }
    }
    while(check.size()) {
      auto [i, j] = check.front();
      check.pop();
      if((mask & a[i][j]) != (mask & b[i][j])) {
        if(mask & a[i][j]) {
          if(unchanged.count(i)) {
            // 1 -> 0 (need to do row)
            for(int j = 1; j <= m; ++j) {
              a[i][j] &= supermask ^ mask; // remove this bit from all elements in this column, then recheck
              check.push({i, j});
              if((b[i][j] & mask) > 0) {
                edges[i].push_back(j + col_shift);
              }
            }
            unchanged.erase(i);
          }
        }
        else {
          if(unchanged.count(j + col_shift)) {
            // 0 -> 1 (need to do column)
            for(int i = 1; i <= n; ++i) {
              a[i][j] |= mask;
              check.push({i, j});
              if((b[i][j] & mask) == 0) {
                edges[j + col_shift].push_back(i);
              }
            }
            unchanged.erase(j + col_shift);
          }
        }
      }
    }
    for(int i = 1; i <= n; ++i) {
      if(!vis[i] && !dfs(i)) {
        cout << "No" << endl;
        return;        
      }
    }
    for(int i = 1; i <= m; ++i) {
      if(!vis[i + col_shift] && !dfs(i + col_shift)) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}