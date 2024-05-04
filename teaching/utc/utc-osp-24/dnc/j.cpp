#include <bits/stdc++.h>
using namespace std;
int query(int l, int r) {
  int x;
  // query jumlah dari l ke r
  cout << "? " << l << " " << r << endl;
  cin >> x;
  return x;
}
int main() {
  int n, t, k;
  cin >> n >> t >> k;
  // binary search posisi di mana jumlah 0 = k
  int l = 1, r = n, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    // jumlah dari 1 ke mid?
    // setiap elemen 0/1
    // maka jumlah -> jumlah kemunculan 1
    int jumlah1 = query(1, mid);
    int jumlah0 = mid - jumlah1;
    if(jumlah0 >= k) {
      r = mid - 1, ans = mid;
    }
    else {
      l = mid + 1;
    }
  }
  cout << "! " << ans << endl;
}