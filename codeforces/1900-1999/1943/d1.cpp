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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, k, p;
    cin >> n >> k >> p;
    // dp[n][k[n - 1]][k[n]]
    int dp[2][k + 1][k + 1];
    // pre[pos][k][kdiff]
    int pre[2][k + 1][k + 1];
    memset(dp, 0, sizeof(0));
    memset(pre, 0, sizeof(pre));
    dp[0][0][0] = 1;
    for(int i = 0; i <= k; ++i) {
      pre[0][0][i] = 1;
    }
    for(int i = 1; i <= n + 1; ++i) {
      for(int j = 0; j <= k; ++j) {
        for(int l = 0; l <= k; ++l) {
          dp[i & 1][j][l] = (pre[(i - 1) & 1][j][k] - (j - l - 1 < 0 ? 0 : pre[(i - 1) & 1][j][j - l - 1])) % p;
        }
      }
      for(int j = 0; j <= k; ++j) {
        for(int l = 0; l <= k; ++l) {
          pre[i & 1][j][l] = ((l == 0 ? 0 : pre[i & 1][j][l - 1]) + dp[i & 1][l][j]) % p;
        }
      }
    }
    ll res = 0;
    for(int i = 0; i <= k; ++i)
      res += dp[(n + 1) & 1][i][0];
    res %= p;
    if(res < 0)
      res += p;
    cout << res << endl;
  }
  return 0;
}