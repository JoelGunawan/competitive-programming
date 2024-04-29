#include <bits/stdc++.h>
using namespace std;
int main() {
  // deque<tipe_data> dq;
  // operasi:
  // push_back(x) -> masukkan x di belakang
  // push_front(x) -> masukkan x di depan
  // pop_back() -> keluarkan elemen paling belakang
  // pop_front() -> keluarkan elemen paling depan
  // front() -> mengembalikan elemen di paling depan
  // back() -> mengembalikan elemen di paling belakang
  // size() -> ukuran
  // clear() -> kosongkan deque
  // diakses seperti vector
  // bisa ditetapkan nilai awal seperti vector

  // deque sebagai vector dengan tambahan operasi:
  // pop_front()
  // push_front()

  // kelemahan sangat besar deque:
  // SANGAT SANGAT LAMBAT
  // soal yg bisa diselesaikan vector dan array akan TLE jika menggunakan deque
  deque<int> dq;
  dq.push_front(5);
  dq.push_back(7);
  for(auto x : dq) {
    cout << x << " ";
  }
  cout << endl;
  dq.push_front(3);
  dq.push_back(9);
  cout << "DEPAN " << dq.front() << endl;
  cout << "BELAKANG " << dq.back() << endl;
  dq.pop_front();
  dq.pop_front();
  cout << "DEPAN " << dq.front() << endl;
  cout << "BELAKANG " << dq.back() << endl;
}