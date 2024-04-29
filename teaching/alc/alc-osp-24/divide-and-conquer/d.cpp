#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  //ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  int l = 1, r = 2e9, ans;
  while(l <= r) {
    int mid = ((long long)l + r) / 2;
    // apakah bisa membuat setidanyak n / 2 + 1 elemen lebih dari sama dengan mid
    int cnt = 0, op = k;
    for(int i = 0; i < n; ++i) {
      if(a[i] >= mid) {
        ++cnt;
      }
      else {
        if(op >= mid - a[i]) {
          ++cnt;
          op -= mid - a[i];
        }
      }
    }
    if(cnt >= n / 2 + 1) {
      // coba cri yg lebih besar
      l = mid + 1, ans = mid;
    }
    else {
      // coba cri yg lebih kecil, karena terlalu besar, tidak bisa
      r = mid - 1;
    }
  }
  cout << ans << endl;
}