#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int r = 0;
  // map menyimpan kemunculan angka di sliding window
  map<int, int> b;
  int cnt_group = 0;
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    // kalo sudah ada di segmen sekarang, ga akan nambah distint
    // kalo belum ada di segmen sekarang, tapi jumlah distinct masih kurang, bisa digeser R nya
    // INSERT
    while(r < n && (b[a[r + 1]] > 0 || cnt_group < k)) {
      if(b[a[r + 1]])
        ++b[a[r + 1]];
      else
        ++b[a[r + 1]], ++cnt_group;
      ++r;
    }
    // segmen [i, r] valid
    // segmen [i, r - 1] valid
    // ...
    // segmen[i, i] valid
    // jumlah segmen valid yang kirinya di i: r - i + 1 
    res += r - i + 1;
    // HAPUS
    // hapus i dari sliding window
    if(b[a[i]] == 1) {
      // kurangi jumlah distinct
      --cnt_group;
    }
    --b[a[i]];
  }
  cout << res << endl;
}