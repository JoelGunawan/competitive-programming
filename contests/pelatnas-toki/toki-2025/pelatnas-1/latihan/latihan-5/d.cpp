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
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n; ll pj, pm;
  cin >> n >> pj >> pm;
  ll a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // pm > pj
  if(pj > pm)
    swap(pj, pm);
  // pm larger, pj smaller
  // transition: dp[n] = at n is pm, number of ways
  ll dp[n + 1];
  for(int i = 3; i <= n; ++i) {
    if(a[i] - a[i - 2] < pj) {
      cout << 0 << endl;
      return 0;
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  a[0] = -1e18;
  ll pref[n + 1];
  pref[0] = 1;
  int l = 0, r = 0;
  for(int i = 1; i <= n; ++i) {
    while(a[i] - a[r + 1] >= pm)
      ++r;
    dp[i] = pref[r] - (l == 0 ? 0 : pref[l - 1]);
    if(l > r)
      dp[i] = 0;
    // cerr << i << " " << l << " " << r << " " << dp[i] << endl;
    pref[i] = pref[i - 1] + dp[i];
    dp[i] %= mod;
    pref[i] %= mod;
    // cerr << pj << " " << a[i] << " " << a[i - 1] << endl;
    if(a[i] - a[i - 1] < pj)
      l = i - 1;
  }
  // find last valid
  int last_val = n - 1;
  for(int i = n - 1; i >= 0; --i) {
    last_val = i;
    if(a[i + 1] - a[i] < pj)
      break;
  }
  --last_val;
  cout << (pref[n] - (last_val >= 0 ? pref[last_val] : 0) + 5ll * mod) % mod << endl;
  // cout << (2 * powmod(2, n)) % mod << endl;
  return 0;
}