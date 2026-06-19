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

  vector<vector<int>> tmax(n, vector<int>(20, 0)), tmin(n, vector<int>(20, 0));
  for (int i = 0; i < n; i++) {
    tmax[i][0] = a[i];
  }

  for (int j = 1; j < 20; j++) {
    for (int i = 0; i + bit(j) <= n; i++) {
      tmax[i][j] = max(tmax[i][j - 1], tmax[i + bit(j - 1)][j - 1]);
    }
  }

  auto getind = [&](int i, int j) {
    if (a[i] != a[j]) {
      return (a[i] < a[j]) ? i : j;
    }
    return min(i, j);
  };

  for (int i = 0; i < n; i++) {
    tmin[i][0] = i;
  }
  
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i + bit(j) <= n; i++) {
      tmin[i][j] = getind(tmin[i][j - 1], tmin[i + bit(j - 1)][j - 1]);
    }
  }

  auto getmax = [&](int l, int r) {
    int d = log2(r - l + 1);
    return max(tmax[l][d], tmax[r - bit(d) + 1][d]);
  };

  auto getmin = [&](int l, int r) {
    int d = log2(r - l + 1);
    return getind(tmin[l][d], tmin[r - bit(d) + 1][d]);
  };
  
  ll ans = 0;
  function<void(int, int, int)> solve = [&](int l, int r, int las) -> void {
    if (l > r) {
      return;
    }
    int mx = getmax(l, r);
    int mn = a[getmin(l, r)];

    // cerr << l << " " << r << " " << mn << " " << mx << " " << las << "\n";

    if (mx - 2 * mn <= 0) {
      int curmx = mx - 2 * las;
      int curmn = mn - las;
      int dif = curmx - curmn;
      if (dif >= 0) {
        ans += dif;
        ans += (curmn - dif + 1) >> 1;
      } else {
        ans += (max(0, curmx) + 1) >> 1;
      }
      return;
    } 

    ans += mn - las;
    int pre = l - 1;
    while (pre < r) {
      int i = getmin(pre + 1, r);
      if (a[i] != mn) {
        break;
      }
      solve(pre + 1, i - 1, mn);
      pre = i;
    }
    solve(pre + 1, r, mn);
  };

  solve(0, n - 1, 0);
  cout << ans << "\n";
}