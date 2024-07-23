#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, int> cnt;
  for(int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if(cnt[s] > 0) {
      cout << s << cnt[s] << endl;
    }
    else {
      cout << "OK" << endl;
    }
    ++cnt[s];
  }
}