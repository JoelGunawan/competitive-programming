#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  ll t = 0;
  if (s.back() == 'r') {
    for (int i = 0; i + 2 < n; i++) {
      t = t * 10 + s[i] - '0';
    }
  } else {
    for (int i = 0; i + 2 < n; i++) {
      if (s[i] != '.') {
        t = t * 10 + s[i] - '0';
      }
    }
    t *= 10;
  }
  if (t <= 100) {
    cout << "Bug";
  } else if (t <= 400) {
    cout << "Worm";
  } else if (t <= 1200) {
    cout << "Frog";
  } else if (t <= 2500) {
    cout << "Minnow";
  } else if (t <= 10000) {
    cout << "Bread";
  } else {
    cout << "Back to Home!";
  }
}