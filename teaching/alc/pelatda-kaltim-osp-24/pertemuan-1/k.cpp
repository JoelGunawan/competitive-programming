#include <bits/stdc++.h>
using namespace std;
int main() {
  // faktor bilangan
  // n
  // a faktor dari n atau bukan?
  // a merupakan faktor dari n jika a habis membagi n
  // n % a == 0
  int n;
  cin >> n;
  for(int i = n; i >= 1; i--) {
    // jika n dibagi i sisanya 0
    if(n % i == 0) {
      // i merupakan faktor dari n
      cout << i << endl;
    }
  }
}