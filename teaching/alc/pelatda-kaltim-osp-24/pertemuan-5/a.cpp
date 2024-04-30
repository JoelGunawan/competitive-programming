#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// kompleksitas waktu: O(log2(Y))
long long pangkat(long long x, long long y) {
  if(y == 0) {
    return 1;
  }
  else {
    // x^y -> x pangkat y
    long long tmp = pangkat(x, y / 2); // simpan nilai x^(y/2)
    // y ganjil, karena sisa pembagian y dengan 2 itu 1
    // jika cari pangkat modulo, setelah pangkat, selalu modulo karena bisa
    // overflow jika tidak di modulo
    tmp = (tmp * tmp) % mod;
    if(y % 2 == 1) {
      return (tmp * x) % mod;
    }
    else {
      return tmp;
    }
  }
}
int main() {
  int x, y;
  cin >> x >> y;
  cout << pangkat(x, y) << endl;
}