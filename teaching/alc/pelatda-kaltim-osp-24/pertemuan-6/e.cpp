#include <bits/stdc++.h>
#define ll long long // artinya kalo aku ketik ll, maka programnya itu akan menganggap sebagai long long
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  // prefix -> selalu buat prefix sumnya 1 based (mulai dari 1)
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  ll pref[n + 1];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i]; // konstruksi prefix sum
  }
  for(int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << endl;
  }
}