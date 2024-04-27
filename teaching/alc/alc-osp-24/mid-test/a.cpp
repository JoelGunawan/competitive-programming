#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int cur = 0; // modulo sementara
  int pow10[7];
  pow10[0] = 1;
  for(int i = 1; i < 7; ++i) 
    pow10[i] = pow10[i - 1] * 10;
  int res = 0; // simpan hasil
  for(int i = 1; i <= n; ++i) {
    int length = to_string(i).size();
    cur = (1ll * cur * pow10[length] + i) % k;
    if(cur == 0) {
      ++res;
    }
  }
  cout << res << endl;
}