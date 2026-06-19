#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 9;
  vector<vector<int>> a(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int mask = 0; mask < bit(n); mask++) {
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      if (getbit(mask, i)) {
        pos[i] = a[0][i];
      } else {
        pos[i] = -a[0][i];
      }
    }

    bool found = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        found &= a[i][j] == abs(pos[i] - pos[j]);
      }
    }

    found &= (*max_element(ALL(pos)) - *min_element(ALL(pos))) <= (int) 1e6;

    if (found) {
      int mn = *min_element(ALL(pos));
      for (int x : pos) {
        cout << x - mn << " ";
      }
      return 0;
    }
  }
}