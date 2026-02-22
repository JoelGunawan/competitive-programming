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
    int n, m;
    cin >> n >> m;
    int a[n + 5][m + 5];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
      }
    }
    // cerr << endl;

    int pref[n + 5][m + 5];
    memset(pref, 0, sizeof(pref));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        pref[i][j] += pref[i - 1][j] + pref[i][j - 1] + a[i][j] - pref[i - 1][j - 1];
        // cerr << pref[i][j] << " ";
      }
      // cerr << endl;
    }

    int tgt = pref[n][m] / 2;
    int cnt = 0, x = 0, y = 0;
    // go down
    string s = "";
    while (x < n && pref[x + 1][m] <= tgt) {
      // check go down
      cnt = pref[x + 1][m];
      ++x;
      s += 'D';
    }

    // go right
    if (x < n) {
      int cnt_row = pref[x + 1][m] - pref[x][m];
      // want to remove: cnt_row - (tgt - cnt)
      int rem = cnt_row - (tgt - cnt);
      // cerr << "DEB: " << cnt_row << " " << rem << " " << tgt << " " << cnt << endl;
      while (y < m && rem) {
        ++y;
        s += 'R';
        if (a[x + 1][y]) --rem;
      }
      ++x;
      s += 'D';
    }

    while (y < m)
      ++y, s += 'R';
    
    while (x < n)
      ++x, s += 'D';
    
    cout << 1ll * tgt * (pref[n][m] - tgt) << endl;
    cout << s << endl;
  }
  return 0;
}