#include <bits/stdc++.h>
using namespace std;
int main() {
  // masalah yg mgkn akan dihadapi:
  // bagaimana klo menyimpan banyak nilai
  // kita diberi input 10 bilangan
  // solusi: simpan dalam 10 variabel
  // simpan daftar yang berisi beberapa nilai
  // misalkan, simpan daftar nilai osnk

  // membuat larik (akan aku bilang sebagai array) berukuran 5
  int a[5];
  // array a memiliki 5 elemen
  a[0] = 7; // elemen a di indeks ke 0
  a[1] = 3; // a indeks 1
  a[2] = 4;
  a[3] = 5;
  a[4] = 1;
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  // membalik array
  // reverse(a, a + 5);
  // membalik array di segmen tertentu
  // mau balik dari index x ke index y
  int x = 2, y = 4;
  reverse(a + x, a + y + 1); // O(y - x)

  // tukar elemen di indeks 0 dan elemen di indeks 1
  swap(a[0], a[1]);

  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;

  // int jumlah = 0;
  // for(int i = 0; i < 5; ++i) {
  //   jumlah += a[i];
  // }
  // cout << jumlah << endl;
}