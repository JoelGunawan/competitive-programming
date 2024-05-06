#include <bits/stdc++.h>
using namespace std;
// osnp 2023 b1
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  // dikeluarkan pakai pop_back() di vector
  long long hasil = 0, jumlaha = 0, jumlahb = 0;
  for(auto x : a)
    jumlaha += x;
  for(auto x : b)
    jumlahb += x;
  // selama rata" a tidak lebih dari b
  while(b.size() > 0 && jumlaha / (double)a.size() <= jumlahb / (double)b.size()) {
    // bisa pindah dari b ke a
    int nilai_besar = b.back();
    while(b.size() >0 && b.back() == nilai_besar) {
      // keluarkan dari b dan pindah ke a
      // jumlaha dan jumlahb berubah
      jumlaha += b.back();
      jumlahb -= b.back();
      hasil += b.back();
      a.push_back(b.back());
      b.pop_back();
    }
  }
  if(b.size() == 0) {
    cout << -1 << endl;
  }
  else {
    cout << hasil << endl;
  }
}