#include <bits/stdc++.h>
using namespace std;
int main() {
  // upper bound and lower bound solution
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= m; ++i)
    cin >> b[i];
  sort(b + 1, b + m + 1);
  // function c++ lower_bound dan upper_bound
  // lower_bound -> return iterator elemen pertama yang >= a[i]
  // upper_bound -> return iterator elemen pertama yang > a[i]
  // upper_bound dikurangin 1 -> iterator elemen pertama yg <= a[i]
  // lower_bound(iterator_awal + indeks_awal, iterator_awal + indeks_akhir + 1, a[i])
  // ex di soal ini:
  // lower_bound(b + 1, b + m + 1, a[i])
  // utk upper bound sama
  int mx = 0;
  for(int i = 1; i <= n; ++i) {
    // cari elemen pertama yg >= a[i]
    // lower_bound(b + 1, b + m + 1) -> iterator
    // b + 1 -> iterator
    // dikurangin -> cari jarak antara dua iterator (indeks)
    // array -> O(1) iterator subtraction
    // lainnya -> bisa O(N)
    int higher = lower_bound(b + 1, b + m + 1, a[i]) - b;
    int lower = upper_bound(b + 1, b + m + 1, a[i]) - b - 1;
    int closest;
    if(lower < 1) {
      closest = b[higher] - a[i];
    }
    else if(higher > m) {
      closest = a[i] - b[lower];
    }
    else {
      closest = min(b[higher] - a[i], a[i] - b[lower]);
    }
    mx = max(mx, closest);
  }
  cout << mx << endl;
}