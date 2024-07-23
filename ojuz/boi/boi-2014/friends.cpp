// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
  ll ret = a * b - M * ull(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
struct shash {
  ull mod;
  vector<ull> pref, power;
  shash(string &s, ull key, ull m) {
    mod = m;
    pref = power = vector<ull>(s.size() + 1, 0);
    power[0] = 1;
    for(int i = 0; i < s.size(); ++i) {
      pref[i + 1] = modmul(pref[i], key, mod) + s[i];
      pref[i + 1] = pref[i + 1] >= mod ? pref[i + 1] - mod : pref[i + 1];
      power[i + 1] = modmul(power[i], key, mod);
    }
  }
  ull norm(ll a) {
    if(a < 0)
      return a + mod;
    else if(a >= mod)
      return a - mod;
    else
      return a;
  }
  ull query(int l, int r) {
    return norm((ll)pref[r] - modmul(pref[l - 1], power[r - l + 1], mod));
  }
  ull query(int l1, int r1, int l2, int r2) {
    return norm(modmul(query(l1, r1), power[r2 - l2 + 1], mod) + query(l2, r2));
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if(!(n & 1)) {
    cout << "NOT POSSIBLE" << endl;
    exit(0);
  }
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  const ull mod = (1ll << 61) - 1;
  shash h(s, rng() % mod, mod);
  int cnt = 0, idx = -1;
  ll pr = -1;
  for(int i = 1; i <= n; ++i) {
    // without the i-th index, is the rest equal?
    int old_cnt = cnt;
    if(i <= n / 2) {
      if(h.query(1, i - 1, i + 1, n / 2 + 1) == h.query(n / 2 + 2, n))
        cnt += h.query(n / 2 + 2, n) != pr, pr = h.query(n / 2 + 2, n);
    }
    else if(i == n / 2 + 1) {
      if(h.query(1, i - 1) == h.query(i + 1, n))
        cnt += h.query(1, i - 1) != pr, pr = h.query(1, i - 1);
    }
    else {
      if(h.query(1, n / 2) == h.query(n / 2 + 1, i - 1, i + 1, n))
        cnt += h.query(1, n / 2) != pr, pr = h.query(1, n / 2);
    }
    idx = old_cnt == cnt ? idx : i;
  }
  if(cnt == 1) {
    int out = 0;
    for(int i = 0; i < n && out < n / 2; ++i) {
      if(i == idx - 1)
        continue;
      cout << s[i], ++out;
    }
    cout << endl;
  }
  else 
    cout << (cnt == 0 ? "NOT POSSIBLE" : "NOT UNIQUE") << endl;
  return 0;
}