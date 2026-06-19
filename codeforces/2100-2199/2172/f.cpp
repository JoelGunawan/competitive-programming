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
  int n;
  cin >> n;
  int p[n + 5];
  for (int i = 1; i <= n; ++i) cin >> p[i];
  int pref[n + 5], suff[n + 5];
  memset(pref, 0, sizeof(pref));
  memset(suff, 0, sizeof(suff));
  for (int i = 1; i <= n; ++i) {
    pref[i] = __gcd(pref[i - 1], p[i]);
  }
  for (int i = n; i >= 1; --i) {
    suff[i] = __gcd(suff[i + 1], p[i]);
  }

  ll res = pref[n];
  for (int i = 2; i < n; ++i) {
    res += min(pref[i], suff[i]);
  }
  cout << res << endl;
  return 0;
}