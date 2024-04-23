#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while(n != 1) {
    cout << n << " ";
    // kasus genap
    if(n % 2 == 0) {
      n /= 2;
    }
    else {
      // kasus ganjil
      n = 3 * n + 1;
    }
  }
  cout << n << endl;
}