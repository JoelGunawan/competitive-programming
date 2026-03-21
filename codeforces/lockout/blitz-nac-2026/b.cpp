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
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> cand[n + 5];
  int dp[n + 5];
  memset(dp, 0, sizeof(dp));
  
  vector<int> vals[n + 5];
  for (int i = 1; i <= n; ++i) {
    vals[a[i]].push_back(i);
    dp[i] = dp[i - 1];
    if (vals[a[i]].size() >= a[i]) {
      dp[i] = max(dp[i], dp[vals[a[i]][vals[a[i]].size() - a[i]] - 1] + a[i]);
    }
  }
  cout << dp[n] << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    tc();
  }
  return 0;
}