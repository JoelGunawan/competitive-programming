#include <bits/stdc++.h>
using namespace std;
int main() {
  // operasi aritmatika: 
  // + -> penjumlahan 
  // - -> pengurangan
  // * -> perkalian
  // / -> pembagian
  int a, b;
  cin >> a >> b;
  cout << "PENJUMLAHAN: " << a + b << endl;
  cout << "PENGURANGAN: " << a - b << endl;
  cout << "PERKALIAN: " << a * b << endl;
  cout << "PEMBAGIAN: " << a / (double)b << endl;
  // jika kita melakukan pembagian antara 2 INTEGER (atau long long)
  // hasilnya akan berupa integer
  
  // cin -> input (masukan)
  // cout -> output (keluaran)

  // operasi string:
  string e = "abcd";
  string f = "efgh";  
  cout << e + f << endl;
}