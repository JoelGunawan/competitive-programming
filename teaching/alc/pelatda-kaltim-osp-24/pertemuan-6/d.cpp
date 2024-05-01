#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i) {
    // 2-sum dari i + 1 ke n
    int r = n;
    for(int j = i + 1; j <= n; ++j) {
      // penjumlahan 3 bilangan bulat, yang nilai maksimalnya 10^9
      // 10^9 + 10^9 + 10^9 = 3*10^9 (3 milliar -> batas integer overflow)
      while(r > j && a[j].first + a[r].first > x - a[i].first) {
        --r;
      }
      if(r <= j) {
        break;
      }
      if(a[i].first + a[j].first == x - a[r].first) {
        cout << a[i].second << " " << a[j].second << " " << a[r].second << endl;
        return 0; // berhentikan programnya
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}