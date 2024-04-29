#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  // misal a terurut
  int a[n];
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int l = 0, r = n - 1, ans = -1; // ans menyimpan jawaban, l kiri, r kanan
  while(l <= r) {
    int mid = (l + r) / 2;
    cout << l << " " << r << endl;
    if(a[mid] == x) {
      ans = mid;
      break;
    }
    else if(a[mid] > x) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}