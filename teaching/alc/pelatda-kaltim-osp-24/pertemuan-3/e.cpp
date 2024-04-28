#include <bits/stdc++.h>
using namespace std;
// mencari n!
// mencari nilai kombinasi
// mencari nilai inverse modulo (pembagian)
// kebanyakan soal: carilah ... modulo 10^9 + 7
// carilah ... modulo 998244353
// 2*10^9 -> 2e9
// 5*10^6 -> 5e6
// 10^9 -> 1e9

int mod = 1e9 + 7;
// bahas di divide and conquer
// fungsi untuk mencari pangkat modulo mod
long long pangkat_modulo(long long a, long long b) {
  if(b == 0)
    return 1;
  else {
    long long tmp = pangkat_modulo(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
long long fact[1005], inv[1005];
long long perkalian(long long a, long long b) {
  return (a * b) % mod;
}
long long kombinasi(int a, int b) {
  // a! / (b!(a-b)!)
  return perkalian(fact[a], perkalian(inv[b], inv[a - b]));
}
int main() {
  // menghitung nilai kombinasi
  fact[0] = inv[0] = 1;
  for(int i = 1; i <= 1000; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = pangkat_modulo(fact[i], mod - 2);
  }
  cout << kombinasi(7, 3) << endl; 
}