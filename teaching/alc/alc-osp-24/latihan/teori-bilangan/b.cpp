#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // sqrt(10^12) -> batas atas yg perlu di cek primanya
  int lim = 1e6 + 5; // 1e6 -> 10^6
  bool prime[lim];
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for(int i = 2; i < lim; ++i) {
    if(prime[i]) {
      for(int j = 2 * i; j < lim; j += i)
        prime[j] = 0;
    }
  }
  for(int i = 1; i <= n; ++i) {
    int x = sqrt(a[i]);
    if(1ll * x * x == a[i] && prime[x]) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}