#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  while(true) {
    // apakah s mengandung t sebagai substring?
    bool ada = 0;
    // nama_string.size() -> cari ukuran nama_string
    for(int i = 0; i + t.size() <= s.size(); ++i) {
      if(s.substr(i, t.size()) == t) {
        // t = "abc"
        // s = "babcd"
        // i = 1, hapus dari indeks 1 ke indeks 3
        // hapus dari indeks i ke indeks i + t.size() - 1
        s.erase(s.begin() + i, s.begin() + i + t.size());
        ada = 1;
        break;
      }
    }
    if(!ada) {
      break;
    }
  }
  // s = babcdabc -> bdabc -> bd
  // t = abc
  cout << s << endl;
}