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
    int l = 1, r = n, posisi_jawaban = -1;
    while(l <= r) {
      int m = (l + r) / 2;
      cout << l << " " << m << " " << r << endl;
      if(a[m] >= x) {
        // karena memenuhi, kita mau coba cari yang lebih kecil yang memenuhi
        // lebih kecil -> ke kiri
        // ke kiri: kanannya kita geser ke kiri
        r = m - 1;
        posisi_jawaban = m;
      }
      else {
        // ini belum memenuhi, kalau belum memenuhi, harus cari yang lebih besar
        // lebih besar -> ke kanan
        // ke kanan: kirinya kita geser ke kanan
        l = m + 1;
      }
    }
    cout << "Posisi: " << posisi_jawaban << endl;
  }
}