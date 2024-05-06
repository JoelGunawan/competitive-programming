#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  // supaya string indeks dari 1 ke n
  // prefix menyimpan banyak 'O'
  // suffix menyimpan banyak 'N'
  int pref[n + 1], suff[n + 2];
  memset(pref, 0, sizeof(pref));
  memset(suff, 0, sizeof(suff));
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1];
    if(s[i] == 'O')
      ++pref[i];
  }
  for(int i = n; i >= 1; --i) {
    suff[i] = suff[i + 1];
    if(s[i] == 'N')
      ++suff[i];
  }
  long long res = 0;
  for(int i = 1; i <= n; ++i) {
    if(s[i] == 'S')
      res += (long long)pref[i - 1] * suff[i + 1];
  }
  cout << res << endl;
}