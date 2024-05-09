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
int mod = 998244353;
const int lim = 105;
struct disjoint_set {
  int h[lim], sz[lim], l[lim], r[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
    for(int i = 0; i < lim; ++i)
      l[i] = r[i] = i;
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      h[y] = x;
      l[x] = min(l[x], l[y]);
      r[x] = max(r[x], r[y]);
      sz[x] += sz[y];
    }
    return x != y;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int c[n + 1][n + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) {
      cin >> c[i][j];
    }
  }
  /*
  for(int i = 1; i <= n; ++i) {
    if(c[i][i] == 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  */
  disjoint_set dsu;
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) {
      if(c[i][j] == 1) {
        for(int k = i; k <= j; ++k)
          dsu.merge(i, k);
      }
    }
  }
  bool invalid[n + 1][n + 1];
  memset(invalid, 0, sizeof(invalid));
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) {
      if(c[i][j] == 2) {
        invalid[i][j] = 1;
      }
    }
  }
  for(int i = 1; i < n; ++i) {
    for(int j = 1; j + i <= n; ++j) {
      // cout << "Set invalid: " << i << " " << i + j << endl;
      invalid[j][j + i] = invalid[j + 1][j + i] | invalid[j][j + i - 1] | invalid[j][j + i];
    }
  }
  ll dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 2;
  for(int i = 1; i <= n; ++i) {
    // dp, has to satisfy all the constraints
    for(int j = 1; j <= i; ++j) {
      // try transition, observe that it can not be a "super" subarray of L, R that has
      // 2 unique
      // cout << j << " " << i << " " << invalid[j][i] << " " << dsu.l[dsu.fh(j)] << " " << dsu.r[dsu.fh(i)] << endl;
      if(!invalid[j][i] && dsu.l[dsu.fh(j)] >= j && dsu.r[dsu.fh(i)] <= i) {
        // cout << "add " << i << " " << dp[j - 1] << endl;
        dp[i] += dp[j - 1];
        dp[i] %= mod;
      }
    }
    dp[i] %= mod;
  }
  cout << dp[n] << endl;
  return 0;
}