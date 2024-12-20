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
  int n;
  cin >> n;
  ll a[3][n + 1];
  for(int i = 0; i < 3; ++i)
    for(int j = 1; j <= n; ++j)
      cin >> a[i][j];
  // last pos, index
  ll dp[3][n + 1];
  const ll inf = 1e18;
  for(int i = 0; i < 3; ++i)
    fill(dp[i], dp[i] + n + 1, -inf);
  // dp[1] is already calculated
  dp[0][1] = a[0][1];
  dp[1][1] = a[0][1] + a[1][1];
  dp[2][1] = a[0][1] + a[1][1] + a[2][1];
  // take block, special case need to handle. after that just take 2/3
  dp[0][2] = dp[2][2] = a[0][1] + a[1][1] + a[2][1] + a[0][2] + a[1][2] + a[2][2];
  for(int i = 2; i <= n; ++i) {
    ll tmp = max(dp[0][i - 2], dp[2][i - 2]) + a[0][i - 1] + a[1][i - 1] + a[2][i - 1] + a[0][i] + a[1][i] + a[2][i];
    dp[0][i] = max({tmp, dp[0][i], dp[0][i - 1] + a[0][i], dp[1][i - 1] + a[0][i] + a[1][i], dp[2][i - 1] + a[0][i] + a[1][i] + a[2][i]});
    dp[1][i] = max({dp[1][i], dp[0][i - 1] + a[0][i] + a[1][i], dp[1][i - 1] + a[1][i], dp[2][i - 1] + a[2][i] + a[1][i]});
    dp[2][i] = max({tmp, dp[2][i], dp[0][i - 1] + a[0][i] + a[1][i] + a[2][i], dp[1][i - 1] + a[1][i] + a[2][i], dp[2][i - 1] + a[2][i]});
  }
  cout << dp[2][n] << endl;
  return 0;
}