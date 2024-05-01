#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  int r = -1, unik = 0;
  // elemen unik 3, k = 4
  // setelah masukkan 1 elemen, tdk mungkin elemen unik jadi 5
  // maka jika jumlah unik < k, maka selalu aman utk masukkan
  map<int, int> kemunculan;
  int mx = 0, kiri, kanan;
  for(int i = 0; i < n; ++i) {
    // selama r bisa digeser ke kanan dan penambahan elemen ke r + 1 tidak akan membuat jumlah elemen
    // unik menjadi lebih dari k
    while(r < n - 1 && (unik < k || kemunculan[a[r + 1]] > 0)) {
      ++r;
      // masukkan elemen ke r
      ++kemunculan[a[r]];
      if(kemunculan[a[r]] == 1) {
        // elemen yang baru, tambah jumlah unik
        ++unik;
      }
    }
    // akan dapat r terjauh yang memiliki paling banyak k elemen unik
    // segmen dari i ke r
    // panjang: r - i + 1
    // jika panjang segmen sekarang lebih dari maksimal, maka ubah segmen maksimal jadi segmen sekarang
    if(r - i + 1 > mx) {
      mx = r - i + 1;
      kiri = i;
      kanan = r;
    }
    --kemunculan[a[i]];
    if(kemunculan[a[i]] == 0) {
      // yang barusan dikeluarkan itu elemen terakhir
      // mengurangi jumlah elemen unik
      --unik;
    }
  }
  cout << kiri + 1 << " " << kanan + 1 << endl;
}