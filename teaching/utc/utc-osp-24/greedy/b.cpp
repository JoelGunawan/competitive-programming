#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      ++cnt[x];
    }
    bool first = 0;
    int res = n;
    for(int i = 0; i < n; ++i) {
      // 0/1/2?
      // note: 2 mksdnya lebih dari 1 (bisa 3, 4, 21098341, dll)
      if(cnt[i] == 0) {
        res = i;
        break;
      }
      else if(cnt[i] == 1) {
        // yg pertama, kita bisa ambil
        // kalo yg bukan pertama gabisa diambil
        if(first) {
          res = i;
          break;
        }
        else {
          // sebelumnya 1 udah dipake
          first = 1;
        }
      }
      // kalo > 1 biarin aja
    }
    cout << res << endl;
  }
}