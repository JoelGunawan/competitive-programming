#include <bits/stdc++.h>
using namespace std;
int main() {
  // input sebuah array ukuran n
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  // tanyakan q pertanyaan
  int q;
  cin >> q;
  for(int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    // apakah ada x di array ini atau tida?
    int l = 1, r = n;
    bool ans = false; // apakah kita ketemu x atau tidak
    while(l <= r) {
      int m = (l + r) / 2;
      cout << l << " " << m << " " << r << endl;
      if(a[m] == x) {
        // di posisi sekarang = x
        ans = true;
        break;
      }
      else if(a[m] < x) {
        // terlalu kecil, harus ke kanan
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    if(ans) {
      cout << "Ketemu" << endl;
    }
    else {
      cout << "Tidak ketemu" << endl;
    }
  }
}