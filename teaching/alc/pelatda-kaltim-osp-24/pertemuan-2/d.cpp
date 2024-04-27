#include <bits/stdc++.h>
using namespace std;
// subprogram
// "nilai kembalian" tipe data
// parameters -> nilai yang kita mau masukkan ke subprogram
// tipe_data nama_subprogram/fungsi(parameters) {
//  
// }
// fungsi akan menerima 1 bilangan bulat, lalu mengembalikan pangkat 3nya
int pangkat3(int x) {
  return x * x * x; // fungsi langsung akan berhenti dan mengembalikan nilai
  cout << "TEST" << endl;
}
int jumlah(int x, int y) {
  x = pangkat3(x), y = pangkat3(y);
  // hanya bisa memanggil fungsi yang ada di atasnya (atau bisa dirinya sendiri)
  // cout << catatan() << endl;
  x += y;
  return x;
}
string catatan() {
  return "abcdef";
}
// buat subprogram yang melakukan cout
// void -> tidak mau ada nilai kembalian
void print(string s) {
  cout << s << endl;
  return; // memberhentikan
  cout << "Salah" << endl;
}
int main() {
  // input x, y, z, a, b, c
  // x^3, y^3, z^3
  cout << pangkat3(5) << endl; 
  cout << jumlah(7, 4) << endl;
  cout << catatan() << endl;
  print("test");
  // int x, y, z, a, b, c;
  // cin >> x >> y >> z >> a >> b >> c;
  // cout << x * x * x << " " << y * y * y << " " << z * z * z << " ";
  // cout << a * a * a << " " << b * b * b << " " << c * c * c << endl;
}