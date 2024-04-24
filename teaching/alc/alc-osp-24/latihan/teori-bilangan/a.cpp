#include <bits/stdc++.h>
using namespace std;
int fpb(int x, int y) {
  if(y == 0)
    return x;
  else 
    return fpb(y, x % y);
}
long long kpk(int x, int y) {
  return 1ll * x * y / fpb(x, y);
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << kpk(a, b) / a + kpk(a, b) / b << endl;
}