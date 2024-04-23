#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  // berheti di 1 -> base case di 1
  if(x == 1) {
    return 1;
  }
  // 5 * f(4)
  // 4/2 * f(3) 
  if(x % 2 == 0) {
    return x / 2 * f(x - 1);
  }
  else {
    return x * f(x - 1);
  }
}
int main() {
  // banyak soal rekursi bisa dikerjakan pakai perulangan (yang pasti tidak semua)
  // f(1) = 1
  // f(2) = 2 / 2 * f(1) = 1
  // f(3) = 3 * f(2) = 3
  // f(4) = 4 / 2 * f(3) = 2 * 3 = 6
  // f(5) = 5 * f(4) = 30
  int x;
  cin >> x;
  cout << f(x) << endl;
}