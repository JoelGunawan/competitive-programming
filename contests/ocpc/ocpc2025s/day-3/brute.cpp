#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define ll long long 
using namespace std;

const int oo = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  
  ll ans = 0;
  function<void(int, int, int)> solve = [&](int l, int r, int las) -> void {
    if (l > r) {
      return;
    }
    int mn = oo, mx = -oo;

    for (int i = l; i <= r; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }

    // cerr << l << " " << r << " " << mn << " " << mx << " " << las << "\n";
    if (mx - 2 * mn <= 0) {
      int curmx = mx - 2 * las;
      int curmn = mn - las;
      int dif = curmx - curmn;
      ans += dif;
      ans += (curmn - dif + 1) >> 1;
      return;
    }

    ans += mn - las;
    int pre = l - 1;
    for (int i = l; i <= r; i++) if (a[i] == mn) {
      solve(pre + 1, i - 1, mn);
      pre = i;
    }
    solve(pre + 1, r, mn);
  };

  solve(0, n - 1, 0);
  cout << ans << "\n";
}