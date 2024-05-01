#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  // harusnya isinya hanya integer
  // buat jadi pair
  // pair<int, int> 
  // pair.first (elemen pertama pair) akan menyimpan nilainya
  // pair.second (elemen kedua pair) akan menyimpan indeks awalnya
  // pair<int, pair<int, int>> -> boleh
  // pertama: berdasarkan pair.first
  // kedua: berdasarkan pair.second.first
  // ketiga: berdasarkan pair.second.second
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  /*
  for(int i = 1; i <= n; ++i) {
    cout << a[i].first << " " << a[i].second << endl;
  }
  */
  sort(a + 1, a + n + 1);
  /*
  cout << "Setelah di Sort: " << endl;
  for(int i = 1; i <= n; ++i) {
    cout << a[i].first << " " << a[i].second << endl;
  }
  */
  int r = n;
  // for loop akan jadi l
  // kompleksitas waktu: O(n)
  for(int i = 1; i <= n; ++i) {
    // selama terlalu besar, geser ke kiri
    while(a[i].first + a[r].first > x) {
      --r;
    }
    // kanan sudah kurang dari sama dengan kiri -> tidak sah, berhenti
    if(r <= i) {
      break;
    }
    if(a[i].first + a[r].first == x) {
      // ketemu jawaban
      cout << a[i].second << " " << a[r].second << endl;
      return 0; // berhentikan program
    }
  }
  // sampai akhir program tdk ketemu -> output tidak mungkin
  cout << "IMPOSSIBLE" << endl;
}