#include <bits/stdc++.h>
using namespace std;
int main() {
  // a a a
  // 1 1 2
  // 
  // a 1 1 1
  // a 1 1 1
  // a 1 1 2
  
  // a b c d
  // e f g h

  // a = 1 * 1 + 1 * 1 + 1 * 1
  int n, m, p;
  cin >> n >> m >> p;
  int a[n + 1][m + 1]; // array ukuran n * m
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  int b[m + 1][p + 1];
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= p; ++j) {
      cin >> b[i][j];
    }
  }
  int c[n + 1][p + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= p; ++j) {
      c[i][j] = 0;
      for(int k = 1; k <= m; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= p; ++j) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}