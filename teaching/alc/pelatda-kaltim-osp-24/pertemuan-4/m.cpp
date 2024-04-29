#include <bits/stdc++.h>
using namespace std;
int main() {
  // map<T1, T2> a;
  // akses seperti array a[T1] = T2;
  // operasi O(logN) -> N banyak elemen di a
  // note: O(logN) untuk map lebih lambat dari priority queue 
  // operasi tambahan:
  // a.clear();
  // (bisa 10x-50x lebih lambat)
  map<string, int> a;
  a["osn"] = 2024;
  a["jumlah makanan"] = 5;
  map<int, int> b;
  b[-1000] = 1000;
  b[1000000] = 3;
   // belum di tetapkan nilainya, maka:
  // tipe data int/double/bool/dan semacam -> 0
  // tipe data string -> ""
  // tipe data vector -> vector kosong
  cout << a["osn"] << " " << b[-1000] << " " << a["kosong"] << endl;

  for(auto x : a) {
    cout << x.first << " " << x.second << endl;
  }

  // kegunaan map:
  // 1. indeksnya bukan integer
  // 2. indeksya itu sparse/jaraknya jauh"
  // contoh kategori 2:
  // hitung frekuensi kemunculan di dalam sebuah array jika angkanya besar
}