#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if(y == 2) {
    cout << 2 * (3 - x) << endl;
  }
  else {
    cout << (3 - x) + 1 << endl;
  }
}