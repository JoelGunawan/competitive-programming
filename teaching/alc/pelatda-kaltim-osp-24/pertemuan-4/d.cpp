#include <bits/stdc++.h>
using namespace std;
int main() {
  // untuk mengikat 2 variabel jadi 1 (utk pasangan)
  // pair<T1, T2> a;
  // T1 -> tipe data 1
  // T2 -> tipe data 2
  // akses elemen dengan tipe data 1 menggunakan a.first
  // akses elemen dengan tipe data 2 menggunakan a.second
  pair<string, int> a; 
  a.first = "test";
  a.second = 1;
  cout << a.first << a.second << endl;
  a = make_pair("osn", 2024);
  cout << a.first << a.second << endl;

  // kegunaan pair:
  // - untuk graf (nanti di graf)
  // - untuk pengurutan
  // - koordinat/geometri
  // - ada hal yang lebih logis pake pair
  // - untuk cari max/min dengan indeksnya lebih pendek (ga penting)
}