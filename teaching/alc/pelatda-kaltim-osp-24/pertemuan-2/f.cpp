#include <bits/stdc++.h>
using namespace std;
// n! = n * (n - 1) * (n - 2) * ... * 1
// n! = n * (n - 1)!
// (n - 1)! = (n - 1) * (n - 2) * ... * 1
// 1! = 1 * 0!
// 0! = 1
int faktorial(int n) {
  cout << n << endl;
  if(n == 0) {
    return 1;
  }
  int x = faktorial(n - 1);
  cout << n << " " << x << endl;
  return n * x;
}
int main() {
  int n;
  cin >> n;
  cout << faktorial(n) << endl;
}