#include <bits/stdc++.h>
using namespace std;
int a[105], depth[105];
void solve(int l, int r, int cur_depth) {
  // cari maksimum
  int mx = 0, mxidx = 0;
  for(int i = l; i <= r; ++i) {
    if(a[i] > mx)
      mx = a[i], mxidx = i;
  }
  // yg jadi root -> node max index
  depth[mxidx] = cur_depth;
  // ada yg dikirinya max index
  if(mxidx > l)
    solve(l, mxidx - 1, cur_depth + 1);
  // ada yg di kanannya max index
  if(mxidx < r) 
    solve(mxidx + 1, r, cur_depth + 1);
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    solve(1, n, 0);
    for(int i = 1; i <= n; ++i)
      cout << depth[i] << " ";
    cout << endl;
  }
}