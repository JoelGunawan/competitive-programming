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
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int w;
  cin >> w;
  int a[w + 1];
  for(int i = 1; i <= w; ++i)
    cin >> a[i];
  sort(a + 1, a + w + 1);
  int pref[n + 2][m + 2];
  memset(pref, 0, sizeof(pref));
  vector<int> v;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i + k - 1 <= n && j + k - 1 <= m) {
        ++pref[i][j];
        ++pref[i + k][j + k];
        --pref[i + k][j];
        --pref[i][j + k];
      }
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      v.pb(pref[i][j]);
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  reverse(a + 1, a + w + 1);
  v.insert(v.begin(), 0);
  ll res = 0;
  for(int i = 1; i <= w; ++i) {
    res += 1ll * v[i] * a[i];
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}