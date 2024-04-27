#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  // a[i].first -> nilai
  // a[i].second -> index
  pair<int, int> a[n];
  for(int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n);
  int r = n - 1;
  for(int i = 0; i < n; ++i) {
    while(r > 0 && a[r - 1].first + a[i].first >= x) {
      --r;
    }
    if(a[i].first + a[r].first == x && i != r) {
      // ketemu jawaban
      cout << a[i].second << " " << a[r].second << endl;
      return 0; // langsung berhenti programnya
    }
  }
  cout << "IMPOSSIBLE" << endl;
}