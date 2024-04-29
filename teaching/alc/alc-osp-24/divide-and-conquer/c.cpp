#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1);
  int mx = 0;
  for(int i = 1; i <= n; ++i) {
    // cari yg di kiri/kurang dari sama dengan yang paling besar
    int l = 1, r = m, kiri = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(b[mid] <= a[i]) {
        kiri = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    l = 1, r = m; int kanan = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(b[mid] >= a[i]) {
        // ketemu jawaban optimal, coba geser ke kiri karena bisa jadi ada yg lebih optimal
        // geser ke kiri
        kanan = mid;
        r = mid - 1;
      }
      else {
        // geser ke kanan, karena b[mid] terlalu kecil, maka dari l ... mid -> pasti terlalu kecil
        l = mid + 1;
      }
    }
    // coba cari terdekat di kanan/kiri
    if(kanan == -1) {
      // kanan ga ada, pasti yg kiri
      mx = max(mx, a[i] - b[kiri]);
    }
    else if(kiri == -1) {
      // kiri ga ada, pasti yg kanan
      mx = max(mx, b[kanan] - a[i]);
    }
    else {
      // ada dua"nya, cari minimum
      mx = max(mx, min(b[kanan] - a[i], a[i] - b[kiri]));
    }
  }
  cout << mx << endl;
}