#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  long long res = 0;
  for(int i = 1; i <= n; ++i) {
    int mx = a[i];
    for(int j = i + 1; j <= n; ++j) {
      mx = max(mx, a[j]);
      if((a[i] ^ a[j]) > mx) {
        ++res;
      }
    }
  }

  cout << res << endl;
}