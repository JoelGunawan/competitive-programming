#include <bits/stdc++.h>
using namespace std;
int main() {
  // secara praktek, priority queue yang paling sering dipakai adalah
  // priority_queue<pair<int, int>> pq; (dibahas di kode selanjutnya)
  priority_queue<int> pq;
  // sintaks: priority_queue<tipe_data> pq; 
  // secara standar, mulai dari yang paling besar
  // di priority queue, kita hanya bisa akses dan keluarkan yang paling besar
  // operasi:
  // N ukuran pq
  // pq.push(x) -> masukkan x ke dalam priority queue O(logN)
  // pq.top() -> akses elemen paling besar di pq // O(1)
  // pq.pop() -> keluarkan elemen paling besar di pq // O(logN)
  // pq.size() -> mengembalikkan ukuran
  pq.push(2);
  pq.push(5);
  pq.push(3);
  // 2, 5, 3
  cout << "Ukuran: " << pq.size() << endl; // 3 elemen
  cout << "Top: " << pq.top() << endl; // elemen paling besar
  pq.push(4);
  // 2, 5, 3, 4
  cout << "Ukuran: " << pq.size() << endl; // 4 elemen
  cout << "Top: " << pq.top() << endl; // elemen paling besar
  pq.push(9);
  // 2, 5, 3, 4, 9
  cout << "Ukuran: " << pq.size() << endl; // 5 elemen
  cout << "Top: " << pq.top() << endl; // elemen paling besar
  pq.pop();
  // 2, 5, 3, 4
  pq.pop();
  // 2, 3, 4
  cout << "Ukuran: " << pq.size() << endl; // 3 elemen
  cout << "Top: " << pq.top() << endl; // elemen paling besar
}