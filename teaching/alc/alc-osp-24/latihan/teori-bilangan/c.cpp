#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long mn = 1e18; // (anggap infinity/tak terhingga)
  for(int i = 1; 1ll * i * i <= n; ++i) {
    if(n % i == 0) {
      // i merupakan faktor dri n
      // (1, 1) -> (i, n / i)
      if(i + n / i < mn)
        mn = n / i + i;
      //mn = min(mn, n / i + i); (alternatif yang sama)
    }
  }
  cout << mn - 2 << endl;
}