#include <bits/stdc++.h>
using namespace std;
int main() {
  // konversi angka menuju string dan string menuju angka
  // string s = "9234723";
  // // bisa ubah string to long long/string to integer
  // long long a = stoll(s); // ubah dari string jadi long long
  // int b = stoi(s); // ubah dari string menjadi int
  // string x = to_string(12315.231); // ubah apapun yang numerik jadi string
  // // mau tulis angka sebagai long long
  // // angkall
  // // contoh: 1ll
  // // contoh: 0ll
  // string y = to_string(234129415151212123); // ubah apapun yang numerik jadi string
  // cout << 2 * a << " " << 3 * b << " " << x << " " << y << endl;

  // kegunaan: 
  // int to string -> lebih mudah di manipulasi sebagai string
  // untuk beberapa bagian perhitungan
  // contoh: cari banyak digit satu angka
  int v;
  cin >> v;
  // cari banyak angka v
  cout << to_string(v).size() << endl;
}