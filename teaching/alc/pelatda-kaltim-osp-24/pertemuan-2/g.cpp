#include <bits/stdc++.h>
using namespace std;
int f(int n) {
  if(n == 1) {
    return 1;
  }
  if(n % 2 == 0) {
    return n / 2 * f(n - 1);
  }
  else {
    return n * f(n - 1);
  }
}
int main() {
  int n;
  cin >> n;
  cout << f(n) << endl;
}