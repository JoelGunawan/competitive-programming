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
  int dp[(int)1e6 + 5];
  while(t--) {
    int a, b, m;
    cin >> a >> b >> m;
    for(int i = 0; i <= m; ++i)
      dp[i] = 0;
    dp[0] = 2;
    for(int i = 1; i <= m; ++i) {
      dp[i] = dp[i - 1];
      if(i >= a)
        dp[i] = max(dp[i], dp[i - a] + 1);
      if(i >= b) {
        dp[i] = max(dp[i], dp[i - b] + 1 + b / a);
        if(i >= (b + a - (b % a))) {
          dp[i] = max(dp[i], dp[i - (b + a - (b % a))] + 1 + (b + a - (b % a)) / a);
        }
      }
    }
    cout << 1ll * dp[m] * 160 << endl;
  }
  return 0;
}