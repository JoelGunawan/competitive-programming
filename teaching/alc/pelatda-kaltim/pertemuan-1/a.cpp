#include <bits/stdc++.h>
using namespace std;
int main() {
  //cout << "Halo, Dunia!" << " halo " << "Hello World!" << endl;
  int x; // int -> integer (bilangan bulat) ini variabel x bilangan bulat
  string s; // ini variabel s berisi kata
  x = 3;
  s = "Halo, Dunia!";
  //cout << x << " " << s << endl;
  // tipe data:
  // int -> bilangan bulat, batasan: -2^31 ... 2^31 - 1 (kurang lebih -2 milliar ... 2 milliar)
  // long long -> bilangan bulat, batasan: -2^63 ... 2^63 - 1 (kurang lebih dari -9 * 10^18 ... 9 * 10^18)
  // string -> kata
  // double -> bilangan desimal (precision error)
  // char -> menyimpan karakter
  double d = 12937211253.141234129431412;
  // benar:  141234129431412
  // output: 1412334442
  cout << fixed << setprecision(10);
  //cout << d << endl;
  x = -4.7;
  //cout << x << endl;
  char c = '>';
  //cout << c << endl;
  x = 10000000000;
  //cout << x << endl;
  int v;
  cin >> v;
  cout << v << endl;
  string t;
  cin >> t;
  cout << t << endl;
  double dbl;
  cin >> dbl;
  cout << dbl << endl;
}