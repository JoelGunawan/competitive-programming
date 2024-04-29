#include <bits/stdc++.h>
using namespace std;
int main() {
  // vector<tipe_data> v
  // operasi:
  // (semua O(1))
  // v.push_back(x) -> masukkan elemen x ke belakang vector
  // v.pop_back() -> keluarkan elemen x dari belakang vector
  // v.clear() -> kosongkan isi vector
  // v.size() -> ukuran
  // v[i] -> akses indeks seperti array
  vector<int> v;
  v.push_back(5);
  v.push_back(3);
  v.push_back(-10);
  v.push_back(7);
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
  v.pop_back();
  v.pop_back();
  v[1] = 15;
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
  v.clear();
  cout << v.size() << endl;
}