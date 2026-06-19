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
  while (t--) {
    int n;
    cin >> n;
    int a[n + 5], c[n + 5];
    ll pref[n + 5];
    pref[0] = 0;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    for (int i = 1; i <= n; ++i)
      cin >> c[i], pref[i] = pref[i - 1] + c[i];
    a[n + 1] = 1e9 + 5;
    ll dp[n + 5];
    for (int i = 1; i <= n + 1; ++i)
      dp[i] = 1e18;
    dp[0] = 0;
    a[0] = 0;
    for(int i = 1; i <= n + 1; ++i) {
      for(int j = 0; j < i; ++j) {
        if(a[i] >= a[j]) {
          dp[i] = min(dp[i], dp[j] + pref[i - 1] - pref[j]);
        }
      }
    }
    cout << dp[n + 1] << endl;
  }
  return 0;
}