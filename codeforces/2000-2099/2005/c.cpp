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
    int n, m;
    cin >> n >> m;
    char a[n + 1][m];
    for(int i = 1; i <= n; ++i) {
      for(int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    char b[] = {'n', 'a', 'r', 'e', 'k'};
    int dp[n + 1][5];
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j < 5; ++j)
        dp[i][j] = -1e9;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
      for(int sn = 0; sn < 5; ++sn) {
        int n = 0, g = 0, cnt = 0;
        n = sn;
        for(int j = 0; j < m; ++j) {
          if(a[i][j] == b[n % 5]) {
            ++n, ++cnt;
          }
          else {
            bool y = 0;
            for(auto x : b) {
              if(x == a[i][j])
                y = true;
            }
            if(y)
              ++g;
          }
        }
        dp[i][n % 5] = max(dp[i][n % 5], dp[i - 1][sn] + cnt - g);
        dp[i][sn] = max(dp[i][sn], dp[i - 1][sn]);
      }
      // for(int j = 0; j < 5; ++j)
      //   cerr << dp[i][j] << " ";
      // cerr << endl;
    }
    int res = 0;
    for(int i = 0; i < 5; ++i)
      res = max(res, dp[n][i] - 2 * i);
    cout << res << endl;
  }
  return 0;
}