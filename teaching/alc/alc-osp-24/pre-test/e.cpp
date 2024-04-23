#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int pow(int a, int b) {
  int res = 1;
  // batas atas: 10^7
  // 10^7
  // 1e7
  for(int i = 1; i <= b; ++i) {
    if(res >= 1e7) {
      break;
    }
    res = (res * a);
  }
  return res;
}
void tc() {
  int a, b, l;
  cin >> a >> b >> l;
  vector<int> v;
  // vector<tipe_data> nama;
  // deklarasi khusus: vector<tipe_data> nama(ukuran, nilai_awal);
  // deklarasi khusus: vector<tipe_data> nama(ukuran);
  // size() -> sama string
  // push_back() -> tambah elemen di akhir vector
  // pop_back() -> hapus elemn di akhir vector
  // fill(v.begin(), v.begin() + ...);
  // dari sebelumnya: arr -> arr.begin()
  for(int i = 0; i <= 20; ++i) {
    for(int j = 0; j <= 20; ++j) {
      long long ax = pow(a, i);
      long long by = pow(b, j);
      if(l % (ax * by) == 0) {
        // bisa
        v.push_back(l / (ax * by));
      }
    }
  }
  // yg duplikat jadi hilang
  /*
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;
  */
  // sort() -> sortir array
  // sort(arr + indeks_awal, arr + indeks_akhir)
  // sort(arr.begin() + indeks_awal, arr.begin() + indeks_akhir)
  // keseluruhan vector; sort(arr.begin(), arr.end())
  sort(v.begin(), v.end());
  // kalo lakukan ini di vector sorted -> menghilangkan elemen duplikat
  v.resize(unique(v.begin(), v.end()) - v.begin()); 
  /*
  cout << "SETELAH MENGHILANGKAN DUPLIKAT" << endl;
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;
  */
  cout << v.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
}