#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  ll tinggi = m;
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    tinggi += k;
    while(a.size() && a.back() <= tinggi)
      a.pop_back();
    if(a.size())
      tinggi = a.back(), a.pop_back(), ++res;
  }
  cout << res << endl;
}