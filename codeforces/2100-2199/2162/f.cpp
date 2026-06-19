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
    // ans \in \{0, 1, 2\}
    // ans = 0 -> all segments contain some x
    // ans = 1 -> all segments does not contain some x OR contain(0) -> contain(1)
    // ans = 2 -> else
    int diff[n + 5];
    memset(diff, 0, sizeof(diff));
    pair<int, int> p[m];
    for (int i = 0; i < m; ++i) {
      cin >> p[i].fi >> p[i].se;
      ++diff[p[i].fi];
      --diff[p[i].se + 1];
    }

    int mx = 0;
    bool has_empty = 0;
    for (int i = 1; i <= n; ++i) {
      diff[i] += diff[i - 1];
      mx = max(mx, diff[i]);
      if (diff[i] == 0)
        has_empty = 1;
    }
    if (mx == m) {
      // diff[i] == n contains 0, rest is whatever
      int ans[n + 5];
      memset(ans, -1, sizeof(ans));
      for (int i = 1; i <= n; ++i) {
        if (diff[i] == m) {
          ans[i] = 0;
          break;
        }
      }

      for (int i = 1, cur = 1; i <= n; ++i) {
        if (ans[i] == -1) {
          ans[i] = cur++;
        }
      }

      for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
      }
      cout << endl;
      continue;
    } else if (has_empty) {
      // diff[i] == 0 contains 0, rest is whatever
      int ans[n + 5];
      memset(ans, -1, sizeof(ans));
      for (int i = 1; i <= n; ++i) {
        if (diff[i] == 0) {
          ans[i] = 0;
          break;
        }
      }

      for (int i = 1, cur = 1; i <= n; ++i) {
        if (ans[i] == -1) {
          ans[i] = cur++;
        }
      }

      for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
      }
      cout << endl;
      continue;
    }
    
    // if 0 is located at x, then optimally 1 is at x - 1 or x + 1
    // then, all segments that contain x must contain x - 1 OR all segments that contain x must contain x + 1
    // try each position of x
    int ans[n + 5];
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
      // try i, i + 1
      if (i != n) {
        bool pos = 1;
        for (auto [l, r] : p) {
          if (l <= i && r >= i) {
            if (r == i) {
              pos = 0;
              break;
            }
          }
        }

        if (pos) {
          ans[i] = 0, ans[i + 1] = 1;

          for (int j = 1, cur = 2; j <= n; ++j) {
            if (ans[j] == -1) {
              ans[j] = cur++;
            }
          }
        }
      }

      if (ans[1] != -1)
        break;

      // try i, i - 1
      if (i != 1) {
        bool pos = 1;
        for (auto [l, r] : p) {
          if (l <= i && r >= i) {
            if (l == i) {
              pos = 0;
              break;
            }
          }
        }

        if (pos) {
          ans[i] = 0, ans[i - 1] = 1;

          for (int j = 1, cur = 2; j <= n; ++j) {
            if (ans[j] == -1) {
              ans[j] = cur++;
            }
          }
        }
      }

      if (ans[1] != -1)
        break;
    }

    if (ans[1] != -1) {
      for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
      cout << endl;
    } else {
      cout << "0 2 1 ";
      for (int i = 3; i < n; ++i) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}