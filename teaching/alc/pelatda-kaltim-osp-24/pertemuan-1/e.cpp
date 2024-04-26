#include <bits/stdc++.h>
using namespace std;
int main() {
  // input 2 angka a, b
  // jika a > b -> "a lebih dari b"
  // jika a == b -> "a sama dengan b"
  // jika a < b -> "a kurang dari b"
  int a, b;
  cin >> a >> b;
  if(a > b) {
    cout << "a lebih dari b" << endl;
  }
  else if(a == b) {
    cout << "a sama dengan b" << endl;
  }
  else {
    cout << "a kurang dari b" << endl;
  }
}