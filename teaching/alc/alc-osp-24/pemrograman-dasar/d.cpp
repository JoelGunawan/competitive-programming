#include <bits/stdc++.h> // library standar c++
using namespace std;
int main() {
  // sekumpulan variabel
  // 10 angka
  // 10 variabel? -> repot
  // tipe_data nama_variabel[ukuran_array (harus integer)];
  int a[5];
  // pada awalnya (berlaku buat array dan variabel) nilai tidak terdefinisi
  // akses array nama_variabel[indeks]
  // indeks array dimulai dari 0
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3;
  a[4] = 4;
  int sum = 0;
  for(auto x : a) {
    cout << x << " ";
    sum += x;
  }
  cout << endl;
  cout << sum << endl;
  // fill(a + indeks_awal, a + indeks_akhir + 1, value)
  fill(a + 1, a + 3, 100);
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  // reverse(a + indeks_awal, a + indeks_akhir + 1)
  reverse(a + 2, a + 5);
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}