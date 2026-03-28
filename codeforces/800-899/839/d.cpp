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
ll powmod(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return (b & 1) ? (tmp * a) % mod : tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  const int lim = 1e6 + 5;
  int cnt[lim];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];

  // bool prime[lim];
  // memset(prime, 0, sizeof(prime));
  // vector<int> primes;
  // for (int i = 2; i < lim; ++i) {
  //   if (prime[i]) {
  //     for (ll j = 1ll * i * i; j < lim; j += i) {
  //       prime[j] = 0;
  //     }
  //     primes.push_back(i);
  //   }
  // }

  int contrib[lim];
  memset(contrib, 0, sizeof(contrib));
  for (int i = 1; i < lim; ++i) {
    for (int j = 1; 1ll * j * j <= i; ++j) {
      if (i % j == 0) {
        contrib[j] += cnt[i];
        if (j != i / j) {
          contrib[i / j] += cnt[i];
        }
      }
    }
  }

  ll v = 0;

  // 1 * nC1
  // 2 * nC2
  // 3 * nC3
  // 4 * nC4
  // n * nCn
  
  // 1 -> 1
  // 2 -> 4
  // 3 -> 3 + 6 + 3 = 12

  ll res[lim];
  memset(res, 0, sizeof(res));
  for (int i = lim - 1; i > 1; --i) {
    if (contrib[i]) {
      res[i] += (contrib[i] * powmod(2, contrib[i] - 1)) % mod;
      res[i] %= mod;
      // cerr << "init: " << (contrib[i] * powmod(2, contrib[i] - 1)) % mod << endl;
      for (int j = 2; 1ll * j * j <= i; ++j) {
        if (i % j == 0) {
          res[j] -= res[i];
          if (j != i / j) {
            res[i / j] -= res[i];
          }
        }
      }
    }
  }

  // 2, 4, 6
  // 4, 6
  // 2
  // 2, 6
  // 2, 4

  for (int i = 2; i < lim; ++i) {
    // if (res[i] > 0) {
    //   cerr << i << " " << res[i] * i << endl;
    // }
    v = (v + 1ll * res[i] * i) % mod;
  }

  cout << v << endl;

  return 0;
}