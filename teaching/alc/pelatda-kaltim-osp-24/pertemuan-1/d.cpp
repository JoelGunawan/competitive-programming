#include <bits/stdc++.h>
using namespace std;
int main() {
  // percabangan
  // jika sebuah nilai lebih besar dari nilai lain, maka kita mau keluarkan "iya"
  // buat program yang menerima input a dan b dan memeriksa apakah a > b
  // misal jika a > b -> keluarkan "iya"
  // jika tidak, maka keluarkan "tidak"
  // if = jika
  int a, b;
  cin >> a >> b;
  // kondisi -> syarat yang harus dipenuhi agar kode yg di dalam if dijalankan
  // operator perbandingan/comparison operator
  // >= -> lebih dari sama dengan
  // <= -> kuran dari sama dengan
  // > -> lebih dari
  // < -> kurang dari
  // == -> sama dengan atau tidak
  // != -> tidak sama dengan

  // tipe data:
  // bool -> true/false (benar/salah)
  bool x = true;
  bool y = false;
  bool z = a > b;
  if(z) {
    // kode disini...
    cout << "iya" << endl;
  } 
  if(x) {
    cout << "x" << endl;
  }
  if(!y) {
    cout << "y" << endl;
  }
}