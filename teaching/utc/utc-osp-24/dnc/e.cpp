#include <bits/stdc++.h>
using namespace std;
int main() {
  // binary search solution
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= m; ++i)
    cin >> b[i];
  // untuk tiap kota di a, cari tower terdekat di b
  // utk higher:
  // indeks terkecil yg >= a[i] (angka terkecil)
  // utk lower: 
  // indeks terbesar yg <= a[i] (angka terbesar)
  // syarat binary search: terurut
  // sort B
  sort(b + 1, b + m + 1);
  int closest[n + 1];
  int mx = 0;
  for(int i = 1; i <= n; ++i) {
    int lower = -1, higher = -1;
    int l = 1, r = m;
    // lower (<= a[i])
    while(l <= r) {
      int mid = (l + r) / 2;
      // a[i] terlalu besar
      if(a[i] < b[mid]) {
        // mid bukan bagian dari search space lagi
        // [l, mid - 1] (semua lebih kecil dari a[mid])
        r = mid - 1;
      }
      else {
        // mid bukan bagian dari search space lagi
        l = mid + 1;
        // [mid + 1, r] (semua lebih besar dari b[mid], jika ada di range ini yang valid maka pasti lebih optimal)
        // lower = mid, tujuannya:
        // "ini valid, tapi coba kita cari yang lebih mendekati"
        // jawaban sementara kita, tapi kalo dapat yang lebih optimal, 
        // kita ganti (yang lebih optimal pasti di [mid + 1, r] karena lebih besar)
        lower = mid;
      }
    }
    // higher (>= a[i])
    l = 1, r = m;
    while(l <= r) {
      int mid = (l + r) / 2;
      // a[i] terlalu kecil
      if(a[i] > b[mid]) {
        l = mid + 1;
      }
      else {
        r = mid - 1;
        higher = mid;
      }
    }
    // lower dan higher
    if(lower == -1) {
      closest[i] = b[higher] - a[i];
    }
    else if(higher == -1) {
      closest[i] = a[i] - b[lower];
    }
    else {
      closest[i] = min(b[higher] - a[i], a[i] - b[lower]);
    }
    //cout << closest[i] << " ";
    mx = max(mx, closest[i]);
  }
  //cout << endl;
  cout << mx << endl;
}