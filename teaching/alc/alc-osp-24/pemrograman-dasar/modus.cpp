#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  // cnt -> count/jumlah kemunculan, awalnya set ke 0
  int cnt[1005];
  fill(cnt, cnt + 1005, 0);
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x]; // cnt[x] += 1
  }
  int mx = 0, ans;
  /*
  for(int i = 1; i <= 1000; ++i) {
    if(cnt[i] > mx) {
      mx = cnt[i];
      ans = i;
    }
  }
  */
  // yang benar:
  for(int i = 1; i <= 1000; ++i) {
    if(cnt[i] >= mx) {
      mx = cnt[i];
      ans = i;
    }
  }
  cout << ans << endl;
}