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
  int n;
  cin >> n;
  if(n <= 2) {
    cout << n << endl;
    return 0;
  }
  vector<int> allow[n + 5];
  for(int i = 3; i <= n; ++i) {
    for(int j = 2 * i; j <= n; j += i)
      allow[j].pb(i);
  }
  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[2] = 1;
  for(int i = 2; i <= n; i += 4)
    allow[i].pb(2);
  for(int i = 3; i < n; ++i) {
    // add all
    dp[i] = 1;
    for(int j = i - 1; j <= i + 1; ++j)
      for(auto x : allow[j]) {
        // guaranteed no dupe
        dp[i] += dp[x];
        if(dp[i] >= mod) 
          dp[i] -= mod;
      }
    cout << dp[i] << " ";
  }
  cout << endl;
  // case dari 1 lgsg ke n
  ll res = 1;
  for(int i = 3; i < n; ++i) {
    res += dp[i];
  }
  cout << (2 * n * res) % mod << endl;
  return 0;
}