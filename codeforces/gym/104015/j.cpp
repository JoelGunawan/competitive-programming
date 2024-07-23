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
  // dp[n][i] -> min changes for first n chars with last char equal to i
  // do dp backtrack :D
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  int dp[n + 1][26];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; ++i) {
    int mn = 1e9;
    for(int j = 0; j < 26; ++j) {
      mn = min(mn, dp[i - 1][j]);
      dp[i][j] = mn + (s[i] == 'a' + j ? 0 : 1);
    }
  }
  pair<int, int> mnres = mp((int)1e9, (int)1e9);
  for(int i = 0; i < 26; ++i) {
    mnres = min(mnres, mp(dp[n][i], i));
  }
  pair<int, int> cur = mp(n, mnres.se);
  string res = "";
  while(cur.fi != 0) {
    res += ('a' + cur.se);
    pair<int, int> mn = mp((int)1e9, (int)1e9);
    for(int j = 0; j <= cur.se; ++j) {
      mn = min(mn, mp(dp[cur.fi - 1][j], j));
    }
    cur = mp(cur.fi - 1, mn.se);
  }
  reverse(res.begin(), res.end());
  cout << mnres.fi << endl;
  cout << res << endl;
  return 0;
}