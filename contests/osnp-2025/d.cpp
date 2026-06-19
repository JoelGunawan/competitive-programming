#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  int pad = 0;
  while(s.size() && s.back() == 'B') {
    s.pop_back();
    ++pad;
  }

  reverse(s.begin(), s.end());

  while(s.size() && s.back() == 'B') {
    s.pop_back();
    ++pad;
  }

  vector<int> sz;
  int last = -1;
  n = s.size();
  s = " " + s;
  
  for(int i = 1; i <= n; ++i) {
    if(s[i] == 'B') {
      if(last != i - 1)
        last = i;
    } else {
      if(i != 1 && s[i - 1] == 'B') {
        sz.push_back(i - last);
      }
    }
  }

  sort(sz.begin(), sz.end());

  for(int i = 0; i < min((int)sz.size(), k - 1); ++i) {
    pad += sz[i];
  }

  cout << pad << endl;

  return 0;
}