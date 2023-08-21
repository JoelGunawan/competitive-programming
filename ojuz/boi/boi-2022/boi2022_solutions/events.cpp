#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int LG = 17;

int main() {
  int n, q; cin >> n >> q;
  vector<vector<int>> nx(LG);
  vector<vector<pair<int, int>>> rmq(LG);
  for (int i = 0; i < LG; i++)
    nx[i].resize(n), rmq[i].resize(n, {1'000'000'001, -1});
  vector<pair<int, int>> a(n);
  vector<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i].st >> a[i].nd;
    b.push_back(a[i].nd);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; i++) {
    int r = lower_bound(b.begin(), b.end(), a[i].nd) - b.begin();
    rmq[0][r] = min(rmq[0][r], {a[i].st, i});
  }
  for (int i = 0; i + 1 < LG; i++)
    for (int j = 0; j + (1 << (i + 1)) <= n; j++)
      rmq[i + 1][j] = min(rmq[i][j], rmq[i][j + (1 << i)]);
  for (int i = 0; i < n; i++) {
    int l = lower_bound(b.begin(), b.end(), a[i].st) - b.begin();
    int r = lower_bound(b.begin(), b.end(), a[i].nd) - b.begin();
    int h = 31 - __builtin_clz(r - l + 1);
    nx[0][i] = min(rmq[h][l], rmq[h][r + 1 - (1 << h)]).nd;
  }
  for (int i = 0; i + 1 < LG; i++)
    for (int j = 0; j < n; j++)
      nx[i + 1][j] = nx[i][nx[i][j]];
  while (q--) {
    int x, y, l = 1; cin >> x >> y; x--, y--;
    if (x == y || (a[y].st <= a[x].nd && a[x].nd <= a[y].nd)) {
      cout << (x == y ? 0 : 1) << "\n";
      continue;
    }
    for (int i = LG - 1; ~i; i--) {
      if (a[x].nd < a[nx[i][y]].st)
        l += 1 << i, y = nx[i][y];
    }
    y = nx[0][y];
    if (a[x].nd < a[y].st || a[x].nd > a[y].nd)
      cout << "impossible\n";
    else
      cout << l + (a[x].nd >= a[y].st) << "\n";
  }
}