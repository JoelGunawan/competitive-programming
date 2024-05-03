#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long tinggi = m;
  int efektif = 0;
  for(int i = 0; i < n; ++i) {
    tinggi += k;
    // cek apakah ada di a yang nilainya lebih dari tinggi
    while(a.size() > 0 && a.back() <= tinggi) {
      // tidak mungkin bisa efektif dibuang
      a.pop_back();
    }
    if(a.size() == 0) {
      // tidak ada yg efektif -> berhenti
      break;
    }
    // ada yg memenuhi syarat > tinggi
    tinggi = max(tinggi, (long long)a.back());
    a.pop_back();
    ++efektif;
  }
  cout << efektif << endl;
}