#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5];
  for(int i = 0; i < 5; ++i) {
    a[i] = -1;
  }
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  // ubah nilai dari [2, 4 - 1] -> [2, 3]
  // fill(a + indeks_awal, a + indeks_akhir + 1, value)
  fill(a + 2, a + 3 + 1, 30);
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}