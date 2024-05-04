#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int cntmax = 0;
  long long sum = 0;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    sum += x;
    cntmax = max(cntmax, x);
  }
  // kemungkinan 1
  if(sum > 1ll * cntmax * k) {
    if(sum % k == 0)
      cout << 0 << endl;
    else
      cout << k - (sum % k) << endl;
  }
  // kemungkinan 2
  else {
    cout << 1ll * cntmax * k - sum << endl;
  }
}