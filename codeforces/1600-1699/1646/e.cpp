#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  // start from large to small, if there is a multiple of that number in the range, then we can not use it
  // problem: 2^6 4^3 8^2
  // how do we handle this?
  // from small to large -> more easy, at most 19
  // but how do we handle certain numbers?
  // precompute from 1 to 1e6 * 20?
  // count the number of conflicts
  // for each number that is not the result of another power (aka 2, 3, 5, 6, 7, etc)
  // aka the base
  // we can precalculate the number of powers it will have
  // 1e6 * 19 at most
  int lim = 2e7 + 5;
  bool used[lim];
  memset(used, 0, sizeof(used));
  bool base[n + 1];
  memset(base, 1, sizeof(base));
  int cnt[25];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 2; i <= n; ++i) {
    if(base[i]) {
      int cur = 1;
      for(ll j = 1ll * i * i; j <= n; j *= i) {
        base[j] = 0;
        ++cur;
      }
      cnt[cur]++;
    }
  }
  ll res = 1, cur = 0;
  for(int i = 1; i <= 20; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(!used[i * j])
        used[i * j] = 1, ++cur;
    }
    res += cur * cnt[i];
  }
  cout << res << endl;
}