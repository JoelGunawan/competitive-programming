#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  map<string, string> a;
  for(int i = 0; i < n; ++i) {
    string x, y;
    cin >> x >> y;
    a[x] = y;
  }
  for(int i = 0; i < q; ++i) {
    string s;
    cin >> s;
    if(a[s] == "") {
      cout << "NIHIL" << endl;
    }
    else {
      cout << a[s] << endl;
    }
  }
}