#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  // positif: > 0
  if(n > 0) {
    cout << "positif" << endl;
  }
  // nol: == 0
  else if(n == 0) {
    cout << "nol" << endl;
  }
  // kalau bukan positif, dan bukan 0, pasti negatif
  else {
    cout << "negatif" << endl;
  }
}