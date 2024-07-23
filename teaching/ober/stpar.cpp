#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while(true) {
    cin >> n;
    if(n == 0)
      break;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    int idx = 1;
    stack<int> js;
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
      // yg di tempat skrg itu harus = i
      if(js.size() && js.top() == i)
        js.pop();
      else {
        while(idx <= n && a[idx] != i)
          js.push(a[idx]), ++idx;
        if(idx == n + 1) {
          ans = 0;
        }
        else {
          ++idx;
        }
      }
    }
    if(ans)
      cout << "yes" << endl;
    else 
      cout << "no" << endl;
  }
}