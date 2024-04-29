#include <bits/stdc++.h>
using namespace std;
int main() {
  // membalikkan sebuah vector/array
  // sintaks untuk array:
  // mis. array a
  // reverse(a + indeks_awal, a + indeks_akhir + 1)
  // sintaks untuk vector:
  // mis. vector v
  // reverse(v.begin() + indeks_awal, v.begin() + indeks_akhir + 1)
  // kasus khusus untuk vector:
  // balik seluruh vector
  // reverse(v.begin(), v.end());
  // dengan kata lain: 
  // jika indeks_akhir di posisi akhir, kita bisa pakai v.end()
  // v.end() = v.begin() + v.size()
  // cara deklarasi array langsung dengan nilai
  int a[] = {1, 2, 9, 3, 5};
  // cara deklarasi vector langsung dengan nilai
  vector<int> v = {4, 5, 4, 23, 41, 9};
  // balik indeks 0 ke 2
  reverse(a, a + 3);
  for(auto x : a) {
    cout << x << " ";
  }
  cout << endl;
  // balik indeks 1 ke 4
  // kompleksitas: O(banyak elemen yg di reverse)
  reverse(v.begin() + 1, v.begin() + 5); 
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  // kompleksitas: banyak_elemen = n
  // kompleksitas: O(nlogn)
  sort(v.begin(), v.end());
  cout << (*(v.begin() + 3)) << endl;
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  // sort()
  // lower_bound() -> bahas di divide and conquer
  // upper_bound() -> bahas di divide and conquer
  // binary_search() -> bahas di divide and conquer
}