#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  // x^0 = 1
  if(b == 0) {
    return 1;
  }
  else {
    // cari x^(y/2)
    ll tmp = powmod(a, b / 2);
    tmp = (tmp * tmp) % mod;
    // b ganjil
    if(b & 1) {
      // x^(y/2)*x^(y/2)*x note: x^(floor(y/2))
      return (tmp * a) % mod;
    }
    else {
      return tmp;
    }
  }
}
int main() {
  cout << powmod(3, 5) << endl;
  cout << (powmod(2, mod - 2) * 2) % mod << endl; // 2^-1 * 2 mod m
}