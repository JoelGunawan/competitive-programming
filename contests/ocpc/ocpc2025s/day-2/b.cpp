#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;

  vector<int> a[2][26];
  for(int i = 1; i <= n; ++i) {
    // cerr << "PUSH " << (i & 1) << " " << i << endl;
    a[i & 1][s[i] - 'A'].push_back(i);
  }

  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 26; ++j) {
      reverse(a[i][j].begin(), a[i][j].end());
    }
  }
  
  string res = "";
  int idx = 0;
  while(idx < n) {
    // next must have same parity as idx + 1
    int nxpar = (idx + 1) & 1;
    int nxidx = -1;
    for(int i = 25; i >= 0; --i) {
      if(a[nxpar][i].size()) {
        // use this as next
        nxidx = a[nxpar][i].back();
        // cout << "POP1 " << nxpar << " " << i << " " << nxidx << endl;
        a[nxpar][i].pop_back();
        break;
      }
    }

    // if(nxidx == -1) {
    //   cout << s << endl;
    //   cout << "CUR " << idx << endl;
    //   for(int i = 0; i < 26; ++i) {
    //     cout << a[nxpar][i].size() << " ";
    //   }
    //   cout << endl;
    //   cout << nxpar << endl;
    //   for(int i = 0; i < 26; ++i) {
    //     cout << a[0][i].size() << " ";
    //   }
    //   cout << endl;
    //   assert(false);
    // }

    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 26; ++j) {
        // if (a[i][j].size()) {
        //   cout << "DEBUG " << i << " " << j << " " << a[i][j].back() << " " << nxidx << endl;
        // }
        while(a[i][j].size() && a[i][j].back() <= nxidx) {
          // cerr << "POP " << i << " " << j << endl;
          a[i][j].pop_back();
        }
      }
    }

    res += s[nxidx];
    idx = nxidx;
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--)
    solve();
}