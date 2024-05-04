// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
ll solve(int n, vector<int> p, vector<int> q) {
  // choose min q
  vector<pair<int, int>> v;
  for(int i = 1; i <= n; ++i)
    v.pb(mp(q[i], i));
  sort(v.begin(), v.end());
  ll res = 0;
  for(auto x : v) {
    if(p[x.se] == x.se)
      continue;
    while(p[x.se] != x.se) {
      res += q[x.se];
      swap(p[x.se], p[p[x.se]]);
    }
  }
  return res;
}
ll solve2(int n, vector<int> p, vector<int> q) {
  // try every possible operation order?
  // 1 operation -> make position of item at position i to correct position
  vector<int> perm;
  for(int i = 1; i <= n; ++i)
    perm.pb(i);
  ll res = 1e18;
  do {
    vector<int> tmp = p;
    // try this order of swaps
    ll cur_res = 0;
    for(auto x : perm) {
      for(int j = 1; j <= n; ++j) {
        if(tmp[j] == x && tmp[j] != j) {
          cur_res += q[j];
          swap(tmp[j], tmp[tmp[j]]);
        }
      }
    }
    res = min(res, cur_res);
  } while(next_permutation(perm.begin(), perm.end()));
  return res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n = 7;
  vector<int> p;
  for(int i = 1; i <= n; ++i)
    p.pb(i);
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  do {
    vector<int> q = {0};
    for(int i = 1; i <= n; ++i) {
      q.pb(rng() % (int)1e9);
    }
    vector<int> x = p;
    x.insert(x.begin(), 0);
    if(solve(n, x, q) != solve2(n, x, q)) {
      for(int i = 1; i <= n; ++i) {
        cout << x[i] << " ";
      }
      cout << endl;
      for(int i = 1; i <= n; ++i) 
        cout << q[i] << " ";
      cout << endl;
      cout << solve(n, x, q) << endl;
      cout << solve2(n, x, q) << endl;
    }
    assert(solve(n, x, q) == solve2(n, x, q));
  } while(next_permutation(p.begin(), p.end()));
  return 0;
}