#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  auto solve = [&]() -> void {
    string s; cin >> s;
    int n = s.size();
    s = s + 'R';
    vector<int> r(n + 1), l(n + 1), f(n + 1); 
    l[0] = s[0] == 'L';
    r[0] = s[0] == 'R';
    for (int i = 1; i <= n; i++) {
      l[i] = l[i - 1] + (s[i] == 'L');
      r[i] = r[i - 1] + (s[i] == 'R');
    }

    for (int i = 0; i <= n; i++) {
      f[i] = max(l[i], r[i]);
    }   

    ll ans = 0;
    for (int i = 0, cur = 0; i < n; i++) {
      if (i > 0 && s[i] == 'L') {
        ans += max(cur + l[i - 1], r[i - 1]);
      }

      if (i > 0) {
        cur = max(cur, r[i - 1] - l[i] + 1);
      } else {
        cur = max(cur, - l[i] + 1);
      }
    }

    ans += (ll) r[n - 1] * (r[n - 1] - 1) >> 1;

    cout << ans << "\n";
  };

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
}
