#include <bits/stdc++.h>
using namespace std;
int main() {
  // 3 2 4 5 9 18
  // 3 -> 4 -> 8 -> 10 -> 18 -> 36
  // cari kelipatan x yang muncul selanjutnya di mana?
  // cara cari: 
  // - pembagian
  // - modulo
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    long long year = a[1];
    for(int i = 2; i <= n; ++i) {
      ++year;
      // cari kelipatan a[i] yg paling dekat setelah year
      int sisa = year % a[i];
      // sisa 0 -> sekarang udah di kelipatan a[i]
      if(sisa != 0) {
        // 9 dibagi 4 sisa 1
        // 9 + (4 - 1) dibagi 4 sisa 0
        // kelipatan selanjutnya year + a[i] - sisa
        year += a[i] - sisa;
      }
    }
    cout << year << endl;
  }
}