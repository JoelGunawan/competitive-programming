#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  // trik mengubah vector v jadi isinya elemen unik
  sort(v.begin(), v.end());
  // v.resize -> ubah ukuran vektor
  // unique(v.begin(), v.end()) - v.begin() -> cara dapet ukurannya vektor yg isinya elemen unique
  v.resize(unique(v.begin(), v.end()) - v.begin());
  // for(int i = 0; i < v.size(); ++i)
  //   cout << v[i] << " ";
  // cout << endl;
  // jawaban
  cout << v.size() << endl;
}