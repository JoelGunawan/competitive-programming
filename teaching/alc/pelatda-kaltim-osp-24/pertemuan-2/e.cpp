#include <bits/stdc++.h>
using namespace std;
int a, b;
int f(int x, int k) {
  if(k == 0)
    return x;
  else {
    // jika kita mau aplikasikan k kali, maka sama saja
    // kita aplikasikan sekali, lalu kita aplikasikan k - 1 kali
    x = f(x, k - 1);
    int hasil = a * x + b;
    if(hasil < 0)
      hasil = -hasil;
    return hasil;
  }
}
int main() {
  int k, x;
  cin >> a >> b >> k >> x;
  cout << f(x, k) << endl;
}