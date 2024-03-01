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
  // kind of "greedy"
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[2][n + 1];
    a[0][n] = a[1][n] = 2;
    for(int i = 0; i < 2; ++i)
      for(int j = 0; j < n; ++j) {
        char x;
        cin >> x;
        a[i][j] = x - '0';
      }
    bool valid[2][n + 1];
    memset(valid, 0, sizeof(valid));
    for(int i = 0; i <= n; ++i) {
      if(i == 0) {
        valid[0][0] = 1;
        if(a[0][1] == a[1][0])
          valid[0][1] = valid[1][0] = 1;
        else if(a[0][1] < a[1][0])
          valid[0][1] = 1;
        else
          valid[1][0] = 1;
      }
      else if(i == n) {
        valid[1][n - 1] = 1;
      }
      else {
        if(valid[0][i]) {
          // both valid, choose min as valid
          int mn = min(a[0][i + 1], a[1][i]);
          if(mn == a[0][i + 1])
            valid[0][i + 1] = 1;
          if(mn == a[1][i])
            valid[1][i] = 1;
        }
        else if(valid[1][i - 1])
          valid[1][i] = 1;
      }
    }
    for(int i = n - 2; i >= 0; --i) {
      if(!valid[1][i + 1])
        valid[1][i] = 0;
    }
    int dp[2][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < n; ++j) {
        if(!valid[i][j])
          continue;
        if(i == 0 && j == 0)
          dp[i][j] = 1;
        else {
          if(i > 0)
            dp[i][j] += dp[i - 1][j];
          if(j > 0)
            dp[i][j] += dp[i][j - 1];
        }
      }
    }
    pair<int, int> x = mp(0, 0);
    string res = to_string(a[0][0]);
    while(x != mp(1, n - 1)) {
      if(x.fi == 1) {
        // move down
        res += to_string(a[x.fi][++x.se]);
      }
      else {
        // try optimal
        if(valid[x.fi + 1][x.se]) {
          res += to_string(a[++x.fi][x.se]);
        }
        else {
          res += to_string(a[x.fi][++x.se]);
        }
      }
    }
    cout << res << endl << dp[1][n - 1] << endl;
  }
  return 0;
}