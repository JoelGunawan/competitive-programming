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
int mod = 998244353;
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  // must have common highest point (global max)
  // choose the global max
  // then find count of subseq?

  vector<int> fr, bk;

  int tmp = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > tmp) {
      fr.push_back(a[i]);
      tmp = a[i];
    }
  }

  tmp = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] > tmp) {
      bk.push_back(a[i]);
      tmp = a[i];
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; ++i) mx = max(mx, a[i]);

  ll res = 0;
  ll dpl[n + 5][fr.size() + 5], dpr[n + 5][bk.size() + 5];
  memset(dpl, 0, sizeof(dpl));
  memset(dpr, 0, sizeof(dpr));

  dpl[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    // smaller -> add
    // larger -> don't add
    dpl[i][0] = 1;
    for (int j = 1; j <= fr.size(); ++j) {
      dpl[i][j] = dpl[i - 1][j];
      // do this logic using lazy segment tree!!!
      if (a[i] == fr[j - 1]) {
        // add 1 elem !!!
        dpl[i][j] += dpl[i - 1][j - 1];
        if (a[i] != mx) {
          dpl[i][j] += dpl[i - 1][j];
        }
      } else if (a[i] < fr[j - 1]) {
        // can add
        // lazy mul by 2 !!!
        if (j != fr.size()) {
          dpl[i][j] += dpl[i - 1][j];
        }
      }
      // cerr << i << " " << j << " " << dpl[i][j] << endl;
      dpl[i][j] %= mod;
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << dpl[i][fr.size()] << " ";
  // }
  // cout << endl;

  reverse(a + 1, a + n + 1);
  dpr[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    // smaller -> add
    // larger -> don't add
    dpr[i][0] = 1;
    for (int j = 1; j <= bk.size(); ++j) {
      dpr[i][j] = dpr[i - 1][j];
      if (a[i] == bk[j - 1]) {
        dpr[i][j] += dpr[i - 1][j - 1];
        dpr[i][j] += dpr[i - 1][j];
      } else if (a[i] < bk[j - 1]) {
        // can add
        dpr[i][j] += dpr[i - 1][j];
      }
      // cerr << i << " " << j << " " << dpr[i][j] << endl;
      dpr[i][j] %= mod;
    }
  }

  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (dpl[i - 1][fr.size()] != dpl[i][fr.size()]) {
      // cerr << "deb " << i << " " << (dpl[i][fr.size()] - dpl[i - 1][fr.size()]) << " " << dpr[n - i + 1][bk.size()] << endl;
      res += 1ll * (dpl[i][fr.size()] - dpl[i - 1][fr.size()]) * (dpr[n - i][bk.size()] + dpr[n - i][bk.size() - 1]);
      res %= mod;
    }
  }
  if (res < 0)
    res += mod;
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // front same and back same
  // consider front only + back only
  // then consider shared view
  int t;
  cin >> t;
  while (t--) {
    tc();
  }
  return 0;
}