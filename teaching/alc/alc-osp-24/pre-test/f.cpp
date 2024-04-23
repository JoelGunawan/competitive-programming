#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void tc() {
  int n;
  string s;
  cin >> n >> s;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  // c -> karakter di dalam s
  for(auto c : s) {
    cnt[c - 'a']++;
  }
  int mx = 0;
  for(int i = 0; i < 26; ++i) {
    // fungsi max
    // max(angka1, angka2)
    if(cnt[i] > mx)
      mx = cnt[i];
    // mx = max(mx, cnt[i]); ekuivalen dengan yang atas
  }
  if(mx <= n / 2) {
    if(n % 2 == 0) {
      // genap
      cout << 0 << endl;
    }
    else {
      // ganjil
      cout << 1 << endl;
    }
  }
  else {
    cout << n  - 2 * (n - mx) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--)
    tc();
}