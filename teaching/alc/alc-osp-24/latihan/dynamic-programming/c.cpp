// header file
#include <bits/stdc++.h>
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
bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b) {
  return a.fi < b.fi;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, p, k;
  cin >> n >> p >> k;
  pair<int, vector<int>> a[n + 1];
  long long dp[n + 1][1 << p];
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].fi;
  }
  for(int i = 1; i <= n; ++i) {
    vector<int> x(p);
    for(int j = 0; j < p; ++j)
      cin >> x[j];
    a[i].se = x;
  }
  sort(a + 1, a + n + 1, compare);
  reverse(a + 1, a + n + 1);
  for(int i = 0; i < 1 << p; ++i) {
    dp[0][i] = -1e18;
  }
  dp[0][0] = 0;
  // udah sorted audiens dari besar ke kecil
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 1 << p; ++j) {
      // i - orang yang masuk ke tim <= k
      int cnt = 0;
      for(int k = 0; k < p; ++k) {
        if((1 << k) & j)
          ++cnt;
      }
      // masukkan orang sekarang ke audiens
      if(i - cnt <= k)
        dp[i][j] = dp[i - 1][j] + a[i].fi;
      else
        dp[i][j] = dp[i - 1][j];
      // utk setiap mask, coba setiap transisi
      for(int k = 0; k < p; ++k) {
        if((1 << k) & j) {
          // bisa di transisi
          dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << k)] + a[i].se[k]);
        }
      }
    }
  }
  cout << dp[n][(1 << p) - 1] << endl;
  return 0;
}