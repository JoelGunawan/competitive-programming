#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].fi;
    a[i].se = i;
  }
  int r = n;
  sort(a + 1, a + n + 1);
  // kasus corner:
  // pake 1 indeks 2 kali?
  for(int l = 1; l <= n; ++l) {
    // selama terlalu besar, geser r ke kiri
    while(r > 0 && a[l].fi + a[r].fi > x)
      --r;
    if(l >= r)
      break;
    if(a[l].fi + a[r].fi == x) {
      cout << a[l].se << " " << a[r].se << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}