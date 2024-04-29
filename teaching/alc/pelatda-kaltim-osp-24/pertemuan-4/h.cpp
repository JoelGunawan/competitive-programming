#include <bits/stdc++.h>
using namespace std;
int main() {
  // mempercepat input/output
  // jangan dipakai di tipe soal interactive (tidak ada di osp)
  // semua cout dijalankan setelah semua cin dijalankan
  ios_base::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin >> n;
  deque<int> dq;
  bool rev = 0; // menandakan apakah operasinya perlu dibalik
  // N -> n
  // max(Y)/max(X) -> y
  // Kompleksitas waktu: O(ny)
  // op = 0, op = 1, op = ... , op = n - 1 -> n kali
  for(int op = 0; op < n; ++op) { // n kali
    string s;
    cin >> s;
    // kemungkinan 1:
    if(s == "add") {
      // operasi add
      int x, y;
      cin >> x >> y;
      // misalkan m adalah nilai maksimal y
      // i = 0, i = 1, ..., i = y - 1 -> y kali
      for(int i = 0; i < y; ++i) { // y kali
        // tidak kebalik
        if(!rev) {
          dq.push_back(x);
        }
        else {
          dq.push_front(x);
        }
      }
      cout << dq.size() << endl;
    }
    else if(s == "del") {
      // operasi del
      int x;
      cin >> x;
      if(!rev) {
        cout << dq.front() << endl;
      }
      else {
        cout << dq.back() << endl;
      }
      for(int i = 0; i < x; ++i) { // y kali
        if(!rev) {
          // tdk terbalik
          dq.pop_front();
        }
        else {
          // terbalik
          dq.pop_back();
        }
      }
    }
    else {
      // O(1)
      // operasi rev
      rev = !rev;
    }
  }
}