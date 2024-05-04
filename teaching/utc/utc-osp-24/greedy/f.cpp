#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    char suit[] = {'C', 'D', 'H', 'S'};
    // tiap suit isinya angka berapa aja
    vector<int> a[4];
    char trump_char;
    cin >> trump_char;
    int trump = 0;
    for(int i = 0; i < 4; ++i) {
      if(suit[i] == trump_char)
        trump = i;
    }
    for(int i = 1; i <= 2 * n; ++i) {
      string s;
      cin >> s;
      int num = s[0] - '0';
      for(int j = 0; j < 4; ++j) 
        if(s[1] == suit[j]) {
          a[j].push_back(num);
        }
    }
    for(int i = 0; i < 4; ++i)
      sort(a[i].begin(), a[i].end());
    // pair setipe kecuali trump
    vector<pair<string, string>> v;
    // first -> number
    // second -> suit;
    vector<pair<int, int>> need;
    for(int i = 0; i < 4; ++i) {
      if(trump == i)
        continue;
      while(a[i].size() >= 2) {
        // sebenernya ga harus 2 terakhir, bisa pilih terserah, tapi supaya gampang aja
        pair<string, string> x;
        x.second = to_string(a[i].back()) + suit[i];
        a[i].pop_back();
        x.first = to_string(a[i].back()) + suit[i];
        a[i].pop_back();
        v.push_back(x);
      }
      if(!a[i].empty()) {
        // ada sisa
        need.push_back({a[i][0], i});
      }
    }
    bool ans = 1;
    for(auto x : need) {
      if(a[trump].empty()) {
        ans = 0;
        break;
      }
      // pair x dengan trump (terserah yang mana)
      pair<string, string> s;
      s.second = to_string(a[trump].back()) + suit[trump];
      a[trump].pop_back();
      s.first = to_string(x.first) + suit[x.second];
      v.push_back(s);
    }
    if(!ans) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    while(a[trump].size()) {
      pair<string, string> x;
        x.second = to_string(a[trump].back()) + suit[trump];
        a[trump].pop_back();
        x.first = to_string(a[trump].back()) + suit[trump];
        a[trump].pop_back();
        v.push_back(x);
    }
    for(auto x : v) {
      cout << x.first << " " << x.second << endl;
    }
  }
}