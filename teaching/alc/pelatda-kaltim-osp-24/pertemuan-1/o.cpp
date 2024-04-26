#include <bits/stdc++.h>
using namespace std;
int main() {
  // menghitung frekuensi kemunculan angka
  // frequency array/counting array
  // int cnt[5];
  // for(int i = 0; i < 5; ++i)
  //   cnt[i] = 0;
  
  // int n;
  // cin >> n;
  // for(int i = 1; i <= n; ++i) {
  //   int x;
  //   cin >> x;
  //   cnt[x]++;
  // }

  // for(int i = 0; i < 5; ++i) {
  //   cout << cnt[i] << " ";
  // }
  // cout << endl;
  
  // tambahan: 
  // string bisa dianggap sebagai array karakter
  string s = "halo dunia";
  s[2] = 'x';
  // dri index_awal ke index_akhir
  int index_awal = 7, index_akhir = 5;
  reverse(s.begin() + index_awal, s.end());
  // dri awal ke akhir
  // reverse(s.begin(), s.end());
  cout << s << endl;
}