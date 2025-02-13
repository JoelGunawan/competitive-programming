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
    int s[n + 1];
    int tags[n + 1];
    for(int i = 1; i <= n; ++i)
    cin >> tags[i];
    for(int i = 1; i <= n; ++i)
    cin >> s[i];
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    ll plr[n + 1], pr[n + 1];
    memset(plr, 0, sizeof(plr));
    memset(pr, 0, sizeof(pr));
    ll res = 0;
    // have plr
    // have insert
    for(int i = 2; i <= n; ++i) {
      memset(dp, 0, sizeof(dp));
      // case of pr
      for(int j = i - 1; j >= 1; --j) {
        dp[j] = max(dp[j + 1], tags[j] == tags[i] ? 0ll : pr[j] + abs(s[i] - s[j]));
      }
      // case of plr
      for(int j = i - 1; j >= 1; --j) {
        dp[j] = max({dp[j], dp[j + 1], tags[i] == tags[j] ? 0ll : plr[j] + abs(s[i] - s[j])});
        res = max(res, dp[j]);
      }
      ll mx = 0;
      for(int j = i - 1; j >= 1; --j) {
        // from i to j to some R
        if(tags[i] != tags[j])
          plr[j] = max(plr[j], mx + abs(s[i] - s[j]));
        // plr[j] also counts maxL
        res = max(res, plr[j]);
        mx = max(mx, dp[j]);
      }
      // from i to some R
      pr[i] = mx;
    }
    cout << res << endl;
  }
  return 0;
}