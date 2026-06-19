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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  // find number of pairs s.t. gcd(a, b) = 1
  // we want to do sum of subsets for factor stuff
  // use mobius function
  // find number of pairs divisble by 2 OR 3 OR 4 OR ...
  const int lim = max({a, b, c, d}) + 1;
  bool is_sq[lim];
  bool div_sq[lim];
  bool prime[lim];
  memset(is_sq, 0, sizeof(is_sq));
  memset(div_sq, 0, sizeof(div_sq));
  memset(prime, 1, sizeof(prime));
  int cnt[lim];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 2; i < lim; ++i) {
    if (1ll * i * i < lim) is_sq[1ll * i * i] = 1;

    if (prime[i]) {
      cnt[i] = 1;
      for (int j = 2 * i; j < lim; j += i) {
        ++cnt[j];
        prime[j] = 0;
      }
    }

    if (is_sq[i]) {
      for (int j = i; j < lim; j += i) {
        div_sq[j] = 1;
      }
    }
  }

  ll res = 0;
  for (int i = 2; i < lim; ++i) {
    if (div_sq[i]) continue;
    ll tmp = 1ll * ((b / i) - (a - 1) / i) * ((d / i) - (c - 1) / i);
    res += cnt[i] & 1 ? tmp : -tmp;
  }
  // cerr << res << endl;
  cout << 1ll * (b - a + 1) * (d - c + 1) - res << endl;
  return 0;
}