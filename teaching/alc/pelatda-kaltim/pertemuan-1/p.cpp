#include <bits/stdc++.h>
using namespace std;
int main() {
  // cnt[5] -> banyak kemunculan 5
  int cnt[1001];
  for(int i = 1; i <= 1000; ++i) {
    cnt[i] = 0;
  }

  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x; // di input 1
    ++cnt[x]; // array di indeks 1 akan bertambah 1 sebanyak 1
  }

  // cari maksimum di cnt
  int mx = 0, idx;
  for(int i = 1; i <= 1000; ++i) {
    // jika jumlah sekarang > maks
    if(cnt[i] >= mx) {
      // maks = jumlah sekarang
      mx = cnt[i];
      idx = i;
    }
  }
  cout << idx << endl;
}