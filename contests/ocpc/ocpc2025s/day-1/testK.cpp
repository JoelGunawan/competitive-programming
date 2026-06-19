#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << sqrt(182378);
  return 0;
  map<int, int> cnt;
  for (int i = 1; i <= 3e5; i++) {
    int p = 1, x = i;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        p *= j;
        while (x % j == 0) {
          x /= j;
        }
      }
    }
    if (x > 1) {
      p *= x;
    }
    cnt[p] = 1;
  }
  cout << cnt.size();
}