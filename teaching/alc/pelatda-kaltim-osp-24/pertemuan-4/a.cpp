#include <bits/stdc++.h>
using namespace std;
int main() {
  // stack<tipe_data> s;
  // operasi:
  // s.push(x) -> masukkan x ke atas tumpukan
  // s.pop() -> keluarkan elemen paling atas dari tumpukan
  // s.top() -> mengembalikan elemen paling atas di tumpukan
  // s.size() -> banyak elemen dalam tumpukan
  // contoh operasi:
  stack<int> s;
  s.push(3);
  s.push(2);
  s.push(5);
  s.push(7);
  cout << "Size: " << s.size() << endl; // banyak elemen di tumpukan
  cout << "Elemen paling atas: " << s.top() << endl; // elemen paling atas di tumpukan
  s.pop();
  cout << "Size: " << s.size() << endl; // banyak elemen di tumpukan
  cout << "Elemen paling atas: " << s.top() << endl; // elemen paling atas di tumpukan
  return 0; // tanda memberhentikan program (gak wajib)
}