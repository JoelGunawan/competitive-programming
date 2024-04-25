#include <bits/stdc++.h>
using namespace std;
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int mn = 1e9, mx = 0;
  for(int i = 1; i <= n; ++i) {
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  int cnt_min = 0, cnt_max = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == mn)
      ++cnt_min;
    if(a[i] == mx)
      ++cnt_max;
  }
  if(mn == mx) {
    cout << 1ll * n * (n - 1) << endl;
  }
  else {
    cout << 2ll * cnt_min * cnt_max << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--)
    tc();
}