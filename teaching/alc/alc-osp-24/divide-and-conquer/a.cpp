#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
// O(logN)
// y -> y / 2 -> y / 4 -> y / 8 -> ... -> 0 (pangkat tp kebalik -> logaritma)
// kegunaan: cari inverse modulo
// cari pangkat yg besar
ll pangkat_biner(ll x, ll y) {
  // apapun dipangkat 0 hasilnya 1
  if(y == 0)
    return 1;
  else {
    ll tmp = pangkat_biner(x, y / 2);
    // y ganjil -> x^(y/2) * x^(y/2) * x
    // y genap -> x^(y/2) * x^(y/2)
    if(y % 2 == 1)
      return tmp * tmp * x;
    else
      return tmp * tmp;
  }
}
int main() {
  
}