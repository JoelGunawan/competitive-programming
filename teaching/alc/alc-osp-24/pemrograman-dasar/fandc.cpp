#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  cin >> n;
  // sifat dari double ke integer
  // 1. -2.5 -> integer -> -2
  // 2. 2.5 -> integer -> 2
  // cek apakah n bilangan bulat atau tidak
  int x = n;
  if(x == n) {
    // n udah bilangan bulat
    cout << n << " " << n << endl;
  }
  else if(n < 0) {
    // 1. ceiling -> x
    // floor -> x - 1
    cout << x - 1 << " " << x << endl;
  }
  else {
    // 2. floor -> x
    // ceiling -> x + 1
    cout << x << " " << x + 1 << endl;
  }
}