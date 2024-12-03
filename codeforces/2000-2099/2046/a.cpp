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
  while(t--) {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    for(int i = 1; i <= n; ++i)
      cin >> b[i];
    ll dp[n + 1][2];
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j < 2; ++j)
        dp[i][j] = -1e18;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
      dp[i][1] = max(dp[i - 1][1] + max(a[i], b[i]), dp[i - 1][0] + a[i] + b[i]);
      dp[i][0] = dp[i - 1][0] + max(a[i], b[i]);
    }
    cout << dp[n][1] << endl;
  }
  return 0;
}