#include <bits/stdc++.h>
using namespace std;
int main() {
  // 5
  // 2 3 1 5
  // count: 1 1 1 0 1
  int n;
  cin >> n;
  int cnt[n + 5];
  // memset(nama, value, sizeof(naam));
  // set semua nilai di array -> -1 / 0 (utk int)
  // set semua nilai di array -> 0 / 1 (false/true) (utk boolean)
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i = 1; i <= n; ++i) {
    if(cnt[i] == 0) {
      cout << i << endl;
      break;
    }
  }
}