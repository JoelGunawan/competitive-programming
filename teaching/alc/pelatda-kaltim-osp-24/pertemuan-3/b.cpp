#include <bits/stdc++.h>
using namespace std;
int main() {
  // tipe_data nama_arr[ukuran];
  // ada suatu struktur data yang namanya vector
  // sintaks:
  // vector<tipe_data> nama;
  // vector<tipe_data> nama(ukuran);
  // vector<tipe_data> nama(ukuran, nilai_awal);
  vector<int> v;
  // vector bisa dianggap sebagai array
  // ukurannya bisa berubah
  // v.size() -> mengembalikan banyak elemen di vector
  // v.push_back(x) -> memasukkan elemen x ke di belakang vector
  // v.pop_back() -> mengeluarkan elemen di posisi paling belakang
  v.push_back(3);
  v.push_back(5);
  v.push_back(2);
  cout << v[0] << " " << v[1] << " " << v.size() << endl;
  v.pop_back();
  v.pop_back();
  cout << v.size() << endl;
  vector<int> a(5, -1);
  for(int i = 0; i < a.size(); ++i)
    cout << a[i] << " ";
  cout << endl;
}