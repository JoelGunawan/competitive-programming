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
  int b;
  string y;
  cin >> b >> y;
  int n = y.size();
  y = " " + y;
  ll dp[n + 1];
  memset(dp, 0, sizeof(dp)), dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    // check the last x chars
    // check if it is less than y
    for(int j = 0; j < 6 && i - j > 0; ++j) {
      int cur = 0;
      for(int k = i - j; k <= i; ++k) {
        cur = (cur * 10) + (y[k] - '0');
      }
      if(cur < b && (y[i - j] != '0' || j == 0))
        dp[i] += dp[i - j - 1];
    }
    dp[i] %= mod;
  }
  cout << dp[n] << endl;
  return 0;
}