#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 2e5 + 1, M = 20;
int n, m, tot;
int a[N];
pair<int, int> dp[1 << M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  tot = (1 << m) - 1;
  for (int i = 0; i <= tot; i++) {
    dp[i] = {m + 1, n + 1};
  }
  vector<int> all;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'Y') {
        a[i] |= 1 << j;
      }
    }
    int t = a[i] ^ tot;
    dp[t] = min(dp[t], {__builtin_popcount(t), i});
    if (a[i] == tot) {
      all.push_back(i);
    }
  }
  if (all.size()) {
    if (all.size() > 1) {
      cout << all[0] << ' ' << all[1];
    } else {
      int j = 1;
      if (all[0] == 1) {
        j = 2;
      }
      for (int i = 1; i <= n; i++) {
        if (i != all[0]) {
          if (__builtin_popcount(a[i]) > __builtin_popcount(a[j])) {
            j = i;
          }
        }
      }
      if (j > all[0]) {
        cout << all[0] << ' ' << j;
      } else {
        cout << j << ' ' << all[0];
      }
    }
    return 0;
  }
  for (int i = 1; i <= tot; i++) {
    int j = i;
    while (j > 0) {
      int t = j & -j;
      if (dp[i ^ t].first < dp[i].first) {
        dp[i] = dp[i ^ t];
      } else if (dp[i ^ t].first == dp[i].first) {
        dp[i] = min(dp[i], dp[i ^ t]);
      }
      j ^= t;
    }
  }
  int ans = -1;
  pair<int, int> p = {n + 1, n + 1};
  for (int i = 1; i <= n; i++) {
    if (dp[a[i]].first != m + 1) {
      int t = __builtin_popcount(a[i]) - dp[a[i]].first;
      pair<int, int> tt = {dp[a[i]].second, i};
      if (p.first > p.second) {
        swap(p.first, p.second);
      }
      if (t > ans) {
        ans = t;
        p = tt;
      } else if (t == ans) {
        p = min(p, tt);
      }
    }
  }
  if (ans != -1) {
    cout << p.first << ' ' << p.second;
  } else {
    cout << "No";
  }
}