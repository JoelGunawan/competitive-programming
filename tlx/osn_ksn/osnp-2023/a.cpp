#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < m; ++i)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll suma = 0, sumb = 0;
  for(int i = 0; i < n; ++i) {
    suma += a[i];
  }
  for(int i = 0; i < m; ++i) {
    sumb += b[i];
  }
  ll res = 0;
  while(b.size() != 0 && suma / (double)a.size() <= sumb / (double)b.size()) {
    int cur = b.back();
    while(b.size() && b.back() == cur) {
      suma += b.back();
      sumb -= b.back();
      res += b.back();
      a.push_back(b.back());
      b.pop_back();
    }
    //cout << suma / (double)a.size() << " " << sumb / (double)b.size() << endl;
  }
  if(b.empty())
    cout << -1 << endl;
  else
    cout << res << endl;
}