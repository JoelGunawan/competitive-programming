#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long tinggi = m;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  // yg kecil itu di belakang
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    tinggi += k;
    // coba aplikasikan botol ajaib
    while(a.size() > 0 && a.back() <= tinggi) {
      a.pop_back();
    }
    // ada yg efektif
    if(a.size() > 0) {
      // pilih yg paling kecil (di a.back())
      tinggi = a.back();
      ++res;
      a.pop_back();
    }
  }
  cout << res << endl;
}