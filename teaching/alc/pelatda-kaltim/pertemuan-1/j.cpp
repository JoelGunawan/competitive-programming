#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  // cek bilangan pangkat 2:
  // 1. bisa bagi 2 terus menerus (selama bisa dibagi 2). 
  // Jika bilangan merupakan bilangan pangkat 2, maka pasti bilangan akhirnya 1
  // 2^5 / 2
  // -> 2^4 / 2
  // -> 2^3 / 2
  // -> 2^2 / 2
  // -> 2^1 / 2
  // -> 1 -> pangkat dua
  // 24
  // 24 / 2
  // -> 12 / 2
  // -> 6 / 2
  // -> 3 -> bukan pangkat dua
  // operator tambahan untuk mencari sisa pembagian:
  // modulo/%
  // a % b -> sisa pembagian a terhadap b
  // Cara 1:
  // while(n % 2 == 0) {
  //   n /= 2;
  // }
  // if(n == 1) {
  //   cout << "ya" << endl;
  // }
  // else {
  //   cout << "bukan" << endl;
  // }
  // n = 1 -> 1
  // n = 2 -> 2 
  // n = 4 -> 3
  // n = 8 -> 4 
  // n = 16 -> 5 
  // n = 32 -> 6 
  // n = 1024 -> 11
  // naiknya setara kebalikan 2^... (kebalikan pangkat)
  // kebalikan pangkat -> logaritma/log
  // kompleksitas waktu: O(logN)
  while(n > 1) {
    // mau bagi n dengan 2
    // kita mau pastikan n bisa dibagi 2
    if(n % 2 == 0) {
      n /= 2;
    }
    else {
      // stop while loop
      // kata kunci break
      // memberhentikan loop langsung
      break;
    }
  }
  if(n == 1) {
    cout << "ya" << endl;
  }
  else {
    cout << "tidak" << endl;
  }
}