#include <bits/stdc++.h>
using namespace std;
int main() {
  // perulangan (do while loop)
  int a = 11, b = 10;
  // perbedaan dengan while looop:
  // jalankan kode dulu baru cek kondisi
  // (biasanya aku gunakan untuk kode yang brute force permutasi)
  do {
    a++;
    cout << a << " " << b << endl;
  } while(a < b);
}