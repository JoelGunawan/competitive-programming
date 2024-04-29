#include <bits/stdc++.h>
using namespace std;
int main() {
  // queue
  // queue<tipe_data> q;
  // operasi:
  // q.push(x) -> masukkan x ke belakang antrian
  // q.pop() -> keluarkan dari depan antrian
  // q.front() -> mengembalikan hal yang ada di depan antrian
  // q.size() -> mengembalikan banyak elemen di antrian
  queue<int> q;
  q.push(2);
  q.push(100);
  q.push(-150);
  q.push(1);
  cout << "DEPAN " << q.front() << endl;
  cout << "UKURAN " << q.size() << endl;
  q.pop();
  cout << "DEPAN " << q.front() << endl;
  cout << "UKURAN " << q.size() << endl;

  // kegunaan:
  // BFS
  // DP Directed Acyclic Graph/DP on Graph (yg bukan tree)
  // urutkan utk proses sesuatu
}