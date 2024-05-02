#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  int a[n + 1][n + 1];
  int pref[n + 1][n + 1];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      if(c == '*') {
        a[i][j] = 1;
      }
      else {
        a[i][j] = 0;
      }
    }
  }
  // konstruksi prefiks
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }
  }
  // menjawab pertanyaan
  for(int i = 0; i < q; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // x2 >= x1, y2 >= y1
    cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << endl;
  }
}