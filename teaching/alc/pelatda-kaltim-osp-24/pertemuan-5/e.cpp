#include <bits/stdc++.h>
using namespace std;
int main() {
  // 1e9 -> 10^9
  // 2e10 -> 2 * 10^10
  // 1e18 -> 10^18
  int n, t;
  cin >> n >> t;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // binary search jawaban: batas bawah dan batas atas
  // batas bawah: 1 satuan waktu
  // batas atas: 1 mesin, waktu paling lama, produknya paling banyak
  // 10^9 * 10^9 = 10^18
  // 1e18 -> cara cepat tulis 10^18
  long long l = 1, r = 1e18, ans = -1;
  // O(nlog10^18)
  while(l <= r) {
    long long m = (l + r) / 2;
    // apakah m ini membuat setidaknya t produk?
    // banyak produk yg dibuat?
    long long produk = 0;
    for(int i = 1; i <= n; ++i) {
      // m -> waktu yg dicoba
      // a[i] -> waktu yg dibutuhkan mesin utk membuat 1 produk
      // waktu m
      // setiap a[i], dia buat 1 produk
      // waktu m -> menghasilkan m / a[i] produk
      // jumlahkan seluruh mesin  
      produk += m / a[i];
      // produk udh lebih yg kita perlukan berhenti 
      // (harus ada, karena kalo tidak bisa jadi wktu kita cek
      // jumlah produk bisa lebih dari batasnya long long)
      if(produk >= t) {
        break; 
      }
    }
    if(produk >= t) {
      // coba cari waktu yang lebih singkat (lebih kecil)
      // geser ke kiri
      r = m - 1;
      ans = m;
    }
    else {
      // coba naikin waktunya supaya produk bisa >= t
      // geser ke kanan
      l = m + 1;
    }
  }
  cout << ans << endl;
}