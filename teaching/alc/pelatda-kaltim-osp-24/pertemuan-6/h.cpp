#include <bits/stdc++.h>
using namespace std;
// kecilkan ukuran array jika error di komputer kalian
long long memo[(int)1e3 + 5];
int mod = 1e9 + 7;
long long f(int n) {
  if(n == 0) {
    return 1;
  }
  else if(n < 0) {
    return 0;
  }
  else {
    // udah punya nilai
    if(memo[n] != -1) {
      return memo[n];
    }
    else {
      memo[n] = (f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)) % mod;
      return memo[n];
    }
  }
}
int main() {
  memset(memo, -1, sizeof(memo));
  int n;
  cin >> n;
  cout << f(n) << endl;
}