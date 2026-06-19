#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    if (n % 2 == 0) {
      cout << max(1, n - 3) << endl;
    }
    else {
      if(n == 3) {
        cout << 1 << endl;
      }
      else {
        long long res = 2 * (n - 4);
        for(int i = 2; i <= n - 4; ++i) {
          if(i % 2 == 0) {
            int num = (n - i - 1);
            // cout << "DEB " << i << " " << num << endl;
            res += max(0, num - 3);
          }
          else {
            int num = (n - i - 2);
            // cout << "DEB2 " << i << " " << num << endl;
            res += max(0, num - 3);
          }
        }
        cout << res << endl;
      }
    }
  }
}