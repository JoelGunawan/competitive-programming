#include <bits/stdc++.h>
using namespace std;
int main() {
  int maks = 200005;
  int n, k, q;
  cin >> n >> k >> q;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  // buat dulu difference array
  int diff[maks];
  memset(diff, 0, sizeof(diff));
  for(int i = 1; i <= n; ++i) {
    // tambah dari a[i].first ke a[i].second
    // diff[a[i].first] ditambah 1
    // diff[a[i].second + 1] dikurangi 1
    diff[a[i].first] += 1;
    diff[a[i].second + 1] -= 1;
  }
  int rekomendasi[maks];
  memset(rekomendasi, 0, sizeof(rekomendasi));
  for(int i = 1; i < maks; ++i) {
    rekomendasi[i] = rekomendasi[i - 1] + diff[i];
  }
  // jika rekomendasi[i] lebih dari sama dengan maka kita akan masukkan ke prefix sum
  int pref[maks];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i < maks; ++i) {
    // temperatur yang diperbolehkan
    if(rekomendasi[i] >= k) {
      pref[i] = pref[i - 1] + 1;
    }
    else {
      pref[i] = pref[i - 1];
    }
  }
  for(int i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << endl;
  }
}