#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, B = 21;
int k, n, ma;
int bit[N];
void add(int x, int k) {
  while (x <= ma) {
    bit[x] += k;
    x += x & -x;
  }
}
int getSum(int x) {
  int sum = 0;
  while (x > 0) {
    sum += bit[x];
    x -= x & -x;
  }
  return sum;
}
void solve() {
  cin >> n >> k;
  ma = 0;
  vector<array<int, 2>> cnt(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ma = max(ma, (int)s.size());
    for (char c: s) {
      cnt[i][c - '0']++;
    }
  }
  ma = min(ma * 2 + 1, N - 1);
  for (int i = 1; i <= ma; i++) {
    bit[i] = 0;
  }
  sort(begin(cnt), end(cnt));
  int ans = ma * 2;
  for (int i = 0; i < n; i++) {
    add(cnt[i][1] + 1, 1);
    int cur = 0, sum = 0;
    for (int j = B - 1; j >= 0; j--) {
      if ((cur + (1 << j)) <= ma && sum + bit[cur + (1 << j)] < k) {
        cur += 1 << j;
        sum += bit[cur];
      }
    }
    if (i >= k - 1) {
      ans = min(ans, cnt[i][0] + cur);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << '\n';
  }
}