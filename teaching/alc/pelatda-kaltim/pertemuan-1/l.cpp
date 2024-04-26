#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  // 0
  // 12
  // 345
  // 6789
  // 01234
  // 567890
  // sederhanakan dulu:
  // *
  // **
  // ***
  // ****
  // ...
  // i = 1, 1 bintang
  // i = 2, 2 bintang
  // i = 3, 3 bintang
  // i = 4, 4 bintang
  // i = 5, 5 bintang

  // analisis kompleksitas:
  // cara kita menganalisa waktu jalan yang dibutuhkan kode berdasarkan input


  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2
  // n = 3 -> 6
  // n = 4 -> 13
  // n = 10 -> 45
  // Kompleksitas Waktu: O(N^2)
  int cnt = 0;
  for(int i = 1; i <= n; ++i) {
    // n kali
    for(int j = 1; j <= i; ++j) {
      // n kali
      cout << cnt % 10; // dijalankan n * n kali
      cnt++; // dijalankan n * n kali -> n^2
    }
    cout << endl; // dijalankan n kali
  }
}