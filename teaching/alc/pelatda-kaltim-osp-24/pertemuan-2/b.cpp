#include <bits/stdc++.h>
using namespace std;
int main() {
  // string s = "abcdefgh";
  // string t = "ijkl";
  // s = s + t;
  // // macam-macam operasi string
  // int sz = s.size();
  // // s.substr(); // akan mengambil "substring"/sepotong dari string
  // // string dari indeks ke 2 hingga indeks ke 5
  // // s.substr(index_awal, ukuran)
  // string y = s.substr(2, 4);
  // cout << y << " " << z << endl;
  // // operasi erase/penghapusan
  // // s.erase();
  // // index 1 ke index 5, ukuran yang dihapus: 5
  // // s.erase(s.begin() + indeks_awal, s.begin() + indeks_akhir + 1)
  // s.erase(s.begin() + 1, s.begin() + 5 + 1);
  // cout << s << endl;
  // string x = "tes";
  // cout << x.size() << endl;
  // s.insert() -> memasukkan karakter/string ke dalam string
  // s.insert(s.begin() + index, karakter)
  // s.insert(index, string)
  string s = "abcd";
  s.insert(s.begin() + 4, 'c');
  cout << s << endl;
  s.insert(2, "ef");
  cout << s << endl;

  // reverse(s.begin() + indeks_awal, s.begin() + indeks_akhir + 1)
}