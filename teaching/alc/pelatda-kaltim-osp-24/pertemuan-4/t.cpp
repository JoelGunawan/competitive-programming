#include <bits/stdc++.h>
using namespace std;
int main() {
  // mirip dengan set
  // TAPI dengan beberapa edge case
  // s.erase(x) jika dimasukkan angka maka akan menghapus semua kemunculan angka tersebut
  // jika mau hapus 1, maka harus pakai s.erase(s.find(x))
  // 
  // s.count(x) mempunyai kompleksitas worst case O(n)
  // (pengalaman pribadi: kena TLE on contest karena aku gatau (wktu pelatnas))
  multiset<int> s;
  s.insert(3);
  s.insert(3);
  s.insert(5);
  s.insert(-1);
  s.insert(-1);
  for(auto x : s) {
    cout << x << " ";
  }
  cout << endl;
}