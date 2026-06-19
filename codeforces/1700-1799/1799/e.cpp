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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    array<array<bool, m + 5>, n + 5> a;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        char x;
        cin >> x;
        a[i][j] = x == '#';
      }
    }

    // step: "normalize", if (i, j) and (i, k) exists, then (i, x), [x \in [j + 1, k - 1]] must exist
    // claim: that is the only lemma, other than the fact we need to find a nice way to connect the two cities
    // if two cities are completely disjoint, then we can find a "shortest path" relatively trivially
    // assume we are on the "left" partition, then the right most position needs to extend downwards/upwards
    // we extend as we need to the correct "height", then we fill everything accordingly
    // it is also possible to do it the opposite way, i.e. check vertical first

    // normalize step for each cc
    array<array<bool, m + 5>, n + 5> vis;
    array<int, n + 5> mxh, mnh;
    array<int, m + 5>, mxv, mnv;
    vector<pair<int, int>> nx = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
    std::function<void(int, int)> dfs_cc = [&] (int x, int y) {
      vis[x][y] = 1;
      mxh[x] = max(mxh[x], y);
      mnh[x] = min(mnh[x], y);
      mxv[y] = max(mxv[y], x);
      mnv[y] = min(mnv[y], x);

      for (auto [nx, ny] : nx) {
        if (a[x + nx][y + ny] && !vis[x + nx][y + ny]) {
          dfs_cc(x + nx, y + ny);
        }
      }
    };

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (!vis[i][j] && a[i][j]) {
          for (int k = 1; k <= n; ++k)
            mxh[k] = m + 1, mnh[k] = 0;
          for (int k = 1; k <= m; ++k)
            mxv[k] = n + 1, mnv[k] = 0;
          // check cc + normalize
          dfs_cc(i, j);

          for (int k = 1; k <= n; ++k) {
            for (int l = mnh[k]; l <= mxh[k]; ++l) {
              vis[k][l] = 1;
              a[k][l] = 1;
            }
          }

          for (int k = 1; k <= m; ++k) {
            for (int l = mnv[k]; l <= mxv[k]; ++l) {
              vis[l][k] = 1;
              a[l][k] = 1;
            }
          }
        }
      }
    }

    // check if one cc
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j)
        vis[i][j] = 0;
    }
    std::function<void(int, int)> dfs = [&] (int x, int y) {
      vis[x][y] = 1;
      for (auto [nx, ny] : nx) {
        if (a[x + nx][y + ny] && !vis[x + nx][y + ny]) {
          dfs_cc(x + nx, y + ny);
        }
      }
    };
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] && !vis[i][j]) {
          dfs(i, j);
          ++cnt;
        }
      }
    }

    if (cnt == 1) {
      // output
    }

    
  }
  return 0;
}