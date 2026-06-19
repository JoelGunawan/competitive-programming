#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod = 998244353;


int main() {
  int n; cin >> n;
  if (n >= 100) {
    cout << n << "\n";
  } else {
    int fac = 1;
    for (int i = 1; i <= n; i++) {
      fac = (ll) fac * i % (mod - 1);
    }

    auto binpow = [&](int x, int k) -> int {
      int res = 1;
      for (; k; k >>= 1, x = (ll) x * x % mod)
        if (k & 1)
          res = (ll) res * x % mod;
      return res;
    };

    int res = 1;
    res = (ll) res * binpow(binpow(n, fac), mod - 2) % mod;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum = (sum + binpow(i, fac)) % mod;
    }
    res = (ll) res * sum % mod;
    cout << res << "\n";
  }
  return 0; 
}