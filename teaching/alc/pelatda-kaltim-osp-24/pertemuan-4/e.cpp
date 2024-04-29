#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  v.push_back(3);
  v.push_back(5);
  v.push_back(-4);
  // iterasi setiap elemen dari vector/array secara urut
  // dari indeks 0 ke indeks terakhir
  // for(tipe_data variabel : nama)
  for(int x : v) {
    cout << x << " ";
  }
  cout << endl;
  int a[5];
  for(int i = 0; i < 5; ++i) 
    a[i] = 3 * i;
  // auto -> supaya otomatis (gaperlu di tulis tipe datanya)
  for(auto x : a) {
    cout << x << " ";
  }
  cout << endl;
}