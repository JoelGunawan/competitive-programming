// struktur dasar program
#include <bits/stdc++.h>
using namespace std;
int main() {
  // isi program ...
  // angka namanya x
  // tipe_data nama_variabel;
  // int -> angka bilangan bulat/integer
  // int x = 8;
  // syarat penamaan variabel:
  // awalnya harus a...zA...Z_
  // huruf sisanya harus a...zA...Z_0..9
  // int a0 = -3;
  // int _ = 2;
  // int b = 3;
  // endl -> buat baris baru
  // cout << x << endl;
  // cout << a0 << endl;
  // cout << _ << endl;
  // cout << b << endl;
  //cout << x << " " << a0 << endl;
  // int c = 1000000000000;
  // cout << c << endl;
  //cout << "lsdjlsrjalsjfvlsaba" << endl;
  // tipe data primitif:
  // int -> bilangan bulat -2^31 ~ -2 milliar ... 2^31 - 1 ~ 2 milliar
  // int, 2.5 -> 2
  // bool -> true/false
  // long long -> bilangan bulat -2^63 ... 2^63 - 1 / -9*10^18...9*10^18
  // long long, 3.9 -> 3
  // char -> 1 karakter 'a', 'b', '/'
  // double -> bilangan desimal, bisa simpan angka yang ada koma, nilainya tidak presisi (bisa salah)
  // int a = 4;
  // cout << a << " " << 4 << endl;
  // int b = 2.7;
  // cout << "B: " <<  b << endl;
  // bool c = true;
  // cout << "C: " << c << endl;
  // char d = '^';
  // cout << "D: " << d << endl;
  // double e = 3204832424.141519784023482;
  // cout << fixed << setprecision(15);
  // cout << "E: " << e << endl;
  // string s = "ksfjdlajfabcxbds";
  // cout << "S: " << s << endl;
  cout << "penjumlahan " << 3 + 7 << endl;
  cout << "pengurangan " << 3 - 7 << endl;
  cout << "perkalian " << 3 * 7 << endl;
  cout << "perkalian " << 2.5 * 2.7 << endl;
  // pembagian normal 4.5
  cout << "pembagian integer 9 / 2 " << 9 / 2 << endl; // keluar berapa? 4
  // kenapa? int / int -> int
  cout << "pembagian double 9 / 2" << 9.0 / 2 << endl;
  // % -> sisa pembagian (cuman bisa integer)
  cout << "12 mod 5 = " << 12 % 5 << endl;
  cout << ((true) && (true)) << endl;
  cout << ((true) && (false)) << endl;
  cout << ((false) && (false)) << endl;
  cout << ((true) ^ (true)) << endl;
  cout << ((true) ^ (false)) << endl;
  cout << ((false) ^ (false)) << endl;
  cout << ((true) || (true)) << endl;
  cout << ((true) || (false)) << endl;
  cout << ((false) || (false)) << endl;
  cout << !(false) << endl;
  int in1;
  string in2;
  char in3;
  double in4;
  cin >> in1 >> in2 >> in3;
  cin >> in4;
  cout << in1 << " " << in2 << " " << in3 << " " << in4 << endl;
}