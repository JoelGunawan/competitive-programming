#include <bits/stdc++.h>
using namespace std;
int main() {
  // priority queue pair
  // algoritma jarak terpendek
  // untuk soal greedy (bisa pilih elemen paling kecil)
  priority_queue<pair<int, int>> pq;
  // mana yang lebih besar?
  pq.push(make_pair(3, 2));
  pq.push(make_pair(2, 4));
  cout << pq.top().first << " " << pq.top().second << endl; // output (3, 2)
  // perbandingan yang lebih besar untuk pair:
  // bandingkan pertama dulu (.first)
  // bandingkan kedua (.second)
  pq.push(make_pair(3, 5));
  cout << pq.top().first << " " << pq.top().second << endl; // output (3, 5)
}