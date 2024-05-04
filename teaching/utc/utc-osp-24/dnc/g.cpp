#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int x[n + 1];
  int mx_elem = 0;
  ll sum = 0;
  for(int i = 1; i <= n; ++i)
    cin >> x[i], mx_elem = max(mx_elem, x[i]), sum += x[i];
  ll l = mx_elem, r = sum, ans;
  while(l <= r) {
    ll mid = (l + r) / 2;
    int cnt = 1;
    ll cur = 0;
    // cek minimum partition yg diperlukan utk maxsum = mid
    for(int i = 1; i <= n; ++i) {
      // buat partition baru jika jumlah melebihi maksimum
      if(cur + x[i] > mid)
        ++cnt, cur = 0;
      // partition sekarang ditambah a[i]
      cur += x[i];
    }
    // cnt -> jumlah partition yg dibutuhkan
    // jumlah partition yg dibutuhkan terlalu banyak
    if(cnt > k) {
      // naikin maksimum sum, supaya jumlah partition yg dibutuhkan lebih dikit
      l = mid + 1;
    }
    else {
      // yg sekarang valid, kita coba cari max sum yang lebih kecil
      r = mid - 1;
      ans = mid;
    }
    // kenapa +1/-1 -> karena kita ga perlu cek mid lagi
  }
  cout << ans << endl;
}