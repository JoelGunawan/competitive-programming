#include <bits/stdc++.h>
#define ll long long
using namespace std;
// yg penting modulo adalah prima
int m = 1e9 + 7;
// a^b mod m
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b / 2);
    tmp = (tmp * tmp) % m;
    return b & 1 ? (tmp * a) % m : tmp;
  }
}
// kompleksitas: O(b)
// b -> 10^9 (terlalu lambat)
/*
ll pangkat(ll a, ll b) {
  ll tmp = 1;
  for(int i = 1; i <= b; ++i) {
    tmp = (tmp * a) % m;
  }
  return tmp;
}
*/
long long mul(long long a, long long b) {
  return (a * b) % m;
}
int main() {
  // 9! / (4! * 3! * 2!)
  long long fact[15];
  fact[0] = 1;
  for(int i = 1; i <= 10; ++i) {
    fact[i] = ((fact[i - 1]) * i) % m;
  }
  cout << mul(mul(fact[9], powmod(fact[4], m - 2)), mul(powmod(fact[3], m - 2), powmod(fact[2], m - 2))) << endl;
}