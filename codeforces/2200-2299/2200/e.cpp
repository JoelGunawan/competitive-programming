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
  vector<ll> primes;
  const int lim = 1e6 + 5;
  bool prime[lim];
  memset(prime, 1, sizeof(prime));
  for (int i = 2; i < lim; ++i) {
    if (prime[i]) {
      for (ll j = 1ll * i * i; j < lim; j += i) {
        prime[j] = false;
      }

      primes.push_back(i);
    }
  }
  while (t--) {
    int n;
    cin >> n;
    int a[n + 5];
    int b[n + 5];
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    bool diff = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        diff = true;
        break;
      }
    }

    if (!diff) {
      cout << "Bob" << endl;
      continue;
    }

    bool aw = false;
    int factor[n + 5];
    for (int i = 1; i <= n; ++i) {
      unordered_set<int> factors;
      for (int j = 0; primes[j] * primes[j] <= a[i]; ++j) {
        if (a[i] % primes[j] == 0) {
          factors.insert(primes[j]);
          while (a[i] % primes[j] == 0) a[i] /= primes[j];
        }
      }

      if (a[i] > 1) {
        factors.insert(a[i]);
      }

      if (factors.size() > 1) {
        aw = true;
        break;
      } else {
        if (factors.size() == 1) {
          factor[i] = *factors.begin();
        } else {
          factor[i] = 1;
        }
      }
    }

    if (aw) {
      cout << "Alice" << endl;
      continue;
    }

    // Then, need to check if Bob can even somehow win, check if primes are increasing
    int pr = 0;
    aw = false;
    for (int i = 1; i <= n; ++i) {
      if (factor[i] < pr) {
        aw = true;
        break;
      }

      pr = factor[i];
    }

    cout << (aw ? "Alice" : "Bob") << endl;
  }
  return 0;
}