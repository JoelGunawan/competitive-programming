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
const int lim = 100;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  bool mul[n + 1];
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    char x;
    cin >> x >> a[i];
    mul[i] = x == 'm';
  }
  ll dp[n + 1][min(n, lim) + 1][min(30, k + 1)];
  memset(dp, 0, sizeof(dp));
  // cerr << "HERE" << endl;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= min(n, lim); ++j){
      for(int l = 0; l < min(30, k + 1); ++l){ 
        // cerr << i << " " << j << " " << l << endl;
        dp[i][j][l] = dp[i - 1][j][l];
        if(j > 0) {
          if(mul[i] && l > 0)
              dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1] * a[i]);
          else if(!mul[i])
            dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l] + a[i]);
        }
        // cerr << i << " " << j << " " << l << " " << dp[i][j][l] << endl;
      }
    }
  }
  for(int i = 1; i <= min(n, lim); ++i) {
    ll cur = 0;
    for(int j = 0; j < min(30, k + 1); ++j)
      cur = max(cur, dp[n][i][j]);
    cout << cur << endl;
  }
  if(n > lim) {
    // for all n > lim, try all configurations of first 10 muls, last muls can be whatever
    // works for n larger than 50 ish
    vector<int> muls;
    for(int i = 1; i <= n; ++i)
      if(mul[i])
        muls.pb(i);
    for(int i = 0; i < (1 << min(muls.size(), 10)); ++i) {
      // take the first 10 things from mul and activate them
      // all behind will be activated
      // do dp size n
    }
  }
  return 0;
}