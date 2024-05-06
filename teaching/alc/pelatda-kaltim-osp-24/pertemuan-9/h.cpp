#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int a[n], b[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < n; ++i)
    cin >> b[i];
  // dari x ke kanan
  // dari x ke kiri
  int r = -1;
  long long jumlah_segmen = 0;
  long long maks = 0;
  // ke kiri terus ke kanan
  // ke kanan terus ke kiri
  for(int i = 0; i < n; ++i) {
    // selama r bisa digeser
    // cout << a[i] << " " << a[r + 1] << endl;
    // cout << abs(a[i] - a[r + 1]) << " " << min(abs(x - a[i]), abs(x - a[r + 1])) << " " << k << endl;
    while(r + 1 < i) {
      ++r;
      jumlah_segmen += b[r];
    }
    while(r < n - 1 && abs(a[i] - a[r + 1]) + min(abs(x - a[i]), abs(x - a[r + 1])) <= k) {
      ++r;
      jumlah_segmen += b[r];
    }
    maks = max(maks, jumlah_segmen);
    jumlah_segmen -= b[i];
  }
  long long jumlah_kiri = 0, jumlah_kanan = 0;
  for(int i = 0; i < n; ++i) {
    // yg posisinya itu di kiri x dan jaraknya dari x <= k, masukkan ke hitungan
    if(a[i] <= x && x - a[i] <= k)
      jumlah_kiri += b[i];
    if(a[i] >= x && a[i] - x <= k)
      jumlah_kanan += b[i];
  }
  cout << max(maks, max(jumlah_kiri, jumlah_kanan)) << endl;
}