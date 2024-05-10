// header file
#include <bits/stdc++.h>
// macros
#define ll long long
#define endl "\n"
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[2 * n + 10];
  memset(a, 0, sizeof(a));
  for(long long i = 1; i <= n; ++i)
    cin >> a[i];
  long long pref[2 * n + 10];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i <= n; ++i)
    pref[i] = pref[i - 1] + a[i];
  for(int i = n + 1; i <= 2 * n; ++i)
    pref[i] = pref[i - 1];
  bitset<200005> dp[2];
  dp[0] = 2;
  ll res = 0;
  for(int i = 1; i <= 2 * n; ++i) {
    dp[i & 1] = (dp[(i - 1) & 1] << a[i]) | dp[(i - 1) & 1];
    if(dp[i & 1][i]) {
      res = max(res, pref[i] - i + 1);
      dp[i & 1][i] = 0;
    }
  }
  cout << res << endl;
  return 0;
}