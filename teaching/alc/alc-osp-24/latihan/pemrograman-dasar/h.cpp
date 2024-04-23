#include <bits/stdc++.h>
using namespace std;
int main() {
  // pola kelipatan 4 -> cari modulo/sisa pembagian dengan 4
  // 0 -> meja kosong
  // 1 -> kue yg tidak terhias
  // 2 -> kue yg sudah terhias VALID, 2
  // 3 -> kue yg sudah terhias dan terkemas VALID, 3
  // 4 -> meja kosong
  // 5 -> kue yg tidak terhias
  // 6 -> kue yg sudah terhias VALID, 2
  // 7 -> kue yg sudah terhias dan terkemas VALID, 3
  int n, m;
  cin >> n >> m;
  int cnt[n + 5];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(cnt[i] % 4 == 2 || cnt[i] % 4 == 3) {
      res++;
    }
  }
  cout << res << endl;
}