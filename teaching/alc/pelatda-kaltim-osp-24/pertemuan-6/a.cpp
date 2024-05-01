#include <bits/stdc++.h>
using namespace std;
// array global a
int a[100], b[100], inversi = 0;
// void -> tidak ada nilai kembalian
void merge_sort(int l, int r) {
  // 1 elemen tidak perlu di sort
  if(l == r) {
    return;
  }
  int m = (l + r) / 2;
  merge_sort(l, m);
  merge_sort(m + 1, r);
  // gabungkan
  // b -> tempat simpan sementara
  // lidx -> indeks array kiri
  // ridx -> indeks array kanan
  int lidx = l, ridx = m + 1;
  // selama ada elemen yang belum diambil
  int idxb = l;
  while(lidx <= m || ridx <= r) {
    // indeks kiri lebih dari m
    if(lidx > m) {
      // kiri habis, harus ambil yg kanan
      b[idxb] = a[ridx];
      ++idxb;
      ++ridx;
    }
    // indeks kanan lebih dari r
    else if(ridx > r) {
      // kanan habis, harus ambil yg kiri
      // masukkan kiri, tambah inversi
      inversi += ridx - m - 1;
      b[idxb] = a[lidx];
      ++idxb;
      ++lidx;
    }
    else {
      // dua"nya masih ada, harus pilih yg minimum
      // harus kurang dari sama dengan, karena utk hitung inversi harus
      // prioritaskan yang di kiri
      if(a[lidx] <= a[ridx]) {
        // kiri kurang dari knana
        // ambil yg kiri
        // masukkan kiri, tambah inversi
        inversi += ridx - m - 1;
        b[idxb] = a[lidx];
        ++idxb;
        ++lidx;
      }
      else {
        // ambil yg kanan
        b[idxb] = a[ridx];
        ++idxb;
        ++ridx;
      }
    }
  }
  for(int i = l; i <= r; ++i) {
    a[i] = b[i];
    //cout << b[i] << " ";
  }
  /*
  cout << "OUT " << l << " " << r << endl;
  cout << endl;
  */
}
int main() {
  // implementasi merge sort
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  merge_sort(1, n);
  for(int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "Inversi: " << inversi << endl;
}