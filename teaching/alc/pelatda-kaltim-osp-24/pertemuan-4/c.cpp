#include <bits/stdc++.h>
using namespace std;
int main() {
  // awalnya a ini punya ukuran 5
  // vector<T> a;
  // sintaks menetapkan nilai awal vector
  // T -> tipe data (bebas)
  // vector<T> a(ukuran) // O(ukuran)
  // vector<T> a(ukuran, nilai_awal) // O(ukuran)
  // lebih formalnya: ukuran * waktu_deklarasi
  // contoh waktu deklarasi: 
  // string ukuran 10 -> waktu deklarasi 10
  vector<int> a(5, 12);
  cout << a.size() << endl;
  a[0] = 1;
  a[4] = 13; 
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << endl;
  }
  cout << a.front() << " " << a.back() << endl;
  // operasi tambahan vector
  // v.front() -> mengembalikan elemen paling depan di vector
  // v.back() -> mengembalikan elemen paling belakang di vector

  // kegunaan vector
  // 1. Butuh array (sedikit lebih lambat, tapi kurang lebih sama)
  // 2. Butuh array yang bisa dihapus/dimasukkan nilainya di belakang
  // 3. Butuh array yang bisa berubah ukuran
  // 4. vector bisa digunakan untuk stack
  // note: biasanya orang implementasi stack pakai vector

  // ubah operasi stack jadi vector:
  // top() -> back()
  // push(x) -> push_back()
  // pop() -> pop_back()
}