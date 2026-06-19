#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define ll long long 
using namespace std;
typedef __int128_t lll;
void solve() {
  string s;
  cin >> s;
  if (s == "1") {
    cout << "POSSIBLE\n1 1 1\n1 1 1";
  } else if (s == "2") {
    cout << "POSSIBLE\n1 1 1\n1 2 1";
  } else if (s == "3") {
    cout << "IMPOSSIBLE";
  } else {
    cout << "POSSIBLE\n";
    lll n = 0;
    for (char c: s) {
      n = n * 10 + (c - '0');
    }
    lll l = 1, r = 1e18, mid;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (mid * mid <= n) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ll rem = n - r * r;
    ll t = r;
    if (rem == 0) {
      cout << "1 1 " << t << '\n';
      cout << "1 1 " << t;
      return;
    }
    cout << "1 1 " << t << '\n';
    if (rem <= r) {
      cout << "1 " << t - rem + 2 << ' ' << rem;
    } else {
      if (rem & 1) {
        rem = (rem + 1) / 2;
        cout << 2 + t - rem << ' ' << 2 + t - rem << ' ' << rem;
      } else {
        rem /= 2;
        cout << "1 " << t - rem + 3 << ' ' << rem;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
    cout << '\n';
  }

}