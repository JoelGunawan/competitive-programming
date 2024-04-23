#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void tc() {
  string l, r;
  cin >> l >> r;
  // dua"nya sama, tdk ada first idx yg beda
  // dua"nya sama -> 0
  if(l == r) {
    cout << 0 << endl;
    // return di fungsi void -> stop
    return;
  }
  int first_idx;
  while(l.size() < r.size()) {
    l = "0" + l;
  }
  for(int i = 0; i < l.size(); ++i) {
    if(l[i] != r[i]) {
      first_idx = i;
      break;
    }
  }
  cout << r[first_idx] - l[first_idx] + 9 * (l.size() - first_idx - 1) << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
}