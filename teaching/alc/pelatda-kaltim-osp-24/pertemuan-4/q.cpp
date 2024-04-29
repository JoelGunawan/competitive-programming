#include <bits/stdc++.h>
using namespace std;
int main() {
  // set<T> s;
  // hal unik: tidak bisa menyimpan elemen duplikat
  // otomatis terurut
  // operasi:
  // s.insert(x) -> masukkan angka ke set O(logn)
  // s.erase(x) -> hapus angka x dari set O(logn)
  // s.count(x) -> mencari banyak kemunculan elemen x (0/1) O(logn)
  // s.size() -> ukuran dari set O(1)
  // s.begin() -> mengembalikan iterator awal
  // s.end() -> mengambalikan iterator akhir
  // jika tidak ada: maka akan megnembalikan s.end()
  // s.lower_bound(x) -> mengembalikan iterator elemen pertama yg >= x
  // praktisnya: untuk mencari nilai yg >= x, untuk mencari yg nilai yg < x
  // s.upper_bound(x) -> mengembalikan iterator elemen pertama yg > x 
  // praktisnya: untuk mencari nilai yg > x, untuk mencari nilai yg <= x
  // s.find(x) -> mengembalikan iterator elemen yang == x
  set<int> s;
  s.insert(2);
  s.insert(3);
  s.insert(100);
  s.insert(-1);
  int x;
  cin >> x;
  if(s.lower_bound(x) != s.end()) {
    cout << (*s.lower_bound(x)) << endl;
    cout << "Benar" << endl;
  }
  else {
    cout << "Tidak Benar" << endl;
  }
  // iterator set tidak bisa ditambah/dikurang dengan konstan
  // hanya bisa di increment/decrement
  // operator increment/decrement lebih baik pakai yang di depan
  
  cout << (*s.begin()) << endl;
  cout << (*--s.end()) << endl;
  s.erase(s.begin());
  s.erase(100);
  s.insert(5);
  s.erase(5);
  s.insert(5);
  for(auto x : s) {
    cout << x << " ";
  }
  cout << endl;
}