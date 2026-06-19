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
  int n, l;
  cin >> n >> l;
  int b[n + 5];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  int pref[n + 5];
  pref[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + b[i];
  }

  // cerr << "TEST" << endl;
  const int lim = 15 * 32;

  bool libur[lim];
  memset(libur, 0, sizeof(libur));
  for (int i = 1; i <= l; ++i) {
    int m, d;
    cin >> d >> m;
    libur[d + pref[m - 1]] = 1;
  }

  // cerr << "TEST" << endl;

  bool ans = false;
  for (int i = 1; i < lim; ++i) {
    if (libur[i - 1] && libur[i + 1] && !libur[i]) {
      ans = true;
    }
  }

  cout << (ans ? "YA" : "TIDAK") << endl;
  return 0;
}