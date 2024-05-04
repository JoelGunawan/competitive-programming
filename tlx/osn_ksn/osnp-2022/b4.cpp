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
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if(n == 1) {
    ll dp[m + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= m; ++i) {
      dp[i][1] = dp[i - 1][1] + 2 * dp[i - 1][0];
      dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1];
      dp[i][0] %= mod;
      dp[i][1] %= mod;
    }
    cout << (dp[m][0] + dp[m][1]) % mod << endl;
  }
  else {
    ll dp[m + 1][4];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = dp[1][3] = 1;
    dp[1][2] = 2;
    for(int i = 2; i <= m; ++i) {
      dp[i][0] = (dp[i - 1][0] + 3 * dp[i - 1][1] + 2 * dp[i - 1][2] + 4 * dp[i - 1][3]) % mod;
      dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1] + 4 * dp[i - 1][2] + 2 * dp[i - 1][3]) % mod;
      dp[i][2] = (3 * dp[i - 1][0] + 7 * dp[i - 1][1] + 2 * dp[i - 1][2] + 3 * dp[i - 1][3]) % mod;
      dp[i][3] = dp[i][0];
    }
    cout << (dp[m][0] + 2 * dp[m][1] + dp[m][2] + dp[m][3]) % mod;
  }
  return 0;
}