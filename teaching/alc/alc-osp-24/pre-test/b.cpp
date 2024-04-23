#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // reverse indeks 1 ke n
  reverse(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i) {
    cout << a[i];
    // posisi terakhir
    // != -> tidak sama dengan
    if(i != n) {
      cout << ",";
    }
  }
  cout << endl;
}