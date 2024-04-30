#include <bits/stdc++.h>
using namespace std;
int main() {
  // catatan:
  // fungsi max(a, b) -> mengembalikan maksmimum dari 2 bilangan
  // fungsi min(a, b) -> mengembalikan minimum dari 2 bilangan
  // nilai max(3, 5) adalah 5
  // nilai min(3, 5) adalah 3
  int n, m;
  cin >> n >> m;
  // a -> koordinat kota
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // b -> koordinat menara seluler
  int b[m + 1];
  for(int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  // binary search lokasi menara selulernya (cari yg <= x dan >= x)
  sort(b + 1, b + m + 1); // sorting dari indeks 1 ke indeks m
  int mx = 0; // maksimal jarak terdekat ke menara seluler untuk setiap kota
  for(int i = 1; i <= n; ++i) {
    // untuk setiap kota, cari menara seluler terdekat
    // ada 2 cara binary search:
    // a[i] -> koordinat dari kota yang kita mau cek
    // cari yg >= a[i] dan <= a[i]
    int l = 1, r = m, kurang_dari = -1;
    while(l <= r) {
      int m = (l + r) / 2;
      if(b[m] > a[i]) {
        // geser ke kiri, karena terlalu besar
        r = m - 1;
      }
      else {
        // memenuhi syarat <= a[i]
        // tapi kita mau cari yg paling besar, jadi geser ke kanan
        kurang_dari = m;
        l = m + 1;
      }
    }
    l = 1, r = m; int lebih_dari = -1;
    while(l <= r) {
      // / -> tanda bagi
      // a / b -> a bagi b
      int m = (l + r) / 2; // tengahnya l dan r
      if(b[m] < a[i]) {
        // terlalu kecil, maka kita harus geser ke kanan
        l = m + 1;
      }
      else {
        // memenuhi syarat >= a[i]
        // geser ke kiri, cari yg lebih kecil
        lebih_dari = m;
        r = m - 1;
      }
    }
    if(lebih_dari == -1) {
      // tdk ada yg lebih dari
      // jarak terdekat: a[i] - b[kurang_dari]
      mx = max(mx, a[i] - b[kurang_dari]);
    }
    else if(kurang_dari == -1) {
      // tidak ada yg kurang dari 
      // jarak terdekat: b[lebih_dari] - a[i]
      mx = max(mx, b[lebih_dari] - a[i]);
    }
    else {
      // dua"nya ada ya
      // jarak terdekat: min(a[i] - b[kurang_dari], b[lebih_dari] - a[i])
      int jarak_terdekat = min(a[i] - b[kurang_dari], b[lebih_dari] - a[i]);
      mx = max(mx, jarak_terdekat);
    }
    // langsung cari yg terdekat (susah/implementasinya lucu)
  }
  cout << mx << endl;
}