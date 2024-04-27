#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int x[n];
  for(int i = 0; i < n; ++i)
    cin >> x[i];
  // invalid -> -1
  int minR[n], maxR[n];
  map<int, int> a;
  int r = -1, distinct = 0;
  for(int i = 0; i < n; ++i) {
    // maxR
    while(r < n - 1 && (distinct < k || a[x[r + 1]] > 0)) {
      ++r;
      if(a[x[r]] == 0)
        ++distinct;
      ++a[x[r]];
    }
    maxR[i] = r;
    --a[x[i]];
    if(a[x[i]] == 0)
      --distinct;
  }
  r = -1, distinct = 0;
  a.clear();
  for(int i = 0; i < n; ++i) {
    // minR
    while(r < n - 1 && distinct < k) {
      ++r;
      if(a[x[r]] == 0)
        ++distinct;
      ++a[x[r]];
    }
    if(distinct == k)
      minR[i] = r;
    else
      minR[i] = -1;
    --a[x[i]];
    if(a[x[i]] == 0)
      --distinct;
  }
  long long res = 0;
  for(int i = 0; i < n; ++i) {
    if(maxR[i] != -1) {
      res += maxR[i] - i + 1;
    }
  }
  cout << res << endl;
}