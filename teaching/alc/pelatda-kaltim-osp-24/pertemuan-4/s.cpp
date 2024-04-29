#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  int q; 
  cin >> q;
  while(q--) {
    int nilai;
    cin >> nilai;
    int lb = lower_bound(a, a + n, nilai) - a;
    int ub = upper_bound(a, a + n, nilai) - a;
    // utk vector
    // int lb = lower_bound(vector.begin(), vector.end(), nilai) - vector.begin();
    // int ub = upper_bound(vector.begin(), vector.end(), nilai) - vector.begin();
    // tambahan:
    // mau cek apakah nilai exist atau tidak, bisa pakai binary_search
    // binary_search(iterator_awal, iterator_akhir, nilai) akan mengembalikan bool yg menandakan
    // apakah nilai tersebut berada di antara iterator awal dan akhir
    if(binary_search(a, a + n, nilai)) {
      cout << "Nilai ada di a" << endl;
    }
    else {
      cout << "Nilai tidak ada di a" << endl;
    }
    cout << "index lower bound " << lb << endl;
    cout << "index upper bound " << ub << endl;
  }
}