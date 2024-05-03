#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  long long jumlah_a = 0, jumlah_b = 0;
  for(int i = 0; i < n; ++i) {
    jumlah_a += a[i];
  }
  for(int i = 0; i < m; ++i) {
    jumlah_b += b[i];
  }
  long long dipindah = 0;
  while(b.size() > 0 && jumlah_a / (double)a.size() <= jumlah_b / (double)b.size()) {
    // harus masukkan dari b ke a (dari yang paling besar)
    // keluarkan yang paling besar -> b.back()
    int keluar = b.back();
    while(b.size() > 0 & b.back() == keluar) {
      // keluarkan semua nilai yang sama dengan yang kita mau keluarkan
      // pindahkan dari b ke a
      // pindah dari b ke a
      // jumlah_b dikurangi
      // jumlah_a ditambah
      jumlah_a += keluar;
      jumlah_b -= keluar;
      dipindah += keluar;
      b.pop_back();
      a.push_back(keluar);
    }
  }
  if(b.size() == 0) {
    cout << -1 << endl;
  }
  else { 
    cout << dipindah << endl;
  }
}