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
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  ll pref[n + 1][m + 1], dp[n + 1][m + 1];
  memset(pref, 0, sizeof(pref));
  pref[1][1] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  }
  
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      //cout << i << " " << j << " " << pref[i][j] << endl;
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      //cout << i << " " << j << " " << pref[i][j] << endl;
      pref[i][j] %= mod;
      // this is the count of ways to i, j
      ll tmp = pref[i][j];
      if(i != 1 || j != 1) {
        pref[i][j] *= 2;
        pref[i][j] %= mod;
      }
      if(i + a[i][j] + 1 <= n) {
        //cout << "REDUCE " << i + a[i][j] + 1 << " " << j << " " << tmp << endl;
        pref[i + a[i][j] + 1][j] += -tmp;
      }
      if(j + a[i][j] + 1 <= m) {
        //cout << "REDUCE " << i << " " << j + a[i][j] + 1 << " " << tmp << endl;
        pref[i][j + a[i][j] + 1] += -tmp;
      }
      if(i + a[i][j] + 1 <= n && j + a[i][j] + 1 <= m) {
        //cout << "ADD " << i + a[i][j] + 1 << " " << j + a[i][j] + 1 << " " << tmp << endl;
        pref[i + a[i][j] + 1][j + a[i][j] + 1] += tmp;
      }
      //cout << "VALUE " << i << " " << j << " " << pref[i][j] << endl;
    }
    //cout << endl;
  }
  /*
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      // cout << pref[i][j] / 2 << " ";
    }
    // cout << endl;
  }
  */
  if(pref[n][m] < 0)
    pref[n][m] += mod;
  if(n == 1 && m == 1)
    cout << pref[n][m] << endl;
  else
    cout << (pref[n][m] * powmod(2, mod - 2)) % mod << endl;
  return 0;
}