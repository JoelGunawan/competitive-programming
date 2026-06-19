#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n != m) {
    cout << "No";
    return 0;
  }
  char ans[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = '.';
    }
    for (int j = 0; j <= i; j++) {
      ans[i][n - j - 1] = '#';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}